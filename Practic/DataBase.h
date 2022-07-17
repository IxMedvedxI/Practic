#pragma once
#include "person.h"

struct DataBase{
	Person* data[100];
} ;
typedef struct DataBase DataBase;

DataBase createDB() {
	Person* man = createPerson(" ", " ", " ", " ", NULL);
	DataBase base ;
	for (int i = 0; i < 100; i++) {
		base.data[i] = man;
	}
	return base;
}

DataBase scan(DataBase db) {
	int n = 0, j = 0;
	int age = 0;
	char surname[100];
	char name[100];
	char patronymic[100];
	char gender[100];
	printf("write the number of people\n");
	scanf("%d", &n);
	for (; getAge(db.data[j]) != NULL;j++);
	for (int i = j; i < n+j; i++) {
		printf("enter %d people fullname,gender,age separated by a space:\n",i+1-j);
		scanf("%s%s%s%s%d", surname,name,patronymic,gender,&age);
		db.data[i] = createPerson(surname, name, patronymic, gender, age);
	}
	return db;
}
DataBase fadd(DataBase base) {
	int j = 0;
	int age = 0;
	char surname[100];
	char name[100];
	char patronymic[100];
	char gender[100];
	char filename[100];
	printf("File name:\n");
	scanf("%s", filename);
	FILE* file = fopen(filename, "r");;
	for (; getAge(base.data[j]) != NULL; j++);
	while (!feof(file)) {
		fscanf(file, "%s%s%s%s%d", surname, name, patronymic, gender, &age);
		base.data[j] = createPerson(surname, name, patronymic, gender, age);
		j++;
	}
	fclose(file);
	base.data[j - 1] = createPerson(" ", " ", " ", " ", NULL);
	return base;
}

void DBprint(DataBase db) {
	for (int i = 0; getAge(db.data[i]) != NULL;i++) {
		print(db.data[i]);
	}
}
void fDBprint(DataBase base) {
	char filename[100];
	printf("File name:\n");
	scanf("%s", filename);
	FILE* file = fopen(filename, "w");
	for (int j = 0; getAge(base.data[j]) != NULL; j++) {
		fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
	}
	fclose(file);
}

int key() {
	char str[100];
	printf("enter the type key(surname,namen,patronymic,gender,age):\n");
	scanf("%s", str);
	if (!strcmp(str, "surname")) return 1;
	if (!strcmp(str, "name")) return 2;
	if (!strcmp(str, "patronymic")) return 3;
	if (!strcmp(str, "gender")) return 4;
	if (!strcmp(str, "age")) return 5;
	return 0;
}
DataBase nulswap(DataBase base) {
	Person* bufer;
	Person* null = createPerson(" ", " ", " ", " ", NULL);
	int i;
	for (i = 0; getAge(base.data[i]) != NULL; i++);
	for (int j = i; j < 100; j++) {
		if (getAge(base.data[j]) != NULL) {
			bufer = base.data[j];
			base.data[j] = null;
			base.data[i] = bufer;
			i++;
		}
	}
	return base;
}

