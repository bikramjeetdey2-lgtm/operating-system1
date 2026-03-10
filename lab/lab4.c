#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#define N 5 
sem_t forks[N]; 
pthread_t philosophers[N]; 
void* philosopher(void* num) { 
int id = *(int*)num; 
printf("Philosopher %d is thinking\n", id); 
sleep(1); 
sem_wait(&forks[id]); 
sem_wait(&forks[(id + 1) % N]); 
    printf("Philosopher %d is eating\n", id); 
    sleep(1); 
    sem_post(&forks[id]); 
    sem_post(&forks[(id + 1) % N]); 
    printf("Philosopher %d finished eating\n", id); 
    return NULL; 
} 
int main() { 
    int i, id[N]; 
 
    for (i = 0; i < N; i++) 
        sem_init(&forks[i], 0, 1); 
    for (i = 0; i < N; i++) { 
        id[i] = i; 
        pthread_create(&philosophers[i], NULL, philosopher, &id[i]); 
    } 
    for (i = 0; i < N; i++) 
        pthread_join(philosophers[i], NULL); 
    return 0; 
}
