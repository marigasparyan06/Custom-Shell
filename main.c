#include "shell.h"

int main() {
    char input[MAX];
    char* args[MAX];

    signal(SIGINT, Handler);

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if (history_count < MAX_HISTORY) {
            history[history_count] = strdup(input);
        } 

        else {
            free(history[history_count % MAX_HISTORY]);   
            history[history_count % MAX_HISTORY] = strdup(input);
        }

        ++history_count;

        char* token = strtok(input, " ");
        int i = 0;

        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        
        args[i] = NULL;

        if (args[0] == NULL) {
            continue;  
        }

        else if (strcmp(args[0], "cd") == 0) {
            Cd(args[1]);  
        } 

        else if (strcmp(args[0], "history") == 0) {
            History();  
        }

        else if (strcmp(args[0], "pwd") == 0) {
            PWD();  
        } 
        
        else if (strcmp(args[0], "echo") == 0) {
            Echo(args);  
        } 
        
        else if (strcmp(args[0], "clear") == 0) {
            Clear();  
        } 
        
        else if (strcmp(args[0], "setenv") == 0) {
            Setenv(args[1], args[2]);  
        } 
        
        else if (strcmp(args[0], "unsetenv") == 0) {
            Unsetenv(args[1]);  
        } 
        
        else if (strcmp(args[0], "chprompt") == 0) {
            Chprompt(args[1]);  
        } 
        
        else if (strcmp(args[0], "exit") == 0) {
            break;  
        } 
        
        else if (strcmp(args[0], "help") == 0) {
            Help();  
        } 
        
        else {
            pid_t pid;
            pid = fork();
            
            if (pid < 0) {
                perror("Fork failed");
            } 

            if (pid == 0) {
                if (execvp(args[0], args) < 0) {
                    perror("Exec failed, try again\n");
                }

                exit(1);
            } 

            else {
                wait(NULL);
            }
        }
    }

    for (int i = 0; i < (history_count < MAX_HISTORY ? history_count : MAX_HISTORY); ++i) {
        free(history[i]);
    }

    return 0;
}