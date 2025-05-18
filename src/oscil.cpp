#include "oscil.h"
#include <math.h>
#include <stdio.h>
#include "driver/i2c.h"
#include "../lib/ssd1306/ssd1306.h"

// Instancia global del display SSD1306 (ajusta los pines según tu hardware)
SSD1306_t dev = {};

// Define I2C pins and port (adjust as needed)
#define OLED_I2C_SDA 21
#define OLED_I2C_SCL 22
#define I2C_PORT I2C_NUM_0
#define I2C_ADDRESS 0x3C

void oscil_init() {
    // Inicializa el display (ajusta los pines y puerto según tu hardware)
    ssd1306_init(&dev, 128, 64);
    i2c_master_init(&dev, OLED_I2C_SDA, OLED_I2C_SCL, -1);
    i2c_device_add(&dev, I2C_PORT, -1, I2C_ADDRESS);
    ssd1306_clear_screen(&dev, false);
    ssd1306_show_buffer(&dev);
}

void oscil_muestrear(float muestras[OSCIL_NUM_CANALES][OSCIL_NUM_MUESTRAS]) {
    // Simulación de muestreo (ajusta según tu hardware)
    for (size_t ch = 0; ch < OSCIL_NUM_CANALES; ++ch) {
        for (size_t i = 0; i < OSCIL_NUM_MUESTRAS; ++i) {
            muestras[ch][i] = 1.65f + 1.65f * sinf(2 * M_PI * i / OSCIL_NUM_MUESTRAS + ch * M_PI / 2);
        }
    }
}

void oscil_procesar(const float muestras[OSCIL_NUM_CANALES][OSCIL_NUM_MUESTRAS], OscilDatos datos[OSCIL_NUM_CANALES]) {
    // Procesamiento simple (puedes mejorar según tus necesidades)
    for (int ch = 0; ch < OSCIL_NUM_CANALES; ++ch) {
        float min = muestras[ch][0], max = muestras[ch][0], sum = 0.0f;
        for (int i = 0; i < OSCIL_NUM_MUESTRAS; ++i) {
            if (muestras[ch][i] < min) min = muestras[ch][i];
            if (muestras[ch][i] > max) max = muestras[ch][i];
            sum += muestras[ch][i] * muestras[ch][i];
        }
        datos[ch].amplitud = (max - min) / 2.0f;
        datos[ch].rms = sqrtf(sum / OSCIL_NUM_MUESTRAS);
        // Frecuencia y periodo: deberías implementar un algoritmo de cruce por cero o FFT si lo necesitas
        datos[ch].frecuencia = 0.0f;
        datos[ch].periodo = 0.0f;
    }
}

void oscil_graficar_oled(const float muestras[OSCIL_NUM_CANALES][OSCIL_NUM_MUESTRAS]) {
    ssd1306_clear_screen(&dev, false);

    for (int ch = 0; ch < OSCIL_NUM_CANALES; ++ch) {
        int len = (OSCIL_NUM_MUESTRAS < 128) ? OSCIL_NUM_MUESTRAS : 128;
        float min = 3.3f, max = 0.0f;
        for (int i = 0; i < len; ++i) {
            if (muestras[ch][i] < min) min = muestras[ch][i];
            if (muestras[ch][i] > max) max = muestras[ch][i];
        }
        float range = (max - min) > 0.01f ? (max - min) : 1.0f;
        for (int x = 0; x < len; ++x) {
            int y = (int)((muestras[ch][x] - min) / range * 31.0f);
            if (ch == 1) y += 32;
            _ssd1306_pixel(&dev, x, y, true);
        }
    }
    ssd1306_show_buffer(&dev);
}
