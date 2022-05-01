#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define  MIDI_DEVICE  "/dev/midi3"

int main(void) {
    unsigned char c[4];
    int fd = open(MIDI_DEVICE, O_RDONLY);
    if (fd == -1) {
        printf("Error: cannot open %s\n", MIDI_DEVICE);
        exit(1);
    } 

    while (1) {
        read(fd, &c, sizeof(c));
        printf("%c\n", c[1] + 'a');
    }
      
   return 0;
}
