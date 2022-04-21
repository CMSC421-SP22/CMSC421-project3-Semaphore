# README: Monitors
Amy Phan -- Mphan1@umbc.edu -- Github @ Amyypi -- 4/18/2022

## Users

For the semaphore file, I used some of my code from part 2.1, which used 1.1 as a base,  as a base for part 3.

Unlike part 1.1, I had to integrate 3 unique functions called Enqueue, Dequeue, and print_buffer. These functions are more unique in a way that they includes semaphores within or print values of the semaphores.

My approach was to get the base functionality to work (copy code of part 2.1) first. Once that's done and tested out - I started to include semaphore statements.

Then I will switch all of my semaphore statments to monitors, such as how sem_init() will be turned into pthread_cond_init(), sem_wait is pthread_cond_wait(), and sem_destroy is pthread_cond_destroy. Some of these take different arguments. Other than that, the layout is about the same from part 2. 

### Execution

 In terminal, type: gcc test_user_sem.c buffer_user_sem.c -pthread

 from there, it should produce a file titled 'a.out'

 You can then type and enter: ./a.out

 for valgrind, you can type and enter: valgrind ./a.out


