#include <stdio.h>
#include <stdlib.h>

#define SAMPLES 3000
char path_file1[] = "sensor1.txt";
char path_file2[] = "sensor2.txt";

struct SensorData{
    float time;
    double probability;
};
struct DetectionInterval{
    float start;
    float end;
    struct DetectionInterval *ptr_next;
};
struct Sensor{
    int ID;
    double threshold;
    struct SensorData data[SAMPLES];
    int object_detection[SAMPLES];
    struct DetectionInterval *ptr_head;
};
struct DataFusion{
    float time[SAMPLES];
    char object_detection[SAMPLES];
    struct DetectionInterval *ptr_head;
};

int readSensorData(char *ptr_path, struct Sensor *ptr_sensor){
    FILE *ptr_f1 = fopen(ptr_path, "r");
    if(ptr_f1 == NULL){
        printf("Error couldn't open %s", ptr_path);
        return -1;
    }
    for(int i = 0; i < SAMPLES; i++){
        fscanf(ptr_f1, "%f %lf", &ptr_sensor->data[i].time, &ptr_sensor->data[i].probability);
    }
    fclose(ptr_f1);
    return 1;
}

void checkDetection(struct Sensor *ptr_sensor){
    for(int i = 0; i < SAMPLES; i++){
        if(ptr_sensor->data[i].probability >= ptr_sensor->threshold){
            ptr_sensor->object_detection[i] = 1;
        }
        else{
            ptr_sensor->object_detection[i] = 0;
        }
    }
}

void dataFusion(struct Sensor *ptr_sensor1, struct Sensor *ptr_sensor2, struct DataFusion *ptr_fusion){
    for (int i = 0; i < SAMPLES; i++){
        if (ptr_sensor1->object_detection[i] && ptr_sensor2->object_detection[i])
        {
            ptr_fusion->object_detection[i] = 1;
        }
        else{
            ptr_fusion->object_detection[i] = 0;
        }
        ptr_fusion->time[i] = ptr_sensor1->data[i].time;
    }
}

void sensorInsertNodeAfter(struct DetectionInterval *ptr_node, struct DetectionInterval *ptr_nnode, struct Sensor *ptr_sensor){
    if (!ptr_node){ // First element
        ptr_sensor->ptr_head = ptr_nnode;
    }
    else{
        ptr_node->ptr_next = ptr_nnode;
    }
}

void fusionInsertNodeAfter(struct DetectionInterval *ptr_node, struct DetectionInterval *ptr_nnode, struct DataFusion *ptr_fusion){
    if (!ptr_node){ // First element
        ptr_fusion->ptr_head = ptr_nnode;
    }
    else{
        ptr_node->ptr_next = ptr_nnode;
    }
}

int getInterval(struct Sensor *ptr_sensor){
    char interval = 0;
    float start = 0.0;
    float end = 0.0;
    struct DetectionInterval *ptr_last_node = NULL;
    for (int i = 0; i < SAMPLES; i++){
        if (ptr_sensor->object_detection[i] == 1 && interval == 0){
            start = ptr_sensor->data[i].time;
            interval = 1;
        }
        if (ptr_sensor->object_detection[i] == 0 && interval == 1){
            end = ptr_sensor->data[i- 1].time;
            struct DetectionInterval *ptr_nnode = malloc(sizeof(ptr_nnode));
            if(!ptr_nnode){
                printf("Failed to create new Interval Element\n");
                return -1;
            }
            ptr_nnode->start = start;
            ptr_nnode->end = end;
            ptr_nnode->ptr_next = NULL;
            sensorInsertNodeAfter(ptr_last_node, ptr_nnode, ptr_sensor);
            ptr_last_node = ptr_nnode; // Save Adress of last element
            ptr_nnode = NULL; // Clear Pointer
            interval = 0;
        }
    } 
    struct DetectionInterval *ptr_node = ptr_sensor->ptr_head;
    int i = 0;
    while (ptr_node){
        printf("Interval %d: Start: %f End: %f   ", i, ptr_node->start, ptr_node->end);
        ptr_node = ptr_node->ptr_next;
        i++;
    }
    printf("\n");
    return 1;
}

int getFusionInterval(struct DataFusion *ptr_fusion){
    char interval = 0;
    float start = 0.0;
    float end = 0.0;
    struct DetectionInterval *ptr_last_node = NULL;
    for (int i = 0; i < SAMPLES; i++){
        if (ptr_fusion->object_detection[i] == 1 && interval == 0){
            start = ptr_fusion->time[i];
            interval = 1;
        }
        if (ptr_fusion->object_detection[i] == 0 && interval == 1){
            end = ptr_fusion->time[i - 1];
            struct DetectionInterval *ptr_nnode = malloc(sizeof(ptr_nnode));
            if(!ptr_nnode){
                printf("Failed to create new Interval Element\n");
                return -1;
            }
            ptr_nnode->start = start;
            ptr_nnode->end = end;
            ptr_nnode->ptr_next = NULL;
            fusionInsertNodeAfter(ptr_last_node, ptr_nnode, ptr_fusion);
            ptr_last_node = ptr_nnode; // Save Adress of last element
            ptr_nnode = NULL; // Clear Pointer
            interval = 0;
        }
    } 
    struct DetectionInterval *ptr_node = ptr_fusion->ptr_head;
    int i = 0;
    while (ptr_node){
        printf("Interval %d: Start: %f End: %f   ", i, ptr_node->start, ptr_node->end);
        ptr_node = ptr_node->ptr_next;
        i++;
    }
    printf("\n");
    return 1;
}

int main(){
    struct Sensor sensor1 = {1,0.8};
    struct Sensor sensor2 = {1,0.7};
    struct DataFusion fusion = {};
    sensor1.ptr_head = NULL;
    sensor2.ptr_head = NULL;
    struct DetectionInterval *ptr_head;

    readSensorData(path_file1, &sensor1);
    readSensorData(path_file2, &sensor2);

    checkDetection(&sensor1);
    checkDetection(&sensor2);

    dataFusion(&sensor1, &sensor2, &fusion);

    printf("%-18s", "Sensor1: ");
    getInterval(&sensor1);
    printf("%-18s", "Sensor2: ");
    getInterval(&sensor2);
    printf("%-18s", "Fusion Intervals: ");
    getFusionInterval(&fusion);
}