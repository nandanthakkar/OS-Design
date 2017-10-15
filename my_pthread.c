// File:	my_pthread.c
// Author:	Yujie REN
// Date:	09/23/2017

// name: nandan Thakkar
// username of iLab: nt284
// iLab Server:

#include "my_pthread_t.h"
#include <errno.h>

my_pthread_mutex_t *LOCK;

void spin_aquire(my_pthread_mutex_t *mutex){
    my_pthread_mutex_init(mutex, NULL);
    while(1){
        while(lock==1);
        if(__sync_lock_test_and_set(&mutex->lock, 1)==0){
            break;
        }
    }
}

void spin_release(my_pthread_mutex_t *mutex){
    if(!mutex)return;
    mutex->lock = 0;
}


void scheduler(int sig){
    
}


int my_pthread_init(){
    sigemptyset(&sigProcMask);
    sigaddset(&sigProcMask, SIGPROF);
}

/* create a new thread */
int my_pthread_create(my_pthread_t * thread, pthread_attr_t * attr, void *(*function)(void*), void * arg) {
    
	tcb *my_tcb=(tcb *) malloc(sizeof(tcb));
	//Thread status is decided by scheduler
	thread.thread_context.uc_link=;//initializes ucontext_t
	thread.thread_context.uc_sigmask=;
	thread.thread_context.uc_stack.ss_sp=sizeof(struct tcb);
	thread.thread_context.uc_stack.ss_flags=0;
	thread.thread_context.uc_stack.ss_size;
	thread.stack=&thread;//initializes other parameters
	thread.thread_params.run=function;
	thread.thread_params.arg=arg;
	thread.thread_params.joinable= true ; 
	//attaches function to context
	makecontext(&thread.thread_context,function,arg);
	add(&thread);//adds TCB to priority queue
	return 0;
}

/* give CPU pocession to other user level threads voluntarily */
int my_pthread_yield() {
	//makes call to scheduler
	return 0;
}

/* terminate a thread */
void my_pthread_exit(void *value_ptr) {
	//removes thread from queue
	free(value_ptr);//removes thread from memory
}

/* wait for thread termination */
int my_pthread_join(my_pthread_t thread, void **value_ptr) {
while(**value_ptr!=PTHREAD_EXITED){
	if(thread.status!=NULL){
		return ESRCH;
		//error means that thread is invalid and could not be found
	}
	else if(!thread.thread_params.joinable){
		return EINVAL;//not joinable
	}
	**value_ptr=thread.status;
	else if(**value_ptr==PTHREAD_WAITING && == my_pthread_t.status==PTHREAD_WAITING ){
		return EDEADLK;//1 means error EDEADLK
		//this means two threads joined with eachother or a thread joined with itself
	}
	my_pthread_yield();
}
return 0;
}

/* initial the mutex lock */
int my_pthread_mutex_init(my_pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr) {
	mutex->lock = 0;
    mutex->flags = 0;
    return 0;
}

/* aquire the mutex lock */
int my_pthread_mutex_lock(my_pthread_mutex_t *mutex) {
    while(__sync_lock_test_and_set(mutex->lock, 1) != 0){ //shared mutex was locked
        spin_aquire(LOCK);
        if(mutex->lock == 1){ //value of mutex->lock is 
            my_pthread_yield();
            spin_release(LOCK);
            return 1; //thread is in waiting queue and blocked
        }else{
            spin_release(LOCK);
        }
    }
    return 0; //got the lock
}

/* release the mutex lock */
int my_pthread_mutex_unlock(my_pthread_mutex_t *mutex) {
    spin_aquire(LOCK);
    //load next thread in the queue
    __sync_lock_release(mutex);i
    spin_release(LOCK);
    //if next!=null then wake up the next thread
    return 0;
}

/* destroy the mutex */
int my_pthread_mutex_destroy(my_pthread_mutex_t *mutex) {
	if(!mutex)return EINVAL;
    mutex->lock = 0;
    mutex->flags = 0;
    return 0;
}

