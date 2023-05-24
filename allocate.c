#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 100

int main() {
    key_t key = 1234; // Fixed key

    // Create shared memory segment
    int shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    printf("Shared memory allocated successfully.\n");

    return 0;
}
