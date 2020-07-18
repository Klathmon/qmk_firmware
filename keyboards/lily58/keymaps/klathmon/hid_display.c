#include <stdio.h>
#include "lily58.h"

// Add headers for raw hid communication
#include "split_common/transport.h"
#include "raw_hid.h"

// HID input
bool    hid_connected                                       = false;  // Flag indicating if we have a PC connection yet
uint8_t screen_max_count                                    = 0;      // Number of info screens we can scroll through (set by connecting node script)
uint8_t screen_show_index                                   = 0;      // Current index of the info screen we are displaying
uint8_t screen_data_buffer[SERIAL_SCREEN_BUFFER_LENGTH - 1] = {0};    // Buffer used to store the screen data sent by connected node script
int     screen_data_index                                   = 0;      // Current index into the screen_data_buffer that we should write to
char    hid_status_str[21]                                  = {};

const char *read_logo(void);

bool is_hid_connected(void) { return hid_connected; }

const char *get_hid_status_display_string(void) {
    if (hid_connected) {
        snprintf(hid_status_str, sizeof(hid_status_str), "HID Screen: %d", screen_show_index + 1);
    } else {
        snprintf(hid_status_str, sizeof(hid_status_str), "HID Disconnected");
    }
    return hid_status_str;
}

void raw_hid_send_screen_index(void) {
    if (hid_connected) {
        // Send the current info screen index to the connected node script so that it can pass back the new data
        uint8_t send_data[32] = {0};
        send_data[0]          = screen_show_index + 1;  // Add one so that we can distinguish it from a null byte
        raw_hid_send(send_data, sizeof(send_data));
    }
}

void increase_screen_num(void) {
    screen_show_index++;
    if (screen_show_index >= screen_max_count) {
        screen_show_index = 0;
    }
    raw_hid_send_screen_index();
}

void decrease_screen_num(void) {
    if (screen_show_index == 0) {
        screen_show_index = screen_max_count - 1;
    } else {
        screen_show_index--;
    }
    raw_hid_send_screen_index();
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
  // PC connected, so set the flag to show a message on the master display
  hid_connected = true;

  // Initial connections use '1' in the first byte to indicate this
  if (length > 1 && data[0] == 1) {
    // New connection so restart screen_data_buffer
    screen_data_index = 0;

    // The second byte is the number of info screens the connected node script allows us to scroll through
    screen_max_count = data[1];
    if (screen_show_index >= screen_max_count) {
      screen_show_index = 0;
    }

      // Tell the connection which info screen we want to look at initially
      raw_hid_send_screen_index();
      return;
  }

  // Otherwise the data we receive is one line of the screen to show on the display
  if (length >= 21) {
    // Copy the data into our buffer and increment the number of lines we have got so far
    memcpy((char *)&screen_data_buffer[screen_data_index * 21], data, 21);
    screen_data_index++;

    // Once we reach 4 lines, we have a full screen
    if (screen_data_index == 4) {
      // Reset the buffer back to receive the next full screen data
      screen_data_index = 0;

      // Now get ready to transfer the whole 4 lines to the slave side of the keyboard.
      // First clear the transfer buffer with spaces just in case.
      memset((char *)&serial_slave_screen_buffer[0], ' ', sizeof(serial_slave_screen_buffer));

      // Copy in the 4 lines of screen data, but start at index 1, we use index 0 to indicate a connection in the slave code
      memcpy((char *)&serial_slave_screen_buffer[1], screen_data_buffer, sizeof(screen_data_buffer));
      // Set index 0 to indicate a connection has been established
      serial_slave_screen_buffer[0] = 1;

      // Make sure to zero terminate the buffer
      serial_slave_screen_buffer[sizeof(serial_slave_screen_buffer) - 1] = 0;

      // Indicate that the screen data has changed and needs transferring to the slave side
      hid_screen_change = true;
    }
  }
}
