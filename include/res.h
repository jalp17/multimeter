#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ESCALA_MILI_OHM,
    ESCALA_UNIDAD_OHM,
    ESCALA_KILO_OHM,
    ESCALA_MEGA_OHM
} EscalaResistencia;

void set_escala_resistencia(EscalaResistencia escala);
EscalaResistencia get_escala_resistencia(void);

float medir_resistencia(void);
const char* obtener_nombre_escala_resistencia(EscalaResistencia escala);

#ifdef __cplusplus
}
#endif