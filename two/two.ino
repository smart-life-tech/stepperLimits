#include <Stepper.h>
#define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)
Stepper stepper(STEPS, 9, 11, 10, 12);
int Pin0 = 9;
int Pin1 = 10;
int Pin2 = 11;
int Pin3 = 12;
int i;
int n;
int currentStep = 0;

void setup()
{
    pinMode(Pin0, OUTPUT);
    pinMode(Pin1, OUTPUT);
    pinMode(Pin2, OUTPUT);
    pinMode(Pin3, OUTPUT);
}

void loop()
{
    for (i = 0; i < 6; i++)
    {
        stepper.setSpeed(12); // rpm
        stepper.step(-2048);  // do 2048 steps -- corresponds to one revolution in one minute

        digitalWrite(Pin0, LOW);
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, LOW);
        digitalWrite(Pin3, LOW);
        delay(3600); //   8min = 3600000        900000 = 15min           1800000 = 30min
    }

    for (i = 0; i < 6; i++)
    {
        stepper.setSpeed(12); // rpm
        stepper.step(2048);   // do 2048 steps in the other direction with faster speed -- corresponds to one revolution in 10 seconds

        digitalWrite(Pin0, LOW);
        digitalWrite(Pin1, LOW);
        digitalWrite(Pin2, LOW);
        digitalWrite(Pin3, LOW);
        delay(3600);
    }
}
