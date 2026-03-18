#include "include/errors.h"

#include <errno.h>
#include <stdio.h>

void print_syscall_error(const char *msg, const int e) {
    if (e) {
        errno = e;
    }
    perror(msg);
    errno = 0;
}

void print_syntax_error(const char *msg, const int e) {}
