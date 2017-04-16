#include <stdio.h>
#include <stdlib.h>

/*
 * Take four parallel arrays, which list respectively, years, day of April,
 * time of day and day of the week. This set of four arrays represent time and date
 * of appearance of pink moon. Allow user to sort by year, date, or time.
 * of 1000 cubic feet per second.
 * Location:	Temple University CIS1057 Spring 2017
 * Programmer:	Shmuel Jacobs
 * Assignment:	9
 * Date:	April 14
 */


void copy_char_list(char[], char[], int);
void copy_int_list(int[], int[], int);
void swap_ints(int*, int*);
void swap_chars(char*, char*);

/*
 * Function:	indirect_selection_sort_char
 * Programmer:	Shmuel Jacobs
 * Date:	April 14
 * Input:	respect_to - list of values to form the basis of new sort
            length - number of pink moons listed
 * Outputs:	lookups - order in which items in lists should be after sort
 * Returns: none
 * Globals:	none
 *			CHANNEL_SLOPE	-	slope of channel stated rise over run
 * Desription:	Given a channel depth, calculate cubic feet per second
 * of water flowing through.
 */
void indirect_selection_sort_char(int lookups[], char respect_to[], const int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;

    /*Create copy of respect_to, and set lookups to assume
    respect_to is in order,	so that later swaps move what we expect*/
    char respect_to_sorted[length];
    copy_char_list(respect_to, respect_to_sorted, length);
	for(index = 0; index < 4; index++){
        lookups[index] = index;
		printf("%c ", respect_to_sorted[index]);
	}
	puts("");
    //setup complete...enter true sorting loop
    for( sorted_until = 0; sorted_until < length; sorted_until++){
        //hold place of smallest item so far
        int loc_smallest = sorted_until;

        //find smallest item left
        for(index = sorted_until; index < length; index++){
            if(respect_to_sorted[index] < respect_to_sorted[loc_smallest]){
                loc_smallest = index;
            }
        }
        //once position of smallest if found, swap
        swap_chars( &respect_to_sorted[sorted_until], &respect_to_sorted[loc_smallest]);
        swap_ints( &lookups[sorted_until], &lookups[loc_smallest]);
    }
}

void indirect_selection_sort_int(int lookups[], int respect_to[], const int length)
{
    //The sublist containing all indices less than this number is sorted
    int sorted_until;

    //inner counting loop will use this
    int index;

    /*Create copy of respect_to, and set lookups to assume
    respect_to is in order,	so that later swaps move what we expect*/
    int respect_to_sorted[length];
    copy_int_list(respect_to, respect_to_sorted, length);
	for(index = 0; index < 4; index++){
        lookups[index] = index;
		printf("%d ", respect_to_sorted[index]);
	}
	puts("");



    //setup complete...enter true sorting loop
    for( sorted_until = 0; sorted_until < length; sorted_until++){
        //hold place of smallest item so far
        int loc_smallest = sorted_until;

        //find smallest item left
        for(index = sorted_until; index < length; index++){
            if(respect_to_sorted[index] < respect_to_sorted[loc_smallest]){
                loc_smallest = index;
            }
        }
        swap_ints( &respect_to_sorted[sorted_until], &respect_to_sorted[loc_smallest]);
        swap_ints( &lookups[sorted_until], &lookups[loc_smallest]);
    }
}

void copy_char_list(char copy_from[], char copy_to[], const int length)
{
    int index;
    for(index = 0; index < length; index++){
        copy_to[index] = copy_from[index];
    }//copy now ready
}

void copy_int_list(int copy_from[], int copy_to[], const int length)
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
