#pragma once
#ifndef PERSON_H
#define PERSON_h
#include <stdio.h>
#include <string.h>

struct Person;

typedef struct Person Person;

Person* createPerson(char* surname, char* name, char* patronymic, char* gender, int age);

void detele(Person* man);

char* getSurname(Person* man);
char* getName(Person* man);
char* getPatronymic(Person* man);
char* getGender(Person* man);
int getAge(Person* man);

void setSurname(Person* man,char surname[100]);
void setName(Person* man,char name[100]);
void setPatronymic(Person* man,char patronymic[100]);
void setGender(Person* man, char gender[100]);
void setAge(Person* man, int age);

void print(Person* man);
#endif