PROG=blink
SRC=$(PROG).c

# modify according to the device file under /dev, /dev/tty.usbmodemNNN under mac for example.                                                                                   
DUE_USB_DEV=/dev/ttyUSB0
UNO_USB_DEV=/dev/ttyACM0

# modify if the libarduino directory is different than what's below.
LIBARDUINO_PATH=/opt/libarduino

# change to $(AVRDUDE_DUE) if necessary.
AVRDUDE=$(AVRDUDE_UNO) 

include /opt/libarduino/build/arduino.mk

clean:
	-rm -f *.o *.elf *.map
	-rm -f $(PROG)






