// File:	my_pthread.c
// Author:	Yujie REN
// Date:	09/23/2017

// name:
// username of iLab:
// iLab Server:

#include "my_pthread_t.h"

/* create a new thread */
int my_pthread_create(my_pthread_t * thread, pthread_attr_t * attr, void *(*function)(void*), void * arg) {
	struct tcb* thread=struct tcb* malloc(sizeof(struct tcb));
	//Thread status is decided by scheduler
	thread.thread_context.uc_link=;//initializes ucontext_t
	thread.thread_context.uc_sigmask=;
	thread.thread_context.uc_stack.ss_sp=sizeof(struct tcb);
	thread.thread_context.uc_stack.ss_flags=0;
	thread.thread_context.uc_stack.ss_size;
	thread.stack=&thread;//initializes other parameters
	thread.thread_params.run=function;
	thread.thread_params.arg=arg;
	//attaches function to context
	makecontext(&thread.thread_context,function,arg);
	add(&thread);//adds TCB to priority queue
	return 0;
};

/* give CPU pocession to other user level threads voluntarily */
int my_pthread_yield() {
	swapcontext(,)
	return 0;
};

/* terminate a thread */
void my_pthread_exit(void *value_ptr) {
	//removes thread from queue
	free(value_ptr);//removes thread from memory
};

/* wait for thread termination */
int my_pthread_join(my_pthread_t thread, void **value_ptr) {
	return 0;
};

/* initial the mutex lock */
int my_pthread_mutex_init(my_pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr) {
	return 0;
};

/* aquire the mutex lock */
int my_pthread_mutex_lock(my_pthread_mutex_t *mutex) {
	return 0;
};

/* release the mutex lock */
int my_pthread_mutex_unlock(my_pthread_mutex_t *mutex) {
	return 0;
};

/* destroy the mutex */
int my_pthread_mutex_destroy(my_pthread_mutex_t *mutex) {
	return 0;
};

