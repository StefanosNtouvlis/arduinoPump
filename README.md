# Pump Control Project with Arduino  

This repository documents my experiment to control a small pump using an Arduino, a MOSFET, and a button. The project is part of my ongoing journey in robotics and electronics, exploring new ideas and learning by doing.  

---

## 🚀 **Project Overview**  

This circuit controls a 120 l/h pump with a simple ON/OFF toggle mechanism using a button. The Arduino monitors the button's state and drives the MOSFET to power the pump.  

However, during testing, I found that the pump’s performance was weak due to insufficient Gate voltage for the MOSFET, leading to valuable insights into component selection and circuit optimization.  

---

## 🛠 **Components**  

- **Arduino Uno**: Microcontroller for logic and control.  
- **IRF540N MOSFET**: Handles the pump's high current and switches it ON/OFF.  
- **9V Battery**: Powers the pump independently of the Arduino.  
- **Push Button**: Toggles the pump state (ON/OFF).  
- **Breadboard & Wires**: For modular and reusable connections.  
- **Pump**: 120 l/h small DC pump.  

---

## ⚙️ **Circuit Description**  

1. **Arduino Pin Connections**:  
   - **Button**: Connected to digital pin 2 and ground via a pull-down configuration.  
   - **MOSFET Gate**: Controlled via digital pin 9.  
2. **Power Supply**:  
   - 9V battery powers the pump directly (through the MOSFET).  
   - Arduino powered via USB.  
3. **MOSFET Wiring**:  
   - **Gate**: Connected to Arduino pin 9.  
   - **Source**: Connected to ground.  
   - **Drain**: Connected to the pump’s negative terminal.  

---

## 🖥️ **Code**  

```cpp
const int buttonPin = 2;
const int pumpPin = 9;

bool pumpState = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    delay(200); // Debounce delay
    pumpState = !pumpState;
    digitalWrite(pumpPin, pumpState ? HIGH : LOW);
  }
}
```

---

## 🧪 **Observations**  

- **Issue**: The pump operates but not at full strength.  
- **Root Cause**: The IRF540N MOSFET requires at least 10V at the Gate to fully switch on, but the Arduino only provides 5V.  
- **Effect**: The MOSFET operates in its linear region, restricting current flow to the pump.  

---

## 🔧 **Next Steps**  

To optimize the circuit, I’m exploring:  
1. **Replacing the MOSFET** with a logic-level MOSFET like the IRLZ44N, which fully switches on with 5V.  
2. **Adding a Gate Driver** to boost the voltage to the IRF540N’s Gate.  

---

## 🌟 **Reflections**  

This project reinforced the importance of understanding component compatibility. Thanks to the wealth of free online resources, I’ve learned to not only build circuits but also identify their limitations and work toward solutions.  

Feel free to reach out with suggestions, or share similar projects—let’s learn and build together!  

---
Let me know if you'd like further refinements or additions!
