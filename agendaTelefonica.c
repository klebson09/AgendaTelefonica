#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//-------------------------------------------DEFININDO A ESTRUTURA DO CONTATO----------------------------------------------------------------

struct Contato //Estrutura Contato
{
	int id;
	char nome[50];
	char cel[16];
	char email[50];
	char telRes[15];
};

typedef struct Contato contato; //Definindo o typedef(tipo) da estrutura Contato

int quant; //Variável Global que armazena a quantidade total de contatos

contato *contatos; //Lista de contatos que serão adicionados na memória em tempo de execução do programa

//------------------------------------------------------PROTÓTIPOS---------------------------------------------------------------------------

//VALIDAÇÃO----------------------------

int validarNome(char nome[]);
int validarCel(char cel[]);
int validarEmail(char email[]);
int validarTel(char tel[]);

//GRAVAÇÃO------------------------------

void AtualizarQuantContatos(int contatosAdicionados);
int adicionarContatos();
void ordenarEmOrdemAlfabetica();
void gravarContatos(contato *contatos, int contatosAdicionados);
void geraTxt();
contato buscarContatoPorNumRegistro(int numRegistro)
{
	FILE *fbAltC = fopen("contatos.dat", "r");

	contato c, contatos[quant];
	int i;
	
	fread(contatos, sizeof(contatos[i]),quant, fbAltC);

	for(i=0;i<quant;i++)
	{
		if(contatos[i].id==numRegistro)
		{
			printf("achou\n");
			c = contatos[i];
			printf("atribuiu\n");
			getch();
			break;
		}
	}
	
	fclose(fbAltC);
	
	return c;
	
}

void atualizarContato(contato c, int numReg)
{
	FILE *fAlterar = fopen("contatos.dat","rb+");
	contato contatos[quant];
	int i,elementosAlterados=0;				
			
	fread(contatos, sizeof(contatos[i]), quant, fAlterar);
			
	for(i=0;i<quant;i++)
	{
		if(contatos[i].id==numReg)
		{
			fseek(fAlterar, (sizeof(contatos[i]))*i, SEEK_SET);
			elementosAlterados = fwrite(&c, sizeof(c),1,fAlterar);
			break;
		}
	}
				
	printf("Elementos Alterados: %d\n", elementosAlterados);			
				
	if(elementosAlterados>0)
	{
		printf("Atualização feita com sucesso\n");
	}
	else
	{
		printf("Falha na atualização\n");
	}
					
	fclose(fAlterar);
}

