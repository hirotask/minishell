#include "include/clean.h"
#include "include/errors.h"
#include "include/minishell.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * シェルを初期化する
 */
static t_minishell *init_minishell() {
  t_minishell *mini;
  mini = malloc(sizeof(t_minishell));

  if (!mini) {
    return (NULL);
  }

  mini->line = NULL;
  mini->command = NULL;
  mini->token = NULL;

  return (mini);
}

/**
 * 入力された文字列を処理する
 */
static void process_input(t_minishell *mini) {
  if (!mini->line) {
    clean_exit(mini);
  }
  // プロンプトに何も入力されていなければ
  if (mini->line[0] == '\0') {
    free(mini->line);
    mini->line = NULL;
    return;
  }

  mini->token = lexer();
}

static void run_minishell(t_minishell *mini) {
  while (1) {
    // readline で入力受け付け
    mini->line = readline("(minishell)$ ");

    process_input(mini);
  }
}

int main(int argc, char **argv) {
  if (argc != 1) {
    printf("%s takes no arguments.\n", argv[0]);
    return 1;
  }

  t_minishell *mini;
  mini = init_minishell();

  if (!mini) {
    print_syscall_error("insufficient memory or system resources", ENOMEM);
    exit(EXIT_FAILURE);
  }

  run_minishell(mini);
  return 0;
}
