#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
char n[11] = "LARANJA", c = '{';
int x;
for(x=1;x<strlen(n);x++){
  
  if(n[x] > c)
    c = n[x];
}
printf("Final c: %c", c);
}