void alterarContato(int numRegistro)
{
	
	contato contatoAlterar = buscarContatoPorNumRegistro(numRegistro);
	int opcao, executandoAlteracao=1,elementosAlterados=0, i=0;
	char Nnome[50], Ncel[16], Nemail[50], NtelefoneRes[15];


	if(contatoAlterar.nome!=NULL)
	{
		
		while(executandoAlteracao)
		{
			system("cls");
			printf("CONTATO A SER ALTERADO\n\n");
			printf("[%d]\n", contatoAlterar.id);
			printf("Nome: %s\n",contatoAlterar.nome);
			printf("Celular: %s\n", contatoAlterar.cel);
			printf("Email: %s\n",contatoAlterar.email);
			printf("Telefone Residencial: %s\n\n", contatoAlterar.telRes);
			
			setbuf(stdin, NULL);
			printf("Selecione o dado que deseja alterar:\n");
			printf("\n1)Nome\n2)Celular\n3)Email\n4)Telefone Residencial\n5)Todos\n6)Submeter Alterações\n7)Cancelar\n\n");
			scanf("%d", &opcao);
			
			switch(opcao)
			{
						
				case 1:
					setbuf(stdin, NULL); //sulução para pegar o nome
					printf("Digite o novo nome: ");
					scanf("%[^\n]100s", &Nnome);//ler com espaços
					if(!(validarNome(Nnome)))
					{
						getch();
						break;
					}
					strcpy(contatoAlterar.nome, Nnome);//inserir uma string dentro d outra string (ponteiro)
					setbuf(stdin, NULL);
				break;	
				
				case 2:
					setbuf(stdin, NULL);
					printf("Digite o novo numero de celular: \n");
					scanf("%[^\n]100s", &Ncel);
					if(!(validarCel(Ncel)))
					{
						getch();
						break;
					}
					strcpy(contatoAlterar.cel,Ncel);	
					printf("Celular alterado\n");
					setbuf(stdin, NULL);
				break;	
				
				case 3:
					setbuf(stdin, NULL);
					printf("Digite o novo email: \n");
					scanf("%[^\n]100s", &Nemail);
					if(!(validarEmail(Nemail)))
					{
						getch();
						break;
					}
					strcpy(contatoAlterar.email, Nemail);	
					printf("Email alterado\n");
					setbuf(stdin, NULL);
				break;	
				
				case 4:
					setbuf(stdin, NULL);
					printf("Digite o novo telefone residencial: \n");
					scanf("%[^\n]100s", &NtelefoneRes);
					if(!(validarTel(NtelefoneRes)))
					{
						getch();
						break;
					}
					strcpy(contatoAlterar.telRes, NtelefoneRes);
					printf("Telefone residencial alterado\n");
					setbuf(stdin, NULL);	
				break;	
				
				case 5:
					setbuf(stdin, NULL);
					printf("Digite o novo nome: \n");
					scanf("%[^\n]100s", &Nnome);
					if(!(validarNome(Nnome)))
					{
						getch();
						break;
					}
					strcpy(contatoAlterar.nome, Nnome);
					printf("Nome alterado\n");
					setbuf(stdin, NULL);
						
					
					printf("Digite o novo numero de celular: \n");
					scanf("%[^\n]100s", &Ncel);
					if(!(validarCel(Ncel)))
					{
						getch();
						break;
					}
					strcpy(contatoAlterar.cel, Ncel);	
					printf("Celular alterado\n");
					setbuf(stdin, NULL);	
					
					printf("Digite o novo email: \n");
					scanf("%[^\n]100s", &Nemail);
					if(!(validarEmail(Nemail)))
					{
						getch();
						break;
					}
					strcpy(contatoAlterar.email, Nemail);	
					printf("Email alterado\n");
					setbuf(stdin, NULL);
					
					printf("Digite o novo telefone residencial: \n");
					scanf("%[^\n]100s", &NtelefoneRes);
					if(!(validarTel(NtelefoneRes)))
					{
						getch();
						break;
					}
					strcpy(contatoAlterar.telRes, NtelefoneRes);
					printf("Telefone residencial alterado\n");
					setbuf(stdin, NULL);			
					
					printf("Dados alterados\n");	
				break;	
				
				case 6:
					atualizarContato(contatoAlterar, numRegistro);
					executandoAlteracao=0;
				break;
				
				case 7:
					executandoAlteracao=0;	
				break;	
			}
		}	
		
		
	}
	else
	{
		printf("Nenhum contato encontrado com o numero desse registro\n");
		
	}
	printf("Pressione qualquer tecla para continuar\n");
	getch();
}
void deletarContato(int numRegistro)
{
	contato contatoDeletar = buscarContatoPorNumRegistro(numRegistro);
	contato cLidos[quant], contatosAtualizados[quant-1];
	int opcao,i, indiceDeletar;		
						
	if(contatoDeletar.nome!=NULL)
	{	
	
			system("cls");
			printf("CONTATO A SER DELETADO\n\n");
			printf("[%d]\n", contatoDeletar.id);
			printf("Nome: %s\n",contatoDeletar.nome);
			printf("Celular: %s\n", contatoDeletar.cel);
			printf("Email: %s\n",contatoDeletar.email);
			printf("Telefone Residencial: %s\n\n", contatoDeletar.telRes);
			
			setbuf(stdin, NULL);
			printf("Tem certeza que deseja deletar o contato? (1=Sim / 0=Não): ");
			scanf("%d",&opcao);
			
			if(opcao==1)
			{
				printf("contato deletado\n");
				
				
				FILE *f = fopen("contatos.dat", "rb");
				
				if (f == NULL)
				{
					printf("O arquivo não pode ser aberto.\n");
				}
		
				int contatosRegistrados = fread(cLidos, sizeof(cLidos[i]), quant, f);
				int idCorrente; 
				int achou=0,cont=0;
				int quantidade = quant;
			
				for(i=0;i<quantidade;i++)
				{
					if(cLidos[i].id==numRegistro)
					{
						cont++;//usado em contatos atualizar
						quantidade--;
					}
					
					
					idCorrente = cLidos[i].id; 
					printf("idCorrente = %d\n",idCorrente);
					printf("Nome: %s\n", cLidos[i].nome);
					printf("Celular: %s\n", cLidos[i].cel);
					printf("Email: %s\n", cLidos[i].email);
					printf("Telefone Residencial: %s\n", cLidos[i].telRes);
					printf("ID REGISTRO: %d\n\n", cLidos[i].id);
							
					contatosAtualizados[cont].id = cLidos[i].id;
					strcpy(contatosAtualizados[cont].nome, cLidos[i].nome);//stcpy atribui um valor de uma string a outra
					printf("1 strcpy\n");
					strcpy(contatosAtualizados[cont].cel, cLidos[i].cel);
					printf("2 strcpy\n");
					strcpy(contatosAtualizados[cont].email ,cLidos[i].email);
					printf("3 strcpy\n");
					strcpy(contatosAtualizados[cont].telRes , cLidos[i].telRes);
					printf("4 strcpy\n");
							
					printf("[%d] nome %s\n",i,contatosAtualizados[i].nome);
					printf("[%d] cel %s\n",i,contatosAtualizados[i].cel);
					printf("[%d] email %s\n",i,contatosAtualizados[i].email);
					printf("[%d] telefone %s\n\n",i,contatosAtualizados[i].telRes);	
		
					cont++;
				}
						
				fclose(f);	
				
				FILE *fw = fopen("contatos.dat", "w");
				
				if(fw==NULL)
				{
					printf("Arquivo não pode ser aberto\n");
				}
				
				fwrite(contatosAtualizados, sizeof(contatosAtualizados[i]),quant-1,fw);	
				
				fclose(fw);
			
			
				
				AtualizarQuantContatos(-1);
				ordenarEmOrdemAlfabetica();
				geraTxt();
				
				getch();
			
			}
			else
			{
					
			}
			
	}
	else
	{
		printf("Nenhum contato encontrado com o numero desse registro\n");
		
	}
	
	getch();
}

