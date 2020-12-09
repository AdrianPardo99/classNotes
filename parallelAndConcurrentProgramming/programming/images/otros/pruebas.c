#include <stdio.h>
#include <stdlib.h>
int check_is_prime(int a){
  if(a==0){
    return 0;
  }else if(a==1){
    return 1;
  }
  register int i;
  for(i=2;i<a;i++){
    if(a%i==0){
      return 0;
    }
  }
  return 1;
}
int main(int argc,char **argv){
  if(argc<2){
    exit(EXIT_FAILURE);
  }
  printf("%s %s\n",*(argv+1),check_is_prime(atoi(*(argv+1)))?"S":"N");
  return 0;
}
