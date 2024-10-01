const int switchPin = 10;
const int buttonPin = 11;
const int motorPin1 = 1;
const int motorPin2 = 2;
const int motorPin3 = 3;
const int motorPin4 = 4;
const int motorPin5 = 5;
const int motorPin6 = 6;
const int motorPin7 = 7;
const int motorPin8 = 12;
const int trigPin = 8;
const int echoPin = 9;

bool switchState = false;
bool buttonState = false;
bool motorState = true;

void setup() {
    Serial.begin(9600);
    pinMode(switchPin, INPUT);
    pinMode(buttonPin, INPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(motorPin5, OUTPUT);
    pinMode(motorPin6, OUTPUT);
    pinMode(motorPin7, OUTPUT);
    pinMode(motorPin8, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;
    switchState = digitalRead(switchPin);

    if (distance < 100) {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        digitalWrite(motorPin5, LOW);
        digitalWrite(motorPin6, LOW);
        digitalWrite(motorPin7, LOW);
        digitalWrite(motorPin8, LOW);
    } 
    else if (switchState == HIGH) {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        digitalWrite(motorPin5, HIGH);
        digitalWrite(motorPin6, LOW);
        digitalWrite(motorPin7, LOW);
        digitalWrite(motorPin8, HIGH);
        delay(1000);
    } 
    else {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        digitalWrite(motorPin5, LOW);
        digitalWrite(motorPin6, LOW);
        digitalWrite(motorPin7, LOW);
        digitalWrite(motorPin8, LOW);
    }

    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        digitalWrite(motorPin7, HIGH);
        digitalWrite(motorPin8, HIGH);
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        digitalWrite(motorPin5, HIGH);
        digitalWrite(motorPin6, LOW);
        delay(500);
    }
}
