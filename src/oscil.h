#pragma once

#include <cstddef>

#define OSCIL_NUM_MUESTRAS 256
#define OSCIL_NUM_CANALES 2

#ifdef __cplusplus
extern "C" {
#endif

struct OscilDatos {
    float amplitud;
    float frecuencia;
    float rms;
    float periodo;
};

void oscil_init();
void oscil_muestrear(float muestras[OSCIL_NUM_CANALES][OSCIL_NUM_MUESTRAS]);
void oscil_procesar(const float muestras[OSCIL_NUM_CANALES][OSCIL_NUM_MUESTRAS], OscilDatos datos[OSCIL_NUM_CANALES]);
void oscil_graficar_oled(const float muestras[OSCIL_NUM_CANALES][OSCIL_NUM_MUESTRAS]);

#ifdef __cplusplus
}
#endif