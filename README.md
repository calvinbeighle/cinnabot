# Drawing Machine Project

This project contains code for a drawing machine that converts images into polar coordinates and controls multiple motors to create drawings.

## Project Structure

### Web Interface
- `image_to_stencil.html`: Web-based tool that converts uploaded images into polar coordinates. It provides:
  - Image upload and processing
  - Detection of black pixels in the image
  - Conversion to polar coordinates (r, θ) from the center of the image
  - Visual verification with redrawn coordinates
  - Arduino code generation for servo control using G-code processing

### Motor Control
- `hw10_draw_machine.ino`: Main Arduino sketch for controlling the drawing machine
- `rotationmotorcode.ino`: Code for controlling the rotation motor
- `vibrationmotorcode.ino`: Code for controlling the vibration motor
- `StepperSweep.h`: Example class demonstrating stepper motor control
- `LateralSweep.h`: Control for lateral (X-axis) movement
- `VibrationSweep.h`: Control for vibration motor
- `X_seq.h`: Sequence definitions for X-axis movement
- `V_seq.h`: Sequence definitions for vibration control

### Documentation
- `notes.txt`: Personal notes and documentation
- `README.md`: This file - project overview and documentation

## How to Use

### Image Processing
1. Start the web server:
   ```bash
   python3 -m http.server 8000
   ```

2. Open your browser and navigate to:
   ```
   http://localhost:8000/image_to_stencil.html
   ```

3. Upload an image to convert it to polar coordinates
   - Black pixels will be detected and converted to (r, θ) coordinates
   - The second canvas will show the redrawn points in red
   - The text area will display all coordinates

4. Use the generated Arduino code with your drawing machine setup

## Hardware Requirements
- Arduino board
- X-axis motor for lateral movement
- Rotation motor for angular positioning
- Vibration motor for drawing implement control
- Drawing implement (pen, marker, etc.) 