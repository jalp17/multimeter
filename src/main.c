#include <menu.c>

void app_main() {
    while (1) {
        float valor;
        switch (modo_actual) {
            case MODO_VOLTAGE:
                valor = medirVoltaje();
                actualizarPantalla(valor, "Voltaje");
                break;
            case MODO_CURRENT:
                valor = medirAmperaje();
                actualizarPantalla(valor, "Corriente");
                break;
            case MODO_RESISTANCE:
                valor = medirResistencia();
                actualizarPantalla(valor, "Resistencia");
                break;
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}