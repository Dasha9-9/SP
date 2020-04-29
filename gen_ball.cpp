#include <unistd.h>
#include <sys/wait.h> 
#include <stdio.h> 
#include <iostream>

using namespace std;

int main(){
	int x, y; 
	int stat, flag; 
	int num_balls; 
	cout << "Enter number of balls: ";
	cin >> num_balls; 
	int *pid = new int[num_balls];
	for (int i = 0; i < num_balls; i++){ 
		x = rand() % 15 + 15; 
		y = rand() % 15 + 15; 
		pid[i] = fork(); 
		if (pid[i] == -1){ 
			cout << "Error" << endl; 
			exit(1);
		}
		else if(pid[i] == 0){ 
			execl("ball",(to_string(i)).c_str(), (to_string(x)).c_str(), (to_string(y)).c_str(), NULL); 
			exit(0); 
		}
	}
	do {
		flag = 0; 
		for (int i = 0; i < num_balls; i++){ 
			if (waitpid(pid[i], &stat, WNOHANG) == 0) flag = 1; 
		}
	} while (flag == 1); 
	cout << "all balls out" << endl; 
}
