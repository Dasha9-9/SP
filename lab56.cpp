#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <mutex>
#include <cstdlib>
#include <fstream>
using namespace std;

ofstream out;

pthread_mutex_t m;

struct thread_data { 
    int id;
    int x;
    int y;
};

void *ball (void *arg){
    thread_data *ball;
    ball = (struct thread_data *) arg;
    int i = ball->id;
	int x = ball->x;
	int y = ball->y;
	int timer = 0;
	while ((x < 51) && (x > 0) && (y < 51) && (y > 0)){
		x = x + (rand() % 10 - 5);
		y = y + (rand() % 10 - 5);
		sleep(1);
		timer++;
	}
	pthread_mutex_lock(&m);
	    cout << "Ball №" << i << " out in " << timer << " sec!" << endl;
	    out.open("logs", ios::app);
	    out << "Ball №" << i << " out in " << timer << " sec!" << endl;
	    out.close();
	pthread_mutex_unlock(&m);
	pthread_exit(NULL);
}

int main(){
    pthread_mutex_init(&m,NULL);
	int num_balls;
	cout << "Enter number of balls: ";
	cin >> num_balls;
	thread_data *koor = new thread_data[num_balls];
	pthread_t *thread = new pthread_t[num_balls];
	for (int i = 0; i < num_balls; i++){
		koor[i].x = rand() % 15 + 15;
		koor[i].y = rand() % 15 + 15;
		koor[i].id = i+1;
		pthread_create(&thread[i], NULL, ball, (void *)&koor[i]);
	}
	for(int i = 0; i < num_balls; i++ ) {
        pthread_join(thread[i],NULL);
    }
}	
