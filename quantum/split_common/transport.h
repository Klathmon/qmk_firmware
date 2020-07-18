#pragma once

#include <common/matrix.h>

#ifdef SERIAL_SCREEN_BUFFER_LENGTH
uint8_t volatile hid_status;
uint8_t volatile serial_slave_screen_buffer[SERIAL_SCREEN_BUFFER_LENGTH];
bool volatile hid_screen_change;
#endif

void transport_master_init(void);
void transport_slave_init(void);

// returns false if valid data not received from slave
bool transport_master(matrix_row_t matrix[]);
void transport_slave(matrix_row_t matrix[]);
