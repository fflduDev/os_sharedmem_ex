# Lab: POSIX Shared Memory in C

Run two programs that pass a message through shared memory, answer 8 short questions, and make one small code change. About 30 minutes, 10 points. Use Linux (or WSL).

## Setup

```bash
git clone https://github.com/fflduDev/os_sharedmem_ex.git
cd os_sharedmem_ex
gcc writer.c -o writer
gcc reader.c -o reader
gcc sharedmem.c -o sharedmem     # warnings are OK
```

## Part 1: writer and reader (5 points)

1. Run `./writer`, then `ls -l /dev/shm`. **Q1.** What new entry appears, and how many bytes is it?
2. Run `./reader`, then `ls /dev/shm` again. **Q2.** What did the reader print, and what happened to the entry? Which line of `reader.c` did that?
3. Run `./reader` again, without the writer. **Q3.** What happens, and why? (Hint: compare the two `shm_open` calls.)
4. **Q4.** The two programs share no variables. How does the reader find the memory the writer wrote to?
5. **Q5.** Use `man` to say in one sentence each what `shm_open`, `mmap` and `memcpy` do.

## Part 2: one fix (3 points)

In `reader.c`, check whether `shm_open` returned `-1`. If it did, call `perror("shm_open")` and `return 1`. Recompile & run.  

**Q6.** Run `./reader` with no writer first and paste the output.

## Part 3: sharedmem.c (2 points)

Read `sharedmem.c`, then run `./sharedmem`.

**Q7.** Which process changed the message between the parent's two reads?

**Q8.** This program has no name like `/my_shm`. How do the parent and child share the same memory?

## Turn in

`answers.txt` (Q1 to Q8) and your modified `reader.c`.
