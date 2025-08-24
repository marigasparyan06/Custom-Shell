#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>
#include <sys/types.h>

#define MAX_HISTORY 100
#define MAX 1024

char* history[MAX_HISTORY];
int history_count = 0;
char prompt[50] = "my-shell> ";


void History();
void Cd(char* path); 
void PWD();

void Echo(char** args);

void Clear();

void Setenv(char* name, char* value);
void Unsetenv(char* name);

void Chprompt(char* new_prompt);

void Help();

void Handler(int sig);

#include "shell.c"
#endif //SHELL_H