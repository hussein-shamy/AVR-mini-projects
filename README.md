# AVR Mini Projects

This repository showcases various projects developed to enhance my skills in dealing with 8-bit microcontrollers like the AVR. It includes implementations of drivers for microcontroller peripherals and some easy applications.

## How to Use the Repository

### Folder Structure

The repository is organized as follows:
AVR-Mini-Projects/
├── ProjectName/
│ ├── src/ [Contains the main function and the appication code, from here the code starts]
│ │ ├── main.c 
│ ├── Common/ [Contains the types of target and common useful macros]
│ │ ├── common_macros.h/ 
│ │ ├── std_types.h/
│ ├── HAL/ [Contains the implementation of Hardware Abstraction Layer]
│ │ ├── ex: Dc_Motor/
│ ├── MCAL/ [Contains the implementation of Micocontroller Abstraction Layer]
│ │ ├── Makefile
│ ├── Simulator/ [Contains the schematic design of the project for validation]
│ │ ├── README.md
│ ├── Debug/ [Contains the elf file to be flashed]
│ │ ├── test_module1.c

### Getting Started

### Prerequisites
- AVR-GCC
- Make
- avrdude (for flashing the microcontroller)

1. Install AVR-GCC:
    - On Debian/Ubuntu: `sudo apt-get install gcc-avr avr-libc`
    - On macOS: `brew tap osx-cross/avr && brew install avr-gcc`

2. Install Make:
    - On Debian/Ubuntu: `sudo apt-get install make`
    - On macOS: `brew install make`

3. Clone the repository:
    ```
    git clone [https://github.com/your-username/ATmega32-Project.git](https://github.com/yourusername/AVR-Mini-Projects.git)
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

