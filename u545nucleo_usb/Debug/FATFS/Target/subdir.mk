################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FATFS/Target/usbh_diskio.c 

OBJS += \
./FATFS/Target/usbh_diskio.o 

C_DEPS += \
./FATFS/Target/usbh_diskio.d 


# Each subdirectory must supply rules for building sources it contributes
FATFS/Target/%.o FATFS/Target/%.su FATFS/Target/%.cyclo: ../FATFS/Target/%.c FATFS/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32U545xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32U5xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/FATFS/Target" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/FATFS/App" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/USB_HOST/App" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/USB_HOST/Target" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/Muddlewares/Third_Party/FatFs/src" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/Muddlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.19.0/u545nucleo_usb/Muddlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FATFS-2f-Target

clean-FATFS-2f-Target:
	-$(RM) ./FATFS/Target/usbh_diskio.cyclo ./FATFS/Target/usbh_diskio.d ./FATFS/Target/usbh_diskio.o ./FATFS/Target/usbh_diskio.su

.PHONY: clean-FATFS-2f-Target

