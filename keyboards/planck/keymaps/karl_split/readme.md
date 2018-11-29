# Instruction

```
docker run -e keymap=karl -e subproject=rev4 -e keyboard=planck --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
dfu-programmer atmega32u4 erase --force
dfu-programmer atmega32u4 flash .build/planck_rev4_karl.hex
dfu-programmer atmega32u4 reset
```
