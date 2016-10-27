#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "main.h"
#include <sys/stat.h>
int createRandom() {
  int fd = open("/dev/random",O_RDONLY);
    int buffer;
    read(fd,&buffer,4);
    close(fd);
    return buffer;
}
//test for similarity
/*char * same(int*a1[], int *a2[]){
  int a = memcmp(a1,a2,sizeof(a1));
  char *yes = "all match!";
  char *no = "Not all same";
  if(!a){
    return yes;
  }
  return no;
  }*/
int main() {
    int arr[10];
    int i;
    printf("Initializing array:\n");
    for (i = 0; i < 10; i++) {
        arr[i] = createRandom();
    }
    printf("printing array:\n");
    int k;
    for (k = 0; k < 10; k++) {
      printf("arr[%d]: %d\n",k,arr[k]);
    }
    printf("Original Array Done!-------------------\n\n");
    printf("Creating new file:\n");
    
    umask(0000);
     printf("New file created !-------------------\n\n");
     
    int fd = open("openMe.no", O_CREAT|O_RDWR|O_TRUNC, 0666);
    printf("Copying data into new file:\n");
    write(fd,arr,40);
    close(fd);
    
    printf("printing new array:\n");
    fd = open("openMe.no",O_RDONLY);
    int arrTest[10];
    read(fd,arrTest,40);
    for (i = 0; i < 10; i++) {
      printf("arrTest[%d]: %d\n",i,arrTest[i]);
    }
    //printf("check similarity:\n:");
    //printf("All match?\n%s\n", same(arr,arrTest));
    return 0;
}

