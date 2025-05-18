#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ESCALA_NANO_H,
    ESCALA_MICRO_H,
    ESCALA_MILI_H,
    ESCALA_UNIDAD_H
} EscalaInductancia;

void set_escala_inductancia(EscalaInductancia escala);
EscalaInductancia get_escala_inductancia(void);

float medir_inductancia(void);
const char* obtener_nombre_escala_inductancia(EscalaInductancia escala);

#ifdef __cplusplus
}
#endif