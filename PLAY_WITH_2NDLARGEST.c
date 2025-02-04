#include <stdio.h>


int main(){
//array creation
	int length;
	printf("Enter the length of the array: ");
	scanf("%d",&length);
	int arr[length];
	printf("Enter the array numbers: ");
	for(int i=0;i<length;i++){
		scanf("%d",&arr[i]);
	}

/*second largest
	int first=0,second=0;
		for(int ele=0;ele<length;ele++){
			if(arr[ele]>first){
				second=first;
				first=arr[ele];
			}
			else if(arr[ele]<first  && arr[ele]>second){
				second=arr[ele];
			}
		}
}*/



//second largest
	int max=arr[0];
        int ind=0,pos=0;
	for(int i=0;i<length;i++){
		if(arr[i]>max){
			max=arr[i];
			ind=i;
		}
         }

	int maxi=0;
	for(int j=0;j<length;j++){
		if(j!=ind){
			if(arr[j]>maxi){
				maxi=arr[j];
				pos=j;
			}
		}
	}


//adding
	int sum=0;
	if(pos==0){
		sum=arr[0]+arr[1]+1;
	}
	else if(pos==length-1){
		sum=arr[length-1]+arr[length-2]+1;
	}
	else{
		sum=arr[pos]+arr[pos+1]+arr[pos-1];
	}


//swapping
	int a=arr[0];
	arr[0]=sum;
	arr[pos]=a;

//display
	for(int ele=0;ele<length;ele++){
		printf("%d ",arr[ele]);
	}
}

