################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
portable/MemMang/%.o: ../portable/MemMang/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ARMGCC/bin/arm-none-eabi-gcc-14.2.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -Dgcc -DTARGET_IS_TM4C123_RB1 -I"C:/ti/rb_2" -I"C:/ti/rb_2" -I"C:/ti/rb_2/include" -I"C:/ti/rb_2/portable/GCC/ARM_CM4F" -I"C:/ti/tivaware_SW-EK-TM4C123GXL-2.1.4.178.exe" -I"C:/ARMGCC/arm-none-eabi/include" -Os -ffunction-sections -fdata-sections -fsingle-precision-constant -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"portable/MemMang/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


