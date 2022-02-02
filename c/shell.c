/*
Name: Taylor Moore
Program Type: Course Assignment - Operating Systems
Date: September 24, 2020
Program Description:
	Creates a shell that has some interactivity. 
	Test by using the 'echo' command on execution.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFBUMP 1024
#include <unistd.h>
#include <sys/wait.h>

void loop(void);
char *read_line(void);
char **split_line(char*);
int execute(char**);

int main()
{
    loop();
    return 0;
}

char *read_line(void)
{
    int bufsize = BUFBUMP;
    int position = 0;
    char *carray = malloc(sizeof(char) * bufsize);
    int c;
    if (!carray) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            carray[position] = '\0';
            return carray;
        } else {
            carray[position] = c;
        }
        position++;
        if (position >= bufsize) {
            bufsize += BUFBUMP;
            carray = realloc(carray, bufsize);
            if (!carray) {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char** split_line(char* line)
{
	int position = 0;
    int buf2Size = BUFBUMP;
    char* tempArg;
    tempArg = strtok(line, " ");
    char** buffer = malloc(sizeof(char*) * buf2Size);
    while(tempArg != NULL)
    {
        buffer[position]=strdup(tempArg);
        position++;
        
        if (buffer == NULL) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
        }
        if (position >= buf2Size){
        buf2Size = buf2Size + BUFBUMP;
        buffer = realloc(buffer,buf2Size);
        }
    tempArg = strtok(NULL, " ");
    }
    buffer[position]=NULL;
    return buffer;
}

void loop(void)
{
    char *line=NULL;
    int status=1;
    while(status){
        printf("csis>");
        line = read_line();
        char** args;
        args = split_line(line);
        status=execute(args);
        char** argsHead=args;
    }
}

int execute(char **args)
{
  pid_t pid, wpid;
  int status;
  pid = fork();
  if (pid==0) {
    execvp(*args,args);
    exit(EXIT_FAILURE);
  } 
  else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }  
  return 1;
}