//LEITURA/CONSULTA(LISTA)--------------

void getQuantContatos();
void listarTodosContatos();
void buscarContatoPorTelefone(char telBuscado[]);
void buscarContatoPorNome(char nomeBuscado[]);

//MENU----------------------------------

int exibirMenu();

//--------------------------------------------------------------------------------------------------------------------------------------------


/*************************************************FUNCÃO PRINCIPAL (MAIN)********************************************************************
********************************************************************************************************************************************
********************************************************************************************************************************************
********************************************************************************************************************************************
********************************************************************************************************************************************/


int main(void) 
{
	setlocale(LC_ALL, "Portuguese");
	system("color 17");	
	
	return exibirMenu();
}

/**********************************************FIM DA FUNÇÃO PRINCIPAL (MAIN)***************************************************************
*******************************************************************************************************************************************
********************************************************************************************************************************************
********************************************************************************************************************************************
********************************************************************************************************************************************/



/******************************************************FUNÇÕES*****************************************************************************/


//------------------------------------------------------MENU--------------------------------------------------------------------------------

int exibirMenu()
{
	int opcao, executando=1, contatosAdicionados;
	char nome[50], telefone[15];
	int numRegistro;
	
	while(executando)
	{
		
		//ordenarEmOrdemAlfabetica();
		
		system("cls");
		
		printf("********************************************************************************");
		printf("*\t\t\t     AGENDA TELEFONICA                                 *");
		printf("********************************************************************************\n\n\n\n\n");
		
		
		getQuantContatos(); //Obtendo o numero de contatos registrados
		
			printf("CONTATOS = %d\n\n",quant);
		
		printf("\t\t\tEscolha a opção desejada:\n\n");
		printf("\t\t\t  1)Adicionar Contatos\n\t\t\t  2)Listar Contatos\n\t\t\t  3)Alterar Contato\n\t\t\t  4)Deletar Contato\n\t\t\t  5)Pesquisar Por Nome\n\t\t\t  6)Pesquisar por Telefone\n\t\t\t  7)Sair\n\n\n\t\t\t  ");
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1:
			contatosAdicionados = adicionarContatos(); 	//Adicionar contatos
			gravarContatos(contatos, contatosAdicionados);	//Gravando os contatos
			AtualizarQuantContatos(contatosAdicionados); //Atualizando a quantidade de contatos
			ordenarEmOrdemAlfabetica(); //Ordena em ordem alfabetica o arquivo
			geraTxt();
			break;
			
			case 2:
			listarTodosContatos();	//Lendo dados do arquivo
			break;
			
			case 3:
			system("cls");
			setbuf(stdin, NULL);
			printf("Digite o numero do registro do contato: ");	
			scanf("%d",&numRegistro);
			alterarContato(numRegistro);
			ordenarEmOrdemAlfabetica();
			geraTxt();
			break;
			
			case 4:
			system("cls");
			setbuf(stdin, NULL);
			printf("Digite o numero do registro do contato: ");	
			scanf("%d",&numRegistro);
			deletarContato(numRegistro);
			break;
			
			case 5:
			system("cls");
			setbuf(stdin, NULL);
			printf("Digite o nome a ser buscado: ");
			scanf("%[^\n]50s", &nome);
			buscarContatoPorNome(nome); //Busca o contato pelo nome
			break;
			
			case 6:
			system("cls");
			setbuf(stdin, NULL);
			printf("Digite o telefone a ser buscado: ");
			scanf("%[^\n]15s", &telefone);	
			buscarContatoPorTelefone(telefone); //Busca o contato pelo telefone	
			break;
			
			case 7:
			executando = 0;	
			break;
				
		}
	}
	
	return EXIT_SUCCESS;	
}


