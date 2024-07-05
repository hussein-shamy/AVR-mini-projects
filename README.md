# AVR Mini Projects

This repository showcases various projects developed to enhance my skills in dealing with 8-bit microcontrollers like the AVR. It includes implementations of drivers for microcontroller peripherals and some easy applications.

## How to Use the Repository

### Prerequisites
- AVR-GCC
- Make
- avrdude (for flashing the microcontroller)

### Directory Structure
- `src/`: application code/ main function
- `Common/`: types of target and common useful macros
- `HAL/`: Hardware Abstraction Layer implementation
- `MCAL/`: Microcontroller Abstraction Layer implementation
- `Simulator/`: schematic design of the project for validation
- `Debug/`: elf file to be flashed

### Setting Up the Development Environment

1. Install AVR-GCC:
    - On Debian/Ubuntu: `sudo apt-get install gcc-avr avr-libc`
    - On macOS: `brew tap osx-cross/avr && brew install avr-gcc`

2. Install Make:
    - On Debian/Ubuntu: `sudo apt-get install make`
    - On macOS: `brew install make`

3. Clone the repository:
    ```
    git clone https://github.com/hussein-shamy/AVR-mini-projects.git
    cd AVR-mini-projects
    ```
4. Build the project:
    ```
    make
    ```
5. Flash the firmware:
    ```
    make flash
    ```
