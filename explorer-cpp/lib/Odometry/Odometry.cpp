#include "Odometry.h"
#include <math.h>

Odometry::Odometry() : 
    encoderLeft(ENCODER_LEFT_A_PIN, ENCODER_LEFT_B_PIN),
    encoderRight(ENCODER_RIGHT_A_PIN, ENCODER_RIGHT_B_PIN)
{
    prevLeftCounts = 0;
    prevRightCounts = 0;
    x_pos = 0.0;
    y_pos = 0.0;
    theta = 0.0;
}

void Odometry::begin() {
    // Calcula el factor de conversión una sola vez
    float wheel_circumference = PI * WHEEL_DIAMETER;
    countsToCm = wheel_circumference / COUNTS_PER_REVOLUTION;
}

void Odometry::update() {
    long currentLeftCounts = encoderLeft.read();
    long currentRightCounts = encoderRight.read();

    // Calcula los pulsos desde la última actualización
    long deltaLeftCounts = currentLeftCounts - prevLeftCounts;
    long deltaRightCounts = currentRightCounts - prevRightCounts;

    // Convierte los pulsos a distancia en cm
    float distLeft = deltaLeftCounts * countsToCm;
    float distRight = deltaRightCounts * countsToCm;

    // Calcula la distancia promedio y el cambio en el ángulo
    float delta_distance = (distLeft + distRight) / 2.0;
    float delta_theta = (distRight - distLeft) / WHEEL_BASE;

    // Actualiza la posición y orientación
    x_pos += delta_distance * cos(theta + delta_theta / 2.0);
    y_pos += delta_distance * sin(theta + delta_theta / 2.0);
    theta += delta_theta;

    // Guarda los valores actuales para la próxima iteración
    prevLeftCounts = currentLeftCounts;
    prevRightCounts = currentRightCounts;
}

float Odometry::getX() { return x_pos; }
float Odometry::getY() { return y_pos; }
float Odometry::getTheta() { return theta; }