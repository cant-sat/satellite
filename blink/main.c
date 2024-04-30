#include "boards/pico.h"
#include "pico/stdlib.h"

#define POWEROFF_PIN 15

int main() {
  gpio_init(PICO_DEFAULT_LED_PIN);
  gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

  gpio_init(POWEROFF_PIN);
  gpio_set_dir(POWEROFF_PIN, GPIO_OUT);

  gpio_put(POWEROFF_PIN, false);

  for (int i = 0; i < 5; i++) {
    gpio_put(PICO_DEFAULT_LED_PIN, 1);
    sleep_ms(100);
    gpio_put(PICO_DEFAULT_LED_PIN, 0);
    sleep_ms(100);
  }

  gpio_put(POWEROFF_PIN, true);
}