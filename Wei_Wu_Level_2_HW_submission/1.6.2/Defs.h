#ifndef DEFS_H
#define DEFS_H
#include <stdio.h>
#define PRINT1(x) printf("a:%d\n",x)
#define PRINT2(x,y) printf("a:%d,b:%d\n",x,y)
#define MAX2(x,y) (x>y?x:y)	//if x > y, return x, or return y
#define MAX3(x,y,z) (MAX2(x,y)>MAX2(y,z)?MAX2(x,y):MAX2(y,z))	//if the maximum value of X and Y is greater than 
																//the maximum value of Y and Z, return the maximum value of X and Y,
																//or return maximum value of Z and Y
#endif