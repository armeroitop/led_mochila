#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

const int led_rojo = 0; // Pin number for the LED
const int led_azul = 1; // Pin number for the LED

const int btn_rojo = 3; // Pin number for the button
const int btn_azul = 10; // Pin number for the button


bool ledRojoParpadeando = false; // Estado del LED rojo (parpadeando o apagado)
unsigned long tiempoAnterior = 0; // Para controlar el parpadeo
const unsigned long intervaloParpadeo = 500; // Intervalo de parpadeo en milisegundos


void setup() {
    // put your setup code here, to run once:
    int result = myFunction(2, 3);
    pinMode(led_rojo, OUTPUT);
    pinMode(led_azul, OUTPUT);

    pinMode(btn_rojo, INPUT);
    pinMode(btn_azul, INPUT);


}

void loop() {
    
     // Verificar si el botón rojo fue presionado
     if (digitalRead(btn_rojo) == LOW) { // Botón presionado (LOW debido a INPUT_PULLUP)
        delay(200); // Pequeño retraso para evitar rebotes
        ledRojoParpadeando = !ledRojoParpadeando; // Cambiar el estado
    }

    // Controlar el LED rojo según el estado
    if (ledRojoParpadeando) {
        parpadearLedRojo();
    } else {
        digitalWrite(led_rojo, LOW); // Apagar el LED
    }
}

// Controlar el botón rojo sin delay
void actualizarBotonRojo(){
    static unsigned long tiempoAnteriorBoton = 0; // Para controlar el debounce
    const unsigned long debounceDelay = 50; // Tiempo de debounce en milisegundos

    // Leer el estado del botón y verificar si ha cambiado
    if (digitalRead(btn_rojo) == LOW) { // Botón presionado
        if (millis() - tiempoAnteriorBoton >= debounceDelay) { // Evitar rebotes
            ledRojoParpadeando = !ledRojoParpadeando; // Cambiar el estado
            tiempoAnteriorBoton = millis(); // Actualizar el tiempo del último cambio
        }
    }
}


// Función para hacer que el LED rojo parpadee
void parpadearLedRojo() {
    unsigned long tiempoActual = millis(); // Obtener el tiempo actual
    if (tiempoActual - tiempoAnterior >= intervaloParpadeo) {
        tiempoAnterior = tiempoActual; // Actualizar el tiempo
        int estadoActual = digitalRead(led_rojo); // Leer el estado actual del LED
        digitalWrite(led_rojo, !estadoActual); // Cambiar el estado del LED
    }
}

// put function definitions here:
int myFunction(int x, int y) {
    return x + y;
}