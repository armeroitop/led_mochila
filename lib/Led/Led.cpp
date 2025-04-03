#include "Led.h"


Led::Led(int pin) : pin(pin), parpadeando(false), encendido(false), tiempoAnterior(0) {
    pinMode(pin, OUTPUT);
}

void Led::parpadear() {
    unsigned long tiempoActual = millis();
    if (tiempoActual - tiempoAnterior >= intervaloParpadeo) {
        digitalWrite(pin, !digitalRead(pin)); // Cambiar el estado del LED
        tiempoAnterior = tiempoActual;
    }
}

void Led::apagar() {
    digitalWrite(pin, LOW); // Apagar el LED
    parpadeando = false;
    encendido = false;
}

void Led::encender() {
    digitalWrite(pin, HIGH); // Encender el LED
    parpadeando = false;
    encendido = true;
}

bool Led::isParpadeando() const {
    return parpadeando;
}

bool Led::isEncendido() const {
    return encendido;
}
