
#include "Arduino.h"
enum MotorCommand{
    Frente,
    Tras,
    Freio,
    Coast //freio lento
};
class Motor
{
private:
    int RPM, Diametro;
    MotorCommand _command;  // motor command
    uint8_t _speed;         // motor speed (percentage of maximum speed)
    uint8_t _posPin;        // motor driver positive input control pin
    uint8_t _negPin;        // motor driver negative input control pin

    void _driveMotor ();    // drive motor with current command and speed attributes
public:
    Motor (uint8_t posPin, uint8_t negPin, MotorCommand command = Coast, uint8_t speed = 0)
    {
        RPM =1500; Diametro =22;
    }
    MotorCommand command();  // get motor command
    void setCommand(MotorCommand command);  // set motor command
    uint8_t speed();  // get motor speed
    void setSpeed(uint8_t speed);  // set motor speed
    void drive(MotorCommand command = Frente, uint8_t speed = 100);  // drive motor with specified attributes
    void stop(MotorCommand command = Coast);  // stop motor with specified command


};

