# Semaphore Readme file (part 2.1 + 2.2)
Amy Phan
Mphan1@umbc.edu
Github @ Amyypi
4/18/2022 


## User

  For the semaphore file, I used some of my code from part 1.1 as a base. 
  
  Unlike part 1.1, I had to integrate 3 unique functions called Enqueue, Dequeue, and print_buffer. These functions are more unique in a way that they includes semaphores within or print values of the semaphores. 
  
  My approach was to get the base functionality to work (copy code of part 1.1) first. Once that's done and tested out - I started to include semaphore statements. 
 
### Executing User space

   To run user space, type this into the terminal: gcc -Wall test_user.c buffer_user.c -o test

   If it runs successfully, you will have a new compiled file titled 'test'. To run the program for the user space, type in and enter: './test'. for valgrind, type 'valgrind ./test'

## Kernel

  I used project 1's part 3 and 4 as a rough reference as to how to set up the kernel for the semaphore files. I made sure to add the functions in all of my kernel files to properly execute them.

 I switched out the printf(), malloc(), and free() to their kernel versions which are: kmalloc(), kfree(), and printk(). Overall the algorithm/code architecture is about the same. 


