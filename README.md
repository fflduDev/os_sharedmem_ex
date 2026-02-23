### notes..

How Does the Reader Know Where the Shared Memory Is?

We kick both processes off independently — the writer writes, but how does the reader know which shared memory segment the writer is using?

The answer: **`"/my_shm"`** — a named key.
```c
int fd = shm_open("/my_shm", ...);  // same name used in both processes
```

`shm_open` works like a file — the name is a key that both processes use to look up the same object. The OS maintains a registry of named shared memory objects (on Linux, visible under `/dev/shm/`).

**Danger:** Shared memory persists until it is explicitly unlinked/deleted or the system reboots. If your program crashes or exits without cleaning up, the segment just sits there.
