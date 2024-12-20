#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
FILE *file;
pid_t pid = fork();

if (pid == -1) {
perror("Fork failed");
return 1;
}


if (pid == 0) {
file = fopen("pids.txt", "a");

if (file == NULL) {
perror("Failed to open file");
return 1;
}

fprintf(file, "Child PID: %d\n", getpid());
fclose(file);
}

else { 
sleep(1);
file = fopen("pids.txt", "a");

if (file == NULL) {
perror("Failed to open file");
return 1;
}

fprintf(file, "Parent PID: %d\n", getpid());
fclose(file);
}

return 0;
}
