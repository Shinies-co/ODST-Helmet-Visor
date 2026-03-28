#  Shinies ODST Visor System

Simple motorized visor control system for the Shinies H3 ODST helmet using an **Arduino Nano + MG90S servo + button**.

Designed to be **easy to build, easy to modify, and beginner-friendly**.

> ⚠️ This code is **specifically made for the Shinies ODST helmet model**.  
> It may work on other helmets, but you will likely need to adjust values.

> 🛒 This system is designed for the Shinies ODST helmet  
> You can find the model here: https://etsy.com/shop/shiniesprops
---

## 🚀 Features

- One-button visor control
- Smooth servo movement
- Tap to open/close
- Hold to force visor closed
- Uses common parts
- Beginner-friendly code
- No extra libraries required beyond Arduino's built-in `Servo.h`

---

## 🧰 Hardware Used

- Arduino Nano V3
- MG90S servo
- Momentary push button
- 5V power source for servo
- Wires

---

## 🔌 Wiring

### Servo (MG90S)

| Wire Color | Connect To |
|------------|------------|
| Red        | 5V external power |
| Brown/Black | GND |
| Orange/Yellow | Pin **9** |

### Button

| Button Pin | Connect To |
|------------|------------|
| One side   | Pin **2** |
| Other side | GND |

---

## ⚠️ Power Warning

Do **not** rely on the Arduino Nano 5V pin to power the servo if possible.

Use a **separate 5V power source** for the servo.

> **Important:** Arduino **GND must be connected to the same ground** as the servo power supply.

If you skip shared ground, the servo may jitter, move randomly, or not respond correctly.

---

## 🎮 Controls

| Action | Result |
|--------|--------|
| Tap button | Toggle visor open/close |
| Hold button | Force visor closed |

---

## ⚙️ Arduino Code

---

```md
The full Arduino code is located here:

👉 `code/shinies_odst_visor_system.ino`

### How to use

1. Open Arduino IDE  
2. Open the `.ino` file from the `code/` folder  
3. Upload to your Arduino Nano  

---

### Key values you may want to adjust

```cpp
const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE   = 47;
const bool REVERSE_SERVO = false;
const int STEP_DELAY_MS = 15;
```

---
## ✏️ What You Should Edit

Most people only need to change these values:
```
const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE   = 47;
const bool REVERSE_SERVO = false;
const int STEP_DELAY_MS = 15;

```

What each one does:
### CLOSED_ANGLE
The visor's fully closed position
### OPEN_ANGLE
The visor's fully open position
### REVERSE_SERVO
Change to true if the servo moves in the wrong direction
### STEP_DELAY_MS
Controls speed
lower = faster
higher = slower

---

## 🔧 Tuning Guide
### If the servo moves the wrong way

Change:
```
const bool REVERSE_SERVO = false;
```
to:
```
const bool REVERSE_SERVO = true;
```
### Visor does not open far enough

Increase:

```
const int OPEN_ANGLE = 47;
```

For example:

```
const int OPEN_ANGLE = 50;
```

### Servo pushes too far or hits a hard stop

Lower:

```
const int OPEN_ANGLE = 47;
```

For example:

```
const int OPEN_ANGLE = 45;
```

### Movement is too fast

Increase:

```
const int STEP_DELAY_MS = 15;
```

For example:

```
const int STEP_DELAY_MS = 20;
```

### Movement is too slow

Decrease:

```
const int STEP_DELAY_MS = 15;
```

For example:

```
const int STEP_DELAY_MS = 10;
```

---

## 🧪 Recommended Starting Values

These are good default values to start with and what works with my helmet:
```
const int BUTTON_PIN = 2;
const int SERVO_PIN  = 9;

const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE   = 47;

const bool REVERSE_SERVO = false;

const int STEP_DELAY_MS    = 15;
const int STARTUP_DELAY_MS = 1000;
const int HOLD_TIME_MS     = 800;
const int SETTLE_TIME_MS   = 250;
```

---

## 🛠️ Setup Instructions
1. Wire the button to pin 2 and GND
2. Wire the servo signal to pin 9
3. Power the servo with a proper 5V external source
4. Connect Arduino GND to servo power GND
5. Open Arduino IDE
6. Paste in the code
7. Upload to your Arduino Nano
8. Test the visor before final assembly

---

## ⚠️ Troubleshooting
### Servo jitters or buzzes
- Check shared ground
- Make sure the servo has enough power
- Make sure the mechanism is not binding
- Make sure the servo is not pushing into a hard stop

### Button does nothing
- Make sure one side of the button goes to pin 2
- Make sure the other side goes to GND
- This code uses INPUT_PULLUP, so:
    pressed = LOW
    released = HIGH

### Servo moves, but the visor does not
- Check the linkage/mechanism
- Make sure the servo horn is tight
- Make sure the printed parts are not colliding
- Make sure the servo is strong enough for the actual assembled visor

### Servo resets strangely on startup

This code includes a startup delay:

```
const int STARTUP_DELAY_MS = 1000;
```

If needed, increase it slightly.

---

## 💡 Build Tips
**Test everything outside the helmet first and before painting!**
- Make sure the visor can move freely by hand
- Avoid forcing the servo into mechanical stops
- Tune the open angle before final assembly
- If needed, start with a lower angle and slowly increase it

---

## 🧩 Notes

This project is intentionally kept simple:

- one button
- one servo
- one visor action

No sound, no lights, no extra modules.

That keeps it easier to build, easier to troubleshoot, and easier for other people to use.

---

## ⭐ If You Use This

If this helped you, consider starring the repo or sharing your build.

Would love to see what people make with it.