//----------------------------------------------------VALIDAÇÃO-----------------------------------------------------------------------------

int validarNome(char nome[])
{
	if((strlen(nome))<=50)
	{
		if(isupper(nome[0]))
		{
			return 1;
		}
		else
		{
			printf("Primeira letra deve ser maiúscula\n");
			return 0;
		}
		
	}
	else
	{
		printf("Nome deve ter no máximo 50 caracteres\n");
		return 0;
	}

}

int validarCel(char cel[])
{
	char traco = '-', parentesesEsq = '(', parentesesDir = ')';
	int tamanhoNumCel = strlen(cel); 
	
	if((tamanhoNumCel>=14)&&((tamanhoNumCel<=15)))
	{
		
		if(((cel[0]==parentesesEsq)&&(cel[4]==parentesesDir))&&((cel[9]==traco)||(cel[10]==traco)))
		{
			return 1;	
		}
		else
		{
			printf("Celular deve seguir o formato ((###)#####-####) para numeros com digito 9 e ((###)####-####) para os demais\n");
			return 0;
		}
	}
	else
	{
		printf("O número do celular deve ter entre 14 e 15 digitos\n");
		return 0;
	}

}

int validarEmail(char email[])
{
	//Validando tamanho do email
	if((strlen(email))<=50)
	{
		//Validando se tem @ e .
		if((strstr(email, "@") != NULL)&&(strstr(email, ".") != NULL))
		{
			return 1;	
		}
		else
		{
			printf("Email deve ter @ e .\n");
			return 0;
		}
		
	}
	else
	{
		printf("Email deve ter no máximo 50 caracteres\n");
		return 0;
	}

}

int validarTel(char tel[])
{
	char traco = '-', parentesesEsq = '(', parentesesDir = ')';
	int tamTel = strlen(tel);
	
	
	if(tamTel==14)
	{
		if(((tel[0]==parentesesEsq)&&(tel[4]==parentesesDir))&&(tel[9]==traco))
		{
			return 1;	
		}
		else
		{
			printf("Telefone deve seguir o formato (###)(####-####)\n");
			return 0;
		}
	}
	else
	{
		printf("Número do Telefone Residencial deve ter 14 digitos\n");
		return 0;
	}

}

//---------------------------------------------------GRAVAÇÃO--------------------------------------------------------------------------------

void AtualizarQuantContatos(int contatosAdicionados)
{
	
	FILE *qtdAt = fopen("quantContatos.txt","w");
	
	if(qtdAt==NULL)
	{
		printf("Arquivo não pode ser aberto!");
	}
	
	quant = quant+contatosAdicionados;
	
	fprintf(qtdAt, "%d", quant);
	
	fclose(qtdAt);	
}

