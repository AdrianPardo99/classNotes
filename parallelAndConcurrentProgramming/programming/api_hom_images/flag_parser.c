#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int get_processing_type(int argc,char **argv){
  int c;
  while((c=getopt(argc,argv,"cth"))!=-1){
    switch (c) {
      case 'c':
        return 1;
      break;
      case 't':
        return 0;
      break;
      case 'h':
        printf("Welcome to the API image proccessing the option of app is:\n\t"
        "-c:\tConcurrent solution\n\t-t:\tThread solution\n");
        return -1;
      break;
    }
  }
  return 0;
}
