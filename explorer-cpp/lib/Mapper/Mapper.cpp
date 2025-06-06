#include "Mapper.h"
#include <math.h>

Mapper::Mapper(Odometry* odometry, Radar* radar) {
    _odom = odometry;
    _radar = radar;
}

void Mapper::begin() {
    // Inicializa todo el mapa como Desconocido
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            _map[y][x] = STATE_UNKNOWN;
        }
    }
}

void Mapper::update() {
    // --- 1. Marcar la posición actual del robot como Vacía ---
    float robotX = _odom->getX();
    float robotY = _odom->getY();
    int mapRobotX, mapRobotY;
    worldToMap(robotX, robotY, &mapRobotX, &mapRobotY);

    if (mapRobotX >= 0 && mapRobotX < MAP_WIDTH && mapRobotY >= 0 && mapRobotY < MAP_HEIGHT) {
        _map[mapRobotY][mapRobotX] = STATE_EMPTY;
    }

    // --- 2. Usar el radar para detectar y marcar obstáculos ---
    float robotTheta = _odom->getTheta(); // Ángulo del robot en radianes
    int distance = _radar->getFrontDistance(); // Medir distancia al frente

    if (distance > 0 && distance < MAX_DISTANCE_CM) {
        // Calcular la posición del obstáculo en el mundo
        float obstacleX = robotX + cos(robotTheta) * distance;
        float obstacleY = robotY + sin(robotTheta) * distance;

        // Convertir a coordenadas del mapa y marcarlo
        int mapObstacleX, mapObstacleY;
        worldToMap(obstacleX, obstacleY, &mapObstacleX, &mapObstacleY);
        
        if (mapObstacleX >= 0 && mapObstacleX < MAP_WIDTH && mapObstacleY >= 0 && mapObstacleY < MAP_HEIGHT) {
            _map[mapObstacleY][mapObstacleX] = STATE_OBSTACLE;
        }
    }
}

// Convierte coordenadas del mundo (en cm) a coordenadas de la rejilla del mapa
void Mapper::worldToMap(float x, float y, int* mapX, int* mapY) {
    // El origen (0,0) del mundo del robot corresponde al centro del mapa
    *mapX = (int)round(x / CELL_SIZE) + (MAP_WIDTH / 2);
    *mapY = (int)round(y / CELL_SIZE) + (MAP_HEIGHT / 2);
}

void Mapper::printToSerial() {
    Serial.println("--- Mapa Actual ---");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            char cellChar = '?'; // Carácter para Desconocido
            if (_map[y][x] == STATE_EMPTY) {
                cellChar = ' '; // Espacio para Vacío
            } else if (_map[y][x] == STATE_OBSTACLE) {
                cellChar = '#'; // Símbolo para Obstáculo
            }

            int mapRobotX, mapRobotY;
            worldToMap(_odom->getX(), _odom->getY(), &mapRobotX, &mapRobotY);
            if (x == mapRobotX && y == mapRobotY) {
                cellChar = 'R'; // Mostrar la posición del Robot
            }

            Serial.print(cellChar);
        }
        Serial.println();
    }
    Serial.println("--------------------");
}