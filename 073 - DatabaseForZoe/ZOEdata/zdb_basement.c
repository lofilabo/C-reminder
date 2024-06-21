
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string.h>

char str[1000];

static int callback(void *data, int argc, char **argv, char **azColName){
	int i;
	int z;
	z=1;
	for(i = 0; i<argc; i++){
		if(z>1){
			strcat(str, ",");
		}
		strcat(str, argv[i]);
		z++;
	}
	strcat(str, ";");
   return 0;
}


char* main(int argc, char* argv[]) {

	/*
	   if( argc == 2 ) {
	      printf("The SQL supplied is %s\n", argv[1]); 
	   }
	   else if( argc > 2 ) {
	      printf("Too many argus.\n");
	   }
	   else {
	      printf("No SQL.\n");
	   }

	if( argc > 2 ) {
		printf("Some SQL please. %s\n", argv[1]); 
		return 0;
	}
	*/
	if( argc == 2 ) {
		strcpy(str, "");
		sqlite3 *db;
		char *zErrMsg = 0;
		int rc;
		char *sql;
		const char* data = "Callback function called";
		rc = sqlite3_open("./zdb_data.db", &db);
		/*
		CRUD Create, Read(x2), Update, Delete 
		examples of the SQL to pass in at ./1 "some-sql-here"
		*/
		//sql = "INSERT INTO testtable (id,info) VALUES (11, 'eleven' );";
		//sql = "SELECT * from testtable;";
		//sql = "SELECT * from testtable WHERE id=2;                               	";
		//sql = "UPDATE testtable set info = 'update 4' where id=4;";
		//sql = "DELETE from testtable where id=4;";

		sql = argv[1];
		rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
		printf("%s\n",str);
		sqlite3_close(db);

char *filename = "zdb_output_data.txt";/*Open file*/
FILE *fp = fopen(filename, "w");
fprintf(fp,  str);

	}else {
	      printf("No SQL; wrong number of args.\n");
	}

	return str;
}

