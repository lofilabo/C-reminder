#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "a,AAAy;b,BBBeee;c,Seeee";
	char devChar[] = ";"; /* devChar is an array */
	char *ptr;
	char back_copy[40];
	char leftover_copy[40];
	char leftover_copy_mod[40];

	/*
	Before we do anything else, make a backup
	copy of the string
	*/
	strcpy(back_copy, str);

	/*
	SECTION 1. 'before' the character
	*/
	ptr = strchr(str, *devChar);/* devChar is the Delineation of a pointer here */
	printf( " %s", "Original:               " );
	printf( " %s\n", str );
	printf( " %s", "Check leftover:         " );
	printf( " %s\n", ptr );

	/*
	Now,Before we call strtok, make a backup
	copy of the ptr
	*/

	/*
	SECTION 2. 'after' the character
	*/
	strcpy(leftover_copy, ptr);

	char * token = strtok(str, devChar);/*devChar is a Pointer here*/

	strcpy(leftover_copy_mod, leftover_copy);

	/*
	Biggie!
	Cut off the First character (";"....maybe "," too)
	;b,BBBeee;c,Seeee  BECOMES b,BBBeee;c,Seeee
	**AND It's THE SAME VAR**	
	*/
    	memmove(leftover_copy, leftover_copy+1, strlen(leftover_copy));

	/*
	Do Not change anything afer this point.
	Check to see if the variables are what you think they are....
	and don't change them :)
	*/
	printf( " %s", "***********************************************\n*******DEBUG OVER. FINAL RESULTS***************\n***********************************************\n" );

	printf( " %s", "FIRST PART:           " );
	printf( " %s\n", token );

	printf( " %s", "ORIGINAL (side copy): " );
	printf( " %s\n", back_copy );

	printf( " %s", "LEFTOVER(for next):   " );
	printf( " %s\n", leftover_copy );

	/*
	return token (to get 'selected')
	return leftover_copy (to get 'the rest')
	*/


}