int adicionarContatos()
{
	system("cls");
	
	printf("********************************************************************************");
	printf("*\t\t     AGENDA TELEFONICA - ADICIONAR CONTATOS                    *");
	printf("********************************************************************************");
	
	
	contatos = (contato*) malloc(sizeof(contato)); 
	
	int novoContato=1,i=1,contC=0,cont=0, contQuant=quant+1;
	char nomeC[50], celC[10], emailC[50], telC[10];
	
	//Submetendo dados dos novos contatos
	while(novoContato)
	{
			//Caso mais de um contato foi adicionado, fazer realocação dinâmica de memória
			if(cont>0)
			{
				contatos = (contato*) realloc (contatos, (cont+1)*sizeof(contato));
			}
			
			contato c;
			
			c.id = contQuant;
			
			setbuf(stdin, NULL);
			printf("\nDigite o nome do %dº contato: ", cont+1);
			scanf("%[^\n]100s", nomeC);
			
			if(!(validarNome(nomeC)))
			{
				continue;
			}
		
			strcpy(c.nome, nomeC);
			
			setbuf(stdin, NULL);
			printf("Digite o número do celular ((###)#####-####)|((###)####-####) : ");
			scanf("%[^\n]100s", celC);
			
			if(!(validarCel(celC)))
			{
				continue;
			}
		
			strcpy(c.cel, celC);
				
			setbuf(stdin, NULL);
			printf("Digite o email: ");
			scanf("%[^\n]100s", emailC);
			
			if(!(validarEmail(emailC)))
			{
				continue;
			}
			
			strcpy(c.email, emailC);
			
			setbuf(stdin, NULL);
			printf("Digite o número do telefone residencial (###)(####-####) : ");
			scanf("%[^\n]100s", telC);
			
			if(!(validarTel(telC)))
			{
				continue;
			}
			
			strcpy(c.telRes, telC);
			
			setbuf(stdin, NULL);
			
			*(contatos+contC) = c;	
			cont++;
			contC++;
			contQuant++;
			printf("Deseja inserir mais um contato (Não=0)?");
			scanf("%d", &novoContato);
			
	}
	
	

 	printf("\nCONTATOS REGISTRADOS\n\n");

	
	for(i=0;i<contC;i++)
	{
			contato c = *(contatos+i);
			printf("CONTATO %d\n",i+1);
			printf("ID = %d\n",c.id);
			printf("Nome: %s\n", c.nome);
			printf("Celular: %s\n", c.cel);
			printf("Email: %s\n", c.email);
			printf("Telefone residencial: %s\n\n", c.telRes);
	}
	
	printf("Pressione qualquer tecla para continuar\n");
	getch();
	return contC;
}

void gravarContatos(contato *contatos, int contatosAdicionados)
{
	FILE *fgrv = fopen("contatos.dat","ab");
	
	if(fgrv==NULL)
	{
		printf("O arquivo não pode ser aberto!");
	}
	
	int elementosEscritos = fwrite(contatos, sizeof(contato), contatosAdicionados, fgrv);
	//printf("Elementos escritos: %d\n", elementosEscritos);
	fclose(fgrv);

}

void ordenarEmOrdemAlfabetica()
{
	int i,j;
	contato contatosLidos[quant], contatoAux;
	
	FILE *fAlphaSort = fopen("contatos.dat","rb+");
	
	fread(contatosLidos, sizeof(contatosLidos[i]), quant, fAlphaSort);
	
	//Algoritmo de ordenação simples
	for(i=0;i<quant;i++)
	{
		for(j=0;j<quant;j++)
		{
			if(strcmp(contatosLidos[i].nome, contatosLidos[j].nome)<0)
			{
				contatoAux = contatosLidos[i];
				contatosLidos[i] = contatosLidos[j];
				contatosLidos[j] = contatoAux;
			}
		}
	}
	
	fseek(fAlphaSort, 0, SEEK_SET); //Reposicionando o ponteiro de leitura para o inicio do arquivo para a devida gravação
	int contEscritos = fwrite(contatosLidos, sizeof(contatosLidos[i]), quant, fAlphaSort);
	fclose(fAlphaSort);
}

