
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string.h>

	char str[1000];


static int callback(void *data, int argc, char **argv, char **azColName){

	int i;
	int z;
	//fprintf(stderr, "%s: ", (const char*)data);/* print the 'Callback function...' message */

	//Unpack this to restore the Original way
	/*
	for(i = 0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	*/


	/* 
	my ver.
	try to get data only, , and ; format
	*/
	//printf("%s\n", argv[0] );


	//Unpack this to use my version --
	//to store to an aa,bb,cc;xx,yy,zz; text file
	z=1;
	for(i = 0; i<argc; i++){
		//printf("%s\n", argv[i] );
		if(z>1){
			strcat(str, ",");
		}
		strcat(str, argv[i]);
		z++;
	}
	strcat(str, ";");

   //printf("\n");
   //printf(str);
   return 0;
}


int main(int argc, char* argv[]) {

	strcpy(str, "");
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	//   const char* data = "";
	const char* data = "Callback function called";

	rc = sqlite3_open("test.db", &db);

	/*CRUD Create, Read(x2), Update, Delete */
	//sql = "INSERT INTO testtable (id,info) VALUES (11, 'eleven' );";
	sql = "SELECT * from testtable;";
	//sql = "SELECT * from testtable WHERE id=2;";
	//sql = "UPDATE testtable set info = 'update 4' where id=4;";
	//sql = "DELETE from testtable where id=4;";


	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	/*what is 'data' ????*/
	printf("%s\n",str);

	sqlite3_close(db);
	return 0;
}

// main 3 - insert -
/*
	int main(int argc, char* argv[]) {
	   sqlite3 *db;
	   char *zErrMsg = 0;
	   int rc;
	   char *sql;

	   rc = sqlite3_open("test.db", &db);
	   
		   if( rc ) {
		      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		      return(0);
		   } else {
		      fprintf(stderr, "Opened database successfully\n");
		   }

	   sql = "INSERT INTO testtable (id,info) "  \
		 "VALUES (5, 'five' );";

	   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	   
		   if( rc != SQLITE_OK ){
		      fprintf(stderr, "SQL error: %s\n", zErrMsg);
		      sqlite3_free(zErrMsg);
		   } else {
		      fprintf(stdout, "Records created successfully\n");
		   }

	   sqlite3_close(db);
	   return 0;
	}
*/

// main5 - delete
/*
int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   rc = sqlite3_open("test.db", &db);
   
	   if( rc ) {
	      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	      return(0);
	   } else {
	      fprintf(stderr, "Opened database successfully\n");
	   }

   sql = "DELETE from testtable where id=4; ";

   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
	   if( rc != SQLITE_OK ) {
	      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	      sqlite3_free(zErrMsg);
	   } else {
	      fprintf(stdout, "Operation done successfully\n");
	   }

   sqlite3_close(db);
   return 0;
}
*/





// main 4 - update
/*
int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   rc = sqlite3_open("test.db", &db);
   
	   if( rc ) {
	      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	      return(0);
	   } else {
	      fprintf(stderr, "Opened database successfully\n");
	   }

   sql = "UPDATE testtable set info = 'update 4' where id=4;";

   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
	   if( rc != SQLITE_OK ) {
	      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	      sqlite3_free(zErrMsg);
	   } else {
	      fprintf(stdout, "Operation done successfully\n");
	   }

   sqlite3_close(db);
   return 0;
}



/*
// main 2 - read
	int main(int argc, char* argv[]) {
	   sqlite3 *db;
	   char *zErrMsg = 0;
	   int rc;
	   char *sql;
	   const char* data = "Callback function called";

	   rc = sqlite3_open("test.db", &db);
	   
		   if( rc ) {
		      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		      return(0);
		   } else {
		      fprintf(stderr, "Opened database successfully\n");
		   }

	   sql = "SELECT * from testtable";

	   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	   
		   if( rc != SQLITE_OK ) {
		      fprintf(stderr, "SQL error: %s\n", zErrMsg);
		      sqlite3_free(zErrMsg);
		   } else {
		      fprintf(stdout, "Operation done successfully\n");
		   }

	   sqlite3_close(db);
	   return 0;
	}
*/


/*
// main 1 - basic check
	int main(int argc, char* argv[]) {
	   sqlite3 *db;

	   char *zErrMsg = 0;
	   int rc;
	   rc = sqlite3_open("test.db", &db);
	   if( rc ) {
	      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	      return(0);
	   } else {
	      fprintf(stderr, "Opened database successfully\n");
	   }
	   sqlite3_close(db);
	}
*/
