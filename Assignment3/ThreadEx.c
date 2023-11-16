#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
void* thread_task(void *args) {
    printf("Hello\n We r learning thread concept");
    sleep(30);
}
int main() 
{
    pthread_t  t_id;
    int ret;
    printf("Process id = %d\n", getpid());
    printf("Before creation of Thread\n");

    //Creating new thread
    ret = pthread_create(&t_id, NULL, thread_task, NULL);
    if (ret == 0) 
        printf("Thread created Successfully:\n");
    else
        printf("Problem in creating thread\n");
    
    //Waiting for the created thread to terminate
    pthread_join(t_id, NULL);
    printf("thread terminatted\n");
    return 0;
}