#pragma once

#include "../lib/ssd1306/ssd1306.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    MODO_VOLTAGE,
    MODO_CURRENT,
    MODO_RESISTANCE,
    MODO_CAPACIDAD,
    MODO_INDUCTANCIA,
    MODO_GEN_SIG,
    MODO_OSCIL,
    MODO_TOTAL
} ModoMedicion;

extern ModoMedicion modo_actual;

void menu_init(SSD1306_t* display);
void menu_mostrar();
void menu_navegar(int direccion); // -1: arriba, 1: abajo
void menu_seleccionar();
void menu_cambiar_escala(int direccion); // -1: abajo, 1: arriba

#ifdef __cplusplus
}
#endif
