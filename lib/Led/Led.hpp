#pragma once
#include <Arduino.h>

struct Led {

    int pin;
    bool parpadeando;
    bool encendido;
    unsigned long tiempoAnterior;
    const unsigned long intervaloParpadeo = 500; // Intervalo de parpadeo en milisegundos


    Led(int pin);
    void parpadear();
    void apagar();
    void encender();
    bool isParpadeando() const;
    bool isEncendido() const;
    
};
