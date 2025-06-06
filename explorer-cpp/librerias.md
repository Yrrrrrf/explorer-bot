# Guía de Librerías del Proyecto ExplorerBot

Este documento detalla las librerías de software utilizadas en el proyecto ExplorerBot, el propósito de cada una y por qué fueron elegidas para garantizar un funcionamiento robusto y un código limpio.

## Resumen de Librerías

| Componente | Librería Recomendada | ¿Por qué es necesaria? | Estado en `platformio.ini` |
| :--- | :--- | :--- | :--- |
| **Motores con Encoder** | `paulstoffregen/Encoder` | Para una lectura precisa y fiable de la rotación de las ruedas mediante interrupciones. | **Requerida** |
| **Sensor Ultrasónico HC-SR04** | `tehniq-com/NewPing` | Para una medición de distancia no bloqueante y con filtrado de errores. | **Recomendada** |
| **Servo SG90** | `<Servo.h>` | Para un control sencillo y preciso del ángulo del servo. | **Nativa (no se añade)** |
| **Driver de Motores L298N** | *Ninguna* | Se controla directamente con `digitalWrite` y `analogWrite` para máxima flexibilidad. | No aplica |

---

## 1. Librería para Encoders: `Encoder` by Paul Stoffregen

Esta es la librería más crítica para la funcionalidad principal del robot: la odometría.

-   **Propósito**: Contar con precisión los pulsos generados por los encoders de los motores para determinar la distancia que cada rueda ha recorrido.

-   **Beneficios Clave**:
    1.  **Fiabilidad**: Utiliza interrupciones de hardware (`interrupts`), lo que garantiza que no se pierda ninguna lectura de pulso, incluso si el microcontrolador está ocupado con otras tareas.
    2.  **Simplicidad**: Abstrae toda la complejidad. En lugar de manejar interrupciones manualmente, simplemente lees el valor del contador.
    3.  **Eficiencia**: Está altamente optimizada para consumir muy pocos recursos del microcontrolador.

-   **Ejemplo de Uso Simplificado**:
    ```cpp
    #include <Encoder.h>

    // Inicializa los encoders en los pines de interrupción 2 y 3.
    Encoder encoderIzquierdo(2, 4); // Señal A en Pin 2, Señal B en Pin 4
    Encoder encoderDerecho(3, 5);  // Señal A en Pin 3, Señal B en Pin 5

    void loop() {
      long posicionIzquierda = encoderIzquierdo.read();
      long posicionDerecha = encoderDerecho.read();

      Serial.print("Izquierda: ");
      Serial.print(posicionIzquierda);
      Serial.print(", Derecha: ");
      Serial.println(posicionDerecha);
      delay(100);
    }
    ```

---

## 2. Librería para Sensor Ultrasónico: `NewPing`

Mientras que el sensor HC-SR04 se puede usar sin librería, `NewPing` ofrece mejoras significativas para un robot autónomo.

-   **Propósito**: Medir distancias de forma eficiente y no bloqueante.

-   **Beneficios Clave**:
    1.  **No Bloqueante**: El principal beneficio. El código del robot no se detiene esperando la respuesta del sensor. Puede seguir moviéndose y procesando mientras la librería gestiona la medición en segundo plano.
    2.  **Precisión**: Incluye métodos para realizar mediciones con filtrado (como la mediana de varias lecturas) para eliminar picos de ruido y obtener un valor más estable y fiable.
    3.  **Fácil de Usar**: Simplifica la conversión de tiempo a distancia (cm, pulgadas).

-   **Ejemplo de Uso Simplificado**:
    ```cpp
    #include <NewPing.h>

    #define TRIGGER_PIN  12
    #define ECHO_PIN     11
    #define MAX_DISTANCE 200 // Distancia máxima a medir en cm

    NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

    void loop() {
      delay(50); // Esperar 50ms entre mediciones
      unsigned int distancia = sonar.ping_cm();
      Serial.print("Distancia: ");
      Serial.print(distancia);
      Serial.println("cm");
    }
    ```

---

## 3. Librerías Nativas (Incluidas en el Framework de Arduino)

Estas librerías son parte del ecosistema estándar de Arduino y PlatformIO las gestiona automáticamente.

### `<Servo.h>`

-   **Propósito**: Controlar el servo motor SG90 para el sistema de escaneo.

-   **Beneficios Clave**:
    1.  **Abstracción Total**: Te olvidas de la compleja señal PWM necesaria para posicionar el servo. Simplemente le dices a qué ángulo (0-180) quieres que se mueva.
    2.  **Estándar y Fiable**: Es la librería oficial y funciona perfectamente en segundo plano.

-   **Ejemplo de Uso Simplificado**:
    ```cpp
    #include <Servo.h>

    Servo escanerServo;

    void setup() {
      escanerServo.attach(9); // Conectar el servo al pin 9
    }

    void loop() {
      escanerServo.write(90); // Mover el servo a la posición central
    }
    ```