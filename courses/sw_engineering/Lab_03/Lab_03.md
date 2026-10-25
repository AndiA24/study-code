# Lab 3: Software Implementation and Verification

This lab is designed to help you understand the implementation and verification phases of the software engineering lifecycle by implementing changes and using automated checks to verify their behavior.

🟢 __Simple__: A guided software engineering activity that introduces the basic concepts step by step. It should not take more than 15 - 20 minutes to finish.

🟡 __Moderate__: A software engineering activity that asks you to apply the concepts to a realistic team or project situation. These tasks can usually be completed in about 30 - 45 minutes, depending on your prior knowledge.

🔴 __Complex__: A more demanding or longer software engineering activity that requires you to combine concepts, make decisions as a team, and work through a broader project context. Such tasks might take up to a few hours to complete.


## 🟡 Section I: Your First GitLab Pipeline

In this exercise, you will create a continuous integration (CI) pipeline that automatically checks a small C++ implementation.
You will trigger it by pushing a commit and by creating or updating a merge request (MR), then experience how a failing test provides feedback before a change is merged.

### Prerequisites

* A GitLab account and permission to push branches and create merge requests in your project.
* Git installed locally and authentication configured for your GitLab instance.
* An available Linux runner using the Docker or Kubernetes executor that can run the `gcc:14` image. Check **Settings > CI/CD > Runners**; ask your instructor if no suitable runner is available. This exercise uses jobs without runner tags.

The C++ compiler runs inside the pipeline's container, so a local compiler installation is optional.
A **pipeline** contains automated **jobs**; a **runner** executes those jobs. **Stages** group jobs and determine their order.

### Task Description

#### 1. Prepare a Repository

Create a blank GitLab project named `first-pipeline` and initialize it with a README.
Clone the project using the clone URL shown by GitLab, then enter its directory:

```bash
git clone <your-project-clone-url>
cd first-pipeline
git switch -c ci/first-pipeline
```

Replace `<your-project-clone-url>` with your actual URL.
If you use an instructor-provided practice project, clone that project instead and choose an unused branch name.

#### 2. Add a Small Implementation and Tests

Create `calculator.hpp` in the repository root:

```cpp
#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

int add(int a, int b);

#endif // CALCULATOR_HPP
```

Create `calculator.cpp` beside it:

```cpp
#include "calculator.hpp"

int add(int a, int b)
{
    return a + b;
}
```

Create `test_calculator.cpp` in the same directory:

```cpp
#include "calculator.hpp"
#include <iostream>

int main()
{
    int failures = 0;

    const auto check = [&failures](const char* name, int actual, int expected)
    {
        std::cout << name << ": expected " << expected
                  << ", actual " << actual;
        if (actual != expected)
        {
            std::cout << " [FAIL]\n";
            ++failures;
        }
        else
        {
            std::cout << " [PASS]\n";
        }
    };

    check("Positive numbers", add(2, 3), 5);
    check("Negative number", add(-2, 3), 1);

    return failures == 0 ? 0 : 1;
}
```

This small test program checks expected behavior without an external test framework.
It returns exit code `0` when both checks pass and `1` if any check fails. GitLab uses a command's exit code to determine success or failure.

#### 3. Define the Pipeline

Create `.gitlab-ci.yml` in the repository root. Preserve the leading dot and use spaces for YAML indentation.

```yaml
default:
  image: gcc:14

workflow:
  rules:
    - if: '$CI_PIPELINE_SOURCE == "merge_request_event"'
    - if: '$CI_COMMIT_BRANCH && $CI_OPEN_MERGE_REQUESTS && $CI_PIPELINE_SOURCE == "push"'
      when: never
    - if: '$CI_COMMIT_BRANCH && $CI_PIPELINE_SOURCE == "push"'

stages:
  - build
  - test

build_tests:
  stage: build
  script:
    - g++ -std=c++17 -Wall -Wextra -Werror calculator.cpp test_calculator.cpp -o test_calculator
  artifacts:
    paths:
      - test_calculator

unit_tests:
  stage: test
  script:
    - 'echo "Pipeline source: $CI_PIPELINE_SOURCE"'
    - ./test_calculator
```

`build_tests` compiles and links the implementation and test program. After it succeeds, `unit_tests` runs the resulting executable to check behavior.
The `gcc:14` image supplies the C++ compiler. The build job saves `test_calculator` as an **artifact**, which GitLab downloads into the test job because it runs in a later stage. Jobs have separate working environments, so this explicitly passes the executable between them.

The `workflow` rules create a branch pipeline for a push when the branch has no open MR. Once an MR is open, GitLab uses merge request pipelines instead, avoiding duplicate branch and MR pipelines for the same push.
You do not need to memorize these rules for this exercise.

#### 4. Trigger a Pipeline with a Push

Commit and push the four files:

```bash
git add calculator.hpp calculator.cpp test_calculator.cpp .gitlab-ci.yml
git commit -m "Add implementation, tests, and first CI pipeline"
git push -u origin ci/first-pipeline
```

Open **Build > Pipelines** in your GitLab project and select the new pipeline.

* Confirm that `build_tests` runs before `unit_tests` and that both pass.
* Open the `unit_tests` job log. Find the two test results and the pipeline source, which should be `push`.
* Identify the branch and commit associated with this pipeline.

If a job stays pending, check whether a runner is available and eligible to run untagged jobs on your branch. If the configuration is rejected, check the YAML indentation and filename; use GitLab's pipeline editor validation if available.

#### 5. Trigger a Merge Request Pipeline and Experience a Failure

Create an MR in GitLab from `ci/first-pipeline` into the project's default branch. Leave it open.
Creating the MR should start a merge request pipeline. Open it from the MR's pipeline area and find `merge_request_event` in the `unit_tests` job log.

Now deliberately introduce a bug in `calculator.cpp` by changing the function to:

```cpp
int add(int a, int b)
{
    return a - b;
}
```

Keep the `#include "calculator.hpp"` line at the top of the file.

Commit and push the change to the same branch:

```bash
git add calculator.cpp
git commit -m "Introduce a calculation bug to observe CI feedback"
git push
```

Inspect the new pipeline associated with the open MR.

* Verify that `build_tests` passes, but `unit_tests` fails.
* Read the failure output and identify the expected and actual results.
* Explain why successful compilation does not imply correct behavior.

Restore `return a + b;`, commit the fix, and push again. Confirm that a new MR pipeline passes.
A push updates the existing MR; you do not need to create another one.

#### 6. Reflect on Implementation and Verification

Record the pipeline link and result for the initial push, the failing MR update, and the successful fix.
Then answer briefly:

* Do you understand the complete pipeline code and how it works? If not, which parts are unclear? Try to figure it out and explain them in your own words.
* What triggered each pipeline, and which commit did it verify?
* How did the pipeline connect implementation work to verification?
* Does a passing pipeline prove that the entire program is correct? Explain one limitation of these tests.

Submit your MR link and these observations. Keep the successful MR available for review.

GitLab references: [Merge request pipelines](https://docs.gitlab.com/ci/pipelines/merge_request_pipelines/) and [switching between branch and merge request pipelines](https://docs.gitlab.com/ci/yaml/workflow/#switch-between-branch-pipelines-and-merge-request-pipelines).
