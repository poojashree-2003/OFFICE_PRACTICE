#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//STRUCTURE FOR THE STACK
struct stack_struct{
	int top;
	int* array;
	int count;
};

//CREATING THE STACK 
struct stack_struct* createStack(int length){
	struct stack_struct* stack=(struct stack_struct*)malloc(sizeof(struct stack_struct));

	if(!stack) return NULL;

	stack->top=-1;
	stack->count=0;
	stack->array=(int *)malloc(length*sizeof(int));

	if(!stack->array) return NULL;

	return stack;
}

//DISPLAY THE ELEMENTS IF NEEDED
int display(struct stack_struct* stack){
        int element;
	int temp=stack->count;
        if(!stack) {
                printf("THE STACK IS EMPTY");
                return 0;
        }
        for(element=temp;element>0;element--){
                printf(" The [%d]:%d",temp--,stack->array[element-1]);
        }
	printf("\n");
}


//PUSHING NUMBERS INTO THE STACK
void* push(int val,struct stack_struct* stack){
	if(!stack) return NULL;
	
	stack->array[++stack->top]=val;
	stack->count++;
	display(stack);
}

//DISPLAY THE TOPMOST ELEMENT IN ARRAY
int peek(struct stack_struct* stack){
	return stack->array[stack->top];
}

//POPING THE ELEMENT
int pop(struct stack_struct* stack){
	if(!stack) return 0;
	stack->count--;
	return stack->array[stack->top--];
	
}


int evaluate_input(char* exp){
	struct stack_struct* stack= createStack(strlen(exp));
	int val;
	for(val=0;exp[val];val++){
		if(isdigit(exp[val])){
			push(exp[val]-'0',stack);
		}
		else if(exp[val]=='+'||exp[val]=='-'||exp[val]=='*'||exp[val]=='/'){
			int operate=exp[val];
			int result;
			int num1=pop(stack);
			int num2=pop(stack);
			switch(operate){
			case '+':
				result=num2+num1;
				break;
			case '-':
				result=num2-num1;
				break;
			case '*':
				result=num2*num1;
				break;
			case '/':
				result=num2/num1;
				break;
			}
			push(result,stack);
		}
	}
	return peek(stack);
} 
int main(){
	char input[100];
	printf("Enter a postfix expression: ");
	scanf("%s", input);
	printf("%d",evaluate_input(input));
}

