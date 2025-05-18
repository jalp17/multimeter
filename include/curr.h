#pragma once

#ifdef __cplusplus
extern "C" {
#endif
typedef enum {
    ESCALA_NANO_A,
    ESCALA_MICRO_A,
    ESCALA_MILI_A,
    ESCALA_UNIDAD_A,
    ESCALA_KILO_A
} EscalaCorriente;

void set_escala_corriente(EscalaCorriente escala);
EscalaCorriente get_escala_corriente(void);

float medir_corriente(void);
const char* obtener_nombre_escala_corriente(EscalaCorriente escala);

#ifdef __cplusplus
}
#endif