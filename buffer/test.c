#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

#define __NR_hello 441
long hello_syscall(void) {
	return syscall(__NR_hello);
}

#define __NR_init_buffer_421 442
long init_buffer_421_syscall(void){
	return syscall(__NR_init_buffer_421);
}

#define __NR_insert_buffer_421 443
long insert_buffer_421_syscall(int i){
        return syscall(__NR_insert_buffer_421, i);
}

#define __NR_print_buffer_421 444
long print_buffer_421_syscall(void){
        return syscall(__NR_print_buffer_421);
}

#define __NR_delete_buffer_421 445
long delete_buffer_421_syscall(void){
        return syscall(__NR_delete_buffer_421);
}


int main(int argc, char *argv[]) {
	long rv;
	rv = hello_syscall();

	if(rv < 0) {
		 perror("Hello syscall failed");
	}
	else {
		printf("Hello syscall ran successfully, check dmesg output\n");
	}

	printf("Example of full buffer scenario\n");
	long init_state;
	init_state = init_buffer_421_syscall();
	printf("init finished, %ld\n\n", init_state);

	long insert_state;
	insert_state = insert_buffer_421_syscall(1);
	insert_state = insert_buffer_421_syscall(2);
        insert_state = insert_buffer_421_syscall(3);
        insert_state = insert_buffer_421_syscall(4);
        insert_state = insert_buffer_421_syscall(5);
        insert_state = insert_buffer_421_syscall(6);
        insert_state = insert_buffer_421_syscall(7);
        insert_state = insert_buffer_421_syscall(8);
        insert_state = insert_buffer_421_syscall(9);
        insert_state = insert_buffer_421_syscall(10);
        insert_state = insert_buffer_421_syscall(11);
        insert_state = insert_buffer_421_syscall(12);
        insert_state = insert_buffer_421_syscall(13);
        insert_state = insert_buffer_421_syscall(14);
        insert_state = insert_buffer_421_syscall(15);
        insert_state = insert_buffer_421_syscall(16);
        insert_state = insert_buffer_421_syscall(17);
        insert_state = insert_buffer_421_syscall(18);
        insert_state = insert_buffer_421_syscall(19);
        insert_state = insert_buffer_421_syscall(20);
        insert_state = insert_buffer_421_syscall(21);
        insert_state = insert_buffer_421_syscall(22);
        //insert_state = insert_buffer_421(23);
        printf("Insert finished, %ld\n\n", insert_state);

	long print_status;
	print_status = print_buffer_421_syscall();
	printf("print finished, %ld\n", print_status);

	long del_state;
	del_state = delete_buffer_421_syscall();
	printf("Delete finished, %ld\n",del_state);


	return 0;
}
