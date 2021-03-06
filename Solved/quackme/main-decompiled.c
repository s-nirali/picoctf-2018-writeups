//
// This file was generated by the Retargetable Decompiler
// Website: https://retdec.com
// Copyright (c) 2018 Retargetable Decompiler <info@retdec.com>
//

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------------ Structures ------------------------

struct _IO_FILE {
    int32_t e0;
};

// ------------------- Function Prototypes --------------------

int32_t do_magic(void);
int32_t read_input(void);

// --------------------- Global Variables ---------------------

char * g1 = "\x29\x06\x16\x4f\x2b\x35\x30\x1e\x51\x1b\x5b\x14\x4b\x08\x5d\x2b\x50\x14\x5d";
int32_t g2 = 0x616d0000;
char (*g3)[103] = "You have now entered the Duck Web, and you're in for a honkin' good time.\nCan you figure out my trick?";
struct _IO_FILE * g4 = NULL;
int32_t g5 = 0;

// ------------------------ Functions -------------------------

// Address range: 0x80485db - 0x8048642
int32_t read_input(void) {
    int32_t lineptr = 0; // bp-28
    int32_t n = 0; // bp-24
    int32_t v1;
    if (getline((char **)&lineptr, &n, g4) == -1) {
        // 0x804861a
        puts("No line read...");
        v1 = &g2;
        // branch -> 0x804862f
    } else {
        // 0x8048615
        v1 = lineptr;
        // branch -> 0x804862f
    }
    // 0x804862f
    int32_t result; // 0x8048641
    if (*(int32_t *)20 != *(int32_t *)20) {
        // 0x804863b
        __stack_chk_fail();
        int32_t * v2;
        result = (int32_t)&v2;
        // branch -> 0x8048640
    } else {
        result = v1;
    }
    // 0x8048640
    return result;
}

// Address range: 0x8048642 - 0x8048715
int32_t do_magic(void) {
    int32_t str = read_input(); // 0x8048648
    int32_t len = strlen((char *)str); // 0x8048656
    int32_t size = len + 1; // 0x8048664
    int32_t * mem = malloc(size); // 0x804866b
    if (mem == NULL) {
        // 0x804867c
        puts("malloc() returned NULL. Out of Memory\n");
        exit(-1);
        // UNREACHABLE
    }
    // 0x8048696
    memset(mem, 0, size);
    if (len <= 0) {
        // 0x8048713
        return 0;
    }
    int32_t v1 = 0; // 0x804870b7
    int32_t v2 = 0;
    // branch -> 0x80486bd
    int32_t result; // 0x8048707
    while (true) {
        char v3 = *(char *)(v1 + (int32_t)&g1); // 0x80486c5
        char v4 = *(char *)(v1 + str); // 0x80486d0
        char v5 = *(char *)(v1 + *(int32_t *)&g3); // 0x80486e3
        int32_t v6 = (int32_t)(v5 == (v4 ^ v3)) + v2; // 0x80486eb
        if (v6 == 25) {
            // 0x80486f5
            // branch -> 0x8048713
            // 0x8048713
            return puts("You are winner!");
        }
        // 0x8048707
        result = v1 + 1;
        if ((char *)result >= (char *)len) {
            // break -> 0x8048713
            break;
        }
        v1 = result;
        v2 = v6;
        // continue -> 0x80486bd
    }
    // 0x8048713
    return result;
}

// Address range: 0x8048715 - 0x804876c
int main(int argc, char ** argv) {
    // 0x8048715
    setvbuf((struct _IO_FILE *)g5, NULL, 2, 0);
    puts("You have now entered the Duck Web, and you're in for a honkin' good time.\nCan you figure out my trick?");
    do_magic();
    puts("That's all folks.");
    return 0;
}

// --------------- Dynamically Linked Functions ---------------

// void __stack_chk_fail(void);
// void exit(int status);
// _IO_ssize_t getline(char ** restrict lineptr, size_t * restrict n, FILE * restrict stream);
// void * malloc(size_t size);
// void * memset(void * s, int c, size_t n);
// int puts(const char * s);
// int setvbuf(FILE * restrict stream, char * restrict buf, int modes, size_t n);
// size_t strlen(const char * s);

// --------------------- Meta-Information ---------------------

// Detected compiler/packer: gcc (5.4.0)
// Detected functions: 3
// Decompilation date: 2018-10-04 03:19:21
