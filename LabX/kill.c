#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int sig) {
printf("Child received signal: %d\n", sig);
exit(0);
}

int main() {
pid_t pid = fork(); 

if (pid == -1) {
perror("Fork failed");
return 1;
}

if (pid == 0) {
signal(SIGUSR1, signal_handler); 
printf("Child waiting for signal...\n");
pause();
}

else {
sleep(1);
printf("Parent sending signal to child...\n");
kill(pid, SIGUSR1);
}

return 0; 
}
