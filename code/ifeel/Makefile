all:
	@echo "use 'make beos' or 'make linux'"

beos: support/usbkit/usb/USBKit.a
	gcc -o ifeel ifeel-beos.cpp -Isupport/usbkit/usb support/usbkit/usb/USBKit.a -lbe

# BeOS specific support
support/usbkit/usb/USBKit.a: support/usbkit/usb/Makefile
	cd support/usbkit/usb; make; cd ../../..

support/usbkit/usb/Makefile: support/usbkit_99-03-23.tgz
	cd support; tar -xzvf usbkit_99-03-23.tgz; cd ..

clean:
	rm -f *.o ifeel; rm -rf support/usbkit

# dead code
#mouse: mouse.o
#	$(CC) -o mouse mouse.o $(LIBS)

#CFLAGS 	= -O2 -Iusbkit/usb -Lusbkit/usb
#LIBS 	= USBKit.a -lbe
#CC	= gcc

#%.o: %.cpp
#	$(CC) $(CFLAGS) -c $<
	
