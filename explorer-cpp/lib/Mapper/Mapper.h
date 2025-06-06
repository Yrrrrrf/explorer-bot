#ifndef MAPPER_H
#define MAPPER_H

#include <Arduino.h>
#include "Odometry.h"
#include "Radar.h"

// --- Configuración del Mapa ---
#define MAP_WIDTH 30              // Ancho del mapa en celdas
#define MAP_HEIGHT 30             // Alto del mapa en celdas
#define CELL_SIZE 5.0f            // Tamaño de cada celda en cm. ¡Ajustar según la precisión deseada!

// --- Estados de las Celdas ---
#define STATE_UNKNOWN   0
#define STATE_EMPTY     1
#define STATE_OBSTACLE  2

class Mapper {
public:
    // El constructor necesita saber sobre la odometría y el radar
    Mapper(Odometry* odometry, Radar* radar);

    void begin();
    void update(); // La función principal que realiza el mapeo
    void printToSerial(); // Imprime el mapa al monitor serie para depuración

private:
    Odometry* _odom;
    Radar* _radar;

    // El mapa en sí. Usamos int8_t para ahorrar memoria.
    int8_t _map[MAP_HEIGHT][MAP_WIDTH]; 

    // Función para convertir coordenadas del mundo (cm) a celdas del mapa
    void worldToMap(float x, float y, int* mapX, int* mapY);
};

#endif