DataBase deletelast(DataBase base) {
	int j = 0;
	for (; getAge(base.data[j]) != NULL; j++);
	if (j == 0) return base;
	base.data[j - 1] = createPerson(" ", " ", " ", " ", NULL);
	return base;
}
DataBase deletekey(DataBase base) {
	int j = 0;
	int nkey = key();
	char skey[100];
	int sdkey = 0;
	Person* null = createPerson(" ", " ", " ", " ", NULL);
	printf("enter key:\n");
	if (nkey >= 1 && nkey < 5) {
		scanf("%s", skey);
	}
	else if (nkey == 5) {
		scanf("%d", &sdkey);
	}
	else {
		printf("not this key");
	}
	for (; getAge(base.data[j]) != NULL; j++) {
		switch (nkey)
		{
		case 1:
			if (!strcmp(getSurname(base.data[j]), skey)) base.data[j] = null;
			break;
		case 2:
			if (!strcmp(getName(base.data[j]), skey)) base.data[j] = null;
			break;
		case 3:
			if (!strcmp(getPatronymic(base.data[j]), skey)) base.data[j] = null;
			break;
		case 4:
			if (!strcmp(getGender(base.data[j]), skey)) base.data[j] = null;
			break;
		case 5:
			if (getAge(base.data[j]) == sdkey) base.data[j] = null;
			break;
		default:
			break;
		}
	}
	base = nulswap(base);
	return base;
}
DataBase deletekeyArr(DataBase base) {
	int nkey = key(),count = 0;
	char skey[100];
	int sdkey = 0;
	Person* null = createPerson(" ", " ", " ", " ", NULL);
	printf("enter count key:\n");
	scanf("%d", &count);
	for (int g = 0; g < count; g++) {
		printf("enter %d key:\n", g+1);
		if (nkey >= 1 && nkey < 5) {
			scanf("%s", skey);
		}
		else if (nkey == 5) {
			scanf("%d", &sdkey);
		}
		else {
			printf("not this key");
		}
		for (int j = 0; getAge(base.data[j]) != NULL; j++) {
			switch (nkey)
			{
			case 1:
				if (!strcmp(getSurname(base.data[j]), skey)) base.data[j] = null;
				break;
			case 2:
				if (!strcmp(getName(base.data[j]), skey)) base.data[j] = null;
				break;
			case 3:
				if (!strcmp(getPatronymic(base.data[j]), skey)) base.data[j] = null;
				break;
			case 4:
				if (!strcmp(getGender(base.data[j]), skey)) base.data[j] = null;
				break;
			case 5:
				if (getAge(base.data[j]) == sdkey) base.data[j] = null;
				break;
			default:
				break;
			}
		}
		base = nulswap(base);
	}	
	return base;
}

