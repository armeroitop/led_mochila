#pragma once

#include <Arduino.h>

struct Boton {
    int pin;
    bool estado;
    bool presionadoLargo;
    bool presionadoCorto;
    unsigned long tiempoPresionado;
    unsigned long tiempoAnterior;
    const unsigned long tiempoLimite = 1000; // Tiempo en milisegundos para considerar un botón como presionado largo


    Boton(int pin);
    void iniciar();
    bool isPresionado();
    bool isPresionadoLargo();
    bool isPresionadoCorto();
    void reiniciar();
    void actualizar();
    void setEstado(bool estado);
    bool getEstado() const;

};