#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<string.h>
#include <arpa/inet.h>

int main(){
	char ipAddress[100];
	struct in_addr addr; //FUNCTION IN ARPA/INET USED TO REP IPV4 TO BINARY
	struct hostent*  host; //FUNCTION IN ARPA/INET WITH DETAILS OH HOST

	printf("Enter the ip address: ");
	scanf("%s",ipAddress);

	if(inet_aton(ipAddress,&addr)==0){//CHANGE THE IPADDRESS(TEXT) TO BINARY
		printf("Ip address invalid");
		return 1;
	}

	host=gethostbyaddr(&addr,sizeof(addr),AF_INET);//REVERSE DNS LOOKUP

	if(host==NULL){
		printf("The host is not derived");
	}
	else{
		printf("The host of the ip %s is %s\n",ipAddress,host->h_name);
	}
}
