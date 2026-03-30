#  Shinies ODST Visor Motorization

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

- 1x Arduino Nano
- 1x MG90S servo
- 1x Push button
- 5V power source for servo
- Wires

---

## 🔌 Wiring Diagram

Please refer to this wiring diagram to correctly wire the system together:
<img width="1920" height="1080" alt="ODST Wiring Diagram" src="https://github.com/user-attachments/assets/dfdc7b4e-307e-471d-99c2-cd3785bae9a9" />



---

## ⚠️ Power Warning

Do **not** rely on the Arduino Nano 5V pin to power the servo, it will not be strong enough.

Use a **separate 5V power source** for the servo.

> **Important:** Arduino **GND must be connected to the same ground** as the servo power supply.

If you skip shared ground, the servo may jitter, move randomly, or not respond correctly.

---

---
## 🛠️ Assembly & Setup Instructions

Follow these steps carefully to install and configure the visor.

---

### 1. Print and Prepare the Helmet

- Print the Shinies ODST helmet
- Insert the servo into the designated slot on the right side of the helmet
  - **Servo wires should face the right-hand side**
- Secure the servo using screws
- **Do NOT install the servo arm yet**

> ⚠️ Wait until the code is uploaded and the servo is in the **closed (0°) position** before attaching the servo arm

---

### 2. Upload the Code

Before continuing, grab your **Arduino Nano**.

#### Install and open the code

1. Download and install **Arduino IDE**
2. Open the provided `.ino` file

#### Select your board

- In the top toolbar, find the board selection dropdown
- Select: Arduino Nano

#### Select the correct port

1. Go to **Tools → Port**
2. Check which ports are listed
3. Plug in your Arduino Nano
4. Check again — a new port should appear
5. Select that port

#### Upload the code

Click **Upload**

If successful, you will see on the bottom terminal:
```
Sketch uses 2798 bytes (9%) of program storage space. Maximum is 30720 bytes.
Global variables use 58 bytes (2%) of dynamic memory, leaving 1990 bytes for local variables. Maximum is 2048 bytes.
```


---

### 3. Wire the System

- Follow this wiring diagram:

- Double-check all connections before powering on

---

### 4. Test the Servo (No Arm Installed Yet)

After wiring:

- Power on the system
- **Do NOT install the servo arm yet**

Test the button:

- Press → motor should rotate one direction
- Press again → motor should rotate the opposite direction
- Hold button → motor resets to **closed position**

**The motor should spin clock-wise to open, and counter-clockwise to close**

#### If direction is incorrect

If the servo spins the wrong way:

- Open the code
- Change:

```cpp
const bool REVERSE_SERVO = true;
```
to: 
```cpp
const bool REVERSE_SERVO = false;
```
and upload again.

---

### 5. Install the Servo Arm

Once the servo is confirmed working:

Hold the button to ensure the servo is in the closed position
Install the servo arm so it is parallel to the servo body like this:
![IMG_2838](https://github.com/user-attachments/assets/06732570-0a39-46f2-8eff-aa427a3b189e)

Secure the arm tightly.

---

### 6. Connect the Linkage

Now connect the servo arm to the visor frame.

You can use:

The provided 3D printable linkage rod with screws and nuts
OR armature wire (or similar material)
**Important requirements**

Linkage length should be approximately:

74mm
Connections must be:
tight
secure
rigid

**⚠️Your linkage must remain rigid when force is applied. If it flexes or bends under load, the servo will not be able to properly close the visor.**

**Any slack in the linkage will cause:**

- visor sagging
- incomplete opening
- inconsistent motion
  
---

### 7. Final Adjustment

If your geometry varies slightly:

You may need to adjust:

- OPEN_ANGLE
Increase or decrease until the visor opens correctly

---

### ✅ Done

If everything is installed correctly, you now have a fully functioning:

- 🪖 Shinies H3 ODST Motorized Visor
- 💡 Final Notes
Always test before final assembly or painting
Make sure all moving parts are smooth and free of resistance
Avoid forcing the servo into mechanical limits
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

👉 `Shinies-ODST-Visor.ino`

### How to use

1. Open Arduino IDE  
2. Open the `.ino` file from the `code/` folder  
3. Upload to your Arduino Nano  

---

### Key values you may want to adjust

const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE   = 75;
const bool REVERSE_SERVO = true;
const int STEP_DELAY_MS = 10;
```

---
## ✏️ What You Should Edit

Most people only need to change these values:
```cpp 
const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE   = 75;
const bool REVERSE_SERVO = true;
const int STEP_DELAY_MS = 10;

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
```cpp
const bool REVERSE_SERVO = true;
```
to:
```cpp
const bool REVERSE_SERVO = false;
```
### Visor does not open far enough

Increase:

```cpp
const int OPEN_ANGLE = 75;
```

For example:

```cpp
const int OPEN_ANGLE = 80;
```

### Servo pushes too far or hits a hard stop

Lower:

```cpp
const int OPEN_ANGLE = 75;
```

For example:

```cpp
const int OPEN_ANGLE = 70;
```

### Movement is too fast

Increase:

```cpp
const int STEP_DELAY_MS = 10;
```

For example:

```cpp
const int STEP_DELAY_MS = 15;
```

### Movement is too slow

Decrease:

```cpp
const int STEP_DELAY_MS = 10;
```

For example:

```cpp
const int STEP_DELAY_MS = 5;
```

---

## 🧪 Recommended Starting Values

These are good default values to start with and what works with my helmet:
```cpp
const int BUTTON_PIN = 2;          
const int SERVO_PIN  = 9;       

const int CLOSED_ANGLE = 0;      
const int OPEN_ANGLE   = 75;     

const bool REVERSE_SERVO = true;  
const bool HOLD_POSITION = true;   

const int STEP_DELAY_MS    = 10;   
const int STARTUP_DELAY_MS = 1000; 
const int HOLD_TIME_MS     = 800;  
const int SETTLE_TIME_MS   = 250;  

const int OVERSHOOT_ANGLE  = 0; 
```
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

```cpp
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
