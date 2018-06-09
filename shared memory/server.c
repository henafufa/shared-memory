#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ  2
main() {
	char c;
	int shmid;
	key_t key;
	char *shm, *s;
	key = 5678;
	if ((shmid = shmget(key, SHMSZ , IPC_CREAT | 0666)) < 0) {
		exit(1);
		printf("shmget error");
	}
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		printf("shmat error");
		exit(1);
}
	s = shm;
	for (c = 'a'; c <= 'z'; c++)
		*s++ = c;
		*s = '\0';
	while (*shm != '*')
		sleep(1);
	for(s = shm; *s != '\0'; s++)
		putchar(*s);
		putchar('\n');
		exit(0);

}
