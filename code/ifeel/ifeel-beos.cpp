/* ifeel-beos.cpp
   BeOS program to play with the iFeel mouse
   more info at http://moore.cx/dan/out/ifeel
   this code based on ftp://ftp.be.com/pub/samples/usb_kit/usbkit_99-03-23.tgz;examples/mouse.cpp
   compile with "gcc -o ifeel ifeel-beos.cpp -Iusbkit/usb usbkit/usb/USBKit.a -lbe"
*/
#include <USBKit.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 5) {
    printf("Usage: %s <usbdevice> <intensity 0-255> <delay 0-255ms> <count 1-255ms>\n", argv[0]);
    return 1;
    }

  USBDevice ifeel(argv[1]);

  if (ifeel.InitCheck() != B_OK) {
    printf("Error initializing mouse (%s)\n", argv[1]);
    return 2;
    }

  uchar vibrate_cmd[7] = {0x11, 0x0a, atoi(argv[2]), atoi(argv[3]), 0x00, atoi(argv[4]), 0x00};
  uchar abort_cmd[7] = {0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  ifeel.ControlTransfer(0x21, 0x09, 0x0200, 0x0000, 7, vibrate_cmd);

  return 0;
}
