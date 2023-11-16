#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

// Declare the arrays as external
int S[100], A[100], B[100];

void *TaskCode(void *argument) {
    int tid;
    tid = *((int*) argument);
    for(int i = tid * 25; i < (tid + 1) * 25; i++) {
        S[i] = A[i] + B[i];
    }
    sleep(1);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[4];
    int args[4];
    int i;

    printf("Process id = %d\n", getpid());
    printf("Before creation of Thread\n");

    // Initialize arrays A and B with sample values
    for (i = 0; i < 100; i++) {
        A[i] = i; // Initialize A with values 0 to 99
        B[i] = 100 - i; // Initialize B with values 100 to 1
    }

    /* Create all threads */
    for (i = 0; i < 4; ++i) {
        args[i] = i;
        pthread_create(&threads[i], NULL, TaskCode, (void*)&args[i]);
    }
    /* Wait for all threads to complete */
    for (i = 0; i < 4; ++i) 
        pthread_join(threads[i], NULL);
    printf("thread terminatted\n");
        // Print the result in array S
    for (i = 0; i < 100; i++) {
        printf("S[%d] = %d\n", i, S[i]);
    }
    return 0;
}
