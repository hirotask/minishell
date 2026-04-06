#ifndef TOKEN_H
#define TOKEN_H

#include "include/minishell.h"

#define ARGUMENT_SIZE 1024

typedef struct s_token {
  char *word;
} t_token;

t_token **lexer(char *line, t_minishell *mini);
int valid_quote(const char *s);

#endif
