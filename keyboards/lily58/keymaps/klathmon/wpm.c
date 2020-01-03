#include <stdio.h>
#include "lily58.h"

char wpm_string[24] = {};
int time_combo_started = 0;
int number_keys_this_combo = 0;
int time_previous_key_pressed = 0;

void set_wpm(void) {
  if (timer_elapsed(time_previous_key_pressed) >= 2000) {
    time_combo_started = timer_read();
    number_keys_this_combo = 1;
  } else {
    number_keys_this_combo++;
  }
  time_previous_key_pressed = timer_read();
}

const char *read_wpm_string(void) {
  float words = (number_keys_this_combo / 5);
  float time = (time_previous_key_pressed - time_combo_started);
  int wpm = round(words / (time / 1000 / 60));
  snprintf(wpm_string, sizeof(wpm_string), "WPM: %5d", wpm);
  return wpm_string;
}
