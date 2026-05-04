# Corne Rosa - Keyboard Config

Configuracion del teclado Corne (crkbd) de Agus.

## Hardware

| Componente | Detalle |
|------------|---------|
| Teclado | Corne (crkbd) by foostan |
| Layout | Split 3x6 + 3 thumb keys (42 teclas) |
| Controladores | 2x Pro Micro (ATmega32U4) |
| Conexion entre mitades | Cable TRRS |
| Conexion a PC | USB (mitad izquierda = master) |
| Luces | RGB underglow (WS2812) - default azul |
| Display | 2x OLED SSD1306 |
| Case | Rosa |

## Firmware: QMK

| Item | Detalle |
|------|---------|
| Firmware | [QMK](https://qmk.fm/) |
| Keyboard target | `crkbd/rev1` |
| Keymap | `agus` |
| Build | Local con `qmk compile` |
| Flash | `qmk flash` con bootloader `avrdude` |

## Compilar y flashear

**Los archivos que QMK compila estan en `~/qmk_firmware/keyboards/crkbd/keymaps/agus/`.** El directorio `qmk/` de este repo es una copia de respaldo que debe mantenerse sincronizada.

```bash
# Compilar
qmk compile -kb crkbd/rev1 -km agus

# Flashear lado izquierdo (conectar USB, presionar reset en Pro Micro)
qmk flash -kb crkbd/rev1 -km agus -bl avrdude-split-left

# Flashear lado derecho
qmk flash -kb crkbd/rev1 -km agus -bl avrdude-split-right
```

## Layers

### Layer 0: Base (QWERTY)

```
┌───┬───┬───┬───┬───┬───┐    ┌───┬───┬───┬───┬───┬───┐
│Tab│ Q │ W │ E │ R │ T │    │ Y │ U │ I │ O │ P │Bsp│
├───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┤
│Win│ A │ S │ D │ F │ G │    │ H │ J │ K │ L │ ; │ ' │
├───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┤
│Sft│ Z │ X │ C │ V │ B │    │ N │ M │ , │ . │ / │Esc│
└───┴───┴─┬─┴─┬─┴─┬─┴─┬─┘    └─┬─┴─┬─┴─┬─┴─┬─┴───┴───┘
          │CTL│NUM│SPC│          │ENT│SYM│ALT│
          └───┴───┴───┘          └───┴───┴───┘
```

### Layer 1: NAV (mantener ENT)

Flechas Vim (HJKL), Home/End/PgUp/PgDn, home row mods.

```
┌───┬───┬───┬───┬───┬───┐    ┌───┬───┬───┬───┬───┬───┐
│   │   │   │   │   │   │    │   │   │   │   │   │Del│
├───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┤
│   │Win│Alt│Ctl│Sft│   │    │ ← │ ↓ │ ↑ │ → │   │   │
├───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┤
│   │   │   │   │   │   │    │Hom│PgD│PgU│End│   │   │
└───┴───┴─┬─┴─┬─┴─┬─┴─┬─┘    └─┬─┴─┬─┴─┬─┴─┬─┴───┴───┘
          │   │   │   │          │▓▓▓│   │   │
          └───┴───┴───┘          └───┴───┴───┘
```

### Layer 2: SYM (mantener SPC o SYM)

Simbolos: !@#$%^&*(), brackets, pipes, etc.

### Layer 3: NUM (mantener thumb izq medio)

Numeros, F-keys, media, RGB.

```
┌───┬───┬───┬───┬───┬───┐    ┌───┬───┬───┬───┬───┬───┐
│   │ 1 │ 2 │ 3 │ 4 │ 5 │    │ 6 │ 7 │ 8 │ 9 │ 0 │   │
├───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┤
│   │F1 │F2 │F3 │F4 │F5 │    │F6 │V- │V+ │Mut│HU+│HU-│
├───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┤
│   │F7 │F8 │F9 │F10│F11│    │F12│Prv│Ply│Nxt│EFX│BOT│
└───┴───┴─┬─┴─┬─┴─┬─┴─┬─┘    └─┬─┴─┬─┴─┬─┴─┬─┴───┴───┘
          │TOG│   │BR+│          │   │BR-│   │
          └───┴───┴───┘          └───┴───┴───┘
```

## Features

- **RGB underglow**: Default azul (HUE 170), efectos breathing/rainbow/snake
- **OLED**: Habilitadas en ambos lados
- **Split**: EE_HANDS, SERIAL_DRIVER bitbang, SOFT_SERIAL_PIN D2
- **Bootmagic**: Mantener Tab + conectar USB para resetear EEPROM

## Estructura del repo

```
qmk/                    # Copia de respaldo del keymap QMK
  keymap.c              # Keymap (4 layers)
  config.h              # Config split + RGB
  rules.mk              # Features habilitadas
config/                 # Config ZMK (legacy, no activa con Pro Micro)
```
