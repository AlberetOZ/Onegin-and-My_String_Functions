#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_STRINGS 1024
#define MAX_SYMBOLS 128
#define RUS_MOVE 100
#define RUS_POINT_CHANGE 48

int compar(const void* a, const void* b)
{
	int i = 0, j = 0, k = 0;
	i = strlen((char*)a);
	j = strlen((char*)b);
	for(; ((char*)a)[i] >= 0; i--);
	for(; ((char*)b)[j] >=0; j--);
	
	for(; (((char*)a)[i-k] +  RUS_MOVE*(((char*)a)[i-1-k] + RUS_POINT_CHANGE) - ((char*)b)[j-k]  - RUS_MOVE*(((char*)b)[j-1-k] + RUS_POINT_CHANGE)) == 0; k += 2);
	
	return ((char*)a)[i-k] +  RUS_MOVE*(((char*)a)[i-1-k] + RUS_POINT_CHANGE) - ((char*)b)[j-k]  - RUS_MOVE*(((char*)b)[j-1-k] + RUS_POINT_CHANGE) ;
	



}



int main() {
	int i = 0, j = 0;
	char str[MAX_STRINGS][MAX_SYMBOLS] = {0};
	FILE *input, *output;
        input = fopen ("input","r");
        output = fopen ("output","w");
        
	assert(input);
	assert(output);
	assert(!ferror(input));
	assert(!ferror(output));


	for(;fgets(str[i], sizeof(str) - 1, input);i++)
	{

	}


	qsort(str, i, MAX_SYMBOLS , compar);


	for( j = 0; j < i; j++)
	{
		fprintf(output, "%s", str[j]);

	}




	fclose (output);
	fclose (input);

	return 0;
}
