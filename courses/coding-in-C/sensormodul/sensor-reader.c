#include<stdio.h>
int main (void){
    char sensorValue = 0xA7;
    unsigned int measureValue;
    printf("Sensorstatus:\n\n");

    printf("Fehler: ");
    if (0b10000000 & sensorValue){
        printf("Ja\n");
    }
    else{
        printf("Nein\n");
    }

    printf("Temperatur: ");
    if(0b01000000 & sensorValue){
        printf("Übertemperatur\n");
    }
    else{
        printf("Ok\n");
    }

    printf("Spannung: ");
    if(0b00100000 & sensorValue){
        printf("Unterspannung\n");
    }
    else{
        printf("Ok\n");
    }

    printf("Messwert: ");
    measureValue = (0b00001111 & sensorValue);
    printf("%i\n", measureValue);

    return 0;
}