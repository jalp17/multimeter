#include "volt.h"

static EscalaVoltaje escala_actual = ESCALA_UNIDAD;

void set_escala_voltaje(EscalaVoltaje escala) {
    escala_actual = escala;
}

EscalaVoltaje get_escala_voltaje(void) {
    return escala_actual;
}

float medir_voltaje(void) {
    float voltaje_base = 0.0023f; // Simulación
    switch (escala_actual) {
        case ESCALA_NANO:   return voltaje_base * 1e9f;
        case ESCALA_MICRO:  return voltaje_base * 1e6f;
        case ESCALA_MILI:   return voltaje_base * 1e3f;
        case ESCALA_UNIDAD: return voltaje_base;
        case ESCALA_KILO:   return voltaje_base / 1e3f;
        default:            return voltaje_base;
    }
}

const char* obtener_nombre_escala(EscalaVoltaje escala) {
    switch (escala) {
        case ESCALA_NANO:   return "nV";
        case ESCALA_MICRO:  return "uV";
        case ESCALA_MILI:   return "mV";
        case ESCALA_UNIDAD: return "V";
        case ESCALA_KILO:   return "kV";
        default:            return "";
    }
}