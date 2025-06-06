#include "Radar.h"

Radar::Radar() : sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE_CM) {}

void Radar::begin() {
    scannerServo.attach(SERVO_PIN);
    scannerServo.write(90); // Inicia mirando al frente
    delay(500); // Dar tiempo al servo para que se posicione
}

// Devuelve la distancia en cm en un ángulo específico
int Radar::getDistanceAt(int angle) {
    // Limita el ángulo al rango del servo
    angle = constrain(angle, 15, 165); // Rango seguro para SG90
    scannerServo.write(angle);
    delay(300); // Espera a que el servo se mueva
    int distance = sonar.ping_cm();
    if (distance == 0) { // 0 significa fuera de rango
        return MAX_DISTANCE_CM;
    }
    return distance;
}

// Un atajo para medir rápidamente la distancia al frente
int Radar::getFrontDistance() {
    return getDistanceAt(90);
}