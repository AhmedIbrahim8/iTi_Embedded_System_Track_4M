
#include <stdio.h>
void PrintFreqCharacters(char str[]);

int main(void)
{
	char str[100];
	printf("Enter a string : ");
	gets(str); /* Get string from user */

	PrintFreqCharacters(str); /* Call the function and Pass string */

	return 0;
}


void PrintFreqCharacters(char str[])
{
	int i;

	/* array to store how many times each character exist in the input string.
	 * array is 256 as the ASCII table size is 256 */
	int freq[256] = {0}; /* Initialize all the array elements with ZERO value */

	for(i = 0; str[i] != '\0'; i++)
	{
		freq[str[i]]++; /* Increment the value of this array element */
	}

	for(i = 0; i < 256; i++)
	{
		if(freq[i] != 0)
		{
			printf("%c %d\n", i, freq[i]);
		}
	}
}
