// #include <Arduino.h>
// #include "Chassis.h"
// #include "Radar.h"
// #include "Odometry.h"
// #include "Mapper.h" // <-- Incluimos la nueva librería

// // Crear instancias de cada subsistema
// Chassis chassis;
// Radar radar;
// Odometry odom;
// Mapper mapper(&odom, &radar); // <-- El Mapper necesita saber sobre odom y radar

// unsigned long lastMapPrintTime = 0;

// void setup() {
//     Serial.begin(115200);
//     Serial.println("ExplorerBot: Online. Starting Mapping Sequence.");

//     // Inicializar cada subsistema
//     chassis.begin();
//     radar.begin();
//     odom.begin();
//     mapper.begin(); // <-- No olvidar inicializar el mapa
// }

// void loop() {
//     // --- Bucle principal de control ---

//     // 1. Actualizar la estimación de posición
//     odom.update();

//     // 2. Actualizar el mapa con la nueva información de posición y sensores
//     mapper.update();

//     // 3. Lógica de Navegación (Ejemplo Básico)
//     //    Esta lógica debe ser mejorada para una exploración completa.
//     int frontDist = radar.getFrontDistance();
//     if (frontDist < 25) {
//         // Obstáculo cerca: detenerse y girar
//         chassis.move(-100, 100); // Girar sobre su propio eje
//         delay(500); // Girar por medio segundo
//     } else {
//         // Camino libre: avanzar
//         chassis.move(150, 150);
//     }

//     // 4. Imprimir el mapa al Monitor Serie cada 2 segundos para depurar
//     if (millis() - lastMapPrintTime > 2000) {
//         chassis.stop(); // Detener el robot para imprimir el mapa tranquilamente
//         mapper.printToSerial();
//         lastMapPrintTime = millis();
//     }
// }