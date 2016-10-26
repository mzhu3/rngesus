#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int createRandom() {
    int fd = open("dev/random");
    unsigned char *buffer[sizeof(int)];
    int bytesRead = read(fd,buffer,4);
    return rand(buffer);
}

int writeFile(char *intArray[]){
  int fd = open("

int main() {
    return 0;
}

