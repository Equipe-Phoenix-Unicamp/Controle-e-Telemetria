################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/src/ERU002/ERU002.c \
../Dave/Generated/src/ERU002/ERU002_Conf.c 

OBJS += \
./Dave/Generated/src/ERU002/ERU002.o \
./Dave/Generated/src/ERU002/ERU002_Conf.o 

C_DEPS += \
./Dave/Generated/src/ERU002/ERU002.d \
./Dave/Generated/src/ERU002/ERU002_Conf.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/src/ERU002/%.o: ../Dave/Generated/src/ERU002/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -DUC_ID=4502002 -DDAVE_CE -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Include" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Include" -I"C:\DAVE-3.1.10\ARM-GCC/arm-none-eabi/include" -I"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI/inc" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/XMC4500_series/Include" -I"C:\DAVE3_workspace\ws3.1.10\may\ERU001_ERU002_Example2\Dave\Generated\inc\LIBS" -I"C:\DAVE3_workspace\ws3.1.10\may\ERU001_ERU002_Example2\Dave\Generated\inc\DAVESupport" -I"C:\DAVE3_workspace\ws3.1.10\may\ERU001_ERU002_Example2\Dave\Generated\inc\MOTORLIBS" -O0 -ffunction-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


