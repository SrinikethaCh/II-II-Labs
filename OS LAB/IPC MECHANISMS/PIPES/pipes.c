#include<stdio.h>
#include<unistd.h>

int main(){
	int pfds[2];
	int status;
	char writem[3][20]={"Sriniketha","Sahithi","Harini"};
	char readm[40];
	status = pipe(pfds);
	if(status== -1){
		printf("Unable to create pipe\n");
		return 1;
	}
	printf("%s\n",writem[0]);
	write(pfds[1],writem[0],sizeof(writem[0]));
	read(pfds[0],readm,sizeof(readm));
printf("%s\n",readm);
printf("%s\n",writem[0]);	
write(pfds[1],writem[1],sizeof(writem[0]));
	read(pfds[0],readm,sizeof(readm));
	printf("%s\n",readm);

	return 0;
}
