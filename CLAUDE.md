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
cd ~/qmk_firmware
qmk compile -kb crkbd/rev1 -km agus
qmk flash -kb crkbd/rev1 -km agus -bl avrdude-split-left
qmk flash -kb crkbd/rev1 -km agus -bl avrdude-split-right
```

Siempre flashear AMBOS lados despues de cambios en config.h o keymap.
Para cambios solo de OLED se puede flashear solo el derecho para probar rapido.

## Archivos QMK

| Archivo | Que hace |
|---------|----------|
| `keymap.c` | Keymap 4 layers + OLED animations + split sync |
| `config.h` | Split config + RGB defaults + OLED sync transaction |
| `rules.mk` | Features: RGBLIGHT, OLED, SERIAL_DRIVER bitbang |

## Layout actual (thumbs)

```
|CTL|NUM|SPC|    |ENT|SYM|ALT|
     ^^^              ^^^
  hold=numeros    hold=nav
```

- GUI/Win en fila del medio izquierda (no en thumb)
- CTRL en thumb izquierdo interno
- NUM layer tiene flechas HJKL + numeros + F-keys + media + RGB

## OLED Animaciones

La OLED derecha tiene 2 animaciones switcheables con NUM+ALT (thumb der externo):
- **Anim 0**: Typing effect "> just code" con cursor parpadeante + layer
- **Anim 1**: Luna dog (sentada/camina/corre/ladra segun mods y actividad)

### Para agregar nuevas animaciones:
1. Crear funcion `render_xxx()` en la seccion `#ifdef OLED_ENABLE`
2. Agregar case en `oled_task_user()` switch
3. Cambiar `% 2` a `% N` en `process_record_user` (N = total animaciones)
4. NO usar `oled_clear()` cada frame (causa parpadeo). Solo limpiar al cambiar anim.

### Specs OLED para crear animaciones custom:
- Display: SSD1306, 128x32 pixels, landscape
- Grilla texto: 21 chars x 4 lineas (font 6x8)
- Luna usa frames de 32x24px (96 bytes por frame, `oled_write_raw_byte`)
- Para landscape: escribir cada pagina (32 bytes) al offset correcto (page * 128 + col)
- Firmware actual: 90% (25990/28672), ~2682 bytes libres
- Usar PROGMEM para frame data, funciones `_P` para strings

### Split sync (para datos master→slave):
- `SPLIT_TRANSACTION_IDS_USER OLED_SYNC` en config.h
- `transaction_register_rpc()` en `keyboard_post_init_user()`
- `transaction_rpc_send()` en `housekeeping_task_user()`
- Handler en slave recibe y aplica el dato

## Reset EEPROM (Bootmagic)

1. Desconectar USB
2. Mantener Tab (esquina sup izq) presionada
3. Conectar USB manteniendo Tab
4. Soltar despues de 1 segundo

## Config ZMK (legacy)

El directorio `config/` contiene config ZMK para nice_nano_v2. NO se usa con Pro Micro.
