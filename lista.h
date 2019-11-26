#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ell
{
	int data;
	struct ell *next;
	struct ell *prev;
}list;	
void list_add(list**, int);
void list_show(list*);
void list_show_last(list **);
void list_show_first(list **);
void list_delete_first(list**);
void list_delete_last(list**);
int list_find(list**, int);
void list_find_delete(list**, int);
void list_from_file(list **);
int check_sting(char *);
void list_to_file(list *);