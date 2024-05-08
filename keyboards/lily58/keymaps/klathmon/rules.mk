BOOTLOADER          = atmel-dfu

BOOTMAGIC_ENABLE     = no  # Enable Bootmagic Lite
MOUSEKEY_ENABLE      = yes # Mouse keys
EXTRAKEY_ENABLE      = yes # Audio control and System control
CONSOLE_ENABLE       = no  # Console for debug
COMMAND_ENABLE       = no  # Commands for debug and configuration
NKRO_ENABLE          = yes # Enable N-Key Rollover
BACKLIGHT_ENABLE     = no  # Enable keyboard backlight functionality
AUDIO_ENABLE         = no  # Audio output
RGBLIGHT_ENABLE      = no  # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE    = no  # Enable one-hand typing
ENCODER_ENABLE       = yes # Enable rotary encoder
OLED_ENABLE          = yes # OLED display
KEY_OVERRIDE_ENABLE  = yes # Enable key override
LTO_ENABLE           = yes # Enable LTO
OS_DETECTION_ENABLE  = yes # Enable OS detection for keymap
DYNAMIC_MACRO_ENABLE = yes # Enable Dynamic Macros

# save some space
SPACE_CADET_ENABLE     = no
GRAVE_ESC_ENABLE       = no
AVR_USE_MINIMAL_PRINTF = yes

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
