#include <stdlib.h>
#include<stdio.h>

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
                printf("%s",line);
        }

        fclose(fp);


        return 0;
}

