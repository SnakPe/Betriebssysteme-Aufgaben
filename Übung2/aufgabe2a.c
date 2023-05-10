#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



void *verteilen(void* arg){
	while((*((int*)arg)) > 0){
		printf("Packages left: %d\n",*((int*)arg));
		sleep(1);
		(*((int*)arg))--;
	}
	pthread_exit(arg);
	//return arg;
}
void *verteilenRekursiv(void* arg){
	printf("Packages left: %d\n",*((int*)arg));
	sleep(1);
	(*((int*)arg))--;
	if((*((int*)arg)) > 0)verteilenRekursiv(arg);
	pthread_exit(arg);
}

int main(void){
	int packets = 40;
	void* p = &packets;
	pthread_t helpers[5];
	for(int i = 0; i < 5; i++){
		if(pthread_create(&helpers[i], NULL, verteilenRekursiv, p) != 0){
			perror("pthread_create() had an error");
			exit(-1);
		}
	}
	for(int i = 0; i < 5; i++){
		pthread_join(helpers[i],NULL);
	}
	printf("At the end: Packages left: %d\n",packets);
	return 1;
}

