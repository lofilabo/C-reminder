#include <string.h>
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

	

	static char mysql1[] = "INSERT INTO testtable (id,info) VALUES (6, 'six' );";
	static char mysql2[] = "SELECT * from testtable;";
	static char mysql3[] = "SELECT * from testtable WHERE id=2;";
	static char mysql4[] = "UPDATE testtable set info = 'update 4' where id=4;";
	static char mysql5[] = "DELETE from testtable where id=4;";

	/*SIDE-NOTE
		static char some[] = "SELECT * from testtable WHERE id = 1;";
		char *p = strtok(some, ""); 
	this is not needed at the moment - leave as a ref*/


	/* 'static' is to avoid: "error: initializer element is not constant" */

//   	static char *argv1[]={"./zdb_basement", mysql1};
   	static char *argv1[]={"./zdb_basement", mysql2};
//   	static char *argv1[]={"./zdb_basement", mysql3};
//   	static char *argv1[]={"./zdb_basement", mysql4};
//   	static char *argv1[]={"./zdb_basement", mysql5};

	execv("./zdb_basement",argv1);

	/*One will work....but 2 will not!! */
   	//static char *argv2[]={"./zdb_basement", mysql3};
	//execv("./zdb_basement",argv2);

	/*Keep for Reference for now*/
        //exit(127); /* only if execv fails */
        //	static char *argv[]={"./zdb_basement","SELECT * from testtable;"};
        //	static char *argv[]={"./zdb_basement", some};
        //	static char *argv[]={"./zdb_basement","SELECT * from testtable WHERE id > 2;"};
        //	static char *argv[]={"./zdb_basement","INSERT INTO testtable (id,info) VALUES (20, 'Twenty' );"};
        //	static char *argv[]={"./zdb_basement","    ;"};
        
    }
    else { /* pid!=0; parent process */
        waitpid(pid,0,0); /* wait for child to exit */
    }
    return 0;
}


