/*
Uses ; as divider
Do not 'advance' this please.
Look at the next one.
26 has switch-able
*/


#include <stdio.h>
#include <string.h>

const char* myFunc1(char *line) {
	char devChar[] = ";"; /* devChar is an array */
	char *ptr;
	ptr = strchr(line, *devChar);
	
	/* 
	This bit chops off the first character!!
	It fixed the ; at the start of the line 
	*/	
	memmove(ptr, ptr+1, strlen(ptr));

	return ptr;
}


const char* myFunc2(char *line) {
/*
printf( " %s", "--TEMP:    " );
printf( " %s", line );
printf( " %s", "--/TEMP:    " );
*/


	char *ptr;
	char back_copy[40];
	char leftover_copy[40];
	char leftover_copy_mod[40];
	char devChar[] = ";"; 

	char * token = strtok(line, devChar);
/*
printf( " %s", "--TEMP:    " );
printf( " %s", token );
printf( " %s", "--/TEMP:    " );
*/

/*	memmove(token, token+1, strlen(token)); */

	return token;
}


int main(void) {

	char strOriginalVer[] = "a,AAAy;b,BBBeee;c,Seeee";

	char strWorkingCopy[50];
	strcpy(strWorkingCopy, strOriginalVer);	
	char strWorkingCopy2[50];
	strcpy(strWorkingCopy2, strOriginalVer);	

	printf( " %s", "--ORIGINAL:    " );
	printf("%s\n", strOriginalVer);

	printf( " %s", "--COPY:        " );
	printf("%s\n", strWorkingCopy);

	const char * temprBEFORE = myFunc1(strWorkingCopy);
	const char * temprBEFORE_BACKUP = temprBEFORE;
	printf( " %s", "--LEFTOVER:    "); 
	printf("%s\n", temprBEFORE_BACKUP);	

	const char * temprAFTER  = myFunc2(strWorkingCopy2);
	const char * temprAFTER_BACKUP  = temprAFTER;
	printf( " %s", "--FRONT-PART:  " );
 	printf("%s\n", temprAFTER_BACKUP);

	/*
	printf( " %s", "--ORIGINAL:    " );
	printf("%s\n", strOriginalVer);

	printf( " %s", "--COPY:        " );
	printf("%s\n", strWorkingCopy);
	*/
}


