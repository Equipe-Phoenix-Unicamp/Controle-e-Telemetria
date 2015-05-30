################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Lib/subdir.mk
-include Dave/Generated/src/SYSTM002/subdir.mk
-include Dave/Generated/src/LIBS/subdir.mk
-include Dave/Generated/src/IO004/subdir.mk
-include Dave/Generated/src/DAVESupport/subdir.mk
-include Dave/Generated/src/CLK001/subdir.mk
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
PWMSP001_Example1_RelaxKit.hex \

SECONDARY_LIST += \
PWMSP001_Example1_RelaxKit.lst \

SECONDARY_SIZE += \
PWMSP001_Example1_RelaxKit.siz \


# All Target
all: PWMSP001_Example1_RelaxKit.elf secondary-outputs

# Tool invocations
PWMSP001_Example1_RelaxKit.elf: $(OBJS) ../PWMSP001_Example1_RelaxKit.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC C Linker'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -T"../PWMSP001_Example1_RelaxKit.ld" -nostartfiles -L"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Lib" -L"C:\DAVE-3.1.10\eclipse\/../Examples/Lib" -L"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI" -Wl,-Map,"PWMSP001_Example1_RelaxKit.map" -mcpu=cortex-m4 -mthumb -o "PWMSP001_Example1_RelaxKit.elf" "@makefile.rsp" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PWMSP001_Example1_RelaxKit.hex: PWMSP001_Example1_RelaxKit.elf
	@echo 'Invoking: ARM-GCC Create Flash Image'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objcopy" -O ihex "PWMSP001_Example1_RelaxKit.elf"  "PWMSP001_Example1_RelaxKit.hex"
	@echo 'Finished building: $@'
	@echo ' '

PWMSP001_Example1_RelaxKit.lst: PWMSP001_Example1_RelaxKit.elf
	@echo 'Invoking: ARM-GCC Create Listing'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objdump" -h -S "PWMSP001_Example1_RelaxKit.elf" > "PWMSP001_Example1_RelaxKit.lst"
	@echo 'Finished building: $@'
	@echo ' '

PWMSP001_Example1_RelaxKit.siz: PWMSP001_Example1_RelaxKit.elf
	@echo 'Invoking: ARM-GCC Print Size'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-size"  --format=berkeley PWMSP001_Example1_RelaxKit.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(SECONDARY_FLASH)$(S_DEPS)$(ARM_GCC_FOR_XMC_LINKER_OUTPUT_TYPE_OUTPUTS)$(SECONDARY_LIST) PWMSP001_Example1_RelaxKit.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
