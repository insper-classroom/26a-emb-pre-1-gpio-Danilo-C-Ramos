#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);
    int cnt_1 = 0;
    int cnt_2 = 0;

    bool btn_1_prev = false;
    bool btn_2_prev = false;

    while (true) {
        bool btn_1_pressed = !gpio_get(BTN_PIN);

        if (btn_1_pressed && !btn_1_prev) {
            sleep_ms(500);
            printf("Botao 1: %d\n", cnt_1++);
        }
        btn_1_prev = btn_1_pressed;

        bool btn_2_pressed = !gpio_get(BTN_PIN_2);

        if (btn_2_pressed && !btn_2_prev) {
            sleep_ms(500);
            printf("Botao 2: %d\n", cnt_2++);
        }
        btn_2_prev = btn_2_pressed;
    }
}
