#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include "pilha.h"

#include <string.h>

#define MAXSIZE 50



int main()
{


	Pilha l;

	Pilha c;


	iniPilha(&l);

	iniPilha(&c);


	char vet[MAXSIZE];

	for(int i=0; i<MAXSIZE; i++)
	{

		vet[i] = '#';

	}

	printf("Expresao a ser analisada: ");

	scanf("%s", vet);


	for(int i=0; i<MAXSIZE; i++)
	{

		char a = vet[i];

		if(a == '/')
		{

            char h = pop(&c);
            if ( h != '(')
                push(&l, h);

			push(&l, vet[i+1]);

			push(&l, a);

			push(&c, vet[i+2]);

			push(&l, vet[i+3]);

			do{

				int aux5 = pop(&c);

				if(aux5 != '(')
				{

					push(&l, aux5);

				}

			}while(c.topo != 0);

			i+=3;

		}

		if(a == '*' || a == '+' || a == '-' || a == '(')
		{

			push(&c, a);

		}

		if(a == ')')
		{

			int cont = 2;

			do{

				char x = pop(&c);

				if(c.topo == 0)

					push(&c, '(');

				if(x == '(')

					cont--;

				else

					push(&l, x);

			}while((cont != 0));

		}

		if(a != '*' && a != '+' && a != '/' && a != '-' && a != '(' && a != ')')

			push(&l, a);

	}

	listar(&l);

	system("Pause");

}
