# stm32u545-classic-coremw-usb-host-fatfs

stm32u545 support for Classic Middleware STM32 Usb_Host and FatFs to access a USB Pen Drive.

Built using embedded software package STM32U5 v1.8 and STM32CUDEIDE v1.19.0<br>
This project is tested on the NUCLEO-U545RE-Q board.<br>
USB Pen drive must be formatted to FAT32.<br>

To check functionality using Debug :<br>
Add Appli_state and USBWriteOpEnable to the Live Expressions Watch Window.<br>
Appli_state will be APPLICATION_DISCONNECT initially when the USB Pen Drive is not connected.<br>
On Connecting the USB Pen Drive the Appli_state changes to APPLICATION_READY<br>
From the Watch Window set USBWriteOpEnable to 1. It will be immediately set back to 0 indicating sucessful operation.<br>
Unplug the USB Pen Drive and the Appli_state changes back to APPLICATION_DISCONNECT.<br>
Plug-in the USB Pen drive into the PC and check it's contents - TEMP.txt file containing the line "Welcome to EmbeTronicX!!!"<br>


The classic Middleware versions are ST USB Host Lib V3.5.1. and FatFs VR0.12c (ST modified 2023-08-18).<br>
The classic Middlewares are copied over from an F439 project built using embedded software package STM32F4 v1.28.3 and modified for STM32U5 v1.8<br>
Ref: https://github.com/NereusF1/stm32f439-usb-host-fatfs<br>
If interested in studying the changes made in the middleware, you can do a diff between the files in these two repositories.<br>
The changes were summarized below :<br>
a. replacing #include "stm32f4xx_hal.h" to #include "stm32u5xx_hal.h"<br>
b. replacing the F439 variables with equivalent U545 variables USB_OTG_FS  => USB_DRD_FS<br>
c. In ../USB_HOST/Target/usbh_conf.c<br>
1.  hhcd_USB_OTG_FS => hhcd_USB_DRD_FS <br>
2.  USB_OTG_FS => USB_DRD_FS <br>
3.  if(pHandle->hc[pipe].ep_is_in) => if(pHandle->hc[pipe].ch_dir) <br>
4.  Commented out HAL_HCD_MspInit() and HAL_HCD_MspDeInit() as they were defined by CUBEMX in stm32u5xx_hal_msp.c <br>


