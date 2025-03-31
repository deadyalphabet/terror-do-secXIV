#include <Arduino.h>

//motor direito//
const uint8_t ENCODER_DIR_A =2;
const uint8_t ENCODER_DIR_B =3;
const uint8_t PINO_A_MOTOR_DIR =11;
const uint8_t PINO_B_MOTOR_DIR =15;
const uint8_t PWM_PONTE_H_DIR =1;

//motor esquerdo
const uint8_t ENCODER_ESQ_A =4;
const uint8_t ENCODER_ESQ_B =5;
const uint8_t PINO_A_MOTOR_ESQ =12;
const uint8_t PINO_B_MOTOR_ESQ =13;
const uint8_t PWM_PONTE_H_ESQ =6;



void LER_ENCODER();
void SETUP_HARWARE();
