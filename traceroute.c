#include <stdio.h>
#include <stdlib.h>

int main(){
	char destination[100];
	char content[200];
	FILE *fp;
	char line[265];
	int hop_count;

	printf("Enter the destination IP address or hostname: ");
        scanf("%s", destination);

	snprintf(content,sizeof(content),"traceroute -m 30 %s",destination);

	fp=popen(content,"r");

	if(fp==NULL){
		printf("The traceroute has not executed");
		return 1;
	}

	while(fgets(line,sizeof(line),fp)!=0){
		if(line[0]!='\n'){
			hop_count++;
		}
	}

	printf("The number of hopes for ip %s: %d\n",destination,hop_count);
}
