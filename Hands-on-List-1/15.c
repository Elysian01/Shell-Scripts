/* environment variable
lib c define a global variable "environ " which is pointer to the lists of environment variables
Each variable has name and values. By convention, names are upper case and and values are Strings. They are used to communicate to programs how machine is setup and sometimes to control the behaviour of program.
*/

#include<stdio.h>
#include<stdlib.h>


extern char **environ;

int main(){

	for(int i=0;environ[i]!=NULL;i++){
		printf("%d. %s\n \n",i,environ[i]);
	}

	printf(".......................................................\n");
	printf("using getenv() function\n");
	char *value=getenv("SHELL");
	printf("SHELL: %s \n",value);
	return 0;
}
