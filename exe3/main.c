#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int btn_verde = 26;
const int btn_vermelho = 28;
const int led_verde = 6;
const int led_vermelho = 4;

int main() {
  stdio_init_all();

  gpio_init(btn_verde);
  gpio_set_dir(btn_verde, GPIO_IN);
  gpio_pull_up(btn_verde);

  gpio_init(btn_vermelho);
  gpio_set_dir(btn_vermelho, GPIO_IN);
  gpio_pull_up(btn_vermelho);

  gpio_init(led_verde);
  gpio_set_dir(led_verde, GPIO_OUT);

  gpio_init(led_vermelho);
  gpio_set_dir(led_vermelho, GPIO_OUT);
  
  bool led_g_state = false;
  bool led_r_state = false;

  bool btn_g_prev = true;
  bool btn_r_prev = true;

  while (true) {
    bool btn_g_curr = gpio_get(btn_verde);
    bool btn_r_curr = gpio_get(btn_vermelho);

    if (btn_g_prev && !btn_g_curr) {
      led_g_state = !led_g_state;
      gpio_put(led_verde, led_g_state);
    }
    btn_g_prev = btn_g_curr;

    if (btn_r_prev && !btn_r_curr) {
      led_r_state = !led_r_state;           
      gpio_put(led_vermelho, led_r_state);  
    }
    btn_r_prev = btn_r_curr;
    
    sleep_ms(10);
  }
}

