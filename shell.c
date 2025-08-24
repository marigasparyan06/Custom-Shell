#include "shell.h"

void Cd(char *path) {

    if (path == NULL) {
        char* home = getenv("HOME");
        if (home == NULL || chdir(home) != 0) {
            perror("cd");
        }
    } 

}

void History() {
    int start = (history_count > MAX_HISTORY) ? history_count - MAX_HISTORY : 0;
    
    for (int i = start; i < history_count; i++) {
        printf("%d %s\n", i, history[i % MAX_HISTORY]);
    }
}

void PWD() {
    char* cwd = getcwd(NULL, 0);

    if (cwd != NULL) {
        printf("%s\n", cwd);
        free(cwd);
    }

}

void Echo(char** args) {
    int i = 1;

    while (args[i] != NULL) {
        printf("%s ", args[i]);
        ++i;
    }

    printf("\n");
}

void Clear() {
    system("clear");
}

void Setenv(char *name, char *value) {
    if (setenv(name, value, 1) < 0) {
        perror("setenv failed");
    }
}

void Unsetenv(char *name) {
    if (unsetenv(name) < 0) {
        perror("unsetenv failed");
    }
}

void Chprompt(char *new_prompt) {
    if (new_prompt != NULL) {
        snprintf(prompt, sizeof(prompt), "%s> ", new_prompt);
    }
     
    else {
        fprintf(stderr, "chprompt: missing argument\n");
    }
}

void Help() {
    printf("Built-in commands:\n");
    printf("history          : Print history\n");
    printf("echo <text>      : Display the provided text\n");
    printf("help             : Display this help information\n");
    printf("cd <directory>   : Change the current directory\n");
    printf("exit             : Exit the shell\n");
    printf("pwd              : Print the current working directory\n");
    printf("chprompt <string>: Change the shell prompt\n");
    printf("clear            : Clear the terminal screen\n");
    printf("setenv <var> <value> : Set or modify an environment variable\n");
    printf("unsetenv <var>   : Remove an environment variable\n");
    printf("\n");
}

void Handler(int sig) {
    printf("\n");
    fflush(stdout);
}

