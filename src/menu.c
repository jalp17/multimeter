//Menu de seleccion de modos de medicion

typedef enum {
    MODO_VOLTAGE,
    MODO_CURRENT,
    MODO_RESISTANCE
} ModoMedicion;

ModoMedicion modo_actual = MODO_VOLTAGE;

void cambiarModo() {
    modo_actual = (modo_actual + 1) % 3;  // Cambia entre los modos cíclicamente
}