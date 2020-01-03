# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes        # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = yes        # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
RAW_ENABLE = yes            # Enable RAW HID communication to PC
ENCODER_ENABLE = yes        # Enable rotary encoder

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# Reduce size of firmware by optimizing at link time
Link_Time_Optimization = yes
EXTRAFLAGS += -flto

# If you want to change the display of OLED, you need to change here
SRC +=  \
				./lib/logo_reader.c \
				./qmk_hid_custom_font.c \
				./mac_mode.c \
				./layer_state_reader.c \
				./wpm.c \
				# ./lib/timelogger.c \
				# ./lib/rgb_state_reader.c \
				# ./lib/keylogger.c \
				# ./lib/glcdfont.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
