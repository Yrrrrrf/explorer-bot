#ifndef ODOMETRY_H
#define ODOMETRY_H

#include <Arduino.h>
#include <Encoder.h>

// --- Configuración de Pines para Encoders ---
// Recuerda: Los primeros pines (2, 3) deben ser de interrupción en el UNO
#define ENCODER_LEFT_A_PIN 2
#define ENCODER_LEFT_B_PIN 4
#define ENCODER_RIGHT_A_PIN 3
#define ENCODER_RIGHT_B_PIN 12

// --- Constantes Físicas del Robot (¡DEBES MEDIRLAS Y AJUSTARLAS!) ---
#define WHEEL_DIAMETER 6.5 // Diámetro de la rueda en cm
#define WHEEL_BASE 14.5    // Distancia entre el centro de las dos ruedas en cm
#define COUNTS_PER_REVOLUTION 620 // Pulsos del encoder por cada vuelta completa de la rueda

class Odometry {
public:
    Odometry();
    void begin();
    void update(); // Debe llamarse repetidamente en el loop principal
    
    // Funciones para obtener la posición
    float getX();
    float getY();
    float getTheta(); // Ángulo en radianes

private:
    Encoder encoderLeft;
    Encoder encoderRight;

    long prevLeftCounts;
    long prevRightCounts;

    float x_pos;
    float y_pos;
    float theta; // Radianes

    float countsToCm;
};

#endif