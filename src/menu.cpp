#include "menu.h"
#include "volt.h"
#include "curr.h"
#include "res.h"
#include "cap.h"
#include "ind.h"
#include "gen_sig.h"
#include "oscil.h"
#include "../lib/ssd1306/ssd1306.h"

static SSD1306_t* oled = nullptr;
ModoMedicion modo_actual = MODO_VOLTAGE;
static int menu_index = 0;

const char* menu_items[MODO_TOTAL] = {
    "Voltimetro",
    "Amperimetro",
    "Resistencia",
    "Capacitancia",
    "Inductancia",
    "Gen. Senal",
    "Osciloscopio"
};

void menu_init(SSD1306_t* display) {
    oled = display;
    menu_index = 0;
    modo_actual = (ModoMedicion)menu_index;
}

void menu_mostrar() {
    if (!oled) return;
    ssd1306_clear_screen(oled, false);
    // Assuming the library has functions to set font, color, draw rectangle and string
    // These functions need to be implemented or replaced with appropriate calls
    // For now, this is a placeholder to indicate where drawing code should go

    // Example placeholder code (to be replaced with actual library calls):
    // ssd1306_set_font(oled, ArialMT_Plain_10);
    // for (int i = 0; i < MODO_TOTAL; ++i) {
    //     int y = 10 + i * 10;
    //     if (i == menu_index) {
    //         ssd1306_fill_rect(oled, 0, y - 2, 128, 12, true);
    //         ssd1306_draw_string(oled, 2, y, menu_items[i], false);
    //     } else {
    //         ssd1306_draw_string(oled, 2, y, menu_items[i], true);
    //     }
    // }
    // ssd1306_show_buffer(oled);

    // Since the exact functions are not defined in the header, this needs to be implemented accordingly
}

void menu_navegar(int direccion) {
    menu_index += direccion;
    if (menu_index < 0) menu_index = MODO_TOTAL - 1;
    if (menu_index >= MODO_TOTAL) menu_index = 0;
    modo_actual = (ModoMedicion)menu_index;
    menu_mostrar();
}

void menu_seleccionar() {
    modo_actual = (ModoMedicion)menu_index;
    // Aquí podrías mostrar una pantalla de configuración de escala, etc.
}

void menu_cambiar_escala(int direccion) {
    switch (modo_actual) {
        case MODO_VOLTAGE: {
            int escala_int = get_escala_voltaje() + direccion;
            if (escala_int < 0) escala_int = 0;
            if (escala_int > 1) escala_int = 1;
            EscalaVoltaje escala = (EscalaVoltaje)escala_int;
            set_escala_voltaje(escala);
            break;
        }
        case MODO_CURRENT: {
            int escala_int = get_escala_corriente() + direccion;
            if (escala_int < 0) escala_int = 0;
            if (escala_int > 1) escala_int = 1;
            EscalaCorriente escala = (EscalaCorriente)escala_int;
            set_escala_corriente(escala);
            break;
        }
        case MODO_RESISTANCE: {
            int escala = get_escala_resistencia() + direccion;
            if (escala < 0) escala = 0;
            if (escala > 2) escala = 2;
            set_escala_resistencia((EscalaResistencia)escala);
            break;
        }
        case MODO_CAPACIDAD: {
            int escala = get_escala_capacidad() + direccion;
            if (escala < 0) escala = 0;
            if (escala > 4) escala = 4;
            set_escala_capacidad((EscalaCapacidad)escala);
            break;
        }
        case MODO_INDUCTANCIA: {
            int escala = get_escala_inductancia() + direccion;
            if (escala < 0) escala = 0;
            if (escala > 3) escala = 3;
            set_escala_inductancia((EscalaInductancia)escala);
            break;
        }
        default:
            break;
    }
    menu_mostrar();
}
