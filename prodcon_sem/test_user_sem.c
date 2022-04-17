#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#include "buffer_sem.h"

sem_t mutex;

void* thread_producer(void* arg){

	sleep(rand() % 11);
	//lock enqueue if its full?
	sem_wait(&mutex);
	printf("Produced\n");

}

void* thread_consumer(void* arg){

        sleep(rand() % 11);

        printf("Consume\n");
        sem_post(&mutex);

}


int main(int argc, char *argv[]) {

	printf("Example of full buffer scenario\n");
	long init_state = init_buffer_421();
	//printf("init finished, %ld\n", init_state);

	sem_init(&mutex, 0, 1);
	pthread_t tid_producer;
	pthread_t tid_consumer;
	

	for(int i = 0; i <10; i++){

		sleep(rand() % 11);
		// enqueue function here

		sleep(rand() % 11);
		// dequeue function here
	}


	long print_status = print_buffer_421();
	//printf("print finished, %ld\n", print_status);

	long del_state = delete_buffer_421();
	//printf("Delete finished, %ld\n",del_state);

	///////////////////////////////////////////////

	return 0;
}
