#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() { 
int pipe_fd[2];
pid_t pid;

if (pipe(pipe_fd) == -1) { 
perror("Pipe failed");
return 1;
}

pid = fork(); 

if (pid == -1) { 
perror("Fork failed");
return 1; 
}

if (pid == 0) { 
close(pipe_fd[1]);
char buffer[100];
read(pipe_fd[0], buffer, sizeof(buffer)); 
printf("Child received: %s\n", buffer);
close(pipe_fd[0]);
}

else { 
close(pipe_fd[0]);
char message[] = "Hi from parent!";
write(pipe_fd[1], message, strlen(message) + 1);
close(pipe_fd[1]);
}

return 0; 
}
