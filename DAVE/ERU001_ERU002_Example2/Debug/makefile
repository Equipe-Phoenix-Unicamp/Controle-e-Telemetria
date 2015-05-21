################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Lib/subdir.mk
-include Dave/Generated/src/RESET001/subdir.mk
-include Dave/Generated/src/NVIC002/subdir.mk
-include Dave/Generated/src/LIBS/subdir.mk
-include Dave/Generated/src/IO004/subdir.mk
-include Dave/Generated/src/IO002/subdir.mk
-include Dave/Generated/src/ERU002/subdir.mk
-include Dave/Generated/src/ERU001/subdir.mk
-include Dave/Generated/src/DAVESupport/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ERU001_ERU002_Example2.hex \

SECONDARY_LIST += \
ERU001_ERU002_Example2.lst \

SECONDARY_SIZE += \
ERU001_ERU002_Example2.siz \


# All Target
all: ERU001_ERU002_Example2.elf secondary-outputs

# Tool invocations
ERU001_ERU002_Example2.elf: $(OBJS) ../ERU001_ERU002_Example2.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC C Linker'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -T"../ERU001_ERU002_Example2.ld" -nostartfiles -L"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Lib" -L"C:\DAVE-3.1.10\eclipse\/../Examples/Lib" -L"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI" -Wl,-Map,"ERU001_ERU002_Example2.map" -mcpu=cortex-m4 -mthumb -g3 -gdwarf-2 -o "ERU001_ERU002_Example2.elf" "@makefile.rsp" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ERU001_ERU002_Example2.hex: ERU001_ERU002_Example2.elf
	@echo 'Invoking: ARM-GCC Create Flash Image'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objcopy" -O ihex "ERU001_ERU002_Example2.elf"  "ERU001_ERU002_Example2.hex"
	@echo 'Finished building: $@'
	@echo ' '

ERU001_ERU002_Example2.lst: ERU001_ERU002_Example2.elf
	@echo 'Invoking: ARM-GCC Create Listing'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objdump" -h -S "ERU001_ERU002_Example2.elf" > "ERU001_ERU002_Example2.lst"
	@echo 'Finished building: $@'
	@echo ' '

ERU001_ERU002_Example2.siz: ERU001_ERU002_Example2.elf
	@echo 'Invoking: ARM-GCC Print Size'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-size"  --format=berkeley ERU001_ERU002_Example2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(SECONDARY_FLASH)$(S_DEPS)$(ARM_GCC_FOR_XMC_LINKER_OUTPUT_TYPE_OUTPUTS)$(SECONDARY_LIST) ERU001_ERU002_Example2.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
