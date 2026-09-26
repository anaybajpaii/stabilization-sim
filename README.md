# Stabilization Simulator
### Self-Balancing Simulator

This is a C++ simulator that models a 2D inverted pendulum stabilized by a
proportional (P) controller, comparing uncontrolled (gravity-only) motion
against controlled motion under varying gain values.

## Overview
The simulator models a pole balanced upright on a pivot, starting at some
initial tilt angle. Unlike a normal hanging pendulum, gravity here is
destabilizing — it pulls the pole further away from upright rather than back
toward it. It includes two modes:

* Uncontrolled model — gravity torque only, demonstrating the pole falling
  over on its own.
* Controlled model — a proportional controller reads the tilt angle each
  timestep and applies a corrective torque to hold the pole upright.

Simulation data can be exported to CSV and plotted using Python.

## Physics
The pendulum's state is described by its angle (rad, tilt from upright) and
angular velocity (rad/s). Gravity produces an angular acceleration:

$angularAcceleration = \frac{g}{L} · sin(angle)$

where $g$ is gravitational acceleration and $L$ is the pole length. Because
this term always pushes in the same direction as the tilt, the system is
unstable without correction.

The controller adds a corrective torque proportional to the angle:

$correction = -K_p · angle$

where $K_p$ is the proportional gain. The total angular acceleration each
timestep is:

$angularAcceleration = (\frac{g}{L} · sin(angle)) + correction$

A semi-implicit Euler integration method then updates angular velocity and
angle at each fixed timestep using this acceleration, producing an
approximate trajectory of the pole's tilt over time.

## Features
* Uncontrolled pendulum physics (gravity-only)
* Proportional controller with configurable gain
* Runtime CLI input for initial angle, pole length, and gain
* CSV trajectory data output
* Python plotting script for visualizing single and multi-gain comparisons
* Unit tests for controller correctness

## Project Structure
```
├── src/
│   ├── main.cpp
│   ├── Pendulum.h
│   ├── Pendulum.cpp
│   ├── Controller.h
│   ├── Controller.cpp
│   ├── DataLogger.h
│   └── DataLogger.cpp
├── data/
├── scripts/
│   └── plot_stability.py
├── docs/
│   ├── control_notes.md
│   └── screenshots/
├── tests/
│   └── test_controller.cpp
├── Makefile
├── README.md
├── LICENSE
└── .gitignore
```

## Tools
* C++ — simulation and physics calculations
* Python — data visualization
* Matplotlib — trajectory plots
* Git/GitHub — version control

## Build
```bash
g++ src/main.cpp src/Pendulum.cpp src/Controller.cpp src/DataLogger.cpp -o sim
./sim
```

## Plotting
```bash
pip install matplotlib
python scripts/plot_stability.py
```

## Testing
```bash
g++ tests/test_controller.cpp src/Controller.cpp -o test_controller
./test_controller
```

## Documentation
See `docs/control_notes.md` for the mathematical model, gain comparison
findings, the limitation of pure P control, and its connection to drone
flight control. See `docs/screenshots/` for plotted output.

## Project Context
This project is part of a mechatronics-focused portfolio, alongside a
custom-built drone and DIY speaker, and precedes upcoming projects: drone
flight/motor control firmware, a PID controller simulator, and a speaker DSP
toolkit.

## License
MIT
