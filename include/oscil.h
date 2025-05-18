#pragma once

#include <stdint.h>
#include <stddef.h>

#define OSCIL_NUM_CANALES 2
#define OSCIL_NUM_MUESTRAS 256

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float amplitud;
    float frecuencia;
    float rms;
    float periodo;
} OscilDatos;

void oscil_init(void);
void oscil_muestrear(float muestras[OSCIL_NUM_CANALES][OSCIL_NUM_MUESTRAS]);
void oscil_procesar(const float muestras[OSCIL_NUM_CANALES][OSCIL_NUM_MUESTRAS], OscilDatos datos[OSCIL_NUM_CANALES]);
void oscil_graficar_oled(const float muestras[OSCIL_NUM_CANALES][OSCIL_NUM_MUESTRAS]);

#ifdef __cplusplus
}
#endif