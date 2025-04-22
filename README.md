# Drawing Machine Project

This project contains code for a drawing machine that converts images into polar coordinates and controls servos to create drawings.

## Project Structure

### Web Interface
- `image_to_stencil.html`: Web-based tool that converts uploaded images into polar coordinates. It provides:
  - Image upload and processing
  - Conversion to polar coordinates (r, θ)
  - Visualization of the converted coordinates
  - Arduino code generation for servo control

### Arduino Code
- `hw10_draw_machine.ino`: Main Arduino sketch for controlling the drawing machine
- `StepperSweep.h`: Example class demonstrating stepper motor control (for reference)

### Documentation
- `notes.txt`: Personal notes and documentation
- `README.md`: This file - project overview and documentation

## How to Use

1. Start the web server:
   ```bash
   python3 -m http.server 8000
   ```

2. Open your browser and navigate to:
   ```
   http://localhost:8000/image_to_stencil.html
   ```

3. Upload an image to convert it to polar coordinates

4. Use the generated Arduino code with your drawing machine setup

## Hardware Requirements
- Arduino board
- Two servos for X and Y axis control
- Drawing implement (pen, marker, etc.) 