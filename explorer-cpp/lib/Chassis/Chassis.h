#ifndef CHASSIS_H
#define CHASSIS_H

#include <Arduino.h>

// --- Configuración de Pines para el L298N ---
// Motor Izquierdo
#define ENA_PIN 5  // Debe ser un pin PWM
#define IN1_PIN 7
#define IN2_PIN 8
// Motor Derecho
#define ENB_PIN 6  // Debe ser un pin PWM
#define IN3_PIN 9
#define IN4_PIN 10

class Chassis {
public:
    Chassis();
    void begin();
    void move(int leftSpeed, int rightSpeed);
    void stop();

private:
    void setMotorSpeed(char motor, int speed);
};

#endif