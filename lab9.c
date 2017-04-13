#include <stdio.h>
#include <stdlib.h>
#include <parallel_array_sort.h>

int
main()
{
	puts("Program begin");
	//FILE* out = fopen(lab_output.txt, "w");
    //fputs("File opened successfully", out);
    //fclose(out);

    //out = fopen("lab_output.txt", "w");

    char respect_to[4] = "asdf";
    int lookups[4] = {0,1,2,3};


    indirect_selection_sort_char(lookups, respect_to, 4);
    int index;
	puts("selection sort operated successfully");
    for(index = 0; index < 4; index++){
		printf("%d: ,", lookups[index]);
        printf("%c  ", respect_to[lookups[index]]);
        //fprintf(out, "%c  ", respect_to[lookups[index]]);
    }
	puts("For-loop completed");
    puts("");
    //fputc('\n', out);
    for(index = 0; index < 4; index++){
        printf("%c  ", lookups[index]);
        //fprintf(out, "%c  ", lookups[index]);
    }
    puts("Winning! Duh!");
    //fputs("Winning! Duh!", out);

    //fclose(out);

    return EXIT_SUCCESS;
}
