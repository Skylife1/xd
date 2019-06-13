#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#ifndef __MYCOMMON__
#define __MYCOMMON__
#include "pthread.h"
#include "common.h"
#define puerta pthread_mutex_t //nuevo tipo de dato
#define crear_puerta(m) Pthread_mutex_init (&m, NULL)// funcion para crear puerta
#define cerrar_puerta(m) Pthread_mutex_lock(&m)//funcion para cerrar la puerta
#define abrir_puerta(m) Pthread_mutex_unlock(&m)//funcion para abrir la puerta
#define destruir_puerta(m) pthread_mutex_destroy(&m)//funcion para destruir puerta
#endif
volatile int counter = 0; 
int loops;
pthread_mutex_t p3;
void *worker(void *arg){
    cerrar_puerta(p3);
    int i;
    for (i = 0; i < loops; i++) {
	counter++;
    }
    abrir_puerta(p3);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <loops>\n"); 
	exit(1); 
    } 
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    return 0;
    destruir_puerta(p3);
}

