#pragma once
#include "person.h"

struct Person{
	char surname[100];
	char name[100];
	char patronymic[100];
	char gender[100];
	int age;
};


Person* createPerson(char* surname,char* name,char* patronymic,char* gender,int age)
{
	Person* man = malloc(sizeof(Person)); // *
	for (int i = 0; i < 100; i++) {
		man->surname[i] = surname[i];
		man->name[i] = name[i];
		man->patronymic[i] = patronymic[i];
		man->gender[i] = gender[i];
	}
	man->age = age;
	return man;
}

void detele(Person* man)
{
	free(man->surname);
	free(man->name);
	free(man->patronymic);
	free(man->gender);
	free(man->age);
}

char* getSurname(Person* man)
{
	return man->surname;
}

char* getName(Person* man)
{
	return man->name;
}

char* getPatronymic(Person* man)
{
	return man->patronymic;
}

char* getGender(Person* man)
{
	return man->gender;
}

int getAge(Person* man)
{
	return man->age;
}




void setSurname(Person* man, char surname[100])
{
	for (int i = 0; i < 100; i++) {
		man->surname[i] = surname[i];
	}
}

void setName(Person* man, char name[100])
{
	for (int i = 0; i < 100; i++) {
		man->name[i] = name[i];
	}
}

void setPatronymic(Person* man, char patronymic[100])
{
	for (int i = 0; i < 100; i++) {
		man->patronymic[i] = patronymic[i];
	}
}

void setGender(Person* man, char gender[100])
{
	for (int i = 0; i < 100; i++) {
		man->gender[i] = gender[i];
	}
}

void setAge(Person* man, int age)
{
	man->age = age;
}

void print(Person* man)
{
	printf("======================================================================================\n");
	printf("surname: %s, name: %s, patronymic: %s\n",man->surname,man->name,man->patronymic);
	printf("gender: %s, age: %d\n", man->gender, man->age);
	printf("======================================================================================\n");
}

