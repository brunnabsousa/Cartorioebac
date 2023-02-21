#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdio.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Bibloteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sitema
{
	//Inicio da criação de variáveis/strinng
	char arquivo[40];
	char CPF [40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	//Fincal da criação de variáveis/strinng
	
	printf("Digite o CPF a ser cadastrado:\n");//Coletando informação do usuário
	scanf("%s", CPF);//% refere-se a string
	
	strcpy(arquivo, CPF); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria e abrir o arquivo, W é escrever
	fprintf(file,CPF); //Salvo o valor da variável
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
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações de usário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char CPF [40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file ==NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco+1;)
	{
		system("cls");
		
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("~~~ Cartório da EBAC ~~~\n\n"); //Início do menu
	   printf("Escolha a opção desejada do menu\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Opção: "); //Fim do menu
	
	   scanf("%d", &opcao); //Armazenando as escolhas do usuário
	   
	   system("cls");//Responsável por limpar a tela
	   
	   switch(opcao)//Inicio da seleção do menu
	   {
	   	case 1:
	   	registro();//Chamada de funções
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
		printf("Essa opção não está disponível!\n");
		system("pause");
		break;
			
	   }
	
    }
}

