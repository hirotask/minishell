// 同じヘッダーファイルが複数回読み込まれるのを防ぐために
// include guard を行う

#ifndef COMMAND_H // もしCOMMAND_Hが定義されていなければ
#define COMMAND_H // COMMAND_Hを定義する

typedef struct s_command {
    unsigned int track;
    char **argv;
    int argc;
    struct s_command *next;
} t_command;

#endif

