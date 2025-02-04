#include <stdio.h>
 
 
int count_cleared_bits_before_after(unsigned int num) {
    int right_count = 0;
    int left_count=0;
    unsigned int right_mask = num;
    unsigned int left_mask =num;
    while ((right_mask & 1) == 0) { 
        right_count++;
        right_mask >>= 1;  
    }

    while((left_mask & 32768)==0){//checking for the left most 1
	left_count++;
	left_mask <<=1;
    }
    if(right_count==0 && left_count==0){
	num|=65535;
    }
    if (right_count % 2 == 0) {
        num |= (1 << right_count) - 1;
    } else {
        unsigned int mask = (1 << (16 - right_count)) - 1;
        num |= mask << right_count; 
    }
    printf("Decimal: %u\n", num);
 
    return 0;
}

 
int main() {
    int input;
    printf("Enter the number:"); 
    scanf("%u",&input);
    count_cleared_bits_before_after(input);
    return 0;
}
