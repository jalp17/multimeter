#include "cap.h"
#include <stdio.h>

static EscalaCapacidad escala_actual = ESCALA_UNIDAD_F;

void set_escala_capacidad(EscalaCapacidad escala) {
    escala_actual = escala;
}

EscalaCapacidad get_escala_capacidad(void) {
    return escala_actual;
}

float medir_capacidad(void) {
    float capacidad_base = 0.0000012f; // Simulación en Faradios
    switch (escala_actual) {
        case ESCALA_PICO_F:   return capacidad_base * 1e12f;
        case ESCALA_NANO_F:   return capacidad_base * 1e9f;
        case ESCALA_MICRO_F:  return capacidad_base * 1e6f;
        case ESCALA_MILI_F:   return capacidad_base * 1e3f;
        case ESCALA_UNIDAD_F: return capacidad_base;
        default:              return capacidad_base;
    }
}

const char* obtener_nombre_escala_capacidad(EscalaCapacidad escala) {
    switch (escala) {
        case ESCALA_PICO_F:   return "pF";
        case ESCALA_NANO_F:   return "nF";
        case ESCALA_MICRO_F:  return "uF";
        case ESCALA_MILI_F:   return "mF";
        case ESCALA_UNIDAD_F: return "F";
        default:              return "";
    }
}