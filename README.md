# MSN Layout 🎯

> *QWERTY Spanish Corne layout for Vim + Hyprland users*  



---

## ¿Qué es esto?

Un layout para **Corne (crkbd)** diseñado desde cero para:

- 🇪🇸 **QWERTY Spanish** — con Ñ, caracteres especiales en su sitio lógico
- 🖥️ **Hyprland** — capa dedicada con workspaces, focus y split toggle integrados
- ⌨️ **Vim users** — navegación fluida sin salir de home row
- 🖱️ **Sin ratón** — mouse layer completa como fallback
- 💻 **Portabilidad** — compatible con teclado de laptop cuando no llevas el Corne

No existe ningún layout público con esta combinación. La mayoría de layouts para split ortolineal están en inglés y no contemplan Hyprland. Este es el primero.

---

## Filosofía de diseño

### Los 3 thumbs por lado (el tridente)

```
LEFT:  [Ctrl]  [Space]  [Shift→Mouse]
RIGHT: [GUI→HYPR]  [Backspace]  [Enter→NAV]
```

Cada thumb tiene una función clara:
- **Ctrl/Space** — modificadores base, siempre accesibles
- **Shift hold** → activa Mouse layer (L3)
- **GUI tap** → Super para Hyprland / **GUI hold** → activa HYPR layer (L4)
- **Backspace** — libre, sin layer tap, sin miedo a triggers accidentales
- **Enter tap** → Enter / **Enter hold** → activa NAV layer (L2)

La decisión clave fue poner `LT4` en GUI y no en Backspace. Backspace se usa mucho y mantenerlo pulsado mientras escribes rápido activaría HYPR sin querer. GUI en cambio solo se pulsa intencionadamente.

---

## Capas

### L0 — Base

```
┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
│  Tab  │   Q   │   W   │   E   │   R   │   T   │   │   Y   │   U   │   I   │   O   │   P   │  L2   │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Alt  │   A   │   S   │   D   │   F   │   G   │   │   H   │   J   │   K   │   L   │   Ñ   │   '   │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│ Shift │   Z   │   X   │   C   │   V   │   B   │   │   N   │   M   │   ,   │   .   │   -   │  L5   │
└───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
                        │ Ctrl  │ Space │Sft/L3 │   │GUI/L4 │ Bspc  │Ent/L2 │
                        └───────┴───────┴───────┘   └───────┴───────┴───────┘
```

**Por qué así:**
- QWERTY Spanish intacto — sin reaprender nada
- Las teclas laterales extra del Corne (`VOLU/VOLD`) están pero no molestan
- `LT2(KC_NO)` en pinky derecho superior activa la capa de números — tap muerto, solo útil como hold

---

### L1 — Números y Símbolos

```
┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
│  Esc  │       │       │       │       │       │   │   \   │   '   │   ]   │   [   │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│   `   │   1   │   2   │   3   │   4   │   5   │   │   6   │   7   │   8   │   9   │   0   │   -   │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │  <>   │       │       │       │       │   │       │       │       │       │       │   =   │
└───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
                        │ Ctrl  │ Shift │AltGr  │   │  GUI  │ Bspc  │       │
                        └───────┴───────┴───────┘   └───────┴───────┴───────┘
```

**Por qué así:**
- Números en home row izquierda (1-5) y derecha (6-0) — sin mover la mano
- AltGr en thumb para acceder a caracteres especiales del español con la lógica de QWERTY Spanish
- Símbolos de programación (`\ ' ] [`) en home row derecha — acceso directo sin pinky stretch
- `<>` en pinky izquierdo fila inferior — lógica española, misma posición física que en el teclado estándar

---

### L2 — NAV

```
┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
│       │       │       │       │       │       │   │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Alt  │ Home  │ PgDn  │ PgUp  │  End  │       │   │  Left │  Up   │ Down  │ Right │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│ Shift │       │       │       │       │       │   │       │       │       │       │       │       │
└───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
                        │ Ctrl  │ Space │  ▼▼▼  │   │  GUI  │ Bspc  │  ▼▼▼  │
                        └───────┴───────┴───────┘   └───────┴───────┴───────┘
```

**Por qué así:**
- `Home/PgDn/PgUp/End` en home row izquierda — misma mano, sin moverla
- Flechas en home row derecha — flujo natural para quien viene de vim
- Shift y Alt activos para poder hacer selección (`Shift+flechas`) y saltos de palabra (`Alt+flechas`)
- Activada con hold de Enter — el thumb derecho más natural para navegar

> **Nota sobre las flechas:** Las flechas están en orden `Left/Up/Down/Right` en vez del clásico vim `H/J/K/L`. Esto es intencionado — el cerebro las mapea como flechas físicas, no como movimientos vim. Funciona mejor para navegación general fuera de vim.

---

### L3 — Mouse

```
┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
│       │       │       │       │       │       │   │       │  Ac2  │  Ac1  │  Ac0  │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │  ⏮   │  ⏭   │  ⏯   │ Vol-  │ Vol+  │   │  M←   │  M↑   │  M↓   │  M→   │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │       │       │       │       │       │   │       │  W↑   │  W↓   │ Mute  │       │       │
└───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
                        │       │       │  ▼▼▼  │   │ Btn3  │ Btn2  │ Btn1  │
                        └───────┴───────┴───────┘   └───────┴───────┴───────┘
```

