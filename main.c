#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "main.h"

int createRandom() {
    int fd = open("dev/random");
    unsigned char *buffer[sizeof(int)];
    int bytesRead = read(fd,buffer,4);
    return rand(buffer);
}

int main() {
    int arr[10];
    int i;
    for (i = 0; i < 10; i++) {
        arr[i] = createRandom();
    }
    int fd = open("openMe.no", O_CREAT, 0666);
    write(fd,arr,40);
    int arrTest[10];
    read(fd,arrTest,40);
    for (i = 0; i < 10; i++) {
        printf("arrTest[%d]: %d",i,arrTest[i]);
    }
    return 0;
}

