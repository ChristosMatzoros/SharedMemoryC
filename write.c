#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 100

int main() {
    key_t key = 1234; // Fixed key

    // Get the shared memory segment
    int shmid = shmget(key, BUFFER_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    char *shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Write data to the shared buffer
    strncpy(shm, "Hello, shared memory!", BUFFER_SIZE);

    // Detach shared memory segment
    shmdt(shm);

    printf("Data written to shared memory.\n");

    return 0;
}
