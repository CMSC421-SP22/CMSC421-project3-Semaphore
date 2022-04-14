#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

struct node *head;

//static bb_buffer_421_t buffer;
static int bufferLength = 0;
static int readIndex = 0;
static int writeIndex = 0;

long init_buffer_421(void) {
	long function_completion = 0;

	if(head != NULL){
		printf("Buffer not empty, try to delete\n");
		function_completion = -1;
	}else
		// Initialize new buffer - 20 nodes
       		while((bufferLength >= SIZE_OF_BUFFER) && (function_completion != -1)){
			// Allocating new memory for each node, data = 0
			struct node_421 newNode; 
			newNode = malloc(sizeof(taskNode) * (5));
			newNode->data = 0;
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
        }
	temp->next = head;

	if((bufferLength < SIZE_OF_BUFFER) or (bufferLength > SIZE_OF_BUFFER)){
		printf("initializing failed\n");
		function_completion = -1;
	}
	//reset bufferLength for later initializing
	bufferLength = 0;
        return function_completion;
}


long insert_buffer_421(int i){
        long function_completion = 0;

	// check if buffer is initialized
	if(head == NULL){
		printf("uninitialized buffer\n");
		function_completion = -1;
	// Inserting fails if the buffer is already full
	}else if(ring_buffer_421->length == SIZE_OF_BUFFER){
		printf("Buffer is full\n");
		ring_buffer_421->write = head;
		function_completion = -1;
	// Insert the int i into the next node, increment bufferLength
	// Returns 0 if insert is successful, otherwise -1 if it fails

	//}else if((ring_buffer_421->write == head) && (ring_buffer_421->length == 0)){
	//	ring_buffer_421->write->data = i;
	//	ring_buffer_421->write = ring_buffer_421->write->next
	//	ring_buffer_421->length++;

	}else{
		//if((ring_buffer_421->write == head) && (ring_buffer_421->length == 0)){

		//if (ring_buffer_421->write == head){
		//	printf("\nBack to start, buffer full now\n");
		//	function_completion = -1;
		//}else{

               		ring_buffer_421->write->data = i;
        	        printf("\nring_buffer_421 inserted: %d", ring_buffer_421->write->data);
	                ring_buffer_421->write = (ring_buffer_421->write->next);
	                ring_buffer_421->length++;
			//successful insert
			function_completion = 0;
		//}
	}
	//printf("Something went wrong\n");
	return function_completition;
}

long print_buffer_421(void){
        long function_completion = 0;

	if(head == NULL){
		printf("buffer is emtpy, try to initialize\n");
		function_completion = -1;
	}else{
		printf("read buffer until it hits recent node\n");
		while(

	}


	printf("\nHere print the buffer\n");
	//fail return
	return -1;

	//successful return
        return 0;
}


long delete_buffer_421(void) {
        long function_completion = 0;

	//if buffer exists, delete
	if(head != NULL){
		// write your code to delete buffer and other unwanted components
        	temp = head;
		while(head != NULL){
			temp = head;
			head = head->next;
			free(temp);
		}
		printf("\nHere delete the buffer\n");
	}

	//double check if its really deleted
	if(head != NULL){
		function_completion = -1;
	}
	
	return function_completion;
}
