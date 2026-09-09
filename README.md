# Circuit Calculator Toolkit

A menu-driven command-line tool for common intro-circuits calculations: Ohm's Law, series/parallel resistance, and 4-band resistor color code decoding.

## What it does

Three tools in one CLI:

- **Ohm's Law solver** — given any two of voltage, current, and resistance, solves for the third.
- **Series/parallel resistance calculator** — enter any number of resistor values and get the combined resistance either way.
- **4-band resistor color code decoder** — enter the four band colors (e.g. `red red brown gold`) and get the resistance value plus tolerance.

## Why I built it

Kept doing the same Ohm's Law and resistor math by hand for Circuits homework, so I turned it into something reusable instead of redoing it every time.

## Tech

- C++ (standard library only — `iostream`, `string`, `vector`, `map`, no external dependencies)

## How to run it

```bash
g++ -o circuit_calculator circuit_calculator.cpp
./circuit_calculator
```

Then follow the on-screen menu.

## What's next

- Add a 5-band resistor mode (adds a second significant-digit band)
- Add basic capacitor/inductor reactance calculations
- Input validation for out-of-range values (currently trusts the user for numeric input)
