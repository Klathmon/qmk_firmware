Keyboard: Lily58  
Keys: Lily58 is 6×4+5keys column-staggered split keyboard.  
Layout: US layout most non-alphanumeric keys heavily customized
Flash instructions: Flash using dfu, will req the hvp user space to compile.

> make lily58:klathmon

Changes:

* easy switching between Windows and MacOS layouts
* a lot of custom macros which switch how they work to be consistent across both OSs
* rotary encoder added to master side, controls volume and the secondary screen
* the slave screen is used by [qmk-hid-display](https://github.com/Klathmon/qmk-hid-display)
* master screen is setup to show layer, mac/windows mode, HID display info, and words per minute typing speed
