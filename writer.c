#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_NAME "/my_shm"
#define SHM_SIZE 256

int main() {
    // Create shared memory object
    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SHM_SIZE);

    // Map it into address space
    void *ptr = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, fd, 0);

    const char *msg = "Hello from writer!";
    memcpy(ptr, msg, strlen(msg) + 1);
    printf("Written: %s\n", msg);

    munmap(ptr, SHM_SIZE);
    close(fd);
    return 0;
}