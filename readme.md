# BaseCam Gimbal Console Controller Guideline
<br />This document describes the useful info for the test of hardware and update the firmware in development process

## Table of Contents
- [Gimbal Console development workflow](#gimbal-console-development-workflow)
- [Pinout of the PCBs & Pinmap for wiring](#pinout-of-the-PCBs-&-Pinmap-for-wiring)
- [How to flash the firmware on Gimbal console controller](#how-to-flash-the-firmware-on-gimbal-console-controller)
    - flash burner
    - bootloader
- How to install the application on Lattepanda?
    - open Lattepanda on-board UART with LattepandaLeonardo firmware [[Doc](https://docs.lattepanda.com/content/1st_edition/vs_programming/#step-3-blink-your-board)]
    - version management

## Gimbal Console development workflow

- github repo
    - Public repository with application released and runner scrip [[Download](https://github.com/GimbalConsole/GimbalConsolePubRepo)]
    - Linux application (Lattepanda application based on QT) [[Download](https://github.com/GimbalConsole/GimbalConsoleApp2)]
    - LattepandaLeonardo firmware (Lattepanda UART driver based on Arduino)[[Download](https://github.com/GimbalConsole/LattepandaLeonardo)]
    - Controller firmware (Controller board firmware based STM32)[[Download](https://github.com/GimbalConsole/FirmwareConsole)]
    - Controller bootloader (Controller board bootloader)[[Download](https://github.com/GimbalConsole/FirmwareBootloader)]
    - Utility for downloading firmware with bootloader[[Download](https://github.com/GimbalConsole/Util_Bootloader)]
    - Controller PCB's HW design[[Download](https://github.com/GimbalConsole/HardwareShield)]
    - Right board PCB's HW design[[Download](https://github.com/GimbalConsole/HardwareRightboard)]
    - Left board PCB's HW design[[Download](https://github.com/GimbalConsole/HardwareRightboard)]
    - Led ring PCB's HW design[[Download](https://github.com/GimbalConsole/HardwareLedRing)]

- development workflow
    - development - dev branch
    - production - main branch
    - version sync - note in [[version.txt](https://github.com/GimbalConsole/GimbalConsoleApp2/blob/master/version.txt)]
    - application released[[Download](https://github.com/GimbalConsole/GimbalConsolePubRepo/releases)]

## Pinout of the PCBs & Pinmap for wiring
- Controller board pinout
<img title="Controller pinout" alt="pinout image" src="/doc/images/controller_wiring.png">
<img title="Controller pinout" alt="pinout image" src="/doc/images/controller_wiring1.png">
<img title="Controller pinout" alt="pinout image" src="/doc/images/controller_wiring2.png">
- Left board pinout
<img title="Controller pinout" alt="pinout image" src="/doc/images/left_wiring.png">
<img title="Controller pinout" alt="pinout image" src="/doc/images/left_wiring1.png">
- Right board pinout
<img title="Controller pinout" alt="pinout image" src="/doc/images/right_wiring.png">
<img title="Controller pinout" alt="pinout image" src="/doc/images/right_wiring1.png">

## How to flash the firmware on Gimbal console controller
- Wiring to STLink2
    <img title="Controller pinout" alt="pinout image" src="/doc/images/STLink2_pinout.png">

    | Controller Debug | STLink2 |
    | --- | --- |
    |3.3V| VTref (1)|
    |GND  | GND (4)|
    |CLK  | SWCLK (9)|
    |DIO  | SWDIO (7)|
    |RST  | RESET (15)|

- Programming STM32 MCUs using STM32CubeProgrammer