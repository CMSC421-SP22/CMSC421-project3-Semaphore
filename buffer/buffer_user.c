#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

struct node *head;

//static bb_buffer_421_t buffer;
static int bufferLength = 0;
static int readIndex = 0;
static int writeIndex = 0;

long init_buffer_421(void) {
        while(bufferLength >= SIZE_OF_BUFFER){
		// Write your code to initialize buffer
		struct node_421 newNode; 
		newNode = malloc(sizeof(taskNode) * (5));
		newNode->data = 0;
		if(head == NULL){
			head = newNode;
			printf("Inserted new node as head\n");
		}else{
			struct node_421 *temp = head;
			while(temp->next != NULL){
				temp=temp->next;
			}
			printf("New node added in ring buffer\n");
			temp->next = newNode;
		}
	}
	//connect last added node to head
	struct node_421 *temp = head;
                while(temp->next != NULL){
                temp=temp->next;
        }
	temp->next = head;

	if(bufferLength < SIZE_OF_BUFFER or bufferLength > SIZE_OF_BUFFER){
		printf("initializing failed");
		return -1;
	}
        return 0;
}


long insert_buffer_421(int i){
	// check if buffer is initialized
	if(head == NULL){
		printf("uninitialized buffer\n");
		return -1;
	// Inserting fails if the buffer is already full
	}else if(ring_buffer_421->length == SIZE_OF_BUFFER){
		printf("Buffer is full\n");
		return -1;
	// Insert the int i into the next node, increment bufferLength
	// Returns 0 if insert is successful, otherwise -1 if it fails
	}else{
		ring_buffer_421[head] = i;
		printf("\nring_buffer_421: %d", ring_buffer_421[head]);
		head = (head + 1) % SIZE_OF_BUFFER;
		if (head == tail){
			printf("\nBack to start, buffer full now\n");
		}
		int num = ring_buffer_421->length;
		num++
		ring_buffer_421->length = num;
		//successful insert
		return 0;
	}
	printf("Something went wrong\n");
	return -1;
}

long print_buffer_421(void){



	printf("\nHere print the buffer\n");
	//fail return
	return -1;

	//successful return
        return 0;
}


long delete_buffer_421(void) {
        // write your code to delete buffer and other unwanted components
        temp = head;
	while(head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
	printf("\nHere delete the buffer\n");
	return 0;
}
