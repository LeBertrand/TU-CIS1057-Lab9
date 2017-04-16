#include <stdio.h>
#include <stdlib.h>
#include "pink_moon.h"

int
main()
{
	puts("Program begin");
	//FILE* out = fopen(lab_output.txt, "w");
    //fputs("File opened successfully", out);
    //fclose(out);

    //out = fopen("lab_output.txt", "w");

    char respect_to[4] = "asdf";
    int ages[4] = {38, 40, 21, 58};
    int lookups[4];

    //test indirect selection sort for character values
    indirect_selection_sort_char(lookups, respect_to, 4);
    int index;
	puts("selection sort chars operated successfully");
    for(index = 0; index < 4; index++){
		printf("%d: ", lookups[index]);
        printf("%c - ", respect_to[lookups[index]]);
        printf("%d , ", ages[index]);
        //fprintf(out, "%c  ", respect_to[lookups[index]]);
    }
	puts("For-loop completed");
    puts("");
    //fputc('\n', out);
    for(index = 0; index < 4; index++){
        printf("%d  ", lookups[index]);
        //fprintf(out, "%c  ", lookups[index]);
    }
    puts("");

    //test indirect selection sort for integer values
    indirect_selection_sort_int(lookups, ages, 4);
    puts("selection sort ints operated successfully\n");
    for(index = 0; index < 4; index++){
        int current = lookups[index];
		printf("%d: ", current);
        printf("%c - ", respect_to[current]);
        printf("%d,  ", ages[current]);
        //fprintf(out, "%c  ", respect_to[lookups[index]]);
    }
	puts("For-loop completed");
    puts("");
    //fputc('\n', out);
//    for(index = 0; index < 4; index++){
//        printf("%d:  ", lookups[index]);
//        printf("%d", ages[lookups[index]]);
//    }

    puts("\nWinning! Duh!");
    //fputs("Winning! Duh!", out);

    //fclose(out);

    return EXIT_SUCCESS;
}

/*
 * Function:	prompt_category
 * Programmer:	Shmuel Jacobs
 * Date:	April 16
 * Input:	none
 * Outputs:	none
 * Returns: two digit code - first digit for ascending/descending
            second digit for category
 * Globals:	none
 * Description:	Ask user to how to sort the lists and return response,
                encoded in two digit number
 */
int prompt_category()
{
    int response;
    puts("How do you want to see the data sorted?");
}
