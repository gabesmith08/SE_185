// Richard Smith, se185 E, 8/29/2016
// LAB2-0.c : Defines the entry point for the console application.

#include<stdio.h>

int main(int argc, char* argv []){
int x, y, z;
printf("Enter a width:");
scanf("%d",&x);
printf("Enter a height:");
scanf("%d",&y);
printf("Enter a length:");
scanf("%d",&z);
printf("A %d by %d by %d prism is %d\n", x,y,z,x*y*z);
return 0;
}