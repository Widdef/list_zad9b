#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "lista.h"


void ask_value(int *value)
{
	printf("\nPodaj wartosc: ");
	scanf("%d", value);
}
void find_value(int *value)
{
	printf("\nPodaj wartosc do wyszukania: ");
	scanf("%d", value);
}


int main()
{
	list *head = NULL;
	int chose = 0;
	int value;
	int find;
	do
	{
		system("CLS");
		printf("1)Dodaj element\n");
		printf("2)Usun pierwszy element listy\n");
		printf("3)Usun ostatni element listy\n");
		printf("4)Pobierz pierwszy element\n");
		printf("5)Pobierz ostatni element\n");
		printf("6)Znajdz element\n");
		printf("7)Usun wskazany element\n");
		printf("8)Wczytaj zawartosc listy z pliku\n");
		printf("9)Zapisz zawartosc listy z pliku\n");
		printf("10)Wyswietl zawartosc listy\n");
		printf("11)Znajdz element z wartownikiem\n");
		printf("12)Usun element z wartownikiem\n");
		printf("0)Wyjscie\n");
		scanf("%d", &chose);
		switch (chose)
		{
		case 1:
			ask_value(&value);
			list_add(&head, value);
			continue;
		case 2:
			list_delete_first(&head);
			continue;
		case 3:
			list_delete_last(&head);
			continue;
		case 4:
			list_show_first(&head);
			system("PAUSE");
			continue;
		case 5:
			list_show_last(&head);
			system("PAUSE");
			continue;
		case 6:
			find_value(&find);
			list_find(&head, find);
			system("PAUSE");
			continue;
		case 7:
			find_value(&find);
			list_find_delete(&head, find);
			continue;
		case 8:
			list_from_file(&head);
			continue;
		case 9:
			list_to_file(head);
			continue;
		case 10:
			list_show(head);
			system("PAUSE");
			continue;
		case 11:
			find_value(&find);
			list_find_sentry(&head, find);
			system("PAUSE");
			continue;
		case 12:
			find_value(&find);
			list_find_delete_sentry(&head, find);
			system("PAUSE");
			continue;
		default:
			continue;
		}
	} while (chose != 0);

	free(head);
	return 0;
}