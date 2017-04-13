#include <stdio.h>
#include <stdlib.h>
#include <parallel_array_sort.h>

int
main(){
	char vals[] = {'a', 's','d','f'};

	int index;
	for(index = 0; index < 4; index++){
		printf("%c ", vals[index]);
	}
	swap_chars( &vals[2], &vals[0] );
	for(index = 0; index < 4; index++){
		printf("%c ", vals[index]);
	}
}