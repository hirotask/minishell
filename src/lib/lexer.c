#include "include/errors.h"
#include "include/token.h"
#include <readline/history.h>

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
    print_syntax_error()
  }
}
