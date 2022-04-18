#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#include "buffer_sem.h"

int max_exec = 30; // max # of times it will produce/consume

void* thread_producer(void* arg){

	int *incoming = (char *)
	char charValue = incoming+'0';

	


	sleep(rand() % 11);
	//lock enqueue if its full?
	printf("Produced\n");

}

void* thread_consumer(void*arg){


}

int main(int argc, char *argv[]) {

	void *thread_result;
	int num_value = 0;
	int time_exec = 0;
	int prod_cons_exec = 0;
	// 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0

	//printf("Example of full buffer scenario\n");
	long init_state = init_buffer_421();
	printf("init finished, %ld\n", init_state);

	//sem_init(&mutex, 0, 1);
	pthread_t tid_producer;
	pthread_t tid_consumer;

	//if produce enques 4 times -> consume will enque 4 times (randomizer = same for both called)
	while(time_exec != max_exec){

		prod_cons_exec = (rand() % 20);
		for(
		pthread_create(tid_produce, NULL, thread_producer, num_value)
		pthread_create(tid_consumer, NULL, thread_consumer, num_value)
	
		num_value++;
		if(num_value == 10){
			num_value = 0;
		}

	}

	long del_state = delete_buffer_421();
	//printf("Delete finished, %ld\n",del_state);

	///////////////////////////////////////////////

	return 0;
}
