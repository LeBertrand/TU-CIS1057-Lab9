#include <stdio.h>
#include <stdlib.h>


void copy_list(char[], char[], int);
void swap_ints(int*, int*);
void swap_chars(char*, char*);

void indirect_selection_sort_char(int lookups[], char respect_to[], const int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;

    //create copy of respect_to
    char respect_to_sorted[length];
    copy_list(respect_to, respect_to_sorted, length);
	for(index = 0; index < 4; index++){
		printf("%c ", respect_to_sorted[index]);
	}
    //setup complete...enter true sorting loop
    for( sorted_until = 0; length - sorted_until > 1; sorted_until++){
        //hold place of smallest item so far
        int loc_smallest = sorted_until;

        //find smallest item left
        for(index = sorted_until; index < length; index++){
            if(respect_to_sorted[index] < respect_to_sorted[loc_smallest]){
                loc_smallest = index;
            }
        swap_chars( &respect_to_sorted[sorted_until], &respect_to_sorted[loc_smallest]);
        swap_ints( &lookups[sorted_until], &lookups[loc_smallest]);
        }
    }
}

void copy_list(char copy_from[], char copy_to[], const int length)
{
    int index;
    for(index = 0; index < length; index++){
        copy_to[index] = copy_from[index];
    }//copy now ready
}

void swap_ints(int* first_listing, int* second_listing)
{
    if(first_listing != second_listing){
        int holder = * second_listing;
        * second_listing = * first_listing;
        * first_listing = holder;
        printf("Moving %d and %d.\n", *second_listing, *first_listing);
    }
}

void swap_chars( char* first_listing, char* second_listing)
{
    if(first_listing != second_listing){
        char holder = * second_listing;
        * second_listing = * first_listing;
        * first_listing = holder;
        printf("Moving %c and %c.\n", *second_listing, * first_listing);
    }
}
