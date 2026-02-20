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
  
  while (true) {
    if (!gpio_get(btn_verde)) {
      gpio_put(led_verde, 1);
    } else {
      gpio_put(led_verde, 0);
    }

    if (!gpio_get(btn_vermelho)) {
      gpio_put(led_vermelho, 1);
    } else {
      gpio_put(led_vermelho, 0);
    }
    
    sleep_ms(10); 
  }
}

