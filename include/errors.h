#ifndef ERRORS_H
#define ERRORS_H

#define SYNTAX_ERRNO 2

void print_syscall_error(const char *msg, const int e);
void print_syntax_error(const char *token);

#endif
