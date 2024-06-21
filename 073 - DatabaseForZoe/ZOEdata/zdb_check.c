
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

int main()
{
    /*Spawn a child to run the program.*/
    pid_t pid=fork();
    if (pid==0) { /* child process */


	/*
	CRUD Create, Read(x2), Update, Delete 
	examples of the SQL to pass in at ./1 "some-sql-here"
	*/
	//"INSERT INTO testtable (id,info) VALUES (11, 'eleven' );";
	//"SELECT * from testtable;";
	//"SELECT * from testtable WHERE id=2;                               	";
	//"UPDATE testtable set info = 'update 4' where id=4;";
	//"DELETE from testtable where id=4;";

        //	static char *argv[]={"./zdb_basement","SELECT * from testtable;"};
        //	static char *argv[]={"./zdb_basement","SELECT * from testtable WHERE id = 1;"};
        //	static char *argv[]={"./zdb_basement","SELECT * from testtable WHERE id > 2;"};
        	static char *argv[]={"./zdb_basement","INSERT INTO testtable (id,info) VALUES (11, 'Eleven' );"};
        //	static char *argv[]={"./zdb_basement","    ;"};
        
        execv("./zdb_basement",argv);
        exit(127); /* only if execv fails */
    }
    else { /* pid!=0; parent process */
        waitpid(pid,0,0); /* wait for child to exit */
    }
    return 0;
}


