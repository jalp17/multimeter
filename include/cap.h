#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ESCALA_PICO_F,
    ESCALA_NANO_F,
    ESCALA_MICRO_F,
    ESCALA_MILI_F,
    ESCALA_UNIDAD_F
} EscalaCapacidad;

void set_escala_capacidad(EscalaCapacidad escala);
EscalaCapacidad get_escala_capacidad(void);

float medir_capacidad(void);
const char* obtener_nombre_escala_capacidad(EscalaCapacidad escala);

#ifdef __cplusplus
}
#endif