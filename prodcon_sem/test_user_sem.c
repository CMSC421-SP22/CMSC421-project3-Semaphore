#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#include "buffer_sem.h"

int max_exec = 1; // max # of times it will produce/consume


int main(int argc, char *argv[]) {

        void *thread_result;
        int data_value = 0;
        char * char_data_value;
        int time_exec = 0;
        int prod_cons_exec = 0;
        // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0

        int num[10] = {0,1,2,3,4,5,6,7,8,9};
	long init_state = 0;

        //printf("Example of full buffer scenario\n");
        init_state = init_buffer_421();
        printf("init finished, %ld\n", init_state);

        //sem_init(&mutex, 0, 1);
        pthread_t tid_producer;
        pthread_t tid_consumer;

	char test_char[DATA_LENGTH];
	test_char[0] = 0;

	int result = 0;

        //if produce enques 4 times -> consume will enque 4 times (randomizer = same for both called)
        while(time_exec != max_exec){

                pthread_create(&tid_producer, NULL, (void *)enqueue_buffer_421, (char *)&test_char) == 0);
		sleep(2);
                pthread_create(&tid_consumer, NULL, (void *)dequeue_buffer_421, (char *)&test_char) == 0);


		pthread_join(tid_producer, NULL);

		pthread_join(tid_consumer, NULL);



		/*
                prod_cons_exec = 25;
		//(rand() % 10);
		printf("number exec: prod_cons_exec %d \n", prod_cons_exec);

                for(int i = 0; i < prod_cons_exec; i++){
                        //char_data_value = data_value+'0';

			//printf("set new array before enqueue\n");
                        test_char[0] = data_value;
			pthread_create(&tid_producer, NULL, (void *)enqueue_buffer_421, (char *)&test_char) == 0);

			printf("Produced: %d\n", data_value);
                        pthread_join(tid_producer, result);


			data_value++;
                       	if(data_value == 10){
                              data_value = 0;
                       	}

				printf("Insert full: test \n");

		}

		if(data_value != 0){
			data_value = data_value - 1;
		}

             	for(int i = 0; i < prod_cons_exec; i++){
			test_char[0] = 0;
			//printf("execute dequeue \n");
		        pthread_create(&tid_consumer, NULL, (void *)dequeue_buffer_421, (char *)&test_char) == 0);

			printf("Consumer: %d\n", data_value);
                        pthread_join(tid_consumer, NULL);


			//pthread_join(tid_consumer, NULL);

			//printf("Consumed: &d\n", test_char[0]);

			data_value--;
                	if(data_value == -1){
                                data_value = 9;
                        }


				printf("consumer full halt\n");

			//for(int i = 0; i < prod_cons_exec; i++){
			//	pthread_join(tid_producer, NULL);
      			//	pthread_join(tid_consumer, NULL);
			//}


			//pthread_join(tid_producer, NULL);
			//pthread_join(tid_consumer, NULL);

                }

		printf("\n\n\n");

		//data_value = data_value - prod_cons_exec;

		/*
               	for(int i = 0; i < prod_cons_exec; i++){
			printf("Produced: %d\n", data_value);
                       	pthread_join(tid_producer, NULL);
               		data_value++;
                        if(data_value == 9){
                                data_value = 0;
                        }

		}

		data_value = data_value - 1;

               	for(int i = 0; i < prod_cons_exec; i++){
        		printf("Consumer: %d\n", data_value);
	               	pthread_join(tid_consumer, NULL);
			data_value--;
                        if(data_value == -1){
                                data_value = 9;
                        }
               	}


		time_exec++;
       */


	


	}

	//pthread_join(tid_producer, NULL);
	//pthread_join(tid_consumer, NULL);

	/*
	for(int i = 0; i < prod_cons_exec; i++){
        	pthread_join(tid_producer, NULL);
               //}

               //for(int i = 0; i < prod_cons_exec; i++){
                pthread_join(tid_consumer, NULL);
       	}
	*/


	long del_state = delete_buffer_421();
	printf("Delete finished, %ld\n",del_state);

	///////////////////////////////////////////////

	return 0;
}
