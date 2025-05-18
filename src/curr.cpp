#include "curr.h"

static EscalaCorriente escala_actual = ESCALA_UNIDAD_A;

void set_escala_corriente(EscalaCorriente escala) {
    escala_actual = escala;
}

EscalaCorriente get_escala_corriente(void) {
    return escala_actual;
}

float medir_corriente(void) {
    float corriente_base = 0.00056f; // Simulación
    switch (escala_actual) {
        case ESCALA_NANO_A:   return corriente_base * 1e9f;
        case ESCALA_MICRO_A:  return corriente_base * 1e6f;
        case ESCALA_MILI_A:   return corriente_base * 1e3f;
        case ESCALA_UNIDAD_A: return corriente_base;
        case ESCALA_KILO_A:   return corriente_base / 1e3f;
        default:              return corriente_base;
    }
}

const char* obtener_nombre_escala_corriente(EscalaCorriente escala) {
    switch (escala) {
        case ESCALA_NANO_A:   return "nA";
        case ESCALA_MICRO_A:  return "uA";
        case ESCALA_MILI_A:   return "mA";
        case ESCALA_UNIDAD_A: return "A";
        case ESCALA_KILO_A:   return "kA";
        default:              return "";
    }
}