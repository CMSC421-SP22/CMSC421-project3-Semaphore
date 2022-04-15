#include <linux/kernel.h>
#include <linux/syscalls.h>
#include "buffer.h"

// Global variables
struct node_421* head = NULL;
struct ring_buffer_421* buffer = NULL;
int bufferLength = 0;

SYSCALL_DEFINE0(hello) {
	printk("Hello World!\n");
	return 0;
}

SYSCALL_DEFINE0(init_buffer_421){
	long function_completion = 0;
	if(head != NULL){
		printk("Buffer not empty, try to delete\n");
		function_completion = -1;
	}else{
		// Initialize new buffer - 20 nodes
       		while((bufferLength < SIZE_OF_BUFFER) && (function_completion != -1)){
			// Allocating new memory for each node, data = 0
			struct node_421* newNode; 
			newNode =(struct node_421*) kmalloc(sizeof(struct node_421), GFP_KERNEL);
			newNode->data = 0;
			newNode->next = NULL;
			if(newNode == NULL){
				printk("Error!\n");
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
	buff_node = (struct ring_buffer_421*) kmalloc(sizeof(struct ring_buffer_421), GFP_KERNEL);
	buffer = buff_node;
	buffer->length = 0;
	buffer->read = head;
	buffer->write = head;

	if((bufferLength < SIZE_OF_BUFFER) || (bufferLength > SIZE_OF_BUFFER)){
		printk("initializing failed\n");
		function_completion = -1;
	}
	//reset bufferLength for later initializing
	bufferLength = 0;
        return function_completion;
}

SYSCALL_DEFINE0(insert_buffer_421){
        long function_completion = 0;
	// check if buffer is initialized, fail if not
	if(head == NULL){
		printk("uninitialized buffer\n");
		function_completion = -1;
	// Inserting fails if the buffer is already full
	}else if(buffer->length == SIZE_OF_BUFFER){
		printk("Buffer is full, unable to add\n");
		buffer->write = head;
		function_completion = -1;
	// Insert the int i into the next node, increment buffer length
	// Returns 0 if insert is successful, otherwise -1 if it fails
	}else{
		//regular insert into buffer
		struct node_421* temp = buffer->write;
               	temp->data = i;
	        buffer->write = temp->next;
	        buffer->length++;

		//successful insert
		function_completion = 0;
	}
	return function_completion;
}

SYSCALL_DEFINE0(print_buffer_421){
        long function_completion = 0;
	// check if buffer is initialized, fail if not
	if(head == NULL){
		printk("Unable to print: buffer is emtpy, try to initialize\n");
		function_completion = -1;
	// reader is up to date, nothing to print
	}else if((buffer->read == buffer->write) && (buffer->read != head) && (buffer->length == SIZE_OF_BUFFER)){
		printk("Unable to print: read is same as print\n");
		function_completion = -1;
	}else{
		// insert new data and move write pointer up
		struct node_421* temp;
		temp = buffer->read;
                printk("Node data: %d\n",temp->data);
                buffer->read = temp->next;
		while(buffer->read != buffer->write){
			temp = buffer->read;
			fprintf(stdout, "Node data: %d\n",temp->data);
			buffer->read = temp->next;
		}
		function_completion = 0;
	}
        return function_completion;
}

SYSCALL_DEFINE0(delete_buffer_421){
	long function_completion = 0;
	int round = SIZE_OF_BUFFER;
	//checks if buffer exist
	if(head != NULL){
		kfree(buffer);
		buffer = NULL;
		//if buffer exists, delete
		// write your code to delete buffer and other unwanted components
		struct node_421* temp;
        	temp = head;
		while(round != 0){
			temp = head;
			head = temp->next;
			kfree(temp);
			round--;
		}
		head = NULL;
	}else{
                printk("No buffer exists\n");
                function_completion = -1;
	}

	//double check if its really deleted
	if(head != NULL){
		function_completion = -1;
	}
	return function_completion;
}
