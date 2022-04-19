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

sem_t consumer_empty;
sem_t producer_full;
pthread_mutex_t mutex;


long init_buffer_421(void){
	long function_completion = 0;
	if(head != NULL){
		printf("Buffer not empty, try to delete\n");
		function_completion = -1;
	}else{
		sem_init(&consumer_empty, 0, 0);
		sem_init(&producer_full, 0, 0);

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
	//int num = data + '0';
	// check if buffer is initialized, fail if not
	if(head == NULL){
		printf("uninitialized buffer\n");
		function_completion = -1;
	// Inserting fails if the buffer is already full
	}else if(buffer->length == SIZE_OF_BUFFER){
		printf("Buffer is full, unable to add\n");
		//////////////
                // sem lock //
                //////////////
		//pthread_mutex_lock(&mutex);
		sem_wait(&producer_full);
		//sem_wait(&producer_full);
		sem_post(&consumer_empty);
		//carried out so that the consumer process cannot interfere
		function_completion = -1;
	// Insert the int i into the next node, increment buffer length
	// Returns 0 if insert is successful, otherwise -1 if it fails
	}else{
		//sem_post(&producer_full);
		//printf("before insert\n");
		//sem_wait(&consumer_empty);
		//regular insert into buffer
		struct bb_node_421* temp = buffer->write;
               	//printf("Before copy\n");
		strcpy(buffer->write->data, data);
	        buffer->write = temp->next;
	        buffer->length++;
		//successful insert


		//sem_wait(&consumer_empty);
		//printf("insert success\n");
		//printf("Enqueue: %c", data[0]);
                //print_semaphores();

		//pthread_mutex_unlock(&mutex);
		sem_post(&producer_full);
		//sem_post(&consumer_empty);
		//if item is put in, signal operation is carried out on mutex and full - consumer 
		// can now act

		// print info
		printf("Enqueue: %c\n", data[0]);
		print_semaphores();

		//sem_post(&producer_full);

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
	}else if(buffer->length == 0){
		// buffer is empty
		////////////////////////////
		// sem lock 
		// Producer cannot interfere
		////////////////////////////
		//sem_post(&consumer_empty);
		//sem_wait(&consumer_empty);
		//sem_post(&producer_full);
		sem_wait(&consumer_empty);
		sem_post(&producer_full);
		//pthread_mutex_lock(&mutex);
		function_completion = -1;
	}else{
		//sem_wait(&producer_full);
		struct bb_node_421* temp = buffer->read;
		char temp_data[DATA_LENGTH];
		strcpy(temp_data, buffer->read->data);
		buffer->read->data[0] = 0;
		buffer->read = temp->next;
		buffer->length--;
		function_completion = 0;

		//sem_wait(&producer_full);

		//unlock sem, consumer can now act
		//pthread_mutex_unlock(&mutex);
		//printf("Dequeue: %c", temp_data[0]);
                //print_semaphores();

		//sem_post(&consumer_empty);
		//sem_post(&consumer_empty);

		//print info
		printf("Dequeue: %c\n", temp_data[0]);
                print_semaphores();

		sem_post(&consumer_empty);

		function_completion = 0;
	}
	return function_completion;

}

long delete_buffer_421(void){
	long function_completion = 0;
	int round = SIZE_OF_BUFFER;
	//checks if buffer exist
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

		sem_destroy(&consumer_empty);
		sem_destroy(&producer_full);
		pthread_mutex_destroy(&mutex);

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

void print_semaphores(void){
	// print status of semaphore
	if(head == NULL){
		printf("Unable to print: buffer is empty, try to initialize\n");
	}else{

		//printf("sema mutex = %d", sem_getvalue(&mutex, int *valp));
		//printf("\n");
		printf("sema fill_count = %d", buffer->length);
		printf("\n");
		int size = SIZE_OF_BUFFER;
		printf("sema empty_count = %d", (size - buffer->length));
		printf("\n");
	}
}
