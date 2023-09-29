#include <Stepper.h>

const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 9, 11, 10, 12);
unsigned long previousMillis = 0;  // will store the last time the step was performed
const long stepInterval = 3600000; // interval between steps (1 hour in milliseconds)

const int limitSwitch1Pin = 2; // D2 Pin connected to the first limit switch
const int limitSwitch2Pin = 3; // D3 Pin connected to the second limit switch

void setup()
{
    myStepper.setSpeed(5);
    Serial.begin(9600);

    pinMode(limitSwitch1Pin, INPUT_PULLUP);
    pinMode(limitSwitch2Pin, INPUT_PULLUP);
}

void loop()
{
    // Move the motor clockwise until the first limit switch is hit
    Serial.println("Moving clockwise");
    while (digitalRead(limitSwitch1Pin) != HIGH && digitalRead(limitSwitch2Pin) == HIGH)
    {
        unsigned long currentMillis = millis(); // grab the current time

        if (currentMillis - previousMillis >= stepInterval)
        {
            // it's time to step
            previousMillis = currentMillis; // save the last time we stepped

            // Step the motor
            myStepper.setSpeed(12); // rpm
            myStepper.step(2048);   // do 2048 steps -- corresponds to one revolution in one minute
        }

        // Check if the limit switch is triggered (becomes LOW)
        if (digitalRead(limitSwitch1Pin) == LOW)
        {
            // Stop the stepper motor
            myStepper.setSpeed(0);
            myStepper.step(0);
            break; // Exit the loop
        }
    }

    delay(500);

    // Move the motor counterclockwise until the second limit switch is hit
    // Serial.println("Moving counterclockwise");
    while (digitalRead(limitSwitch1Pin) != HIGH&& digitalRead(limitSwitch1Pin) == HIGH)
    {
        unsigned long currentMillis = millis(); // grab the current time

        if (currentMillis - previousMillis >= stepInterval)
        {
            // it's time to step
            previousMillis = currentMillis; // save the last time we stepped

            // Step the motor
            myStepper.setSpeed(12); // rpm
            myStepper.step(-2048);  // do 2048 steps -- corresponds to one revolution in one minute
        }

        // Check if the limit switch is triggered (becomes LOW)
        if (digitalRead(limitSwitch1Pin) == LOW)
        {
            // Stop the stepper motor
            myStepper.setSpeed(0);
            myStepper.step(0);
            break; // Exit the loop
        }
    }
    delay(500);
}
