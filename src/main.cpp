
#include <motor.h>
#include <sensore.h>




void  DIRECAO_ROBO (int DIRECAO, int POTENCIA_MOTOR){
  analogWrite(PWM_PONTE_H_DIR,POTENCIA_MOTOR);//passos do motor
  analogWrite(PWM_PONTE_H_ESQ,POTENCIA_MOTOR);
  switch (DIRECAO)
  {
  case FRENTE:
    MOTOR_DIR_FRENTE();
    MOTOR_ESQ_FRENTE();
    break;
    
  case DIREITA: 
   MOTOR_DIR_FRENTE();
   MOTOR_ESQ_TRAS();
   break;
  
  case ESQUERDA:
   MOTOR_DIR_TRAS();
   MOTOR_ESQ_FRENTE();
   break; 

  }

}


void MOTOR_DIR_FRENTE()// controle frente e tras d cada motor 
{
  digitalWrite(PINO_A_MOTOR_DIR,HIGH);
  digitalWrite(PINO_B_MOTOR_DIR,LOW);
}
void MOTOR_DIR_TRAS()
{
  digitalWrite(PINO_A_MOTOR_DIR,LOW);
  digitalWrite(PINO_B_MOTOR_DIR,HIGH);
}
void MOTOR_ESQ_FRENTE()
{
  digitalWrite(PINO_A_MOTOR_ESQ,HIGH);
  digitalWrite(PINO_B_MOTOR_ESQ,LOW);
}
void MOTOR_ESQ_TRAS()
{
  digitalWrite(PINO_A_MOTOR_ESQ,LOW);
  digitalWrite(PINO_B_MOTOR_ESQ,HIGH);
}

long NUMERO_DE_PASSOS() {
  attachInterrupt(ENCODER_DIR_A,LER_ENCODER,HIGH);
};

