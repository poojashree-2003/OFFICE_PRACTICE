#include <stdio.h>

extern void  modify();

int auto_st(){
	int count=0;
	count++;
	printf("The auto storage specifier prints: %d\n",count);
}

int register_st(){
	register int i=0;
	for(i=0;i<5;i++){
		printf("The register_var %d\n",i);}
}

int static_st(){
	static int count=0;
	count++;
	printf("The static variable count the function call count: %d\n",count);
}

int  main(){
	auto_st();
	register_st();
	static_st();
	static_st();
	static_st();
	modify();
	return 0;
}
