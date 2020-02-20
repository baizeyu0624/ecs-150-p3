#include <stddef.h>
#include <stdlib.h>

#include "queue.h"
#include "sem.h"
#include "thread.h"

#include "assert.h"
#include "stdio.h"



struct semaphore {

	size_t count;
	queue_t block_queue;
	int block_num;



};

sem_t sem_create(size_t count)
{
	sem_t sem = (sem_t)mallock(sizeof(struct semaphore)):
	sem->count = count;
	sem->block_num = queue_create();
	return sem;


	/* TODO Phase 1 */
}

int sem_destroy(sem_t sem)
{

	if (sem == NULL){
		return -1;
	}
	if (queue_length(sem->block_queue) ! = 0){
		return -1;

	}
	free(sem);
	return 0;


	/* TODO Phase 1 */
}

int sem_down(sem_t sem)
{
	if (sem == NULL){
		return -1;
	}
	enter_critical_section;


	while(sem->count == 0){
		int state = queue_enqueue(sem->block_queue, (void*)pthread_self());
		if(state == -1){
			printf("enqueue fail, sem.c :45\n");
			return -1;
		}
		sem->block_num -= 1;
		thread_block();
	}
	sem->count -= 1;
	exit_critical_section();
	return 0;

	/* TODO Phase 1 */
}

int sem_up(sem_t sem)
{
	if (sem == NULL){
		return -1;
	}
	enter_critical_section;
	if (sem->count == 0){
		if (queue_length(sem->block_queue)!=0){
			pthread_t*unblock_next = malloc(sizeof(pthread_t));
			int state =queue_dequeue(sem->block_queue, (void**)unlock_next);
			assert(state == 0);
			thread_unblock(*unlock_next);
		}
	}
	sem->count +=1;
	exit_critical_section();
	return 0;
	/* TODO Phase 1 */
}

int sem_getvalue(sem_t sem, int *sval)
{
	if (sem == NULL){
		return -1;
	}
	if (sem->num == 0){
		*sval = sem->block_num * -1;
		
	}else{
		*sval = (int)sem->count;
	}
	return 0;
	/* TODO Phase 1 */
}

