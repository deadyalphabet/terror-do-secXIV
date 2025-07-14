#include <objetos.h>


Motor::Motor(uint8_t posPin, uint8_t negPin, MotorCommand command, uint8_t speed) {
   _posPin = posPin;
   _negPin = negPin;
   _command = command;
   _speed = speed;

   pinMode(posPin, OUTPUT);
   pinMode(negPin, OUTPUT);
   _driveMotor();
}
MotorCommand Motor::command() { return _command; }
void Motor::setCommand(MotorCommand command) {
   _command = command;
   _driveMotor();
}
uint8_t Motor::speed() { return _speed; }
void Motor::setSpeed(uint8_t speed) {
   _speed = speed;
   _driveMotor();
}
void Motor::drive(MotorCommand command, uint8_t speed) {
   _command = command;
   _speed = speed;
   _driveMotor();
}
void Motor::stop(MotorCommand command) {
   _command = (command == Freio) ? Freio : Coast;
   _driveMotor();
}
void Motor::_driveMotor() {
   if (_command == Freio || _command == Coast) _speed = 0;  // set speed to 0 if motor is stopping
   _speed = constrain(_speed, 0, 100);  // constrain speed to valid percentage range
   switch (_command) {
      case Frente:
         digitalWrite(_negPin, LOW);
         analogWrite(_posPin, map(_speed, 0, 100, 0, 255));  // use PWM to adjust speed
         break;
      case Tras:
         digitalWrite(_posPin, LOW);
         analogWrite(_negPin, map(_speed, 0, 100, 0, 255));  // use PWM to adjust speed
         break;
      case Freio:
         digitalWrite(_posPin, HIGH);
         digitalWrite(_negPin, HIGH);
         break;
      default:  // Coast
         digitalWrite(_posPin, LOW);
         digitalWrite(_negPin, LOW);
         break;
   }
}