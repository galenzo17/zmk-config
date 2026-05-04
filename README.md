# Corne Rosa - Keyboard Config

Configuracion del teclado Corne (crkbd) de Agus. Primer build.

## Hardware

| Componente | Detalle |
|------------|---------|
| Teclado | Corne (crkbd) by foostan |
| Layout | Split 3x6 + 3 thumb keys (42 teclas) |
| Controladores | 2x Pro Micro (ATmega32U4) |
| Conexion entre mitades | Cable TRRS |
| Conexion a PC | USB (mitad izquierda = master) |
| Luces | RGB underglow (WS2812) |
| Switches | - |
| Keycaps | - |
| Case | Rosa |

## Software

| Item | Detalle |
|------|---------|
| Firmware | [QMK](https://qmk.fm/) |
| Keyboard target | `crkbd/rev1` |
| Keymap | `agus` |
| Build | Local con `qmk compile` |
| Flash | `qmk flash` / `avrdude` (AVR109 bootloader) |

## Estructura del repo

```
qmk/
  keymap.c     # Keymap principal (4 capas)
  config.h     # Configuracion RGB
  rules.mk     # Features habilitadas
```

## Compilar y flashear

```bash
# Compilar
qmk compile -kb crkbd/rev1 -km agus

# Flashear (doble-click reset en el Pro Micro, luego):
qmk flash -kb crkbd/rev1 -km agus
```

Repetir flash para cada mitad por separado.

## Notas

- El keymap QMK vive en `qmk/` y se copia a `~/qmk_firmware/keyboards/crkbd/keymaps/agus/` antes de compilar.
- El directorio `config/` contiene una config ZMK legacy (no se usa con Pro Micro).
