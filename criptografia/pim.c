//pim.c
#include<stdio.h>
#include<stdlib.h>
#include<hue.h>

FILE *infile;
FILE *outfile;
int ch, x, y, x_v, y_v;

void get_chaves()
{
	do
		{
			system("cls");
			assinatura();
			printf("Escolha a primeira chave: ");
			scanf("%d", &x);
			x_v = primo(x);
			if(x_v == 0)
			{printf("\n\nA Chave deve ser um numero primo.\n");system("PAUSE");}
		}while(x_v == 0);
		do
		{
			system("cls");
			assinatura();
			printf("Escolha a segunda chave: ");
			scanf("%d", &y);
			y_v = primo(y);
			if(y_v == 0)
			{printf("\n\nA Chave deve ser um numero primo.\n");system("PAUSE");}
	}while(y_v == 0);
}

void cript()
{
	get_chaves();

	infile = fopen("mensagem.txt", "r");
	if (infile == NULL) {
			printf("\nFalha ao abrir o arquivo de entrada.");
	}
	outfile = fopen("mensagem_cript.txt", "w");
	if (outfile == NULL) {
			printf("\nFalha ao abrir o arquivo de saida.");
	}
	while((ch = getc(infile)) != EOF)
	{
		putc((ch + (x*y)), outfile);
	}

	fclose(infile);
	fclose(outfile);
}

void descript()
{
	get_chaves();

	infile = fopen("mensagem_cript.txt", "r");
	if (infile == NULL) {
			printf("\nFalha ao abrir o arquivo de entrada.");
	}
	outfile = fopen("mensagem.txt", "w");
	if (outfile == NULL) {
			printf("\nFalha ao abrir o arquivo de saida.");
	}
	while((ch = getc(infile)) != EOF)
	{
		putc((ch - (x*y)), outfile);
	}

	fclose(infile);
	fclose(outfile);
}

int main()
{
	char op;
	do
	{
		system("cls");
		assinatura();
		printf("Escolha uma operacao: \n 1 - Criptografar \n 2 - Descriptografar\n\n");
		op = getch();
		switch (op)
		{
			case '1':
			cript();
			printf("Mensagem criptografada com sucesso.\n");
			break;
			case '2':
			descript();
			printf("Mensagem descriptografada com sucesso.\n");
			break;
			default:
			printf("Operacao Invalida!\n\n");
			system("PAUSE");
			break;
		}
	}while((op != '1') && (op != '2'));
	system("PAUSE");
}
