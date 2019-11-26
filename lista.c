#include "lista.h"


void list_add(list **p, int value)
{
	if (*p == NULL)
	{
		list *new_el = (list*)malloc(sizeof(list));
		new_el->prev = NULL;
		new_el->data = value;
		new_el->next = NULL;
		*p = new_el;
	}
	else
	{
		list *new_el = (list*)malloc(sizeof(list));
		new_el->data = value;
		if ((*p)->data >= value)
		{
			new_el->prev = NULL;
			new_el->next = *p;
			*p = new_el;
		}
		else
		{
			while (((*p)->next != NULL) && ((*p)->next->data <= value))
			{
				p = &(*p)->next;
			}
			if ((*p)->next == NULL)
			{
				new_el->prev = *p;
				(*p)->next = new_el;
				new_el->next = NULL;
			}
			else
			{
				new_el->next = (*p)->next;
				new_el->prev = *p;
				(*p)->next = new_el;
			}
		}
	}
}

void list_show(list *p)
{
	printf("\n\n");
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void list_delete_first(list **p)
{
	if (*p != NULL)
	{
		list *tmp = *p;
		*p = (*p)->next;
		(*p)->prev = NULL;
		free(tmp);
	}
}

void list_delete_last(list **p)
{
	if (*p != NULL)
	{
		list **marker = p;
		while ((*marker)->next->next)
		{
			marker = &(*marker)->next;
		}
		list *tmp = (*marker)->next;
		(*marker)->next = NULL;
		free(tmp);
	}
}

void list_show_first(list** p)
{
	printf("Pierwszy element: %d\n", (*p)->data);
}

void list_show_last(list** p)
{
	while ((*p)->next != NULL)
		p = &(*p)->next;
	printf("Ostatni element %d\n", (*p)->data);
}

int list_find(list **p, int value)
{
	int flag = 0;
	int index = 0;
	list **marker = p;
	while (*marker != NULL)
	{
		index++;
		if ((*marker)->data == value)
		{
			flag = 1;
			break;
		}
		if ((*marker)->data > value)
			break;
		marker = &(*marker)->next;
	}
	if (flag)
	{
		printf("Element exist. Index: %d\n", index);
		return 1;
	}
	printf("Element not exist\n");
	return 0;
}

void list_find_delete(list **p, int find)
{
	int index = 0;
	list **marker = p;
	if ((*marker)->data == find)
	{
		list_delete_first(p);
		return;
	}
	while ((*marker)->next != NULL)
	{
		index++;
		if ((*marker)->next->data == find)
			break;
		marker = &(*marker)->next;
	}
	if ((*marker)->next->next != NULL)
	{
		list *tmp = (*marker)->next;
		(*marker)->next->next->prev = tmp->prev;
		(*marker)->next = (*marker)->next->next;
		free(tmp);
	}
	else
		list_delete_last(p);
}

int check_sting(char *str)
{
	int len = (int)strlen(str);
	if ((str[len - 3] == 't') && (str[len - 4] == '.') && (str[len - 2] == 'x') && (str[len - 1] == 't'))
		return 1;
	return 0;
}

void list_from_file(list **head)
{
	int value = 0;
	char file[256];
	FILE *fptr;
	do {
		printf_s("Podaj nazwe pliku: ");
		scanf("%s", &file);
		value = check_sting(file); //Sprawdza czy plik zostal podany z rozszerzeniem txt TAK - 1 NIE - 0 
		if (value)
		{
			fptr = fopen(file, "r");
			if (fptr == NULL) // Czy uda³o siê otworzyæ plik
			{
				printf("Blad otwarcia pliku.\n");
				system("PAUSE");
				fclose(fptr);
				break;
			}
			while (fscanf(fptr, "%d", &value) != EOF)
			{
				list_add(head, value);
			}
			printf("Udalo sie odczytac dane z pliku.\n");
			fclose(fptr);
			system("PAUSE");
			break;
		}
		printf("Podales zly format pliku.\n");
		system("PAUSE");
	} while (!value); // Pêtla nie zakonczy sie do momentu podania pliku z rozszerzeniem txt
}

void list_to_file(list *head)
{
	int value;
	char file[256];
	FILE *fptr;
	do {
		printf_s("Podaj nazwe pliku: ");
		scanf("%s", &file);
		value = check_sting(file); //Sprawdza czy plik zostal podany z rozszerzeniem txt TAK - 1 NIE - 0 
		if (value)
		{
			fptr = fopen(file, "w");
			if (fptr == NULL) // Czy uda³o siê otworzyæ plik
			{
				printf("Blad otwarcia pliku.\n");
				system("PAUSE");
				fclose(fptr);
				break;
			}
			while (head != NULL)
			{
				fprintf(fptr,"%d ", head->data);
				head = head->next;
			}
			printf("Udalo sie zapisac dane do pliku.\n");
			fclose(fptr);
			system("PAUSE");
			break;
		}
		printf("Podales zly format pliku.\n");
		system("PAUSE");
	} while (!value); // Pêtla nie zakonczy sie do momentu podania pliku z rozszerzeniem txt
}