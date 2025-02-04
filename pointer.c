#include <stdio.h>

/*int main(){
	int arr[5]={11,22,33};
	int num=27;
	int* ptr=NULL;
	ptr=arr;
	int* ptr2=NULL;
	ptr2=&num;

	printf("%p\n",ptr2);
	printf("%d\n",*ptr2);

	printf("%ld\n",sizeof(arr));
	printf("%ld",sizeof(ptr));
	
	return 0;


}*/

int main(){
	int arr[5]={11,22,33};
	int *ptr=arr;
	printf("%d,%d,%d,%d,%d,%d",*ptr,++*ptr++,(*ptr)++,*ptr++,*++ptr,++*ptr);
	return 0;

}
