################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/src/CNT001/CNT001.c \
../Dave/Generated/src/CNT001/CNT001_Conf.c 

OBJS += \
./Dave/Generated/src/CNT001/CNT001.o \
./Dave/Generated/src/CNT001/CNT001_Conf.o 

C_DEPS += \
./Dave/Generated/src/CNT001/CNT001.d \
./Dave/Generated/src/CNT001/CNT001_Conf.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/src/CNT001/%.o: ../Dave/Generated/src/CNT001/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -DDAVE_CE -DUC_ID=4502002 -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Include" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Include" -I"C:\DAVE-3.1.10\ARM-GCC/arm-none-eabi/include" -I"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI/inc" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/XMC4500_series/Include" -I"C:\Users\Carlos\Documents\GitHub\Controle-e-Telemetria\DAVE\Feather-PonteH\Dave\Generated\inc\DAVESupport" -I"C:\Users\Carlos\Documents\GitHub\Controle-e-Telemetria\DAVE\Feather-PonteH\Dave\Generated\inc\MOTORLIBS" -I"C:\Users\Carlos\Documents\GitHub\Controle-e-Telemetria\DAVE\Feather-PonteH\Dave\Generated\inc\LIBS" -O0 -ffunction-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


