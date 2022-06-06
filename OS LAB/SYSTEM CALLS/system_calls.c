#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd[2];
	char buf1[12] = "Hello World\n";
	char buf2[12];
	
	creat("text1.txt",777);
	
	fd[0] = open("text1.txt",O_RDWR);
	fd[1] = open("text1.txt",O_RDWR);
	
	write(fd[0],buf1,strlen(buf1));
	write(fd[1],buf2,read(fd[1],buf2,12));
	
	close(fd[0]);
	close(fd[1]);
	
	return 0;
}
