#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#include "buffer_mon.h"

int max_exec = 3; // max # of times it will produce/consume

int main(int argc, char *argv[]) {
        void *thread_result;
        int data_value = 0;
        int data_value_down = 0;
        char * char_data_value;
        int time_exec = 0;
        int prod_cons_exec = 0;
        long init_state = 0;

        init_state = init_buffer_421();
        //printf("init finished, %ld\n", init_state);

        pthread_t tid_producer;
        pthread_t tid_consumer;

        for(int i = 0; i < max_exec; i++){
                time_exec = (rand() % 10);
                // Producer thread
                printf(".....Printing producer/enqueue now.....\n");
		for(int i = 0; i < time_exec; i++){
                        sleep(rand() % 11);
                        char test_char[DATA_LENGTH] = {data_value};
                        pthread_create(&tid_producer, NULL, (void *)enqueue_buffer_421, &test_char);
                        printf("Producer: %d\n", data_value);

                        data_value++;
                        if(data_value >= 10){
                                data_value = 0;
                        }

                        pthread_join(tid_producer, NULL);
                }


                printf(".....waiting to print consumer/enqueue.....\n");
		printf("%d\n", (data_value - time_exec));

                //revert data-value for consumer
                if((data_value - time_exec) < 0){
                        int temp_n = 0;
                        while(data_value != 0){
                                data_value++;
                                temp_n++;
                        }
                        temp_n = temp_n % 10;
                        data_value = 9 - temp_n;
		}else{
                        data_value = (data_value - time_exec) % 10;
                }

                //Consumer thread
                for(int i = 0; i < time_exec; i++){
                        sleep(rand() % 11);
                        char test_char[DATA_LENGTH] = {data_value};
                        pthread_create(&tid_consumer, NULL, (void *)dequeue_buffer_421, &test_char);
                        printf("Consumer: %d\n", data_value);
                        data_value++;
                        if(data_value >= 10){
                                data_value = 0;
                        }
                        pthread_join(tid_consumer, NULL);
                }
        }

        long del_state = delete_buffer_421();
        printf("Successful Delete of the buffer: %ld\n",del_state);

        return 0;
}
