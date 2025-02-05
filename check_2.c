#include <stdio.h>
#include <stdlib.h>
int main(){
	char ipAddress[100];
	int pingResult;
	int count;

	printf("Enter the Ip address to ping:");
	scanf("%s",ipAddress);

	char command[150];
	for(int i=0;i<5;i++){
	snprintf(command,sizeof(command),"ping -c 1 %s >/dev/null 2>&1",ipAddress);
	pingResult=system(command);

	count++;
	}

	printf("The ping has been transfered %d times",count);


}
