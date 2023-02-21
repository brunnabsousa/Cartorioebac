#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdio.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Bibloteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sitema
{
	//Inicio da cria��o de vari�veis/strinng
	char arquivo[40];
	char CPF [40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	//Fincal da cria��o de vari�veis/strinng
	
	printf("Digite o CPF a ser cadastrado:\n");//Coletando informa��o do usu�rio
	scanf("%s", CPF);//% refere-se a string
	
	strcpy(arquivo, CPF); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria e abrir o arquivo, W � escrever
	fprintf(file,CPF); //Salvo o valor da vari�vel
	fclose(file); //Fecho o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,","); //Separa os dados
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s",Nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,Nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:\n");
	scanf("%s",Sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,Sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:\n");
	scanf("%s",Cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, Cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	char CPF[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n");
	scanf("%s", CPF);
	
	FILE *file;
	file = fopen(CPF,"r"); //r significa ler
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es de us�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char CPF [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file ==NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco+1;)
	{
		system("cls");
		
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("~~~ Cart�rio da EBAC ~~~\n\n"); //In�cio do menu
	   printf("Escolha a op��o desejada do menu\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Op��o: "); //Fim do menu
	
	   scanf("%d", &opcao); //Armazenando as escolhas do usu�rio
	   
	   system("cls");//Respons�vel por limpar a tela
	   
	   switch(opcao)//Inicio da sele��o do menu
	   {
	   	case 1:
	   	registro();//Chamada de fun��es
	 	break;
	 	
	 	case 2:
	 	consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel!\n");
		system("pause");
		break;
			
	   }
	
    }
}