**Por qué así:**
- Cursor del ratón en home row derecha — misma lógica que las flechas
- Scroll en fila inferior derecha — pulgar/meñique, natural
- Media controls en home row izquierda — mano libre mientras el ratón está en la derecha
- Activada con hold de Shift izquierdo — el Shift está en el pinky, fácil de mantener

---

### L4 — HYPR (Hyprland)

```
┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
│       │       │  WS2  │       │       │       │   │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Alt  │  WS1  │ S+tgl │  WS3  │  WS4  │  WS5  │   │  S+H  │  S+J  │  S+K  │  S+L  │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │  S+.  │  WS-  │       │       │  WS+  │   │ S+←   │ S+↑   │ S+↓   │ S+→   │       │       │
└───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
                        │ Ctrl  │ Shift │       │   │  GUI  │  ▼▼▼  │       │
                        └───────┴───────┴───────┘   └───────┴───────┴───────┘
```

**Leyenda:**
- `WS1-5` → `Super+1` al `Super+5` (workspaces directos)
- `WS2` (fila superior) → `Super+2` (acceso alternativo)
- `S+tgl` → `Super+S` (togglesplit — cambiar entre split horizontal/vertical)
- `WS-/WS+` → `Super+5` / `Super+6` (workspace anterior/siguiente)
- `S+H/J/K/L` → `Super+H/J/K/L` (focus de ventana)
- `S+←↑↓→` → `Super+flechas` (mover ventana — fallback para laptop)
- `S+.` → `Super+.` (vicinae/launcher)

**Por qué así:**
- Workspaces 1-5 en home row izquierda — un movimiento, sin combinaciones
- `WS+/WS-` en fila inferior izquierda porque son los más usados en flujo rápido — pulgar+meñique, cómodo
- `Super+S` (togglesplit) en home row porque se usa constantemente para reordenar ventanas
- Focus de ventana con `Super+hjkl` en home row derecha — misma lógica vim
- `Super+flechas` en fila inferior derecha como fallback para cuando usas el laptop sin Corne
- Activada con hold de GUI — solo se activa intencionadamente

---

### L5 — F-Keys

```
┌───────┬───────┬───────┬───────┬───────┬───────┐   ┌───────┬───────┬───────┬───────┬───────┬───────┐
│       │       │       │       │       │       │   │       │       │       │       │       │       │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │  F1   │  F2   │  F3   │  F4   │  F5   │   │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │
├───────┼───────┼───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┼───────┼───────┤
│       │  F12  │       │       │       │       │   │       │       │       │       │       │       │
└───────┴───────┴───────┼───────┼───────┼───────┤   ├───────┼───────┼───────┼───────┴───────┴───────┘
                        │       │       │       │   │       │       │       │
                        └───────┴───────┴───────┘   └───────┴───────┴───────┘
```

---

## Combos

| Combo | Resultado | Por qué |
|-------|-----------|---------|
| Tab + Enter | `MO(5)` — F-Keys | Acceso rápido a función sin layer tap dedicado |
| VolUp + VolDown | Play/Pause | Las teclas laterales de media hacen algo útil |
| Alt + GUI + RAlt + RGUI | `TG(5)` — Toggle F-Keys | Para cuando necesitas F-Keys durante un rato |

---

## Requisitos Hyprland

Para que la capa HYPR funcione correctamente necesitas estos binds en tu `hyprland.conf`:

```bash
$mainMod = SUPER

# Focus de ventana
bind = $mainMod, H, movefocus, l
bind = $mainMod, J, movefocus, d
bind = $mainMod, K, movefocus, u
bind = $mainMod, L, movefocus, r

# Mover ventana
bind = $mainMod SHIFT, H, movewindow, l
bind = $mainMod SHIFT, J, movewindow, d
bind = $mainMod SHIFT, K, movewindow, u
bind = $mainMod SHIFT, L, movewindow, r

# Workspaces directos
bind = $mainMod, 1, workspace, 1
bind = $mainMod, 2, workspace, 2
bind = $mainMod, 3, workspace, 3
bind = $mainMod, 4, workspace, 4
bind = $mainMod, 5, workspace, -1
bind = $mainMod, 6, workspace, +1

# Split toggle
bind = $mainMod, S, layoutmsg, togglesplit
```

---

## Instalación

### Vial (recomendado)
1. Descarga `msn_layout.json`
2. Abre Vial
3. `File → Import` → selecciona el JSON
4. Flash

### QMK
1. Copia `msn_keymap.c` a `keyboards/crkbd/keymaps/msn/keymap.c`
2. `qmk compile -kb crkbd -km msn`
3. Flash con QMK Toolbox o `qmk flash`

---

## Hardware probado

- **Teclado:** Corne (crkbd) v3
- **Switches:** Kailh Choc V2 Brown
- **Firmware:** Vial

---

## ¿Por qué no home row mods?

Los home row mods son potentes pero tienen un problema real para quien viene de un 65% con velocidad alta (90+ wpm): los triggers accidentales. Cuando escribes rápido, `A` seguido de `S` puede activar `Ctrl+S` sin querer. Para un vim user que ya tiene Shift en thumb y los modificadores accesibles, el coste/beneficio no compensa. MSN layout resuelve el acceso a modificadores con layer taps en thumbs, que tienen menos falsos positivos.

---

## Créditos e inspiración

- [Miryoku](https://github.com/manna-harbour/miryoku) — filosofía de capas
- [Callum mods](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum) — one-shot mods
- La comunidad de r/ErgoMechKeyboards
- El tridente MSN del Barça 2014-2017 🔵🔴

---

*Hecho con ❤️ y demasiadas horas de Vial*
