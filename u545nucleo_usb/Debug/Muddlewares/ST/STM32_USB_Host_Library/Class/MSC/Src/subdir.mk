################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c \
../Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c \
../Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c 

OBJS += \
./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.o \
./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.o \
./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.o 

C_DEPS += \
./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.d \
./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.d \
./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.d 


# Each subdirectory must supply rules for building sources it contributes
Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/%.o Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/%.su Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/%.cyclo: ../Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/%.c Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32U545xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32U5xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/FATFS/Target" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/FATFS/App" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/USB_HOST/App" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/USB_HOST/Target" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/Muddlewares/Third_Party/FatFs/src" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/Muddlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Muddlewares-2f-ST-2f-STM32_USB_Host_Library-2f-Class-2f-MSC-2f-Src

clean-Muddlewares-2f-ST-2f-STM32_USB_Host_Library-2f-Class-2f-MSC-2f-Src:
	-$(RM) ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.cyclo ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.d ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.o ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.su ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.cyclo ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.d ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.o ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.su ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.cyclo ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.d ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.o ./Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.su

.PHONY: clean-Muddlewares-2f-ST-2f-STM32_USB_Host_Library-2f-Class-2f-MSC-2f-Src

