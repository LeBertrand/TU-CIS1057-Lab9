/*
 * Header for Lab9.c
 * This file contains the program logic and UI.
 * Header contains all sorting and information.
 * Location:    Temple University CIS1057 Spring 2017
 * Programmer:  Shmuel Jacobs
 * Assignment:  9
 * Date:    April 14
 */

#include <stdio.h>
#include <stdlib.h>
#include "pink_moon.h"

int prompt_category();
int ascending();
void print_full_table( int lookups[], int year[], int day[], int time[], char **dow, int n );

int
main()
{
	//ask user how to sort list
	int cat = prompt_category();

	//sort list
    int order_of_access[10];
    switch(cat)
    {
        case 1: indirect_selection_sort_int(order_of_access, year_markers, num_years); break;
        case 2: indirect_selection_sort_int(order_of_access, day_markers, num_years); break;
        case 3: indirect_selection_sort_int(order_of_access, time_markers, num_years); break;
    }

    //ask whether to list ascending or descending
    int up = ascending();
    if(!up){//user chose descending display
        reverse_int_list(order_of_access, 10);
    }

    print_full_table(order_of_access, year_markers, day_markers,
        time_markers, day_of_week_markers, 10);

    return EXIT_SUCCESS;
}

/*
 * Function:	prompt_category
 * Programmer:	Shmuel Jacobs
 * Date:	April 16
 * Input:	none
 * Outputs:	none
 * Returns: integer coded to one category of values
 * Globals:	none
 * Description:	Ask user which list to sort based on and return response
 */
int prompt_category()
{
    int response;
    puts("How do you want to see the data sorted?");
    puts("[ 1 - by year, 2 - by day in April");
    puts("3 - by time of day, 4 - exit ]");
    scanf("%d", &response);
    if(response < 1 || response > 4){
        puts(INVLD_RSP_MSG);
        response = prompt_category();
    }
    return response;
}

/*
 * Function:    ascending
 * Programmer:  Shmuel Jacobs
 * Date:    April 16
 * Input:   none
 * Outputs: none
 * Returns: 1 if user chose ascending, 0 otherwise
 * Globals: none
 * Description: Ask user whether to sort in ascending or descending order
 */
/* Treat this as a boolean function.
It offers a chance to choose ascending, and if the user doesn't, it returns false */
int ascending()
{
    puts("Ascending[1] or descending[2] order?");
    int response;
    scanf("%d", &response);
    if(response != 1 && response != 2){
        puts(INVLD_RSP_MSG);
        return ascending();
    }
    return (response == 1);
}

/*
 * Function:    print_full_table
 * Programmer:  Shmuel Jacobs (modified given function)
 * Date:    April 16
 * Input:   year, day, time, dow - parallel lists giving information
            regarding the same pink moon occurrences
            lookups - list of indexes to access in other list
            (this is the sorted input, that controls order of listings)
            n - length of the lists (all lists must be at least n-long)
 * Outputs: none
 * Returns: none
 * Globals: none
 * Description: Print table of pink moon occurrences.
 */
void print_full_table( int lookups[], int year[], int day[], int time[], char **dow, int n )
{
    int look, i;

    for ( i = 0; i < n; i++ ) {
        look = lookups[i];//choose the next lookup value from the array that's sorted correctly
        int hh = time[ look ] / 100;
        int mm = time[ look ] - hh * 100;
        printf( "%d.  %s April %2d, %d at %2.2d:%2.2d.\n", i+1, dow[ look ], day[ look ], year[ look ], hh, mm );
    }

    return;
}
