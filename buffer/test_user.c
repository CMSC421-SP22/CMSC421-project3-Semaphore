#include <stdio.h>
#include <unistd.h>
#include <string.h>
//#include <errno.h>
//#include <linux/kernel.h>
//#include <sys/syscall.h>

#include "buffer.h"

int main(int argc, char *argv[]) {

	printf("Example of full buffer scenario\n");
	long init_state = init_buffer_421();
	//printf("init finished, %ld\n", init_state);

	long insert_state = insert_buffer_421(1);
	insert_state = insert_buffer_421(2);
        insert_state = insert_buffer_421(3);
        insert_state = insert_buffer_421(4);
        insert_state = insert_buffer_421(5);
        insert_state = insert_buffer_421(6);
        insert_state = insert_buffer_421(7);
        insert_state = insert_buffer_421(8);
        insert_state = insert_buffer_421(9);
        insert_state = insert_buffer_421(10);
        insert_state = insert_buffer_421(11);
        insert_state = insert_buffer_421(12);
        insert_state = insert_buffer_421(13);
        insert_state = insert_buffer_421(14);
        insert_state = insert_buffer_421(15);
        insert_state = insert_buffer_421(16);
        insert_state = insert_buffer_421(17);
        insert_state = insert_buffer_421(18);
        insert_state = insert_buffer_421(19);
        insert_state = insert_buffer_421(20);
        insert_state = insert_buffer_421(21);
        insert_state = insert_buffer_421(22);
        insert_state = insert_buffer_421(23);
        //printf("Insert finished, %ld\n", insert_state);

	long print_status = print_buffer_421();
	//printf("print finished, %ld\n", print_status);

	long del_state = delete_buffer_421();
	//printf("Delete finished, %ld\n",del_state);

	///////////////////////////////////////////////////

	printf("\n\n\n");
	printf("Example of somewhat filled buffer\n");
	init_state = init_buffer_421();
        //printf("init finished, %ld\n", init_state);

        insert_state = insert_buffer_421(1);
        insert_state = insert_buffer_421(2);
        insert_state = insert_buffer_421(3);
        insert_state = insert_buffer_421(4);

	print_status = print_buffer_421();
        //printf("print finished, %ld\n", print_status);

        del_state = delete_buffer_421();
        //printf("Delete finished, %ld\n",del_state);


	///////////////////////////////////////////////////

	printf("\n\n\n");
	printf("Example of empty buffer\n");
	printf("Insert into empty buffer\n");
	insert_state = insert_buffer_421(1);
	printf("Insert finished, %ld\n\n", insert_state);

	printf("Print empty buffer\n");
	print_status = print_buffer_421();
	printf("print finished, %ld\n\n", print_status);

	printf("Delete empty buffer\n\n");
	del_state = delete_buffer_421();
        printf("Delete finished, %ld\n\n",del_state);




    	return 0;
}


