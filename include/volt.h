#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ESCALA_NANO,
    ESCALA_MICRO,
    ESCALA_MILI,
    ESCALA_UNIDAD,
    ESCALA_KILO
} EscalaVoltaje;

void set_escala_voltaje(EscalaVoltaje escala);
EscalaVoltaje get_escala_voltaje(void);

float medir_voltaje(void);
const char* obtener_nombre_escala(EscalaVoltaje escala);

#ifdef __cplusplus
}
#endif