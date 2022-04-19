#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#include "buffer.h"

// Global variables
struct node_421* head = NULL;
struct ring_buffer_421* buffer = NULL;
int bufferLength = 0;

sem_t consumer_empty;
sem_t producer_full;
sem_t mutex;

long init_buffer_421(void){
	long function_completion = 0;
	if(head != NULL){
		printf("Buffer not empty, try to delete\n");
		function_completion = -1;
	}else{
		int sem_init(consumer_empty, 0, 20);
		int sem_init(producer_full, 0, 0)


		// Initialize new buffer - 20 nodes
       		while((bufferLength < SIZE_OF_BUFFER) && (function_completion != -1)){
			// Allocating new memory for each node, data = 0
			struct node_421* newNode; 
			newNode =(struct node_421*) malloc(sizeof(struct node_421));
			newNode->data = 0;
			newNode->next = NULL;
			if(newNode == NULL){
				printf("Error!\n");
				function_completion = -1;
			}else if(head == NULL){
				head = newNode;
				bufferLength++;
			}else{
				struct node_421 *temp = head;
				while(temp->next != NULL){
					temp=temp->next;
				}
				temp->next = newNode;
				bufferLength++;
			}
		}
		//connect last added node to head
		struct node_421 *temp = head;
                while(temp->next != NULL){
                	temp=temp->next;
			//temp->next = head;
        	}
		temp->next = head;
	}
	//make start buffer
	struct ring_buffer_421* buff_node;
	buff_node = (struct ring_buffer_421*) malloc (sizeof(struct ring_buffer_421));
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
		sem_wait(mutex);
		sem_wait(producer_full);
		//carried out so that the consumer process cannot interfere
		function_completion = -1;
	// Insert the int i into the next node, increment buffer length
	// Returns 0 if insert is successful, otherwise -1 if it fails
	}else{
		//regular insert into buffer
		struct node_421* temp = buffer->write;
               	temp->data = data;
	        buffer->write = temp->next;
	        buffer->length++;
		//successful insert

		sem_post(mutex);
		sem_post(producer_full);
		sem_post(consumer_empty);
		//if item is put in, signal operation is carried out on mutex and full - consumer 
		// can now act

		// print info
		printf("Enqueue: %c", temp->data);
		print_semaphores();

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
		sem_wait(consumer_empty);
		sem_wait(mutex);
		//producer cannot interfere
		function_completion = -1;
	}else{
		struct node_421* temp = buffer->read;
		char temp_data = temp->data;
		temp->data = 0;
		buffer->read = temp->next;
		buffer->length--;
		function_completion = 0;

		//unlock sem, consumer can now act
		sem_post(mutex);
		sem_post(consumer_empty);
		sem_post(producer_full);

		//print info
		printf("Dequeue: %c", temp_data);
                print_semaphores();

		function_completion = -1;
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
		struct node_421* temp;
        	temp = head;
		while(round != 0){
			temp = head;
			head = temp->next;
			free(temp);
			round--;
		}

		sem_destroy(consumer_empty);
		sem_destroy(producer_full);
		sem_destroy(mutex);

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
	long_completion = 0;
	if(head == NULL){
		printf("Unable to print: buffer is empty, try to initialize\n");
		function_completion = -1;
	}else{
		printf("sema mutex = %d", sem_getvalue(mutex, int *valp));
		printf("\n");
		printf("sema fill_count = %d", buffer->length));
		printf("\n");
		int size = SIZE_OF_BUFFER:
		printf("sema empty_count = %d", (size - buffer->length));
		printf("\n");
	}
}
