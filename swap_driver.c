#include <stdio.h>
#include <stdlib.h>
#include "pink_moon.h"

int
main(){
	if(chars_swap_success() && int_swap_success()){
        puts("Success");
	}
	else puts("Failure");
}

int
chars_swap_success()
{
	char vals[] = {'a', 's','d','f'};

	int index;
	for(index = 0; index < 4; index++){
		printf("%c ", vals[index]);
	}
	puts("");
	swap_chars( &vals[2], &vals[0] );
	for(index = 0; index < 4; index++){
		printf("%c ", vals[index]);
	}
	puts("");
	return vals[0] == 'd' && vals[2] == 'a';
}

int
int_swap_success()
{
	int vals[] = {1,2,3,4};

	int index;
	for(index = 0; index < 4; index++){
		printf("%d ", vals[index]);
	}
	puts("");
	swap_ints( &vals[2], &vals[0] );
	for(index = 0; index < 4; index++){
		printf("%c ", vals[index]);
	}
	puts("");
	return vals[0] == 3 && vals[2] == 1;
}
