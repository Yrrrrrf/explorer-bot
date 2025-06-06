<h1 align="center">
    <!-- <img src="./resources/img/robot.png" alt="ExplorerBot Logo" width="128" height="128"> -->
    <img src="https://raw.githubusercontent.com/Yrrrrrf/explorer-bot/main/resources/img/robot.png" alt="ExplorerBot Logo" width="128" height="128">
    <div align="center">ExplorerBot</div>
</h1>

Proyecto Final de Robótica para diseñar, construir y programar un robot móvil capaz de recorrer un entorno interior desconocido y generar un mapa bidimensional básico del mismo. El robot utilizará odometría para estimar su posición y sensores de presencia para detectar obstáculos.

## ✨ Objetivos Principales

- **Navegación Autónoma Básica**: El robot se desplazará por el entorno.
- **Detección de Obstáculos**: Utilizará sensores para identificar paredes y obstáculos.
- **Estimación de Posición (Odometría)**: Calculará su trayectoria mediante encoders en los motores.
- **Generación de Mapa 2D**: Creará una representación visual del entorno explorado.
- **Integración Completa**: Combinar mecánica, electrónica y programación de forma efectiva.

## 🛠️ Hardware Clave (Sugerido)

- **Microcontrolador**: Arduino UNO/Mega, ESP32, o Raspberry Pi (según complejidad).
- **Chasis del Robot**: Estructura base con ruedas/orugas.
- **Motores**: Motores DC con encoders (para odometría).
- **Controlador de Motores**: L298N, DRV8833, o similar.
- **Sensores de Distancia**:
    - Ultrasónicos (HC-SR04) para detección de obstáculos a media distancia.
    - Infrarrojos (SHARP o similares) para detección a corta distancia o paredes (opcional).
- **Fuente de Alimentación**: Baterías (LiPo, Li-Ion, o AA recargables) y regulador de voltaje si es necesario.

## 📋 Estado del Proyecto

| Fase                                      | Estado |
| ----------------------------------------- | :----: |
| Selección de Hardware y Ensamblaje Inicial|   📅   |
| Control Básico de Motores                 |   📅   |
| Integración de Encoders (Odometría)       |   📅   |
| Integración de Sensores de Distancia      |   📅   |
| Desarrollo del Algoritmo de Mapeo         |   📅   |
| Pruebas de Navegación y Mapeo Integrado   |   📅   |
| Generación del Mapa Visual                |   📅   |
| Documentación Final                       |   📅   |

*(Leyenda: ✅ Completado, 🔄 En Progreso, 📅 Pendiente)*

## 📐 Diseño Conceptual del Robot (Ejemplo)

![Diseño Conceptual](./resources/img/robot-design-placeholder.png)
*(Reemplazar con un boceto o diagrama de tu robot)*

## 🗺️ Ejemplo de Mapa Generado (Objetivo)

![Mapa Ejemplo](./resources/img/map-example-placeholder.png)
*(Reemplazar con un ejemplo del tipo de mapa que esperas generar)*

<!-- 
## 📚 Documentación del Proyecto

- **Informe Técnico Principal**: (Enlace a tu documento principal, puede ser `resources/docs/informe-tecnico.md` o el `.docx` si lo conviertes)
- **Marco Teórico**: `resources/docs/00-marco-teorico-robotica.md`
- **Especificaciones Técnicas del Robot**: `resources/docs/01-especificaciones-tecnicas-robot.md`
- **Diagramas (Esquemático, Conexiones)**: `resources/docs/diagramas.md` (o imágenes en `resources/img/`)
- **Algoritmo de Mapeo**: `resources/docs/algoritmo-mapeo.md`
-->

## ⚖️ Licencia

Este proyecto está bajo la licencia [MIT](./LICENSE).