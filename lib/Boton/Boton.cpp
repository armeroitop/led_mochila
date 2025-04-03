
#include <Boton.hpp>

Boton::Boton(int pin) : pin(pin), estado(false), presionadoLargo(false), presionadoCorto(false), tiempoPresionado(0), tiempoAnterior(0) {
    pinMode(pin, INPUT);
}
void Boton::iniciar() {
    estado = digitalRead(pin);
    reiniciar();
}
bool Boton::isPresionado() {
    return estado;
}
bool Boton::isPresionadoLargo() {
    return presionadoLargo;
}
bool Boton::isPresionadoCorto() {
    return presionadoCorto;
}
void Boton::reiniciar() {
    presionadoLargo = false;
    presionadoCorto = false;
    tiempoPresionado = 0;
}
void Boton::actualizar() {
    unsigned long tiempoActual = millis();
    estado = digitalRead(pin);
    
    if (estado == HIGH) {
        if (tiempoPresionado == 0) {
            tiempoPresionado = tiempoActual;
        }
        if (tiempoActual - tiempoPresionado >= tiempoLimite) {
            presionadoLargo = true;
        }
    } else {
        if (tiempoPresionado > 0) {
            if (tiempoActual - tiempoPresionado < tiempoLimite) {
                presionadoCorto = true;
            }
            reiniciar();
        }
    }
}