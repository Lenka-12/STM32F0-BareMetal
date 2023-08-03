
# Bare Metal STM32F051C6

This is a bare-metal programming repository for UCT second-year development board. Everything is written from scratch.

## Contents
- Start-up code written in C
- Linker Script and Makefile
- MCU specific header files for some peripherals
- LCD library

# Getting Started with STM32F0xx series

Clone the repository to your local computer. Go to linker script `src/stm32_ls.ld` and update the RAM and Flash size according to your processor specs. For the UCT board, you do not need to change anything else.

## Tools Needed

Before you start, ensure you have the following tools installed on your system:

1. **Arm GNU Toolchain**
   - **Windows**:
     - Download the Arm GNU Toolchain for Windows from https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads.
     - Install the toolchain by running the installer.
     - During installation, specify the installation directory (e.g., `C:\Program Files (x86)\GNU Arm Embedded Toolchain`).
     - Add the toolchain's `bin` directory to the system's `PATH` environment variable.
   - **Linux (Ubuntu)**:
     - Install the Arm GNU Toolchain using the package manager:
       ```bash
       sudo apt update
       sudo apt install gcc-arm-none-eabi
       ```

2. **OpenOCD**
   - **Windows**:
     - Download the Windows distribution of OpenOCD from https://gnutoolchains.com/arm-eabi/openocd/.
     - Extract the downloaded archive to a folder of your choice (e.g., `C:\openocd`).
     - Add the OpenOCD `bin` directory to the system's `PATH` environment variable.
   - **Linux (Ubuntu)**:
     - Install OpenOCD using the package manager:
       ```bash
       sudo apt update
       sudo apt install openocd
       ```

3. **Make**
   - **Windows**:
     - Download the Windows binary distribution of Make from https://gnuwin32.sourceforge.net/packages/make.htm.
     - Install Make by running the installer.
     - Add the Make `bin` directory to the system's `PATH` environment variable.
   - **Linux (Ubuntu)**:
     - Install Make using the package manager:
       ```bash
       sudo apt update
       sudo apt install make
       ```

## Downloading Code to our Board

1. Go to the project folder containing the Makefile.
2. Open that folder in the terminal.
3. Type `make`.
4. If there are no errors, type the command: `make load`.
5. Open a new terminal/command prompt window.
6. Type `arm-none-eabi-gdb`.
7. Enter the command: `target extended-remote localhost:3333` (the port number will be visible in the message you get after `make load`).
8. Enter: `monitor reset init`.
9. Enter: `monitor flash write_image erase final.elf`.
10. Enter: `monitor reset halt`.
11. Enter: `monitor resume`.

## For UCT Devboard

- User LED0 will blink every second.
- You will see the message on the LCD screen:
  ```
  "Hello World!!"
  "Well Done!!"
  ```
- Press SW0, and led1 will turn on.

### To-do: add more depth info on installation, library usage, and more...
