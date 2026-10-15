
kick them both off..  writer writes - 

hows reader know where the shared mem writer is using is..?


"/my_shm".

int fd = shm_open("/my_shm", ...);  // same name in both

shm_open works like a file — the name is a key that both processes use to look up the same object. The OS maintains a registry of named shared memory objects (on Linux, you can see them under /dev/shm/):


 

the shared memory stays out there until explicitly unlinked / deleted or reboot.   dangerous!!


