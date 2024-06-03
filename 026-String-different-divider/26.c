/*
Looks like it is working,
*/


#include <stdio.h>
#include <string.h>

const char* myFunc(int frontOfBack, char *line, char *divider) {

	char devChar[20];
	char *token;
	
	if( frontOfBack == 0 ){
		strcpy(devChar, divider);
		token = strchr(line, *devChar);
		memmove(token, token + strlen(divider), strlen(token));
	}else{
		strcpy(devChar, divider);
		token = strtok(line, devChar);
	}

	return token;
}

const char* myFunc1(char *line, char *divider) {
	char devChar[20];
	strcpy(devChar, divider);
	char *ptr;
	ptr = strchr(line, *devChar);
	int diviser_length = strlen(divider);
	memmove(ptr, ptr+diviser_length, strlen(ptr));
	return ptr;
}

const char* myFunc2(char *line, char *divider) {
	char *ptr;
	char devChar[20];
	strcpy(devChar, divider);
	char * token = strtok(line, devChar);
	return token;
}

int main(void) {

	/* 
	char strOriginalVer[] = "a,AAAy,sub1,end1; b,BBBeee, sub2,end2; c,Seeee, sub3,end3"; 
	char strOriginalVer[] = "1;2;3;";
	*/
	char strOriginalVer[] = "one:ONE;two:TWO;three:THREE;";
	char divider[] = ";"; /* make sure ^ and << chars match!! */

	char strWorkingCopy1[50];
	strcpy(strWorkingCopy1, strOriginalVer);	
	char strWorkingCopy2[50];
	strcpy(strWorkingCopy2, strOriginalVer);

	printf( " %s", "--ORIGINAL:    " );
	printf("%s\n", strOriginalVer);

	/* const char * temprBEFORE = myFunc1(strWorkingCopy1, divider); */
	const char * temprBEFORE = myFunc( 0, strWorkingCopy1, divider);
	printf( " %s", "--LEFTOVER:    "); 
	printf("%s\n", temprBEFORE);	

	/* const char * temprAFTER  = myFunc2(strWorkingCopy2, divider); */
	const char * temprAFTER  = myFunc( 1, strWorkingCopy2, divider);
	printf( " %s", "--FRONT-PART:  " );
 	printf("%s\n", temprAFTER);

	printf( " %s", "--ORIGINAL-Chk:" );
	printf("%s\n", strOriginalVer);
}


