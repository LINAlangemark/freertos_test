################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ARMGCC

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./controller.o" \
"./debugger.o" \
"./event_groups.o" \
"./file.o" \
"./gpio.o" \
"./led_state.o" \
"./led_task.o" \
"./list.o" \
"./main.o" \
"./messages.o" \
"./queue.o" \
"./str_debugger.o" \
"./sw_task.o" \
"./swtimers.o" \
"./systick.o" \
"./tasks.o" \
"./timers.o" \
"./tm4c123gh6pm_startup_ccs_gcc.o" \
"./uart_config.o" \
"./uart_rx_task.o" \
"./uart_tx_task.o" \
"./drivers/buttons.o" \
"./drivers/rgb.o" \
"./portable/GCC/ARM_CM4F/port.o" \
"./portable/MemMang/heap_2.o" \
-Wl,-T"../tm4c123gh6pm.lds" \
$(GEN_CMDS__FLAG) \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include drivers/subdir_vars.mk
-include portable/GCC/ARM_CM4F/subdir_vars.mk
-include portable/MemMang/subdir_vars.mk
-include subdir_rules.mk
-include drivers/subdir_rules.mk
-include portable/GCC/ARM_CM4F/subdir_rules.mk
-include portable/MemMang/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
rb_2.out 

EXE_OUTPUTS__QUOTED += \
"rb_2.out" 


# All Target
all: $(OBJS) $(LDS_SRCS) $(A_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "rb_2.out"

# Tool invocations
rb_2.out: $(OBJS) $(LDS_SRCS) $(A_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"C:/ARMGCC/bin/arm-none-eabi-gcc-14.2.1.exe" -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -Dgcc -DTARGET_IS_TM4C123_RB1 -Os -ffunction-sections -fdata-sections -fsingle-precision-constant -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -mcpu=cortex-m4 -Wl,-Map,"rb_2.map" -Wl,--gc-sections -mfloat-abi=hard -mfpu=fpv4-sp-d16 -o"rb_2.out" $(ORDERED_OBJS) $(A_SRCS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "controller.o" "debugger.o" "event_groups.o" "file.o" "gpio.o" "led_state.o" "led_task.o" "list.o" "main.o" "messages.o" "queue.o" "str_debugger.o" "sw_task.o" "swtimers.o" "systick.o" "tasks.o" "timers.o" "tm4c123gh6pm_startup_ccs_gcc.o" "uart_config.o" "uart_rx_task.o" "uart_tx_task.o" "drivers\buttons.o" "drivers\rgb.o" "portable\GCC\ARM_CM4F\port.o" "portable\MemMang\heap_2.o" 
	-$(RM) "controller.d" "debugger.d" "event_groups.d" "file.d" "gpio.d" "led_state.d" "led_task.d" "list.d" "main.d" "messages.d" "queue.d" "str_debugger.d" "sw_task.d" "swtimers.d" "systick.d" "tasks.d" "timers.d" "tm4c123gh6pm_startup_ccs_gcc.d" "uart_config.d" "uart_rx_task.d" "uart_tx_task.d" "drivers\buttons.d" "drivers\rgb.d" "portable\GCC\ARM_CM4F\port.d" "portable\MemMang\heap_2.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

