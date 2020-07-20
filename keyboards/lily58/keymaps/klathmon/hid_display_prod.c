#include <stdio.h>
#include "lily58.h"

// Add headers for raw hid communication
#include "split_common/transport.h"
#include "raw_hid.h"

#define HIDD_OLED_COLS 21
#define HIDD_OLED_ROWS 4
#define SERIAL_SCREEN_BUFFER_LENGTH (HIDD_OLED_COLS * HIDD_OLED_ROWS)

uint8_t volatile hidd_status;
uint8_t volatile hidd_serial_buffer[SERIAL_SCREEN_BUFFER_LENGTH];
bool    volatile hid_screen_change_flag;
bool             hidd_connected                                       = false;  // Flag indicating if we have a PC connection yet
int              screen_row_index                                    = 0;      // Current index into the screen_data_buffer that we should write to

bool is_hidd_connected (void) {
    if (!is_keyboard_master()) {
        return hidd_connected;
    } else {
        return (bool *)&hidd_serial_buffer[0]
    }
}

const char *read_slave_screen () {
    if (hidd_serial_buffer[0] > 0) {
        // If the first byte of the buffer is non-zero we should have a full set of data to show,
        // So we return everything after that first byte to be read into the display
        return hidd_serial_buffer + 1;
    }
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    // PC connected
    hidd_connected = true;

    // Initial connections use '1' in the first byte to indicate this
    if (length > 1 && data[0] == 1) {
      // New connection so restart the buffer
      screen_row_index = 0;
  } else if (length >= 21) {
      if (screen_row_index == 0) {
          // Reset the buffer back to receive the next full screen data
          hidd_serial_buffer[0] = 0;
          memset((char *)&hidd_serial_buffer[1], ' ', sizeof(hidd_serial_buffer));
      }

      // Otherwise the data we receive is one line of the screen to show on the display
      // Copy the data into our buffer and increment the number of lines we have got so far
      memcpy((char *)&hidd_serial_buffer[screen_row_index * HIDD_OLED_COLS + 1], data, HIDD_OLED_COLS);

      if (screen_data_index == HIDD_OLED_ROWS - 1) {
          // Once we reach 4 lines, we have a full screen


          // Set index 0 to indicate a connection has been established
          hidd_serial_buffer[0] = 1;

          // Make sure to zero terminate the buffer
          serial_slave_screen_buffer[sizeof(serial_slave_screen_buffer) - 1] = 0;

          // Indicate that the screen data has changed and needs transferring to the slave side
          hid_screen_change_flag = true;
      }

      // Increment the row index last thing
      screen_row_index++;
}
