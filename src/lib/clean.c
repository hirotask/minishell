#include "include/clean.h"

#include <stdlib.h>

void clean_exit(t_minishell *mini) {
    int status;

    status = mini->status;
    free(mini);

    exit(status);
}