void geraTxt()
{
	int i;
	contato contatos[quant];
	FILE *fb= fopen("contatos.dat", "rb");
	
	if (fb == NULL)
	{
		printf("O arquivo não pode ser aberto.\n");
	}
	
	fread(contatos, sizeof(contatos[i]), quant, fb);

	fclose(fb);
	
	FILE *ft = fopen("contatos.txt","w");
	
	if (ft == NULL)
	{
		printf("O arquivo não pode ser aberto.\n");
	}
	for(i=0;i<quant;i++)
	{
		fprintf(ft,"ID: %d\n", contatos[i].id); 
		fprintf(ft, "Nome: %s\n", contatos[i].nome);
		fprintf(ft, "Celular: %s\n", contatos[i].cel);
		fprintf(ft, "Email: %s\n", contatos[i].email);
		fprintf(ft,"Telefone Residencial: %s\n\n", contatos[i].telRes);
	}
	
	fclose(ft);

}

//------------------------------------------------LEITURA/CONSULTA(LISTA)--------------------------------------------------------------------

void listarTodosContatos()
{

	contato cLidos[quant];
	int i, contatosRegistrados, registrosPorVez=10, temRegistros=1, ultimoRegistro=0;

	FILE *f = fopen("contatos.dat", "rb");
	if (f == NULL)
	{
		printf("O arquivo não pode ser aberto.\n");
	}
	
	while(temRegistros!=0)
	{
		if((quant - ultimoRegistro)<10)
		{
			system("cls");
			printf("********************************************************************************");
			printf("*\t\t AGENDA TELEFONICA - LISTAR CONTATOS - (%.2d a %.2d de %.2d)         *",ultimoRegistro,(ultimoRegistro+(quant - ultimoRegistro)),quant);
			printf("********************************************************************************");
			printf("\n");	
			
			contatosRegistrados = fread(cLidos, sizeof(cLidos[i]), (quant - ultimoRegistro), f);
			
			if((quant - ultimoRegistro)!=0)
			{
				for(i=0;i<(quant - ultimoRegistro);i++)
				{
				   	printf("Nome: %s\n", cLidos[i].nome);
					printf("Celular: %s\n", cLidos[i].cel);
					printf("Email: %s\n", cLidos[i].email);
					printf("Telefone Residencial: %s\n", cLidos[i].telRes);
					printf("ID REGISTRO: %d\n\n", cLidos[i].id);
				}		
			}
		
			if(quant==0)
			{
				printf("Não há contatos registrados\n");
				break;
			}
			else if(quant>10)
			{
				printf("(Página Anterior=1 Sair = 0)\n");	
			}
			else
			{
				printf("(Sair = 0)\n");
			}
			
			//temRegistros=0;
		}
		
		else
		{
			system("cls");
			printf("********************************************************************************");
			printf("*\t\t AGENDA TELEFONICA - LISTAR CONTATOS - (%d a %d de %d)          *",ultimoRegistro,(ultimoRegistro+10),quant);
			printf("********************************************************************************");
			printf("\n");	
			
			contatosRegistrados = fread(cLidos, sizeof(cLidos[i]), registrosPorVez, f);
			
			for(i=0;i<registrosPorVez;i++)
			{
			   	printf("Nome: %s\n", cLidos[i].nome);
				printf("Celular: %s\n", cLidos[i].cel);
				printf("Email: %s\n", cLidos[i].email);
				printf("Telefone Residencial: %s\n", cLidos[i].telRes);
				printf("ID REGISTRO: %d\n\n", cLidos[i].id);
			}
			
			if(ultimoRegistro==0)
			{
				printf("(Próxima Página=3 Sair = 0)\n");	
				
			}
			else if((ultimoRegistro>0)&&(ultimoRegistro)<(quant-10))
			{
				printf("(Página Anterior=1 Próxima Página=3 / Sair = 0)\n");	
			}
						
		}
		
		scanf("%d", &temRegistros);
			setbuf(stdin, NULL);	
			
			switch(temRegistros)
			{
				
				case 1:
					
					if(ultimoRegistro!=0)
					{
						ultimoRegistro -= 10;
						//printf("quant - ultimoRegistro = %d", quant - ultimoRegistro);
						//int sucesso = fseek(f, -10 * sizeof(cLidos[i]), SEEK_CUR);	
						//printf("fseek = %d", sucesso);
						//getch();
					}
				
				break;
				
				case 3:
					if((quant-10)>ultimoRegistro)
					{
						ultimoRegistro += 10;
					}
				break;
				
				case 0:
					temRegistros=0;
				continue;
				
				default:
					temRegistros = -1;	
					printf("Opção Inválida\n\n");	
					getch();
				break;	
			}
			
			if(temRegistros==-1)
			{
				break;
			}
			
 			if((quant - ultimoRegistro)<10)
			{
				fseek(f, -(quant - ultimoRegistro) * sizeof(cLidos[i]), SEEK_END);
			}
			else
			{
				fseek(f, ultimoRegistro * sizeof(cLidos[i]), SEEK_SET);	
			}
		
	
	}
		
	fclose(f);
	printf("\nPressione qualquer tecla para continuar...\n");
	getch();
}

