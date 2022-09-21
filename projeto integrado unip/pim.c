//teste_senha.c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

FILE *pw, *fnome, *fsaldo, *fhist, *fdest, *fsenha;
char tmp[50], ch, senha[4], conf[4], cd;
int arrExib[10], arrSenha[4][2], arrX[4], j, c, p, s, i, x, erro, conta, op, conta_d;
float saldo, vdep, vsaq, vtrans, total;

void fillArray() 
{
	for (x = 0; x < 10; x++)
		arrExib[x] = 20;
	for (x = 0; x < 10; x++) 
	{
		do 
		{
			c = 1;
			arrExib[x] = rand() % 10;
			int count = sizeof (arrExib) / sizeof (arrExib[0]);
			for (j = 0; j < count; j++) 
			{
				if (x != j) 
				{
					if (arrExib[x] == arrExib[j]) 
					{
						c = 0;
						break;
					}
				}
			}
		}
		while (c == 0);
	}
}

void pSenha()
{
	system("CLS");
	printf("Digite a sua senha: \n\n");
	printf("[1] - %d ou %d\n", arrExib[0], arrExib[1]);
	printf("[2] - %d ou %d\n", arrExib[2], arrExib[3]);
	printf("[3] - %d ou %d\n", arrExib[4], arrExib[5]);
	printf("[4] - %d ou %d\n", arrExib[6], arrExib[7]);
	printf("[5] - %d ou %d\n\n", arrExib[8], arrExib[9]);
}

void ArmSenha(int s) {
	switch (s) 
	{
		case '1':
			arrSenha[i][0] = arrExib[0];
			arrSenha[i][1] = arrExib[1];
			putchar('*');
			break;
		case '2':
			arrSenha[i][0] = arrExib[2];
			arrSenha[i][1] = arrExib[3];
			putchar('*');
			break;
		case '3':
			arrSenha[i][0] = arrExib[4];
			arrSenha[i][1] = arrExib[5];
			putchar('*');
			break;
		case '4':
			arrSenha[i][0] = arrExib[6];
			arrSenha[i][1] = arrExib[7];
			putchar('*');
			break;
		case '5':
			arrSenha[i][0] = arrExib[8];
			arrSenha[i][1] = arrExib[9];
			putchar('*');
			break;
		default:
			printf("\n\nOpcao invalida!\n");
			system("PAUSE");
			system("CLS");
			pSenha();
			for (j = 0; j < i; j++) {
				putchar('*');
			}
			i--;
			break;
	}
}

int openSenha(int cc)
{
	sprintf(tmp, "%d/senha.txt", cc);
	pw = fopen(tmp, "rt");
	if (!pw)
		return (0);
	return (1);
}

int CompSenha() 
{
	for (x = 0; x < 4; x++)
		arrX[x] = getc(pw) - '0';
	for (x = 0; x < 4; x++) 
	{
		if ((arrX[x] != arrSenha[x][0]) && (arrX[x] != arrSenha[x][1])) 
		{
			fclose(pw);
			return (0);
		}
	}
	fclose(pw);
	return (1);
}

void getSenha()
{
	openSenha(conta);
	fillArray();
	pSenha();
	i = 0;
	while (i < 4)
	{
		s = getch();
		if (s == 8)
		{
			if (i > 0)
			{
				i--;
				arrSenha[i][0] = '\0';
				arrSenha[i][1] = '\0';
				printf("\b \b");
			}
		}
		else
		{
			ArmSenha(s);
			i++;
		}
	}
}

void menu()
{
	do
	{
		system("CLS");
		sprintf(tmp, "%d/nome.txt", conta);
		fnome = fopen(tmp, "rt");
		printf("Bem Vindo(a), Sr.(a) ");
		while ((ch = fgetc(fnome)) != EOF)
			putchar(ch);
		fclose(fnome);
		printf("\n\n\nO que gostaria de fazer?");
		printf("\n\n 1 - Deposito");
		printf("\n 2 - Saque");
		printf("\n 3 - Transferencia");
		printf("\n 4 - Consultar Saldo");
		printf("\n 5 - Verificar extrato");
		printf("\n 6 - Alterar senha");
		printf("\n 7 - Sair");
		op = getch();
		switch (op)
		{
			case '1':
				deposito();
				break;
			case '2':
				saque();
				break;
			case '3':
				tranferencia();
				break;
			case '4':
				verif_saldo();
				break;
			case '5':
				extrato();
				break;
			case '6':
				alteraSenha();
				break;
			case '7':
				printf("\n\nEncerrando a sessao. Obrigado e volte sempre!\n");
				break;
			default:
				printf("\n\nOpcao invalida\n");
				system("PAUSE");
				break;
		}
	} while (op != '7');
}

