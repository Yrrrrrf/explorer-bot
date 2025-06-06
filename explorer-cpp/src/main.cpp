#include <Arduino.h>
#include "Chassis.h"
#include "Radar.h"
#include "Odometry.h"

// Crear instancias de cada subsistema del robot
Chassis chassis;
Radar radar;
Odometry odom;

unsigned long lastOdomPrintTime = 0;

void setup() {
    Serial.begin(115200); // Usa una velocidad alta para imprimir datos
    Serial.println("ExplorerBot: Online.");

    // Inicializar cada subsistema
    chassis.begin();
    radar.begin();
    odom.begin();
}

void loop() {
    // La odometría debe actualizarse en cada ciclo del loop
    // para la máxima precisión.
    odom.update();

    // --- Bucle de Prueba ---
    // Este es un ejemplo de cómo usarías las librerías.
    // La lógica real del mapeo irá aquí.

    // 1. Mide la distancia al frente
    int frontDist = radar.getFrontDistance();

    // 2. Toma una decisión simple: si hay un obstáculo, detente. Si no, avanza.
    if (frontDist < 20) {
        chassis.stop();
    } else {
        // Moverse hacia adelante a media velocidad (150 de 255)
        chassis.move(150, 150); 
    }

    // 3. Imprime la posición estimada cada segundo
    if (millis() - lastOdomPrintTime > 1000) {
        Serial.print("X: ");
        Serial.print(odom.getX());
        Serial.print(" cm, Y: ");
        Serial.print(odom.getY());
        Serial.print(" cm, Theta: ");
        Serial.print(odom.getTheta() * 180 / PI); // Convierte a grados para leerlo mejor
        Serial.println(" deg");
        
        lastOdomPrintTime = millis();
    }
}