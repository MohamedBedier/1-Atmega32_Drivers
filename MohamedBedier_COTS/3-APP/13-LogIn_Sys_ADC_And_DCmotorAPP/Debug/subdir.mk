################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Prog.c \
../CLCD_program.c \
../DCMotor_Program.c \
../DIO_Program.c \
../KPD_Program.c \
../LDR_Prog.c \
../LM35_Prog.c \
../MAP_Prog.c \
../PORT_Program.c \
../SSD_Prog.c \
../main.c 

OBJS += \
./ADC_Prog.o \
./CLCD_program.o \
./DCMotor_Program.o \
./DIO_Program.o \
./KPD_Program.o \
./LDR_Prog.o \
./LM35_Prog.o \
./MAP_Prog.o \
./PORT_Program.o \
./SSD_Prog.o \
./main.o 

C_DEPS += \
./ADC_Prog.d \
./CLCD_program.d \
./DCMotor_Program.d \
./DIO_Program.d \
./KPD_Program.d \
./LDR_Prog.d \
./LM35_Prog.d \
./MAP_Prog.d \
./PORT_Program.d \
./SSD_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


