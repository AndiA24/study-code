#include<stdio.h>

int main (void){
    char shipClass[] = "NCC-1701-D";
    int crewMembers = 1912;
    int missionDays = 50;
    unsigned long traveledDistance = 30000000000000000;
    float fractionofC = 38.6;
    float currentRange = 7489395.888;

    printf("Spaceship Dashboard\n");
    printf("------------------------------------\n\n");
    printf("%-50s %s\n", "Ship Class:",shipClass);
    printf("%-50s %d\n","Crew Members:",crewMembers);
    printf("%-50s %d\n","Mission Days:", missionDays);
    printf("%-50s %ld\n","Traveled Distance:", traveledDistance);
    printf("%-50s %.1f\n", "Fraction of Speed of Light:", fractionofC);
    printf("%-50s %.3f\n", "Current Range:", currentRange);

    return 0;
}