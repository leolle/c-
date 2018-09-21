/* Predict what will be printed on the screen */
#include <stdio.h>
#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line
// Create and initialse array
int a[]={0, 1, 2, 3, 4};
int main()
{
	int i;
	int* p;
	for (i=0; i<=4; i++) PRD(a[i]); // print the content of array a: 01234
	NL;
	for (p=&a[0]; p<=&a[4]; p++) PRD(*p);	
	//p points to the first address of array a initially, 
	//if the address stored in p is less than or equal to fifth address of array a, 
	//p points to the next array element address,
	//so it will print the content of array a: 01234
	NL;
	NL;
	for (p=&a[0], i=0; i<=4; i++) PRD(p[i]); 
	//p points to the first address of array a initially, counter i is set to 0.
	//if the counter i is less than or equal to 4, print the content of p pointing to,
	//finally p will point to a[0],a[1],a[2],a[3],a[4], which is equal to *(p+0),*(p+1),*(p+2),*(p+3),*(p+4),


	NL;
	for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); 
	//p points to the first address of array a initially, counter is set to 0,
	//when the address stored in p plus i is less than or equal to the address of array a[4], 
	//print the content of stored at address p+i, then address stored in p increments, so does the counter i.
	//so p+i would point to a[0],a[2],a[4], at last content stored at address &a[0],&a[2],&a[4] will be printed.
	NL;
	NL;
	for (p=a+4; p>=a; p--) PRD(*p); 
	//p points to the last address of array a initially, which is &a[4].
	//if address stored in p is greater than or equal to &a[0], print the content which p pointing to,
	//then the address stored in p decrements.
	//so p will point to a[4],a[3],a[2],a[1],a[0].
	NL;
	for (p=a+4, i=0; i<=4; i++) PRD(p[-i]); 
	//p points to the last address of array a initially, which is &a[4], counter is set to 0.
	//if the counter i is less than or equal to 4, print the content of p pointing to,
	//so p will point to a[4],a[3],a[2],a[1],a[0], which is equal to *(p-0),*(p-1),*(p-2),*(p-3),*(p-4),

	NL;
	for (p=a+4; p>=a; p--) PRD(a[p-a]); 
	//p points to the last address of array a initially, which is &a[4].
	//if address stored in p is greater than or equal to &a[0], because p-a=  &a[4] -  &a[0] = 4, 
	//then the difference is set as the index of array a, it will print a[4],
	//then address stored in p decrements.
	//at last it will print a[4],a[3],a[2],a[1],a[0].
	NL;
	return 0;
}