int alteraSenha()
{
	getSenha();
	if (CompSenha() == 1)
	{
		system("CLS");
		printf("Digite a nova senha: ");
		i = 0;
		while (i < 4)
		{
			cd = getch();
			if ((cd == 8) && (i > 0))
			{
				i--;
				senha[i] = '\0';
				printf("\b \b");
			}
			else
			{
				if (((cd - '0') < 0) || ((cd - '0') > 9))
				{
					printf("\n Caractere invalido!\n");
					system("PAUSE");
					system("CLS");
					printf("Digite a nova senha: ");
					for (j = 0; j < i; j++)
						putchar('*');
				}
				else
				{
					senha[i] = cd;
					putchar('*');
					i++;
				}
			}
		}
		system("CLS");
		printf("Confirme a nova senha: ");
		i = 0;
		while (i < 4) 
		{
			cd = getch();
			if ((cd == 8) && (i > 0))
			{
				i--;
				senha[i] = '\0';
				printf("\b \b");
			}
			else
			{
				if (((cd - '0') < 0) || ((cd - '0') > 9))
				{
					printf("\n Caractere invalido!\n");
					system("PAUSE");
					system("CLS");
					printf("Confirme a nova senha: ");
					for (j = 0; j < i; j++)
						putchar('*');
				}
				else
				{
					conf[i] = cd;
					putchar('*');
					i++;
				}
			}
		}
		system("CLS");
		c = 1;
		for (i = 0; i < 4; i++)
		{
			if (senha[i] != conf[i])
				c = 0;
		}
		if (c == 1)
		{
			sprintf(tmp, "%d/senha.txt", conta);
			fsenha = fopen(tmp, "wt");
			fprintf(fsenha, "%c%c%c%c", senha[0], senha[1], senha[2], senha[3]);
			fclose(fsenha);
			printf("Senha alterada com sucesso.\n");
		}
		else
			printf("Senha e confirmacao nao sao iguais.\n");
	}
	else
		printf("\nSenha incorreta!\n");
	system("PAUSE");
}

int tranferencia()
{
	system("CLS");
	printf("Digite a conta de destino: ");
	scanf("%d", &conta_d);
	sprintf(tmp, "%d/saldo.txt", conta_d);
	fdest = fopen(tmp, "rt");
	if (!fdest)
	{
		printf("Conta invalida!\n");
		system("PAUSE");
		return;
	}
	printf("Digite o valor que deseja transferir: R$ ");
	scanf("%f", &vtrans);
	getSenha();
	if (CompSenha() == 1)
	{
		sprintf(tmp, "%d/saldo.txt", conta);
		fsaldo = fopen(tmp, "rt");
		while (!feof(fsaldo))
			fscanf(fsaldo, "%f", &saldo);
		fclose(fsaldo);
		total = saldo - vtrans;
		if (total >= 0)
		{
			fsaldo = fopen(tmp, "wt");
			if (fprintf(fsaldo, "%.2f", total) == EOF)
			{
				printf("Erro na operacao\n");
				return;
			}
			else
				printf("\n\nTansferencia realizado com sucesso, seu saldo agora e de R$ %.2f\n", total);
			fclose(fsaldo);
			sprintf(tmp, "%d/historico.txt", conta);
			fhist = fopen(tmp, "a");
			fseek(fhist, 1, SEEK_END);
			fprintf(fhist, "\nTransferencia realizada no valor de R$%.2f para a conta %d - Saldo Atual: R$ %.2f", vtrans, conta_d, total);
			fclose(fhist);
			while (!feof(fdest))
				fscanf(fdest, "%f", &saldo);
			fclose(fdest);
			total = saldo + vtrans;
			sprintf(tmp, "%d/saldo.txt", conta_d);
			fdest = fopen(tmp, "wt");
			if (fprintf(fdest, "%.2f", total) == EOF)
			{
				printf("Erro na operacao\n");
				return;
			}
			fclose(fsaldo);
			sprintf(tmp, "%d/historico.txt", conta_d);
			fhist = fopen(tmp, "a");
			fseek(fhist, 1, SEEK_END);
			fprintf(fhist, "\nTransferencia recebida no valor de R$%.2f da conta %d - Saldo Atual: R$ %.2f", vtrans, conta, total);
			fclose(fhist);
		}
		else
			printf("\nSaldo insuficiente!\n");
	}
	else
		printf("\nSenha incorreta!\n");
	system("PAUSE");
	return;
}

