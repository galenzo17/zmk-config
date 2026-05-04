# Corne Keyboard - Instrucciones para el agente

## Arquitectura critica: QMK vs este repo

**Los archivos que QMK compila NO estan en este repo.**

- QMK compila desde: `~/qmk_firmware/keyboards/crkbd/keymaps/agus/`
- Este repo (`qmk/`) es una copia de respaldo

Cualquier cambio al firmware debe hacerse en AMBOS lugares:
1. Primero en `~/qmk_firmware/keyboards/crkbd/keymaps/agus/` (lo que realmente compila)
2. Luego sincronizar a `qmk/` de este repo (para backup/git)

## Compilar y flashear

```bash
# Compilar
cd ~/qmk_firmware
qmk compile -kb crkbd/rev1 -km agus

# Flashear lado izquierdo (conectar USB al izquierdo, presionar reset)
qmk flash -kb crkbd/rev1 -km agus -bl avrdude-split-left

# Flashear lado derecho (conectar USB al derecho, presionar reset)
qmk flash -kb crkbd/rev1 -km agus -bl avrdude-split-right
```

Siempre flashear AMBOS lados despues de un cambio en el keymap.

## Archivos QMK

| Archivo | Que hace |
|---------|----------|
| `keymap.c` | Keymap con 4 layers (BASE, NAV, SYM, NUM) |
| `config.h` | Config split keyboard + RGB defaults (azul HUE 170) |
| `rules.mk` | Features: RGBLIGHT, OLED, SERIAL_DRIVER bitbang |

## Layout actual (thumbs)

```
|CTL|NUM|SPC|    |ENT|SYM|ALT|
     ^^^              ^^^
  hold=numeros    hold=nav(flechas)
```

- GUI/Win esta en la fila del medio izquierda (no en thumb)
- CTRL esta en thumb izquierdo interno

## Reset EEPROM (Bootmagic)

Si los LEDs no cambian de color despues de flashear:
1. Desconectar USB
2. Mantener tecla superior izquierda (Tab) presionada
3. Conectar USB manteniendo Tab
4. Soltar despues de 1 segundo

## Config ZMK (legacy)

El directorio `config/` contiene una config ZMK para nice_nano_v2 que NO se usa con los Pro Micro actuales. Se buildea via GitHub Actions pero no es el firmware activo.
