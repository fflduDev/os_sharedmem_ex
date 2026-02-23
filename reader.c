#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_NAME "/my_shm"
#define SHM_SIZE 256

int main() {
    // Open existing shared memory object
    int fd = shm_open(SHM_NAME, O_RDONLY, 0666);

    // Map it into address space
    void *ptr = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, fd, 0);

    printf("Read: %s\n", (char *)ptr);

    munmap(ptr, SHM_SIZE);
    close(fd);
    shm_unlink(SHM_NAME); // Clean up
    return 0;
}