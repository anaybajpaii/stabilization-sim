# Control Notes

## Overview
This project simulates a 2D inverted pendulum. It is a pole balanced upright on a
pivot, unstable by nature, where gravity constantly pulls it further from
vertical rather than back toward it. A proportional (P) controller reads the
tilt angle each timestep and applies a corrective torque proportional to the
error, attempting to hold the pole upright.

## Physics Model
- State: `angle` (radians, tilt from upright) and `angularVelocity` (rad/s)
- Integration: semi-implicit Euler
- Per-step update:
  - `angularAcceleration = (GRAVITY / LENGTH) * sin(angle) + controlTorque`
  - `angularVelocity += angularAcceleration * dt`
  - `angle += angularVelocity * dt`

## Controller
- Proportional only: `correction = -gain * angle`
- Gain ($K_p$) sets how aggressively the controller pushes back against tilt

## Findings from Gain Comparison
Three gains were tested against the same starting conditions (see
`docs/screenshots/gain_comparison.png`):

- **Kp = 1.0** and **Kp = 5.0** both failed to stabilize the pendulum. Since
  gravity's destabilizing term is `GRAVITY / LENGTH = 9.81`, any gain below
  that minumum is not strong enough to overcome gravity's pull, so the
  angle diverges in a widening oscillation.
- **Kp = 20.0** cleared the threshold and prevented the pendulum from falling
  over completely, but it did not settle at 0 either — it oscillated
  indefinitely, overshooting past upright and swinging back.

## Why Pure P Control Can't Fully Settle the System
A proportional controller only reacts to the current error (the angle), not
to how fast that error is changing. This means there is no mechanism in the
system to absorb the pendulum's built-up angular momentum — once it starts
correcting, it overshoots, and nothing removes energy from the system, so it
oscillates rather than settling to rest.

This is a well-known limitation of pure P control. Adding a derivative (D)
term — a correction based on angular velocity, not just angle — would let
the controller anticipate and dampen the overshoot instead of just reacting
to position. That extension (full PID) is a natural next step beyond this
project, and one directly relevant to real flight controller design.

## Connection to Drone Flight Control
This 2D single-axis simulation is a simplified rehearsal of the stabilization
problem a drone's flight controller solves continuously in 3D, across
multiple rotational axes (roll, pitch, yaw), using much faster sensor and
motor update rates. The core idea — measure error, apply proportional
correction, repeat every timestep — is the same logic underlying real
attitude control firmware.
