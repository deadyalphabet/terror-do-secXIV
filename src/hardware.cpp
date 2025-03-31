#include<sensore.h>
#include<Arduino.h>
#include<motor.h>




void SETUP_HARWARE(){
    Serial.begin(115200);
    pinMode(PINO_A_MOTOR_DIR,OUTPUT);
    pinMode(PINO_A_MOTOR_ESQ,OUTPUT);
    pinMode(ENCODER_DIR_A,INPUT);
    pinMode(ENCODER_DIR_B,INPUT);
    


}


void LER_ENCODER(){
    int8_t b = digitalRead(ENCODER_DIR_B);
    if(b>0){
        posicao++;
    }
    else{
        posicao--;
    }
}