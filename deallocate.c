#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 1234; // Fixed key

    // Get the shared memory segment
    int shmid = shmget(key, 0, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared memory deallocated successfully.\n");

    return 0;
}
