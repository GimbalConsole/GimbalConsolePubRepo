# BaseCam Gimbal Console Controller Guideline
<br />This document describes the useful info for the test of hardware and update the firmware in development process

## Table of Contents
- [Gimbal Console development workflow](#gimbal-console-development-workflow)
- [Pinout of the PCBs & Pinmap for wiring](#pinout-of-the-PCBs-&-Pinmap-for-wiring)
- [How to flash the firmware on Gimbal console controller](#how-to-flash-the-firmware-on-gimbal-console-controller)
    - Wiring to STLink2
    - Programming STM32 MCUs using STM32CubeProgrammer
    - Programming STM32 MCUs using Gimbal Bootloader
- [Uart driver installation on Lattepanda](#uart-driver-installationtutorial)
- [Installing the Application with the latest update](#installing-the-application-with-the-latest-update)
- [Device firmware upgarde with the latest updated firmware](#device-firmware-upgarde-with-the-latest-updated-firmware)
- [How to run SimpleBGC_GUI desktop application on Ubuntu 22.04](#how-to-run-simplebgc_gui-desktop-application-on-ubuntu-2204)

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
    - application version sync - note in [[version.txt](https://github.com/GimbalConsole/GimbalConsoleApp2/blob/master/version.txt)]
    - application releases[[Download](https://github.com/GimbalConsole/GimbalConsolePubRepo/releases)]

## Pinout of the PCBs & Pinmap for wiring
- Controller board pinout
![Alt text](./doc/images/controller_wiring.png)
![Alt text](./doc/images/controller_wiring1.png)
![Alt text](./doc/images/controller_wiring2.png)
- Left board pinout
![Alt text](./doc/images/left_wiring.png)
![Alt text](./doc/images/left_wiring1.png)
- Right board pinout
![Alt text](./doc/images/right_wiring.png)
![Alt text](./doc/images/right_wiring1.png)

## How to flash the firmware on Gimbal console controller?
- Wiring to STLink2
    ![Alt text](./doc/images/STLink2_pinout.png)

    | Controller Debug | STLink2 |
    | --- | --- |
    |3.3V| VTref (1)|
    |GND  | GND (4)|
    |CLK  | SWCLK (9)|
    |DIO  | SWDIO (7)|
    |RST  | RESET (15)|

- Programming STM32 MCUs using STM32CubeProgrammer
---


- Programming STM32 MCUs using Gimbal Bootloader
---

## UART Driver installation[[Tutorial](https://docs.lattepanda.com/content/3rd_delta_edition/drivers_and_software/#in-ubuntu-os)]
    
- Download the Arduino IDE 1.8.16.
- Unzip the downloaded arduino
    <Container><Preview>
        <pre><code class="language-html"><backify-button>tar -xvf arduino-1.8.16-linux64.tar.xz</backify-button>
        </code>
        </pre>
    </Preview></Container>
- Move the Arduino IDE to the /opt directory
    <Container><Preview>
        <pre><code class="language-html"><backify-button>sudo mv arduino-1.8.16 /opt</backify-button>
        </code>
        <code class="language-html"><backify-button>cd /opt/arduino-1.8.16</backify-button>
        </code>
        <code class="language-html"><backify-button>sudo ./install.sh</backify-button>
        </code>
        </pre>
    </Preview></Container>
- Add the current user to the dialout group for permission issue
    <Container><Preview>
        <pre><code class="language-html"><backify-button>sudo usermod -a -G dialout $USER</backify-button>
        </code>
        </pre>
    </Preview></Container>
- Download the LattePanda Leonardo configuration files from Dropbox Link or Google Drive Link. Then unzip it
    - download and then unzip configuration files
    [[Download from Dropbox](https://www.dropbox.com/s/2s60p70v6ewmkbh/LattePanda%20Leonardo%20Configuration%20Files.zip?dl=0)]
    [[Download from Google Drive](https://drive.google.com/file/d/1rfrUShz9Y8ZYq2rywhecdoYYGGes5IEM/view?usp=sharing)]
    - Enter into "Arduino IDE Files" folder, copy "avr-0.0.3" folder to "/opt/arduino-1.8.16/hardware"
    <Container><Preview><pre><code class="language-html"><backify-button>cp avr-0.0.3 /opt/arduino-1.8.16/hardware</backify-button></code></pre></Preview></Container>
    <img title="arduino" alt="select port" src="https://docs.lattepanda.com/assets/images/CyLPLeoFile.webp">
- Run Arduino IDE，Open “Tool” menu，Choose “Board：xxx” -> “LattePanda AVR Boards”->“LattePanda Leonardo”
<img title="arduino" alt="select port" src="https://docs.lattepanda.com/assets/images/LPLeoBoardUbuntu.webp">

- Choose the serial port: “Port: /dev/ttyACM0 xxx” -> “/dev/ttyACM0(LattePanda Leonardo)”.
<img title="arduino" alt="select port" src="https://docs.lattepanda.com/assets/images/LPLeonardoPortUbuntu.webp">

- Download the code(Schetch/Upload). [[Download](https://github.com/GimbalConsole/LattepandaLeonardo/blob/master/GimbalConsole_leonardo.ino)]

- Compile the code and Upload firmware

## Installing the Application with the latest update

- download app_update.sh script

    - download the script by using git
    <Container><Preview><pre><code class="language-html"><backify-button>git clone https://github.com/GimbalConsole/GimbalConsolePubRepo.git</backify-button></code></pre></Preview></Container>

- run app_update.sh script 
    <Container><Preview>
        <pre><code class="language-html"><backify-button>cd GimbalConsolePubRepo</backify-button>
        </code>
        <code class="language-html"><backify-button>./app_update.sh</backify-button>
        </code>
        </pre>
    </Preview></Container>

    ![Alt text](./doc/images/app_update_script.png)

## Device firmware upgarde with the latest updated firmware

- download app_update.sh script on your local

    - download the script by using git
    <Container><Preview><pre><code class="language-html"><backify-button>git clone https://github.com/GimbalConsole/FirmwareConsolePubRepo.git</backify-button></code></pre></Preview></Container>

- run firmware_update.sh script 
    <Container><Preview>
    <Container><Preview><pre><code class="language-html"><backify-button>cd FirmwareConsolePubRepo</backify-button></code></pre></Preview></Container>
    <Container><Preview><pre><code class="language-html"><backify-button>chmod 777 firmware_update.sh</backify-button></code></pre></Preview></Container>
    </Preview></Container> 
    <Container><Preview><pre><code class="language-html"><backify-button>./firmware_update.sh</backify-button></code></pre></Preview></Container>
    </Preview></Container>

    ![Alt text](./doc/images/firmware_update_script0.png)
    ![Alt text](./doc/images/firmware_update_script1.png)

## How to run SimpleBGC_GUI desktop application on Ubuntu 22.04

- install java runtime
    - download [install_java_runtime.sh](https://github.com/GimbalConsole/GimbalConsolePubRepo/blob/main/install_java_runtime.sh) 

    <Container><Preview><pre><code class="language-html"><backify-button>chmod +x install_java_runtime.sh</backify-button></code></pre></Preview></Container>
    </Preview></Container>
    <Container><Preview><pre><code class="language-html"><backify-button>./install_java_runtime.sh</backify-button></code></pre></Preview></Container>
    </Preview></Container>

    ![Alt text](./doc/images/install_java_runtime.png)
    <br/>

- download the application from the [basecamelectronics](https://www.basecamelectronics.com/files/SimpleBGC_GUI_2_70b0.zip).

- run SimpleBGC_GUI desktop application

    <Container><Preview><pre><code class="language-html"><backify-button>bash run.sh</backify-button></code></pre></Preview></Container>
    </Preview></Container>
    ![Alt text](./doc/images/run_basecam_desktop_app.png)
    
