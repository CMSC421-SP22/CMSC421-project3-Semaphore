#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "buffer_sem.h"

int main(int argc, char *argv[]) {

	printf("Example of full buffer scenario\n");
	long init_state = init_buffer_421();
	//printf("init finished, %ld\n", init_state);


	int producer_


	long insert_state = insert_buffer_421(1);
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

	return 0;
}
