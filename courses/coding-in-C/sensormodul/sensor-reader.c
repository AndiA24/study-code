#include<stdio.h>

#define MASK_ERROR 0b10000000
#define MASK_OVERTEMP 0b01000000
#define MASK_LOW_VOLTAGE 0b00100000
#define MASK_SENSOR_VALUE 0b00001111

int main (void){
    char sensorValue = 0xA7;
    unsigned int measureValue;
    printf("Sensorstatus:\n\n");

    printf("Fehler: ");
    if (MASK_ERROR & sensorValue){
        printf("Ja\n");
    }
    else{
        printf("Nein\n");
    }

    printf("Temperatur: ");
    if(MASK_OVERTEMP & sensorValue){
        printf("Übertemperatur\n");
    }
    else{
        printf("Ok\n");
    }

    printf("Spannung: ");
    if(MASK_LOW_VOLTAGE & sensorValue){
        printf("Unterspannung\n");
    }
    else{
        printf("Ok\n");
    }

    printf("Messwert: ");
    measureValue = (MASK_SENSOR_VALUE & sensorValue);
    printf("%i\n", measureValue);

    return 0;
}