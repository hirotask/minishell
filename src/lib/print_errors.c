#include "include/errors.h"
#include "include/string.h"

#include <errno.h>
#include <stdio.h>

void print_syscall_error(const char *msg, const int e) {
  if (e) {
    errno = e;
  }
  perror(msg);
  errno = 0;
}

void print_syntax_error(const char *token) {
  char *prefix;
  char *cause;
  char *msg;

  prefix = "minishell: syntax error occured near unexpected token `";
  cause = strjoin(token, "\'");
}
