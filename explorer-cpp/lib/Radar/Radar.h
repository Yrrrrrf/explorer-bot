#ifndef RADAR_H
#define RADAR_H

#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>

// --- Configuración de Pines ---
#define SERVO_PIN 11
#define TRIGGER_PIN 12
#define ECHO_PIN 13
#define MAX_DISTANCE_CM 200 // Distancia máxima a sensar

class Radar {
public:
    Radar();
    void begin();
    int getDistanceAt(int angle);
    int getFrontDistance();

private:
    Servo scannerServo;
    NewPing sonar;
};

#endif