/**********************************************************************
 * @file HW1.c
 * @brief This program takes two decimal numbers from user input, A and B,
 * and then calculates A-B. In this program, subtraction is implemented using
 * the two’s complement method, where subtraction is transformed into addition.
 * Binary logic operations are used to find and print the result.
 * @author Wynne Greene
 * @date September 1, 2025
 ***********************************************************************/
#include <stdio.h>

/* This method performs addition on two binary numbers using binary logic operations.*/
unsigned char addBinary(unsigned char A, unsigned char B) {
	/* carry keeps track of the bits that need to be carried while adding A and B.*/
	unsigned char carry;
	
	/* This loop continues until there are no more bits left to carry.*/
	while (B != 0) {
		/* First, find out what carry is needed by using the AND operation. AND
		will determine where A and B both have bits that are 1. With two 1s, we
		need to carry. Then, the XOR operation is used to find the sum between 
		A and B without carrying any bits. The sum is then stored in A. B is then
		set to the carry shifted left by 1. The carry will affect the next higher
		bit.*/
		carry = A & B;
		A = A ^ B;
		B = carry << 1;
	}
	/* Print the result stored in A*/
	return A;
}

int main() {
	/* A and B are the two decimal numbers given by the user.
	result will store the difference between A and B.*/
	unsigned char A, B;
	unsigned char result;
	
	/* Get user input for A and B.*/
	printf("Enter a decimal number A: ");
	scanf("%hhu", &A);
	printf("\nEnter a decimal number B: ");
	scanf("%hhu", &B);
	printf("\n");
	
	/* Determine the two's complement of B. Invert all the bits and add 1 by calling
	the addBinary method.*/
	B = ~B;
	B = addBinary(B, 1);
	
	/* result will store the result of A + (~B+1).*/
	result = addBinary(A, B);
 
	/* The results are printed in decimal and then in binary.*/
	printf("Decimal result: %d\n", result);
	printf("Binary result: ");
	/* This loop prints the 8 bit binary number, starting at the most significant
	bit. We find this bit by shifting the number right by i positions
	and performing the AND operation with 1 to extract only the last bit.*/
	for(int i = 7; i >= 0; i--) {
		printf("%u", (result >> i) & 1);
	}
	return 0;

	/*Test comment*/
}
