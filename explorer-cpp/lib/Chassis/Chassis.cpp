#include "Chassis.h"

Chassis::Chassis() {}

void Chassis::begin() {
    pinMode(ENA_PIN, OUTPUT);
    pinMode(ENB_PIN, OUTPUT);
    pinMode(IN1_PIN, OUTPUT);
    pinMode(IN2_PIN, OUTPUT);
    pinMode(IN3_PIN, OUTPUT);
    pinMode(IN4_PIN, OUTPUT);
    stop();
}

void Chassis::move(int leftSpeed, int rightSpeed) {
    setMotorSpeed('L', leftSpeed);
    setMotorSpeed('R', rightSpeed);
}

void Chassis::stop() {
    // Apaga los motores
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
    digitalWrite(IN3_PIN, LOW);
    digitalWrite(IN4_PIN, LOW);
    // Velocidad 0
    analogWrite(ENA_PIN, 0);
    analogWrite(ENB_PIN, 0);
}

void Chassis::setMotorSpeed(char motor, int speed) {
    // Limita la velocidad al rango de PWM (-255 a 255)
    speed = constrain(speed, -255, 255);

    if (motor == 'L') {
        if (speed > 0) { // Hacia adelante
            digitalWrite(IN1_PIN, HIGH);
            digitalWrite(IN2_PIN, LOW);
        } else if (speed < 0) { // Hacia atrás
            digitalWrite(IN1_PIN, LOW);
            digitalWrite(IN2_PIN, HIGH);
        } else { // Detener
            digitalWrite(IN1_PIN, LOW);
            digitalWrite(IN2_PIN, LOW);
        }
        analogWrite(ENA_PIN, abs(speed));
    } else if (motor == 'R') {
        if (speed > 0) { // Hacia adelante
            digitalWrite(IN3_PIN, HIGH);
            digitalWrite(IN4_PIN, LOW);
        } else if (speed < 0) { // Hacia atrás
            digitalWrite(IN3_PIN, LOW);
            digitalWrite(IN4_PIN, HIGH);
        } else { // Detener
            digitalWrite(IN3_PIN, LOW);
            digitalWrite(IN4_PIN, LOW);
        }
        analogWrite(ENB_PIN, abs(speed));
    }
}