################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
powerWindow_LightCOntrol.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
powerWindow_LightCOntrol.list \

OBJCOPY_BIN += \
powerWindow_LightCOntrol.bin \


# All Target
all: powerWindow_LightCOntrol.elf secondary-outputs

# Tool invocations
powerWindow_LightCOntrol.elf: $(OBJS) $(USER_OBJS) D:\STM32CubeIDE\workspace_1.0.2\powerWindow_LightCOntrol\STM32F429ZITX_FLASH.ld
	arm-none-eabi-gcc -o "powerWindow_LightCOntrol.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\STM32CubeIDE\workspace_1.0.2\powerWindow_LightCOntrol\STM32F429ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="powerWindow_LightCOntrol.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

powerWindow_LightCOntrol.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "powerWindow_LightCOntrol.list"
	@echo 'Finished building: $@'
	@echo ' '

powerWindow_LightCOntrol.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "powerWindow_LightCOntrol.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
