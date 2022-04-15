#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

struct node_421* head = NULL;
struct ring_buffer_421* buffer = NULL;

int bufferLength = 0;
int readIndex = 0;
int writeIndex = 0;
int size_of_buffer = 20;

long init_buffer_421(void) {
	long function_completion = 0;
	if(head != NULL){
		printf("Buffer not empty, try to delete\n");
		function_completion = -1;
	}else{
		printf("else\n");
		// Initialize new buffer - 20 nodes
       		while((bufferLength < SIZE_OF_BUFFER) && (function_completion != -1)){
			// Allocating new memory for each node, data = 0
			printf("Make new node\n");
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
				printf("Inserted new node as head\n");
			}else{
				struct node_421 *temp = head;
				while(temp->next != NULL){
					temp=temp->next;
				}
				printf("New node added in ring buffer\n");
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
		temp->next = head->next;
	}
	printf("buffer node\n");
	//make start buffer
	struct ring_buffer_421* buff_node;
	buff_node = (struct ring_buffer_421*) malloc (sizeof(struct ring_buffer_421));
	buffer = buff_node;
	buffer->length = 0;
	buffer->read = head;
	buffer->write = head;

	printf("Done here\n");
	printf("buffersize %d\n", bufferLength);
	if((bufferLength < SIZE_OF_BUFFER) || (bufferLength > SIZE_OF_BUFFER)){
		printf("initializing failed\n");
		function_completion = -1;
	}
	//reset bufferLength for later initializing
	bufferLength = 0;
	printf("\n\n\n");
        return function_completion;
}


long insert_buffer_421(int i){
        long function_completion = 0;

	// check if buffer is initialized, fail if not
	if(head == NULL){
		printf("uninitialized buffer\n");
		function_completion = -1;
	// Inserting fails if the buffer is already full
	}else if(buffer->length == SIZE_OF_BUFFER){
		printf("Buffer is full\n");
		buffer->write = head;
		function_completion = -1;
	// Insert the int i into the next node, increment buffer length
	// Returns 0 if insert is successful, otherwise -1 if it fails
	}else{
		//regular insert into buffer
		struct node_421* temp = buffer->write;
               	temp->data = i;
        	printf("ring_buffer_421 inserted: %d\n", temp->data);
	        buffer->write = temp->next;
	        buffer->length++;
		//successful insert
		function_completion = 0;
	}
	return function_completion;
}

long print_buffer_421(void){
	printf("\n\n\n");
        long function_completion = 0;
	// check if buffer is initialized, fail if not
	if(head == NULL){
		printf("buffer is emtpy, try to initialize\n");
		function_completion = -1;
	// reader is up to date, nothing to print
	}else if((buffer->read == buffer->write) && (buffer->read != head) && (buffer->length == SIZE_OF_BUFFER)){
		printf("read is same as write\n");
		function_completion = -1;
	}else{
		struct node_421* temp;
		printf("read buffer until it hits recent node\n");
		temp = buffer->read;
                fprintf(stdout, "Node data: %d\n",temp->data); 
                buffer->read = temp->next;

		while(buffer->read != buffer->write){
			temp = buffer->read;
			fprintf(stdout, "Node data: %d\n",temp->data); 
			buffer->read = temp->next;
		}
		printf("successful read\n");
		function_completion = 0;
	}
	printf("about to exit print function\n");


        return function_completion;
}


long delete_buffer_421(void) {
        printf("\n\n\n");
	long function_completion = 0;
	int round = SIZE_OF_BUFFER;

	printf("Enter deletion\n");
	printf("size number %d\n", buffer->length);

	free(buffer);
	buffer = NULL;
	printf("Free buffer\n");
	//if buffer exists, delete
	if(head != NULL){
		// write your code to delete buffer and other unwanted components
		struct node_421* temp;
        	temp = head;
		while(round != 0){
			temp = head;
			head = temp->next;
			printf("Delete temp\n");
			free(temp);
		round--;
		}
		printf("\nHere delete the buffer\n");
	}
	head = NULL;

	//double check if its really deleted
	if(head != NULL){
		function_completion = -1;
	}
	return function_completion;
}
