#include "res.h"
#include <stdio.h>

static EscalaResistencia escala_actual = ESCALA_UNIDAD_OHM;

void set_escala_resistencia(EscalaResistencia escala) {
    escala_actual = escala;
}

EscalaResistencia get_escala_resistencia(void) {
    return escala_actual;
}

float medir_resistencia(void) {
    float resistencia_base = 1200.0f; // Simulación
    switch (escala_actual) {
        case ESCALA_MILI_OHM:   return resistencia_base * 1e-3f;
        case ESCALA_UNIDAD_OHM: return resistencia_base;
        case ESCALA_KILO_OHM:   return resistencia_base / 1e3f;
        case ESCALA_MEGA_OHM:   return resistencia_base / 1e6f;
        default:                return resistencia_base;
    }
}

const char* obtener_nombre_escala_resistencia(EscalaResistencia escala) {
    switch (escala) {
        case ESCALA_MILI_OHM:   return "mΩ";
        case ESCALA_UNIDAD_OHM: return "Ω";
        case ESCALA_KILO_OHM:   return "kΩ";
        case ESCALA_MEGA_OHM:   return "MΩ";
        default:                return "";
    }
}