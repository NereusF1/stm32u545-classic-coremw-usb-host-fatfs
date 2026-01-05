# stm32u545-classic-coremw-usb-host-fatfs

stm32u545 support for Classic Middleware STM32 Usb_Host and FatFs to access a USB Pen Drive.

Built using embedded software package STM32U5 v1.8 and STM32CUDEIDE v1.19.0<br>
This project is tested on the NUCLEO-U545RE-Q board.<br>
USB Pen drive must be formatted to FAT32.<br>

The classic Middleware versions are ST USB Host Lib V3.5.1. and FatFs VR0.12c (ST modified 2023-08-18).
The classic Middlewares are copied over from an F439 project built using embedded software package STM32F4 v1.28.3

To check functionality using Debug :<br>
Add Appli_state and USBWriteOpEnable to the Live Expressions Watch Window.<br>
Appli_state will be APPLICATION_DISCONNECT initially when the USB Pen Drive is not connected.<br>
On Connecting the USB Pen Drive the Appli_state changes to APPLICATION_READY<br>
From the Watch Window set USBWriteOpEnable to 1. It will be immediately set back to 0 indicating sucessful operation.<br>
Unplug the USB Pen Drive and the Appli_state changes back to APPLICATION_DISCONNECT.<br>
Plug-in the USB Pen drive into the PC and check it's contents - TEMP.txt file containing the line "Welcome to EmbeTronicX!!!"<br>
