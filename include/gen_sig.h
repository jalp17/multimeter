#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ONDA_CUADRADA,
    ONDA_SENOIDAL,
    ONDA_DIENTE_SIERRA
} TipoOnda;

void gen_sig_init(void);
void gen_sig_set_tipo(TipoOnda tipo);
void gen_sig_set_amplitud(float amplitud_v);      // en voltios
void gen_sig_set_frecuencia(float frecuencia_hz); // en Hz
void gen_sig_set_ancho_pulso(float duty_cycle);   // 0.0 a 1.0 (solo cuadrada)

TipoOnda gen_sig_get_tipo(void);
float gen_sig_get_amplitud(void);
float gen_sig_get_frecuencia(void);
float gen_sig_get_ancho_pulso(void);

void gen_sig_start(void);
void gen_sig_stop(void);

#ifdef __cplusplus
}
#endif