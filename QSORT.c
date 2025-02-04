#include <stdio.h>
#include <stdlib.h>

/*sorting the array
void swap(int *a,int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=(low-1);

	for(int j=low;j<=high-1;j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}

int quickSort(int arr[],int low,int high){
	if(low<high){
		int part_ind=partition(arr,low,high);
		quickSort(arr,low,part_ind-1);
		quickSort(arr,part_ind+1,high);
	}
}*/

int make_asc(const void * x,const void * y){
	int a=*((int *)x);
	int b=*((int *)y);
	return a-b;
}

int make_desc(const void * x,const void * y){
	int a=*(int *)x;
	int b=*(int *)y;
	return b-a;
}

int main(){
/*array creation
	int max=100;
	int num;

	int *arr=(int *) malloc(max*sizeof(int));
	if(arr==NULL){
		printf("Memory allocation failed\n");
		return 1;
	}

	for(int i=0;i<max;i++){
		printf("Enter elements %d:",i+1);
		scanf("%d",&num);
		if (num==-1) break;
		else arr[i]=num;
	}*/

//array creation
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);

	int arr[n];
	for( int i=0;i<n;i++){
		scanf("%d",&arr[i]);
}
	int middle=n/2;

	qsort(arr,middle,sizeof(int),make_asc);
	qsort(arr+middle,n-middle,sizeof(int),make_desc);

//diaplay the array
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}



