#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 5000


//Tira todo o lixo que está na variavel para que ela possa receber as stringns.
void zerarpalavra(char *frase)
	{
		int i;
		for(i=0; i<=TAMANHO; i++)
		frase[i]='\0';//coloca um \0 em cada posição do vetor.
	}

//Le a frase que vai ser criptografada.
char *lerDados()
{
	char *discurso;
	discurso = (char *)malloc(TAMANHO * sizeof (char));
	zerarpalavra(discurso);
	printf("Digite o Discurso\n");
	gets (discurso);//le do usuario a frase.
	return discurso;
}


char *eliminarCorrupcao(char *discurso) //Tira da frase todas as palavras 'corrupcao'.
{
	char *auxiliar = (char *)malloc(TAMANHO * sizeof (char));
	char *final = (char *)malloc(TAMANHO * sizeof (char));
	zerarpalavra(auxiliar);
	zerarpalavra(final);
	
	int i, tam=0, k=0;
	
	tam=strlen(discurso);//Conta quantos caracteres tem na variavel 'discurso'.
	
	for(i=0; i<=tam; i++)
	{
		auxiliar[k]=discurso[i];//Quebra a string em substrings.
		k++;
		if ((discurso[i]==' ')|| (discurso[i]=='\0'))//Se for encontrado um espaco ou um \0 vai comparar a susbstring com 'corrupcao'.
		{
			if ((strcmp(auxiliar,"corrupcao ")==0)||(strcmp(auxiliar,"corrupcao")==0))//Compara se a substring eh igual a 'corrupcao'.
			{
				//Se for igual a 'corrupcao vai retornar '0' e não vai fazer nada.
			}else{
				strcat(final,auxiliar);//Se não for igual ela vai pegar a substring e copiar para o final da string 'final'.
				
			}
			zerarpalavra(auxiliar);//Zera a variavel 'auxiliar' para que possa fazer a proxima verificacao.	
			k=0;//K=0 para que a proxima escrita comece no vetor inicial de 'auxiliar'.	
		}
					
	}	

	return (final);//String sem 'corrupcao'.
}

void sono_ampliado(char *discurso)
{
	char *auxiliar1 = (char*)malloc(TAMANHO*sizeof(char));
	char *auxiliar2 = (char*)malloc(TAMANHO*sizeof(char));
	char *auxiliar3 = (char*)malloc(TAMANHO*sizeof(char));
	zerarpalavra(auxiliar1);
	zerarpalavra(auxiliar2);
	zerarpalavra(auxiliar3);
	int tamanho=0, i, cont1=0, cont2=0;
	int x=0;

	
	tamanho = strlen(discurso);
	

	for (i=0;i<=tamanho;i++) //for que vai sair com os casais de z da substring
	{
		if (discurso[i]=='z' && discurso[i+1]=='z')
		{
			cont1++;
			for(x=i+2; x<=tamanho; x++)
			{
				auxiliar2[cont2] = discurso[x];
				discurso[x] = ' ';
				cont2++;
			}
			discurso[i+2] = '\0';
			strcat(discurso, "zz");
			strcat(discurso, auxiliar2);
			i = i+4;
			cont2 = 0;
			zerarpalavra(auxiliar2);
			tamanho = strlen(discurso);
		}
	}
	
	for (i=0;i<cont1;i++) // auxiliar2 recebe a quantidade de z
	{
		strcat(auxiliar3, "zz");
	}
	strcat(auxiliar3, discurso); //jogo a quantidade dos pares de z para o inicio da palavra
	
	for(i=0;i<cont1;i++) //auxiliar3 vai receber a quantidade de pares z para cocatena no final da palavra
	{
		strcat(auxiliar3, "zz");
	}
	strcat(discurso, auxiliar3);
}

int main()
{
	char* frase = lerDados();
	char *palavra_pre_processada=eliminarCorrupcao(frase);
	char *criptografia;
	sono_ampliado(palavra_pre_processada);
	printf("\n\nA FRASE CRIPTOGRAFADA EH: %s\n\n ", palavra_pre_processada);
	printf("\n\nA FRASE DESCRIPTOGRAFADA EH: \n\n ");
	return 0;
}

