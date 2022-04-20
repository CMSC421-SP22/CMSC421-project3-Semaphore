#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#include "buffer_sem.h"

// Global variables
struct bb_node_421* head = NULL;
struct bb_buffer_421* buffer = NULL;
int bufferLength = 0;

pthread_cond_t consumer_empty;
pthread_cond_t producer_full;
pthread_mutex_t mutex;
int nfull = 0;

long init_buffer_421(void){
        long function_completion = 0;
        if(head != NULL){
                printf("Buffer not empty, try to delete\n");
                function_completion = -1;
        }else{
                pthread_cond_init(&consumer_empty, 0, 20);
                pthread_cond_init(&producer_full, 0, 0);
                pthread_mutex_init(&mutex, NULL);
                // Initialize new buffer - 20 nodes
                while((bufferLength < SIZE_OF_BUFFER) && (function_completion != -1)){
                        // Allocating new memory for each node, data = 0
                        struct bb_node_421* newNode;
                        newNode =(struct bb_node_421*) malloc(sizeof(struct bb_node_421));
                        newNode->data[DATA_LENGTH];
                        newNode->next = NULL;
			if(newNode == NULL){
				printf("Error!\n");
				function_completion = -1;
			}else if(head == NULL){
				head = newNode;
				bufferLength++;
			}else{
				struct bb_node_421 *temp = head;
				while(temp->next != NULL){
					temp=temp->next;
				}
				temp->next = newNode;
				bufferLength++;
			}
		}
		//connect last added node to head
		struct bb_node_421* temp = head;
                while(temp->next != NULL){
                	temp=temp->next;
			//temp->next = head;
        	}
		temp->next = head;
	}
	//make start buffer
	struct bb_buffer_421* buff_node;
	buff_node = (struct bb_buffer_421*) malloc (sizeof(struct bb_buffer_421));
	buffer = buff_node;
	buffer->length = 0;
	buffer->read = head;
	buffer->write = head;

	if((bufferLength < SIZE_OF_BUFFER) || (bufferLength > SIZE_OF_BUFFER)){
		printf("initializing failed\n");
		function_completion = -1;
	}
	//reset bufferLength for later initializing
	bufferLength = 0;
        return function_completion;
}

long enqueue_buffer_421(char *data){
        /////////////////////////
        // copy of part 1
        // enqueue ;; producer
        /////////////////////////
        long function_completion = 0;
        if(head == NULL){
                printf("uninitialized buffer\n");
                function_completion = -1;
        // Insert the int i into the next node, increment buffer length
        // Returns 0 if insert is successful, otherwise -1 if it fails
        }else{
                if(nfull == SIZE_OF_BUFFER){
                        pthread_cond_wait(&consumer_empty);
                        pthread_mutex_lock(&mutex);
                        //sem_wait(&mutex);
                }else{
                struct bb_node_421* temp = buffer->write;
                strcpy(buffer->write->data, data);
                buffer->write = temp->next;

                int l = buffer->length;
                buffer->length = (l + 1)%20;
		nfull++

		pthread_mutex_unlock(&mutex);
                pthread_cond_signal(&producer_full);
                }

                function_completion = 0;
        }
        return function_completion;
}


long dequeue_buffer_421(char *data){
        ///////////////////////
        /// dequeue ;; consumer
        ///////////////////////
        long function_completion = 0;
        // check if buffer is initialized, fail if not
        if(head == NULL){
                printf("uninitialized buffer\n");
                function_completion = -1;
        }else{
		
               	if(nfull == 0){
                        pthread_cond_wait(&producer_full);
                        pthread_mutex_lock(&mutex);
                }else{
                	struct bb_node_421* temp = buffer->read;
                	buffer->read->data[0] = 0;
                	buffer->read = temp->next;
                	int l = buffer->length;
                	buffer->length = (l - 1)%20;
			nfull--;

                	pthread_mutex_unlock(&mutex);
                	pthread_cond_signal(&consumer_empty);

                	function_completion = 0;
                }

        }
        return function_completion;

}

long delete_buffer_421(void){
        long function_completion = 0;
        int round = SIZE_OF_BUFFER;
        //checks if buffer exist

        pthread_cond_destroy(&consumer_empty);
        pthread_cond_destroy(&producer_full);
        pthread_mutex_destroy(&mutex);
	//sem_destroy(&mutex);

        if(head != NULL){
                free(buffer);
                buffer = NULL;
                //if buffer exists, delete
                // write your code to delete buffer and other unwanted components
                struct bb_node_421* temp;
                temp = head;
                while(round != 0){
                        temp = head;
                        head = temp->next;
                        free(temp);
                        round--;
                }

                head = NULL;
        }else{
                printf("No buffer exists\n");
                function_completion = -1;
        }

        //double check if its really deleted
        if(head != NULL){
                function_completion = -1;
        }
        return function_completion;

}

