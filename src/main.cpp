#include <Arduino.h>


void parpadearLedRojo();
void actualizarBotonRojo(); // Declaración de la función para el botón rojo
void parpadearLedAzul();
void actualizarBotonAzul(); // Declaración de la función para el botón azul

const int led_rojo = 0; // Pin number for the LED
const int led_azul = 1; // Pin number for the LED

const int btn_rojo = 3; // Pin number for the button
const int btn_azul = 10; // Pin number for the button


bool ledRojoParpadeando = false; // Estado del LED rojo (parpadeando o apagado)
bool ledAzulParpadeando = false; // Estado del LED azul (encendido o apagado)
unsigned long tiempoAnteriorLedRojo = 0; 
unsigned long tiempoAnteriorLedAzul = 0; 
const unsigned long intervaloParpadeo = 500; // Intervalo de parpadeo en milisegundos


void setup() {
    
    pinMode(led_rojo, OUTPUT);
    pinMode(led_azul, OUTPUT);

    //digitalWrite(led_rojo, HIGH);
    //digitalWrite(led_azul, HIGH);


    pinMode(btn_rojo, INPUT);
    pinMode(btn_azul, INPUT);
}

void loop() {

    // Verificar si el botón rojo fue presionado
    actualizarBotonRojo();
    // Verificar si el botón azul fue presionado
    actualizarBotonAzul();

    // Controlar el LED rojo según el estado
    if (ledRojoParpadeando) {
        parpadearLedRojo();
    } else {
        digitalWrite(led_rojo, LOW); // Apagar el LED
    }

    // Controlar el LED azul según el estado
    if (ledAzulParpadeando) {
        parpadearLedAzul();
    } else {
        digitalWrite(led_azul, LOW); // Apagar el LED
    }
    
}

void actualizarBotonRojo() {
    static unsigned long tiempoAnteriorBotonRojo = 0; // Para controlar el debounce
    const unsigned long debounceDelay = 100; // Tiempo de debounce en milisegundos

    // Leer el estado del botón y verificar si ha cambiado
    if (digitalRead(btn_rojo) == HIGH) { // Botón presionado
        if (millis() - tiempoAnteriorBotonRojo >= debounceDelay) { // Evitar rebotes
            ledRojoParpadeando = !ledRojoParpadeando; // Cambiar el estado
            tiempoAnteriorBotonRojo = millis(); // Actualizar el tiempo del último cambio
        }
    }
}

void actualizarBotonAzul() {
    static unsigned long tiempoAnteriorBotonAzul = 0; // Para controlar el debounce
    const unsigned long debounceDelay = 100; // Tiempo de debounce en milisegundos

    // Leer el estado del botón y verificar si ha cambiado
    if (digitalRead(btn_azul) == HIGH) { // Botón presionado
        if (millis() - tiempoAnteriorBotonAzul >= debounceDelay) { // Evitar rebotes
           ledAzulParpadeando = !ledAzulParpadeando; // Cambiar el estado
           tiempoAnteriorBotonAzul = millis(); // Actualizar el tiempo del último cambio
        }
    } 
}

// Función para hacer que el LED rojo parpadee
void parpadearLedRojo() {
    unsigned long tiempoActual = millis(); // Obtener el tiempo actual
    if (tiempoActual - tiempoAnteriorLedRojo >= intervaloParpadeo) {
        tiempoAnteriorLedRojo = tiempoActual; // Actualizar el tiempo
        int estadoActual = digitalRead(led_rojo); // Leer el estado actual del LED
        digitalWrite(led_rojo, !estadoActual); // Cambiar el estado del LED
    }
}

void parpadearLedAzul() {
    unsigned long tiempoActual = millis(); // Obtener el tiempo actual
    if (tiempoActual - tiempoAnteriorLedAzul >= intervaloParpadeo) {
        tiempoAnteriorLedAzul = tiempoActual; // Actualizar el tiempo
        int estadoActual = digitalRead(led_azul); // Leer el estado actual del LED
        digitalWrite(led_azul, !estadoActual); // Cambiar el estado del LED
    }
}

