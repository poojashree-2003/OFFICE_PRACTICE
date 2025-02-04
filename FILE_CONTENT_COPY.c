#include<stdio.h>
#include<string.h>


int main(){
	FILE*file1,*file2,*file3;  //CREATING THE FILE POINTERS
	char content;
	char add;

file3=fopen("file3.txt","w+"); //OPENING FILE3 TO WRITE 20 TO 80 LINES OF FILE 1
file1=fopen("file1.txt","r");  //OPENING FILE1 TO READ THE CONTENT
file2=fopen("file2.txt","r");  //OPENING FILE2 TO READ THE CONTENT

	
//MOVING THE CURSOR TO THE START OF 20th LINE IN FILE1
for (int i=0;i<20;i++){
        while ((content=fgetc(file1))!=EOF && content!='\n') {
        }
        if (content==EOF) {
            	printf("File has fewer than 20 lines.\n");
            	//fclose(file1);
            	fclose(file3);
            	return 1;
        }
}

//READING THE CONTENT TILL 80th LINE(80-20=60) AND COPIED TO FILE3
for(int j=0;j<60;j++)
{
	while((content=fgetc(file1))!='\n'){
	fputc(content,file3);
	}
	fprintf(file3,"\n");
}
	
//fprintf(file3,"\n");
//fclose(file1);
fclose(file3); //CLOSING THE FILE3


file3=fopen("file3.txt","a+"); //OPENING THE FILE3 IN APPEND MODE TO TAKE THE CURSOR TO THE END OF THE FILE
//MOVING THE CURSOR TO THE START OF 50th LINE IN FILE2
for(int l=0;l<50;l++){
	while((add=fgetc(file2))!=EOF && add!='\n'){
	}
	if(add==EOF){
		printf("File has fewer than 50 lines.\n");
		fclose(file2);
		fclose(file3);
		return 1;
	}
}


//READING THE CONTENT TILL 90th LINE(90-50=40) AND APPENDED TO FILE3
for(int m=0;m<40;m++){
	while((add=fgetc(file2))!='\n'){
		fputc(add,file3);
	}
	fprintf(file3,"\n");
}

printf("Content copied successfully!");	
fclose(file2); 
fclose(file3);

}
