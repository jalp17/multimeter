#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "esp_log.h"

#define I2C_MASTER_SCL_IO 22    // SCL pin
#define I2C_MASTER_SDA_IO 21    // SDA pin
#define I2C_MASTER_NUM I2C_NUM_0
#define I2C_MASTER_FREQ_HZ 400000
#define I2C_MASTER_TX_BUF_DISABLE 0
#define I2C_MASTER_RX_BUF_DISABLE 0

static const char *TAG = "i2c_scanner";

void i2c_master_init() {
    i2c_config_t conf = {};
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_MASTER_SDA_IO;
    conf.scl_io_num = I2C_MASTER_SCL_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
    esp_err_t err = i2c_param_config(I2C_MASTER_NUM, &conf);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "i2c_param_config failed: %s", esp_err_to_name(err));
    }
    err = i2c_driver_install(I2C_MASTER_NUM, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "i2c_driver_install failed: %s", esp_err_to_name(err));
    }
}

void i2c_scan_task(void *arg) {
    uint8_t address;
    esp_err_t err;
    int found_devices = 0;

    ESP_LOGI(TAG, "Starting I2C bus scan...");

    for (address = 1; address < 127; address++) {
        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, (address << 1) | I2C_MASTER_WRITE, true);
        i2c_master_stop(cmd);
        err = i2c_master_cmd_begin(I2C_MASTER_NUM, cmd, 1000 / portTICK_PERIOD_MS);
        i2c_cmd_link_delete(cmd);

        if (err == ESP_OK) {
            ESP_LOGI(TAG, "Found device at 0x%02X", address);
            found_devices++;
        } else if (err == ESP_FAIL) {
            // No device at this address
        } else {
            ESP_LOGE(TAG, "Bus error at address 0x%02X: %s", address, esp_err_to_name(err));
        }
    }

    if (found_devices == 0) {
        ESP_LOGW(TAG, "No I2C devices found");
    } else {
        ESP_LOGI(TAG, "I2C scan complete, %d device(s) found", found_devices);
    }

    vTaskDelete(NULL);
}

extern "C" void app_main() {
    i2c_master_init();
    xTaskCreate(i2c_scan_task, "i2c_scan_task", 2048, NULL, 10, NULL);
}