int deposito()
{
	system("CLS");
	printf("Digite o valor que deseja depositar: R$");
	scanf("%f", &vdep);
	getSenha();
	if (CompSenha() == 1)
	{
		sprintf(tmp, "%d/saldo.txt", conta);
		fsaldo = fopen(tmp, "rt");
		while (!feof(fsaldo))
			fscanf(fsaldo, "%f", &saldo);
		fclose(fsaldo);
		total = saldo + vdep;
		fsaldo = fopen(tmp, "wt");
		if (fprintf(fsaldo, "%.2f", total) == EOF)
		{
			printf("Erro na operacao\n");
			return;
		}
		else
			printf("\n\nDeposito realizado com sucesso, seu saldo agora e de R$ %.2f\n", total);
		fclose(fsaldo);
		sprintf(tmp, "%d/historico.txt", conta);
		fhist = fopen(tmp, "a");
		fseek(fhist, 1, SEEK_END);
		fprintf(fhist, "\nDeposito realizado no valor de R$%.2f - Saldo Atual: R$ %.2f", vdep, total);
		fclose(fhist);
	}
	else
		printf("\nSenha incorreta!\n");
	system("PAUSE");
	return;
}

int saque()
{
	system("CLS");
	printf("Digite o valor que deseja sacar: R$");
	scanf("%f", &vsaq);
	getSenha();
	if (CompSenha() == 1)
	{
		sprintf(tmp, "%d/saldo.txt", conta);
		fsaldo = fopen(tmp, "rt");
		while (!feof(fsaldo))
			fscanf(fsaldo, "%f", &saldo);
		fclose(fsaldo);
		total = saldo - vsaq;
		if (total >= 0)
		{
			fsaldo = fopen(tmp, "wt");
			if (fprintf(fsaldo, "%.2f", total) == EOF)
			{
				printf("Erro na operacao\n");
				return;
			}
			else
				printf("\n\nSaque realizado com sucesso, seu saldo agora e de R$ %.2f\n", total);
			fclose(fsaldo);
			sprintf(tmp, "%d/historico.txt", conta);
			fhist = fopen(tmp, "a");
			fseek(fhist, 1, SEEK_END);
			fprintf(fhist, "\nSaque realizado no valor de R$%.2f - Saldo Atual: R$ %.2f", vsaq, total);
			fclose(fhist);
		}
		else
			printf("\nSaldo insuficiente!\n");
	}
	else
		printf("\nSenha Incorreta!\n");
	system("PAUSE");
	return;
}

int verif_saldo()
{
	system("CLS");
	sprintf(tmp, "%d/saldo.txt", conta);
	fsaldo = fopen(tmp, "rt");
	printf("Seu saldo e de R$ ");
	while ((ch = fgetc(fsaldo)) != EOF)
		putchar(ch);
	fclose(fsaldo);
	printf("\n");
	system("PAUSE");
	return;
}

int extrato()
{
	system("CLS");
	sprintf(tmp, "%d/historico.txt", conta);
	fhist = fopen(tmp, "rt");
	while ((ch = fgetc(fhist)) != EOF)
		putchar(ch);
	fclose(fhist);
	printf("\n");
	system("PAUSE");
	return;
}

main()
{
	do
	{
		erro = 0;
		system("CLS");
		printf("Informe o numero da conta corrente: ");
		scanf("%d", &conta);
		if (openSenha(conta))
		{
			srand(time(NULL));
			getSenha();
			//printArray();
			if (CompSenha() == 1)
				menu();
			else
			{
				printf("\nSenha Incorreta!\n");
				erro = 1;
			}
		} 
		else 
		{
			printf("Conta invalida\n");
			erro = 1;
		}
		system("PAUSE");
	} while (erro);
}
