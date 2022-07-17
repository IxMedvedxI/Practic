#include <stdio.h>
#include "person.h"
#include "DataBase.h"

void help() {
	printf("comand:\nhelp\nexit\nadd fadd\ndeletelast deletekey deletemaskey\n");
	printf("print fprint\nfindkey findmaskey findkeyfile findmaskeyfile\nsort\n\n");
}

int main()
{
	char comand[100];
	comand[0] = "s";
	Person* man;
	man = createPerson("Ivanov", "Ivan", "Ivanovich", "man", 1);

	DataBase base  = createDB();
	help();
	while(strcmp(comand , "exit")) {
		printf("enter the command:\n");
		scanf("%s", comand);
		if (!strcmp(comand , "add")) {
			base = scan(base);
		}
		if (!strcmp(comand, "fadd")) {
			base = fadd(base);
		}
		if (!strcmp(comand , "deletelast")) {
			base = deletelast(base);
		}
		if (!strcmp(comand , "deletekey")) {
			base = deletekey(base);
		}
		if (!strcmp(comand , "deletemaskey")) {
			base = deletekeyArr(base);
		}
		if (!strcmp(comand , "print")) {
			DBprint(base);
		}
		if (!strcmp(comand , "fprint")) {
			fDBprint(base);
		}
		if (!strcmp(comand , "findkey")) {
			findkey(base);
		}
		if (!strcmp(comand , "findmaskey")) {
			findkeyArr(base);
		}		
		if (!strcmp(comand , "findkeyfile")) {
			findkeyfile(base);
		}
		if (!strcmp(comand, "findmaskeyfile")) {
			findkeyArrfile(base);
		}
		if (!strcmp(comand, "sort")) {
			base = sort(base);
		}if (!strcmp(comand, "help")) {
			help();
		}
	}
	DBprint(base);
}

