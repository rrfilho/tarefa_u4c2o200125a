#include "pico/stdlib.h"

#define ROWS 4
#define COLS 4

static const uint cols_pins[COLS] = {19, 18, 17, 16};
static const uint rows_pins[ROWS] = {26, 22, 21, 20};
static const char keypad_map[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

static void init_cols() {
  for (int i = 0; i < COLS; i++) {
    gpio_init(cols_pins[i]);
    gpio_set_dir(cols_pins[i], GPIO_OUT);
    gpio_put(cols_pins[i], 0);
  }
}

static void init_rows() {
  for (int i = 0; i < COLS; i++) {
    gpio_init(rows_pins[i]);
    gpio_set_dir(rows_pins[i], GPIO_IN);
    gpio_pull_down(rows_pins[i]);
  }
}

void keypad_init() {
  init_cols();
  init_rows();
}

char keypad_read() {
  for (int i = 0; i < COLS; i++) {
    gpio_put(cols_pins[i], 1);
    for(int j = 0; j < ROWS; j++) {
      if (!gpio_get(rows_pins[j])) continue;
      gpio_put(cols_pins[i], 0);
      return keypad_map[j][i];
    }
    gpio_put(cols_pins[i], 0);
  }
  return '\0';
}