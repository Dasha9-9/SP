#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h> 

using namespace std;

int main(int argc, char* argv[]){ 
	int i = atoi(argv[0]); 
	int x = atoi(argv[1]); 
	int y = atoi(argv[2]); 
	while ((x < 51) && (x > 0) && (y < 51) && (y > 0)){ 
		x = x + (rand() % 10 - 5); 
		y = y + (rand() % 10 - 5); 
		sleep(1); 
	}
	cout << "Ball №" << i << " out!" << endl;
	exit(0); 
}
