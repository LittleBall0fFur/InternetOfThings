#include <Servo.h>

const int trigPin = 5;
const int echoPin = 6;
int servoPin = 3;

long duration;
int distance;

Servo Servo1;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    Servo1.attach(servoPin);
    Servo1.write(0);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 30)
    {
        Servo1.write(90);
        Serial.println("Servo is at 90");
    }
    else
    {
        Servo1.write(0);
    }
    delay(500);
}
