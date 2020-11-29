# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toymain.elf

#additional rules for files

toymain.elf: ${COMMON_OBJECTS} allMain.o stateMachines.o buzzer.o switches.o led.o p2_interrupt_handler.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toymain.elf
	msp430loader.sh toymain.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h buzzer.h switches.h

stateMachines.o: led.h stateMachines.h buzzer.h

buzzer.o: buzzer.h