void getQuantContatos()
{
	
	FILE *qtd = fopen("quantContatos.txt", "r"); //Abre o arquivo para leitura
	char str[10];
	
	if (qtd == NULL)
	{	
		FILE *qtdNovo = fopen("quantContatos.txt","w");
		
		if(qtdNovo==NULL)
		{
			printf("O arquivo não pode ser aberto\n");
		}
		
		fprintf(qtdNovo, "%d", 0);
		
		fclose(qtdNovo);	
	}
	else
	{
		fgets(str, 10, qtd);
		quant = atoi(str);
				
	}
	
	fclose(qtd);
	//Lê até SIZE-1 caracteres por vez

}

void buscarContatoPorTelefone(char telBuscado[])
{
	FILE *fbuscaTel = fopen("contatos.dat", "r");
	contato contatosAchados[10], contatosBuscados[quant];
	int i,cont=0;
	
	if(fbuscaTel==NULL)
	{
		printf("O arquivo não pode ser aberto\n");
	}
	
	fread(contatosBuscados, sizeof((*contatosBuscados)), quant, fbuscaTel);
	
	
	for(i=0;i<quant;i++)
	{
		if((strstr(contatosBuscados[i].telRes, telBuscado))!=NULL)
		{
			contatosAchados[cont] = contatosBuscados[i];
			cont++;	
		}
	}
	
	if(cont>0)
	{
		printf("\nCONTATO(S) ENCONTRADO(S)\n\n");
		
		for(i=0;i<cont;i++)
		{
			printf("Nome: %s\n", contatosAchados[i].nome);
			printf("Celular: %s\n", contatosAchados[i].cel);
			printf("Email: %s\n", contatosAchados[i].email);
			printf("Telefone Residencial: %s\n", contatosAchados[i].telRes);	
			printf("ID REGISTRO: %d\n\n", contatosAchados[i].id);	
		}
	
	}
	else
	{
		printf("\n%s não retornou resultados\n", telBuscado);
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();

}

void buscarContatoPorNome(char nomeBuscado[])
{
	FILE *fBuscaNome = fopen("contatos.dat", "r");
	contato contatosAchados[10], contatosBuscados[quant];
	int i,cont=0;
	
	if(fBuscaNome==NULL)
	{
		printf("O arquivo não pode ser aberto!\n");
	}
	
	
	fread(contatosBuscados, sizeof(contatosBuscados[i]), quant, fBuscaNome);
	
	for(i=0;i<=quant;i++)
	{
		if((strstr(contatosBuscados[i].nome, nomeBuscado))!=NULL)
		{
			contatosAchados[cont] = contatosBuscados[i];
			cont++;
		}
	}
	
	if(cont>0)
	{
		printf("\nCONTATO(S) ENCONTRADO(S)\n\n");
		
		for(i=0;i<cont;i++)
		{
			printf("Nome: %s\n", contatosAchados[i].nome);
			printf("Celular: %s\n", contatosAchados[i].cel);
			printf("Email: %s\n", contatosAchados[i].email);
			printf("Telefone Residencial: %s\n", contatosAchados[i].telRes);
			printf("ID REGISTRO: %d\n\n",contatosAchados[i].id);
		}
		
	}
	else
	{
		printf("\n%s não retornou resultados\n", nomeBuscado);
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
	
}
