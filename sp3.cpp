#include <iostream>
#include <stdio.h>
#include <cstdlib>
 
int main() {
	int t,i;
	int n=5;
	int x[n][n];
printf ("massiv:");
printf ("\n");
	for(t=0; t<n; ++t)
		for (i=0; i<n; ++i)
			x[t][i] = rand() % 9+9;
	for (t=0; t<n; ++t)
	{
		for (i=0; i<n; ++i)
			printf("%d  ",x[t][i]);
			printf ("\n");}
printf ("\n");
printf ("new massiv:");
printf ("\n");
asm(
	"mov %[n],%%eax\n\t"
	"dec %%eax\n\t"
	"mov %%eax,%[i]\n\t"
	"end_asm:\n\t"
	: [i]"=m"(i)
	: [n]"m"(n)
	: "%eax");
    for (t=0;t < n;t++)
{ 
        for (int k=i;k >= 0;k--)
{
        printf("%d  ",x[k][t]);}
printf ("\n");
}
    return 0;
}
