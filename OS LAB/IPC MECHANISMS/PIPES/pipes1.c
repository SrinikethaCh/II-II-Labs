#include<unistd.h>
#include<stdio.h>
int main() {
   int pfds[2];
   int status;
   int pid;
   char writem[2][20]={"Hi", "Hello"};
   char readm[20];
   status = pipe(pfds);
   if (status == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   pid = fork();
   
   // Child process
   if (pid == 0) {
      read(pfds[0], readm, sizeof(readm));
      printf("Child Process - Reading from pipe – Message 1 is %s\n", readm);
      read(pfds[0], readm, sizeof(readm));
      printf("Child Process - Reading from pipe – Message 2 is %s\n", readm);
   } else { //Parent process
      printf("Parent Process - Writing to pipe - Message 1 is %s\n", writem[0]);
      write(pfds[1], writem[0], sizeof(writem[0]));
      printf("Parent Process - Writing to pipe - Message 2 is %s\n", writem[1]);
      write(pfds[1], writem[1], sizeof(writem[1]));
   }
   return 0;
}

