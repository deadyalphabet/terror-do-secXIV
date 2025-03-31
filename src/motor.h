#include <Arduino.h>

#include <sensore.h>


const uint16_t POTENCIA_MOTOR =0; // potencia para a possisao final do motor
//calculo de erro do motor
volatile uint16_t posicao = 0;
const long prevT=0;
const float eprev = 0;
float eintegral=0;
float kp = 1;   //constantes para o calculo de erro
float kd = 0.025;
float ki = 0.0;


bool FREIO_DIR;
bool FREIO_ESQ;

float deltaT (prevT);






enum DIRECAO {
  FRENTE,
  DIREITA,
  ESQUERDA,
  MEIA_VOLTA
};

