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

	

//	static char mysql1[] = "INSERT INTO testtable (id,info) VALUES (6, 'six' );";
//	static char mysql2[] = "SELECT * from testtable;";
//	static char mysql3[] = "SELECT * from testtable WHERE id=2;";
//	static char mysql4[] = "UPDATE testtable set info = 'update 4' where id=4;";
//	static char mysql5[] = "DELETE from testtable where id=4;";




	/* 'static' is to avoid: "error: initializer element is not constant" */

//   	static char *argv1[]={"./zdb_basement", mysql1};
//   	static char *argv1[]={"./zdb_basement", mysql2};
//   	static char *argv1[]={"./zdb_basement", mysql3};
//   	static char *argv1[]={"./zdb_basement", mysql4};
//   	static char *argv1[]={"./zdb_basement", mysql5};



	/*
	IN CASE WE HAVE TO DEAL WITH char[] input and not static char[] input
	we must lean how to copy a char[] into a ___static char[]___

	1. Make a char[] (with something inside it)
	2. Copy into a new static char.
	3. The converted-static-char is now accepted by execv()
	
	IMPORTANY:
	We can Recieve the char as a 'normal' char, and convert it
	into a static char for use by execv()

	*/
	 char mysqlYYY1[] = "INSERT INTO testtable (id,info) VALUES (6, 'six' );";
	 char mysqlYYY2[] = "SELECT * from testtable;";
	 char mysqlYYY3[] = "SELECT * from testtable WHERE id=2;";
	 char mysqlYYY4[] = "UPDATE testtable set info = 'two' where id=2;";
	 char mysqlYYY5[] = "DELETE from testtable where id=6;";


	/*
	BIG DEAL -- mysqlZZZ starts life as a >> static char << so as to be 
	friends with execv().  Which is important and difficult.
	*/
	static char mysqlZZZ[128]; 
	/*Next Line important - it decides which 'function' we will carry out,
	from  mysqlYYY1 to mysqlYYY5  */

	//strcpy(mysqlZZZ, mysqlYYY1); 	//to INSERT   
	strcpy(mysqlZZZ, mysqlYYY2);  //to SELECT all  
	//strcpy(mysqlZZZ, mysqlYYY3);    //to SELECT 1  
	//strcpy(mysqlZZZ, mysqlYYY4);  //to UPDATE 
	//strcpy(mysqlZZZ, mysqlYYY5);  //to DELETE 

	/* Do Not Forget - here, we are copying 'standard' str into 'special' str (static)

	/*
	debug?
	printf("%s\n",mysqlYYY	);
	printf("%s\n",mysqlZZZ	);
	*/

	/*
	Prepare the string which is expected by execv
	*/
	static char *argv1[]={"./zdb_basement", mysqlZZZ};

	/*SIDE-NOTE
		static char some[] = "SELECT * from testtable WHERE id = 1;";
		char *p = strtok(some, ""); 
	this is not needed at the moment - leave as a ref*/



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


