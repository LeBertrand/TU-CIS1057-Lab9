/*
 * Header for Lab9.c
 * Take four parallel arrays, which list respectively, years, day of April,
 * time of day and day of the week. This set of four arrays represent time and date
 * of appearance of pink moon. Allow user to sort by year, date, or time.
 * of 1000 cubic feet per second.
 * Location:	Temple University CIS1057 Spring 2017
 * Programmer:	Shmuel Jacobs
 * Assignment:	9
 * Date:	April 14
 */

#ifndef PINK_MOON_H
#define PINK_MOON_H

int year_markers[] = { 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, };
int day_markers[] = { 18, 6, 25, 15, 4, 22, 11, 30, 19, 8, };
int time_markers[] = { 244, 1919, 1957, 742, 1206, 524, 608, 58, 1112, 235, };
char *day_of_week_markers[] = { "Mon", "Fri", "Thu", "Tue", "Sat", "Fri", "Tue", "Mon", "Fri", "Sat", };
const char* INVLD_RSP_MSG = "Please choose a response listed above.";
const int num_years = sizeof year_markers/ sizeof year_markers[0];

void copy_char_list(char[], char[], int);
void copy_int_list(int[], int[], int);
void swap_ints(int*, int*);
void swap_chars(char*, char*);

/*
 * Function:	indirect_selection_sort_char
 * Programmer:	Shmuel Jacobs
 * Date:	April 14
 * Input:	respect_to - list of chars to form the basis of new sort
            length - number of pink moons listed
 * Outputs:	lookups - ordinal value of items in matching places in respect_to
 * Returns: none
 * Globals:	none
 * Description:	Given an array of values, fill an array of indexes
                to indicate the appropriate order elements of the first.
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
	for(index = 0; index < length; index++){
        lookups[index] = index;
	}
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

/*
 * Function:	indirect_selection_sort_char
 * Programmer:	Shmuel Jacobs
 * Date:	April 14
 * Input:	respect_to - list of chars to form the basis of new sort
            length - number of pink moons listed
 * Outputs:	lookups - ordinal value of items in matching places in respect_to
 * Returns: none
 * Globals:	none
 * Description:	Given an array of values, fill an array of indexes
                to indicate the appropriate order elements of the first.
 */
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
	for(index = 0; index < length; index++){
        lookups[index] = index;
	}

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

/*
 * Function:	copy_char_list
 * Programmer:	Shmuel Jacobs
 * Date:	April 14
 * Input:	copy_from - list of characters to copy
 * Outputs:	copy_to - copy of the input list
 * Returns: none
 * Globals:	none
 * Description:	Copy a list of characters from the input list
                to the output list.
 */
void copy_char_list(char copy_from[], char copy_to[], const int length)
{
    int index;
    for(index = 0; index < length; index++){
        copy_to[index] = copy_from[index];
    }//copy now ready
}

/*
 * Function:	copy_int_list
 * Programmer:	Shmuel Jacobs
 * Date:	April 14
 * Input:	copy_from - list of integers to copy
 * Outputs:	copy_to - copy of the input list
 * Returns: none
 * Globals:	none
 * Description:	Copy a list of integers from the input list
                to the output list.
 */
void copy_int_list(int copy_from[], int copy_to[], const int length)
{
    int index;
    for(index = 0; index < length; index++){
        copy_to[index] = copy_from[index];
    }//copy now ready
}

/*
 * Function:	swap_ints
 * Programmer:	Shmuel Jacobs
 * Date:	April 14
 * Input:	first_listing, second_listing - locations of values to swap
 * Outputs:	first_listing, second_listing
 * Returns: none
 * Globals:	none
 * Description:	Swap the locations of two integers.
 */
void swap_ints(int* first_listing, int* second_listing)
{
    if(first_listing != second_listing){
        int holder = * second_listing;
        * second_listing = * first_listing;
        * first_listing = holder;
    }
}

/*
 * Function:	swap_chars
 * Programmer:	Shmuel Jacobs
 * Date:	April 14
 * Input:	first_listing, second_listing - locations of values to swap
 * Outputs:	first_listing, second_listing
 * Returns: none
 * Globals:	none
 * Description:	Swap the locations of two characters.
 */
void swap_chars( char* first_listing, char* second_listing)
{
    if(first_listing != second_listing){
        char holder = * second_listing;
        * second_listing = * first_listing;
        * first_listing = holder;
    }
}

/*
 * Function:	reverse_int_list
 * Programmer:	Shmuel Jacobs
 * Date:	April 16
 * Input:	int_list - list of integers
            length - number of items in list
 * Outputs:	int_list
 * Returns: none
 * Globals:	none
 * Description:	Reverse the order of input list
 */
 void reverse_int_list(int int_list[], int length)
 {
     int index;
        //reverse current order
        for(index = 0; index < length/2 ; index++){
            swap_ints( &int_list[index], &int_list[length - index - 1]);
        }
 }
#endif
