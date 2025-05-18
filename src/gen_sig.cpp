#include "gen_sig.h"
#include "driver/rmt_tx.h"
#include "driver/gpio.h"
#include <math.h>

static const gpio_num_t GEN_SIG_GPIO = GPIO_NUM_18;
 
static TipoOnda tipo_actual = ONDA_CUADRADA;
static float amplitud_actual = 3.3f;
static float frecuencia_actual = 1000.0f;
static float duty_actual = 0.5f;

static rmt_channel_handle_t rmt_chan = NULL;

void gen_sig_init(void) {
    rmt_tx_channel_config_t tx_chan_config;
    tx_chan_config.gpio_num = GEN_SIG_GPIO;
    tx_chan_config.clk_src = RMT_CLK_SRC_DEFAULT;
    tx_chan_config.resolution_hz = 1000000; // 1 MHz
    tx_chan_config.mem_block_symbols = 64;
    tx_chan_config.trans_queue_depth = 2;
    tx_chan_config.intr_priority = 1;
    tx_chan_config.flags.invert_out = 0;
    tx_chan_config.flags.with_dma = 0;
    tx_chan_config.flags.io_loop_back = 0;
    tx_chan_config.flags.io_od_mode = 0;
    tx_chan_config.flags.allow_pd = 0;

    rmt_new_tx_channel(&tx_chan_config, &rmt_chan);
    rmt_enable(rmt_chan);
}

void gen_sig_set_tipo(TipoOnda tipo) {
    tipo_actual = tipo;
}

void gen_sig_set_amplitud(float amplitud_v) {
    amplitud_actual = amplitud_v;
}

void gen_sig_set_frecuencia(float frecuencia_hz) {
    frecuencia_actual = frecuencia_hz;
}

void gen_sig_set_ancho_pulso(float duty_cycle) {
    if (duty_cycle < 0.0f) duty_cycle = 0.0f;
    if (duty_cycle > 1.0f) duty_cycle = 1.0f;
    duty_actual = duty_cycle;
}

TipoOnda gen_sig_get_tipo(void) { return tipo_actual; }
float gen_sig_get_amplitud(void) { return amplitud_actual; }
float gen_sig_get_frecuencia(void) { return frecuencia_actual; }
float gen_sig_get_ancho_pulso(void) { return duty_actual; }

void gen_sig_start(void) {
    // Ejemplo: solo onda cuadrada usando RMT
    if (tipo_actual == ONDA_CUADRADA) {
        uint32_t periodo_us = (uint32_t)(1e6f / frecuencia_actual);
        uint32_t high_us = (uint32_t)(periodo_us * duty_actual);
        uint32_t low_us = periodo_us - high_us;

        rmt_symbol_word_t symbols[2];
        symbols[0].level0 = 1;
        symbols[0].duration0 = high_us;
        symbols[0].level1 = 0;
        symbols[0].duration1 = low_us;

        rmt_transmit_config_t tx_config;
        tx_config.loop_count = 0; // 0 = infinito
        tx_config.flags.eot_level = 0;
        tx_config.flags.queue_nonblocking = 0;

        rmt_transmit(rmt_chan, NULL, symbols, 2, &tx_config);
    }
    // Para onda senoidal y diente de sierra, deberás generar un buffer PWM o usar un DAC externo.
}

void gen_sig_stop(void) {
    if (rmt_chan) {
        rmt_disable(rmt_chan);
    }
}