void findkey(DataBase base) {
	int j = 0;
	int nkey = key();
	char skey[100];
	int sdkey = 0;
	Person* null = createPerson(" ", " ", " ", " ", NULL);
	printf("enter key:\n");
	if (nkey >= 1 && nkey < 5) {
		scanf("%s", skey);
	}
	else if (nkey == 5) {
		scanf("%d", &sdkey);
	}
	else {
		printf("not this key");
	}
	for (; getAge(base.data[j]) != NULL; j++) {
		switch (nkey)
		{
		case 1:
			if (!strcmp(getSurname(base.data[j]), skey)) print(base.data[j]);
			break;
		case 2:
			if (!strcmp(getName(base.data[j]), skey)) print(base.data[j]);
			break;
		case 3:
			if (!strcmp(getPatronymic(base.data[j]), skey)) print(base.data[j]);
			break;
		case 4:
			if (!strcmp(getGender(base.data[j]), skey)) print(base.data[j]);
			break;
		case 5:
			if (getAge(base.data[j]) == sdkey) print(base.data[j]);
			break;
		default:
			break;
		}
	}
}
void findkeyArr(DataBase base) {
	int nkey = key(), count = 0;
	char skey[100];
	int sdkey = 0;
	Person* null = createPerson(" ", " ", " ", " ", NULL);
	printf("enter count key:\n");
	scanf("%d", &count);
	for (int g = 0; g < count; g++) {
		printf("enter %d key:\n", g + 1);
		if (nkey >= 1 && nkey < 5) {
			scanf("%s", skey);
		}
		else if (nkey == 5) {
			scanf("%d", &sdkey);
		}
		else {
			printf("not this key");
		}
		for (int j = 0; getAge(base.data[j]) != NULL; j++) {
			switch (nkey)
			{
			case 1:
				if (!strcmp(getSurname(base.data[j]), skey)) print(base.data[j]);
				break;
			case 2:
				if (!strcmp(getName(base.data[j]), skey)) print(base.data[j]);
				break;
			case 3:
				if (!strcmp(getPatronymic(base.data[j]), skey)) print(base.data[j]);
				break;
			case 4:
				if (!strcmp(getGender(base.data[j]), skey)) print(base.data[j]);
				break;
			case 5:
				if (getAge(base.data[j]) == sdkey) print(base.data[j]);
				break;
			default:
				break;
			}
		}
	}
}
void findkeyfile(DataBase base) {
	int j = 0;
	int nkey = key();
	char skey[100];
	int sdkey = 0;
	Person* null = createPerson(" ", " ", " ", " ", NULL);
	char filename[100];
	printf("File name:\n");
	scanf("%s", filename);
	FILE* file = fopen(filename, "w");
	printf("enter key:\n");
	if (nkey >= 1 && nkey < 5) {
		scanf("%s", skey);
	}
	else if (nkey == 5) {
		scanf("%d", &sdkey);
	}
	else {
		printf("not this key");
	}
	for (; getAge(base.data[j]) != NULL; j++) {
		switch (nkey)
		{
		case 1:
			if (!strcmp(getSurname(base.data[j]), skey)) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
			break;
		case 2:
			if (!strcmp(getName(base.data[j]), skey)) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
			break;
		case 3:
			if (!strcmp(getPatronymic(base.data[j]), skey)) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
			break;
		case 4:
			if (!strcmp(getGender(base.data[j]), skey)) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
			break;
		case 5:
			if (getAge(base.data[j]) == sdkey) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
			break;
		default:
			break;
		}
	}
	fclose(file);
}
void findkeyArrfile(DataBase base) {
	int nkey = key(), count = 0;
	char skey[100];
	int sdkey = 0;
	Person* null = createPerson(" ", " ", " ", " ", NULL);
	char filename[100];
	printf("File name:\n");
	scanf("%s", filename);
	FILE* file = fopen(filename, "w");
	printf("enter count key:\n");
	scanf("%d", &count);
	for (int g = 0; g < count; g++) {
		printf("enter %d key:\n", g + 1);
		if (nkey >= 1 && nkey < 5) {
			scanf("%s", skey);
		}
		else if (nkey == 5) {
			scanf("%d", &sdkey);
		}
		else {
			printf("not this key");
		}
		for (int j = 0; getAge(base.data[j]) != NULL; j++) {
			switch (nkey)
			{
			case 1:
				if (!strcmp(getSurname(base.data[j]), skey)) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
				break;
			case 2:
				if (!strcmp(getName(base.data[j]), skey)) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
				break;
			case 3:
				if (!strcmp(getPatronymic(base.data[j]), skey)) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
				break;
			case 4:
				if (!strcmp(getGender(base.data[j]), skey)) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
				break;
			case 5:
				if (getAge(base.data[j]) == sdkey) fprintf(file, "%s %s %s %s %d\n", getSurname(base.data[j]), getName(base.data[j]), getPatronymic(base.data[j]), getGender(base.data[j]), getAge(base.data[j]));
				break;
			default:
				break;
			}
		}
	}
	fclose(file);
}

DataBase sort(DataBase base) {
	Person* buf;
	int nkey = key();
	for (int j = 0; getAge(base.data[j+1]) != NULL; j++) {
		switch (nkey)
		{
		case 1:
			if (strcmp(getSurname(base.data[j]), getSurname(base.data[j + 1])) > 0) {
				buf = base.data[j];
				base.data[j] = base.data[j+1];
				base.data[j + 1] = buf;
				j = 0;
			}
			break;
		case 2:
			if (strcmp(getName(base.data[j]), getName(base.data[j + 1])) > 0) {
				buf = base.data[j];
				base.data[j] = base.data[j + 1];
				base.data[j + 1] = buf;
				j = 0;
			}
			break;
		case 3:
			if (strcmp(getPatronymic(base.data[j]), getPatronymic(base.data[j + 1])) > 0) {
				buf = base.data[j];
				base.data[j] = base.data[j + 1];
				base.data[j + 1] = buf;
				j = 0;
			}
			break;
		case 4:
			if (strcmp(getGender(base.data[j]), getGender(base.data[j + 1])) > 0) {
				buf = base.data[j];
				base.data[j] = base.data[j + 1];
				base.data[j + 1] = buf;
				j = 0;
			}
			break;
		case 5:
			if (getAge(base.data[j]) > getAge(base.data[j + 1])) {
				buf = base.data[j];
				base.data[j] = base.data[j + 1];
				base.data[j + 1] = buf;
				j = 0;
			}
			break;
		default:
			break;
		}
	}
	return base;
}
