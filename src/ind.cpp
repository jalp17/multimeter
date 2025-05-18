#include "ind.h"
#include <stdio.h>

static EscalaInductancia escala_actual = ESCALA_UNIDAD_H;

void set_escala_inductancia(EscalaInductancia escala) {
    escala_actual = escala;
}

EscalaInductancia get_escala_inductancia(void) {
    return escala_actual;
}

float medir_inductancia(void) {
    float inductancia_base = 0.0034f; // Simulación en Henrios
    switch (escala_actual) {
        case ESCALA_NANO_H:   return inductancia_base * 1e9f;
        case ESCALA_MICRO_H:  return inductancia_base * 1e6f;
        case ESCALA_MILI_H:   return inductancia_base * 1e3f;
        case ESCALA_UNIDAD_H: return inductancia_base;
        default:              return inductancia_base;
    }
}

const char* obtener_nombre_escala_inductancia(EscalaInductancia escala) {
    switch (escala) {
        case ESCALA_NANO_H:   return "nH";
        case ESCALA_MICRO_H:  return "uH";
        case ESCALA_MILI_H:   return "mH";
        case ESCALA_UNIDAD_H: return "H";
        default:              return "";
    }
}