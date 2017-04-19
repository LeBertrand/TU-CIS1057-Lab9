#include <stdio.h>
#include <stdlib.h>
#include "pink_moon.h"

int
main()
{
	int vals[5];
	int index;
	for(index = 0; index < 5; index++){
		scanf("%d", &vals[index]);
	}
	for(index = 0; index < 5; index++){
		printf("%d ", vals[index]);
	}
	puts("");
	reverse_int_list(vals, 5);
	for(index = 0; index < 5; index++){
		printf("%d ", vals[index]);
	}
	scanf("%d", vals);
}
