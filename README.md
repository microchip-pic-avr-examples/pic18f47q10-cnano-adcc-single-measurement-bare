[![MCHP](images/microchip.png)](https://www.microchip.com)

# PIC18F47Q10 ADCC Single Conversion Configuration Example

The PIC18F47Q10 features one 10-bit ADCC module.
In this demo, the ADCC peripheral is used to read a value from an analog pin connected to a potentiometer.

## Related Documentation

- [TB3263 - Getting Started with ADCC for PIC18](https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en1002103)
- [PIC18F-Q10 Family Product Page](https://www.microchip.com/design-centers/8-bit/pic-mcus/device-selection/pic18f-q10-product-family)
- [PIC18F47Q10 Data Sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/40002043D.pdf)
- [TB3261 - PIC1000: Getting Started with Writing C-Code for PIC16 and PIC18](https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en1002117)

## Software Used
- MPLAB® X IDE 5.30 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® XC8 2.10 or a newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
- MPLAB® Code Configurator (MCC) 3.95.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- MPLAB® Code Configurator (MCC) Device Libraries PIC10 / PIC12 / PIC16 / PIC18 MCUs [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- Microchip PIC18F-Q Series Device Support (1.4.109) or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/)

## Hardware Used
- PIC18F47Q10 Curiosity Nano [(DM182029)](https://www.microchip.com/Developmenttools/ProductDetails/DM182029)
- Curiosity Nano Base for Click boards™ [(AC164162)](https://www.microchip.com/Developmenttools/ProductDetails/AC164162)
- POT Click board™ [(MIKROE-3402)](https://www.mikroe.com/pot-click)

## Setup
The PIC18F47Q10 Curiosity Nano Development Board is used as test platform, along with the Curiosity Nano Base for Click boards™ and the POT Click board™.

The project uses the ADCC peripheral running from its dedicated clock.

The following pin configurations must be made for this project:

| Pin          | Configuration      |
| :----------: | :----------------: |
| RA0          | Analog Input       |

<img src="images/HWsetup.png" alt="Hardware Setup" width="480"/>

## Operation:
1. Connect the board to the PC.

2. Open the *pic18f47q10-cnano-adcc-single-measurement-bare.X* project in MPLAB® X IDE.

3. Set *pic18f47q10-cnano-adcc-single-measurement-bare* project as main project. Right click on the project in the *Projects* tab and click *Set as Main Project*:
<br><img src="images/ADCC-single-meas-bare-main-project.png" width="600">

4. Select the *PIC18F47Q10 Curiosity Nano* in the *Hardware Tool* section of the project settings:
  - Right click on the project and click *Properties*;
  - Select the *PIC18F47Q10 Curiosity Nano* (click on the SN) in the *Hardware Tool* tab and then click *OK*:
<br><img src="images/ADCC-single-meas-bare-tool-settings.png" width="600">


5. Run the code in debug mode: right click on the project and click *Debug*.
<br><img src="images/ADCC-single-meas-bare-debug.png" width="600">


6. Pause the debug process by clicking the *Pause* button (or click *Debug -> Pause* in the Menu bar):
<br><img src="images/ADCC-single-meas-bare-debug-pause.png" width="600">


7. Add *adcVal* variable to the *Variables window*: right click on the `adcVal` variable in main.c file and click *New Watch*:
<br><img src="images/ADCC-single-meas-bare-variable.png" width="600">


The ADC value on RA0 pin will be read only once, before the program gets to the infinite loop. The value of `adcVal` will reflect the potentiometer position.
<br><img src="images/ADCC-single-meas-bare-variable-value.png" width="600">

## Summary
This project showcases how the Analog-to-Digital Converter with Computation (ADCC) on the new PIC18-Q10 can be used to read an analog value from a pin.
