#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void intHandler();
void alarmHandler();

int main( )
{
    alarm(10);
    signal(SIGINT, intHandler);
    signal(SIGALRM, alarmHandler);

    int correct = 0;
    while(!correct) {
        if(getchar() == '1') {
            if(getchar() == '2') {
                if(getchar() == '3') {
                    if(getchar() == '\n') {
                        correct = 1;
                    }
                }
            }
        }
    }


    printf("Correct! \n");
}

void intHandler(int signo)
{
    printf("10 sec reset...\n");
    alarm(10);
}

void alarmHandler(int signo)
{
    printf("Fire!\n");
    exit(0);
}

