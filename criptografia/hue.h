//hue.h
extern FILE *infile;
extern FILE *outfile;
extern int ch, x, y, x_v, y_v;

int primo(int x)
{
    int j;
		for(j=2;j<x;j++)
		{
			if(x%j == 0)
			{
				return (0);
			}
		}
	return (1);
}

void assinatura()
{
     printf("//////////////////////////////////////////////////////\n");
     printf("//////////////////////////////////////////////////////\n");
     printf("//  P.I.M.     -     Criptografia     -       UNIP  //\n");
     printf("//Por:  Victor Matheus Mendonca Vieira  RA C16GFF-8 //\n");
     printf("//      Atila Ribeiro                   RA XXXXXX-X //\n");
     printf("//      Gabriel                         RA XXXXXX-X //\n");
     printf("//////////////////////////////////////////////////////\n");
     printf("//////////////////////////////////////////////////////\n\n");
}
