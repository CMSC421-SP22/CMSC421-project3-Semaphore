#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#include "buffer_sem.h"

int max_exec = 3; // max # of times it will produce/consume


int main(int argc, char *argv[]) {

        void *thread_result;
        int data_value = 0;
        char * char_data_value;
        int time_exec = 0;
        int prod_cons_exec = 0;
        // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0

        int num[10] = {0,1,2,3,4,5,6,7,8,9}
	
        //printf("Example of full buffer scenario\n");
        long init_state = init_buffer_421();
        printf("init finished, %ld\n", init_state);

        //sem_init(&mutex, 0, 1);
        pthread_t tid_producer;
        pthread_t tid_consumer;

        //if produce enques 4 times -> consume will enque 4 times (randomizer = same for both called)
        while(time_exec != max_exec){

                prod_cons_exec = (rand() % 20);

                for(int i = 0; i < prod_cons_exec; i++){
                        char_data_value = data_value+'0';
                        pthread_create(tid_produce, NULL, enqueue_buffer_421, char_data_value);
                        data_value++;
                        if(data_value == 10){
                                data_value = 0;
                        }
                }

                for(int i = 0; i < prod_cons_exec; i++){
                        pthread_create(tid_consumer, NULL, thread_consumer, num_value);
                }

                for(int i = 0; i < prod_cons_exec; i++){
                        pthread_join(tid_produce, NULL);
                }

                for(int i = 0; i < prod_cons_exec; i++){
                        pthread_join(tid_consumer, NULL);
                }

        }


	long del_state = delete_buffer_421();
	//printf("Delete finished, %ld\n",del_state);

	///////////////////////////////////////////////

	return 0;
}
