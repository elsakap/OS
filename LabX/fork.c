#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {  

printf("Parent PID: %d\n", getpid()); 

for (int i=0; i<3; i++) { 
pid_t pid = fork();

if (pid == -1) { 
perror("Fork failed");
return 1;
} 

else if (pid == 0) { 
printf("Child process created! PID: %d, Parent PID: %d\n", getpid(), getppid());
break;
}

else { 
printf("Parent continues. PID: %d, Created child PID: %d\n", getpid(), pid);
}

}

sleep(1); 

return 0;  
}
