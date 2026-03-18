#ifndef MINISHELL_H
#define MINISHELL_H

#include "command.h"

#if defined(HAVE_READLINE)
#include <readline/history.h>
#include <readline/readline.h>
#elif defined(HAVE_EDITLINE)
#include <editline/readline.h>
#include <histedit.h>
#endif

typedef struct s_minishell {
    char *line;         // 標準入力された生の文字列
    t_command *command; // 入力されたコマンド
    int status;         // 現在のシェルのERRNO
} t_minishell;

#define PROJECT_NAME "minishell"

#endif
