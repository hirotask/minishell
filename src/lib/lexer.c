#include "include/errors.h"
#include "include/token.h"
#include <asm-generic/errno-base.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

int valid_quote(const char *s) {
  char active_quote;

  active_quote = '\0';
  while (*s) {
    if ((*s == '\'' || *s == '"')) {
      if (active_quote == '\0') {
        active_quote = *s;
      } else if (*s == active_quote) {
        active_quote = '\0';
      }
    }
    s++;
  }
  return (active_quote == '\0');
}

t_token **lexer(char *line, t_minishell *mini) {
  t_token **tokens;

  add_history(line);

  if (!valid_quote(line)) {
    print_syntax_error("\' or \"");
    mini->status = SYNTAX_ERRNO;
    return (NULL);
  }

  if (strlen(line) > 0) {
    rl_replace_line(line, 1);
  }

  tokens = (t_token **)malloc(ARGUMENT_SIZE * sizeof(t_token *));

  if (!tokens) {
  }
}
