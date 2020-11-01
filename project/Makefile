# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: project.elf

#additional rules for files

project.elf: ${COMMON_OBJECTS} allMain.o stateMachines.o buzzer.o switches.o led.o p2_interrupt_handler.o wdInterruptHandler.o ..//project/timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: project.elf
	msp430loader.sh project.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h
