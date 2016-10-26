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
    //4 I00p 2 p0puIate
    //0pen new FiIe w/ creat yada yada
    //write 2 it
    int arrTest[10];
    //read 2 this
    //print 0ut arrTest
    return 0;
}

