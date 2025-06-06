<h1 align="center">
    <img src="https://raw.githubusercontent.com/Yrrrrrf/explorer-bot/main/resources/img/robot.png" alt="ExplorerBot Logo" width="128" height="128">
    <div align="center">ExplorerBot</div>
</h1>

Proyecto Final de Robótica para diseñar, construir y programar un robot móvil capaz de recorrer un entorno interior desconocido y generar un mapa bidimensional básico del mismo. El robot utilizará odometría a partir de encoders en los motores para estimar su posición y un sensor ultrasónico móvil para detectar obstáculos y mapear el entorno.

## ✨ Objetivos Principales

- **Navegación Autónoma Básica**: El robot se desplazará por el entorno de forma autónoma.
- **Detección de Obstáculos**: Utilizará un sensor ultrasónico montado en un servo para escanear y identificar obstáculos.
- **Estimación de Posición (Odometría)**: Calculará su trayectoria y posición con alta precisión mediante los encoders de los motores.
- **Generación de Mapa 2D**: Creará una representación visual del entorno explorado.
- **Integración Completa**: Combinar mecánica, electrónica y programación de forma efectiva en un prototipo funcional.

## 🛠️ Componentes del Proyecto

Esta es la lista de hardware específico utilizado para construir el ExplorerBot.

#### Control y Cómputo
- **Microcontrolador**: **Arduino UNO R3**. El cerebro que ejecuta toda la lógica de control.
- **Shield de Expansión**: **Sensor Shield V5.0**. Facilita enormemente las conexiones, proveyendo pines VCC/GND dedicados para cada pin de E/S, ideal para conectar sensores y servos.

#### Chasis y Actuadores
- **Chasis**: **Kit de Chasis 2WD para Robot Inteligente**. Proporciona la estructura base y la mecánica de movimiento.
- **Motores**: **2x Motores Garosa 12V DC con Encoders**. Una mejora clave sobre los motores del kit, que permite una lectura precisa de la rotación de las ruedas, crucial para la odometría.
- **Controlador de Motores**: **Módulo L298N**. Permite al Arduino controlar la dirección y velocidad de los motores de 12V.

#### Sensores y Percepción
- **Sensor de Distancia**: **HC-SR04 (Ultrasónico)**. El "ojo" principal del robot para medir la distancia a los obstáculos.
- **Sistema de Escaneo**: **Servo SG90**. Permite que el sensor HC-SR04 gire, dándole al robot la capacidad de "mirar" en diferentes direcciones sin tener que mover todo el chasis, fundamental para un mapeo eficiente.

#### Sistema de Alimentación
- **Fuente de Alimentación Principal**: Un portapilas para suministrar **12V** a los motores.
- **Regulador de Voltaje**: **Módulo DAOKAI DC-DC Buck Converter**. Un componente crítico que toma los 12V de la fuente principal y los reduce de forma segura a **5V** para alimentar el Arduino, el Sensor Shield, y los sensores.

## 📋 Estado del Proyecto

| Fase                                      | Estado |
| ----------------------------------------- | :----: |
| Selección de Hardware y Ensamblaje Inicial|   ✅   |
| Control Básico de Motores                 |   🔄   |
| Integración de Encoders (Odometría)       |   📅   |
| Integración de Sensores de Distancia      |   📅   |
| Desarrollo del Algoritmo de Mapeo         |   📅   |
| Pruebas de Navegación y Mapeo Integrado   |   📅   |
| Generación del Mapa Visual                |   📅   |
| Documentación Final                       |   📅   |

*(Leyenda: ✅ Completado, 🔄 En Progreso, 📅 Pendiente)*

## 📐 Diseño y Ensamblaje del Robot

 
*(Reemplaza esta imagen con una foto real de tu robot una vez ensamblado)*

## 🗺️ Ejemplo de Mapa Generado (Objetivo)

![Mapa Ejemplo](./resources/img/map-example-placeholder.png)
*(Reemplazar con un ejemplo del tipo de mapa que esperas generar)*

## 📚 Documentación del Proyecto

- **Informe Técnico Principal**: `resources/docs/informe-tecnico.md`
- **Marco Teórico**: `resources/docs/00-marco-teorico-robotica.md`
- **Especificaciones Técnicas**: `resources/docs/01-especificaciones-tecnicas-robot.md`
- **Diagramas (Esquemático, Conexiones)**: `resources/docs/diagramas.md`
- **Algoritmo de Mapeo**: `resources/docs/algoritmo-mapeo.md`

## ⚖️ Licencia

Este proyecto está bajo la licencia [MIT](./LICENSE).