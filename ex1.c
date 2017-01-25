#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int sum = 0;


sem_t mutex;
// Note the return type: void*
void* f1(){
	sem_wait (&mutex);
	for(int i = 0; i < 1000000; i++){
		sum = sum+1;
	}
	sem_post (&mutex);
    return NULL;
}

void* f2(){
	sem_wait (&mutex);
	for(int i = 0; i < 1000000; i++){
		sum = sum-1;
	}
	sem_post (&mutex);
    return NULL;
}



int main(){

	sem_init(&mutex, 0, 1);
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, f1, NULL);
    pthread_create(&t2, NULL, f2, NULL);

    // Arguments to a thread would be passed here ---------^
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("C %d \n", sum);
    return 0;
}

int sem_init(sem_t *sem, int pshared, unsigned int value);
int sem_wait(sem_t *sem);
int sem_post(sem_t *sem);