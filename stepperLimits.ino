#include <Stepper.h>

const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 9, 11, 10, 12);

const int limitSwitch1Pin = 2; // Pin connected to the first limit switch
const int limitSwitch2Pin = 3; // Pin connected to the second limit switch

void setup()
{
    myStepper.setSpeed(5);
    Serial.begin(9600);

    pinMode(limitSwitch1Pin, INPUT);
    pinMode(limitSwitch2Pin, INPUT);
}

void loop()
{
    // Move the motor clockwise until the first limit switch is hit
    Serial.println("Moving clockwise");
    while (digitalRead(limitSwitch1Pin) != HIGH)
    {
        // myStepper.step(1);
        myStepper.setSpeed(12); // rpm
        myStepper.step(-2048);  // do 2048 steps -- corresponds to one revolution in one minute
        delay(3600000);
    }

    delay(500);

    // Move the motor counterclockwise until the second limit switch is hit
   // Serial.println("Moving counterclockwise");
    while (digitalRead(limitSwitch2Pin) != HIGH)
    {
        myStepper.setSpeed(12); // rpm
        myStepper.step(2048);  // do 2048 steps -- corresponds to one revolution in one minute
        delay(3600000);
    }
    delay(500);
}
