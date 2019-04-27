#include <stdio.h>

#include <stdlib.h>



#define MAX 50



typedef struct
{
    
	char item [MAX];
    
	int topo;

}Pilha;


void iniPilha(Pilha *p)
{
    
	p->topo = 0;

}


int nullPilha (Pilha *p)
{
    
	if (p->topo == 0)
	{
        
		puts("Pilha vazia");
        
		system("Pause");
        
		return(1);
    
	} else 
	{
        
		return(0);
    
	}

}


int fullPilha(Pilha *p)
{
    
	if (p->topo == MAX)    
		return(1);
    
	else        
		return (0);
    

}


int push(Pilha *p, char x)
{
    
	if (fullPilha(p)) 
		return(-1);

	else 
	{
        
		p->item[p->topo] = x;
        
		p->topo++;
        
		return(p->topo);
    
	}

}


char pop(Pilha *p)
{
    
	p->topo--;
    
	return p->item[p->topo];

}


int listar(Pilha *p)
{
    
	for(int i = 0; i < p->topo; i++)
	{
        
		char a = p->item[i];
		if(a == '#')

			break;

		printf("%c", a);
    
	}

	printf("\n");

}