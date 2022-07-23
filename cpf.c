
 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
//VALIDADOR CPF.  
  
# include <stdio.h>  
# include <conio.h>
 
int main()  
{  
    char cpf[12];  
    int icpf[12];  
    int i,somador=0,digito1,result1,result2,digito2,valor;  
  
    printf("Digite o cpf: ");  
    scanf(" %s",cpf);  
  
    //Efetua a conversao de array de char para um array de int.  
    for(i=0;i<11;i++)  
    {  
    icpf[i]=cpf[i]-48;  
}  
  
    //PRIMEIRO DIGITO.  
  
    for(i=0;i<9;i++)  
    {  
    somador+=icpf[i]*(10-i);  
}  
  
    result1=somador%11;  
  
    if( (result1==0) || (result1==1) )  
    {  
    digito1=0;  
}  
   
    else  
    {  
    digito1 = 11-result1;  
}  
  
    //SEGUNDO DIGITO.  
  
    somador=0;  
   
    for(i=0;i<10;i++)  
    {  
    somador+=icpf[i]*(11-i);  
}  
    valor=(somador/11)*11;  
    result2=somador-valor;  
  
    if( (result2==0) || (result2==1) )  
    {  
    digito2=0;  
}  
    else  
    {  
    digito2=11-result2;  
}  
    //RESULTADOS DA VALIDACAO.  
  
    if((digito1==icpf[9]) && (digito2==icpf[10]))  
    {  
    printf("\nCPF VALIDADO.\n");  
}  
    else  
    {  
    printf("Problema com os digitos.\n");  
}
    getch (); 
}
