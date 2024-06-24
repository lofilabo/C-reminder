#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */


int main()
{
    pid_t pid=fork();
    if (pid==0) { /* child process */

	 char mysqlYYY1[] = "INSERT INTO testtable (id,info) VALUES (7, 'seven' );";
	 char mysqlYYY2[] = "SELECT * from testtable;";
	 char mysqlYYY3[] = "SELECT * from testtable WHERE id=7;";
	 char mysqlYYY4[] = "UPDATE testtable set info = 'SEVVVUN' where id=7;";
	 char mysqlYYY5[] = "DELETE from testtable where id=7;";

	static char mysqlZZZ[128]; 

	/* copy string from 'non-static' to 'static' */
	strcpy(mysqlZZZ, mysqlYYY3);  //to DELETE 

	static char *argv1[]={"./zdb_basement", mysqlZZZ};
	execv("./zdb_basement",argv1);
        printf("%s\n","maybe captured here.");
    }
    else { /* pid!=0; parent process */
        waitpid(pid,0,0); /* wait for child to exit */
    }

    printf("%s\n","You Escaped!");

    return 0;
}


