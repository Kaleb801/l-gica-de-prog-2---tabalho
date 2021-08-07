// Trabalho Final
// Kaleb Vieira Evangelista
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//Tarefa 1 - Parte 1
int Carregar(char NomeServico[],float MatrizServico[][4])
{
	FILE *PonteiroArquivo;
	int I=0,J=0,Funcionario,Dia,Obra;
	float Horas;
	char Vetor[40];
	PonteiroArquivo=fopen(NomeServico,"r");
	if(PonteiroArquivo==NULL)
	{
		printf("Ocorreu um erro! O arquivo de servicos nao foi aberto!\n");
	  exit(1);
	}
	fgets(Vetor,40,PonteiroArquivo);
	while((fscanf(PonteiroArquivo,"%i%i%i%f",&Funcionario,&Dia,&Obra,&Horas))!=EOF)
	{
	  MatrizServico[I][J]=Funcionario;
	  J++;
	  MatrizServico[I][J]=Dia;
	  J++;
	  MatrizServico[I][J]=Obra;
	  J++;
	  MatrizServico[I][J]=Horas;
	  J=0;
	  I++;
  }
	fclose(PonteiroArquivo);
	return I;
}
//Tarefa 2 - Parte 1
void Gravar(char NomeServico[],float MatrizServico[][4],int NumeroServicos)
{
	FILE *PonteiroArquivo;
	int I=0,J=0,Funcionario,Dia,Obra;
	float Horas;
	PonteiroArquivo=fopen(NomeServico,"w");
	if(PonteiroArquivo==NULL)
	{
		printf("Ocorreu um erro! O arquivo de servicos nao foi aberto!\n");
	  exit(1);
	}
	fprintf(PonteiroArquivo," #	FUNCIONARIO	DIA	OBRA	HORAS\n");
	for(I=0;I<NumeroServicos;I++)
	{
	  Funcionario=MatrizServico[I][J];
	  J++;
	  Dia=MatrizServico[I][J];
	  J++;
	  Obra=MatrizServico[I][J];
	  J++;
	  Horas=MatrizServico[I][J];
	  fprintf(PonteiroArquivo,"	%i		%i	%i	%.1f\n",Funcionario,Dia,Obra,Horas);
	  J=0;
	}
	fclose(PonteiroArquivo);
}
//Tarefa 3 (Item 1 do Menu Principal) - Parte 1
int Cadastrar(float MatrizServico[][4],int NumeroServicos)
{
	int I=0,J=0,Escolha,Saida=0,Funcionario,Dia,Obra;
	float Horas;
	do
	{
		printf("Digite o numero do funcionario (somente 1 ao 10): ");
		scanf("%i",&Funcionario);
		printf("Digite o Dia (somente 1 ao 7): ");
		scanf("%i",&Dia);
		printf("Digite o numero da Obra (somente 1 ao 5): ");
		scanf("%i",&Obra);
		printf("Digite as horas: ");
		scanf("%f",&Horas);
	  if(Funcionario>=1&&Funcionario<=10&&Dia>=1&&Dia<=7&&Obra>=1&&Obra<=5&&NumeroServicos<100)
   	{
	  	Saida=1;
  	}
  	else
  	{
  		system("cls");
  		printf("Algum dos dados informados esta incorreto!\n");
  		fflush(stdin);
  	}
	}while(Saida!=1);
	MatrizServico[NumeroServicos][J]=Funcionario;
	J++;
	MatrizServico[NumeroServicos][J]=Dia;
	J++;
	MatrizServico[NumeroServicos][J]=Obra;
	J++;
	MatrizServico[NumeroServicos][J]=Horas;
	NumeroServicos++;
	return NumeroServicos;
}
//Tarefa 4 (Item 2 do Menu Principal) - Parte 1
int Excluir(float MatrizServico[][4],int NumeroServicos)
{
	int I=0,Funcionario,Dia,Obra,Aux,Confirmar=0;
	float Horas;
	printf("Digite o numero do funcionario (somente 1 ao 10): ");
	scanf("%i",&Funcionario);
	printf("Digite o dia (somente 1 ao 7): ");
	scanf("%i",&Dia);
	printf("Digite o numero da obra (somente 1 ao 5): ");
	scanf("%i",&Obra);
	for(I=0;I<NumeroServicos;I++)
	{
		if (MatrizServico[I][0]==Funcionario&&MatrizServico[I][1]==Dia&&Funcionario&&MatrizServico[I][2]==Obra)
		{
			Aux=I;
			Confirmar=1;
		}
	}
	if(Confirmar!=0)
		{
			for(I=Aux;I<NumeroServicos;I++)
			{
				MatrizServico[I][0]=MatrizServico[I+1][0];
			  MatrizServico[I][1]=MatrizServico[I+1][1];
			  MatrizServico[I][2]=MatrizServico[I+1][2];
			  MatrizServico[I][3]=MatrizServico[I+1][3];
			}
		}
	if (Confirmar!=0)
	{
		NumeroServicos--;
	}
	else
	{
		printf("O servico solicitado nao foi encontrado!\n");
		system("pause");
	}
	return NumeroServicos;
}
//Tarefa 5 (Item 3 do Menu Principal) - Parte 1
void Mostrar(float MatrizServico[][4],int NumeroServicos)
{
	int I=0,J=0,Funcionario,Dia,Obra,Servico;
	float Horas;
	printf(" SERVICO  FUNCIONARIO	 DIA	OBRA	HORAS\n");
	for (I=0;I<NumeroServicos;I++)
	{
		Servico=I+1;
		Funcionario=MatrizServico[I][J];
	  J++;
	  Dia=MatrizServico[I][J];
	  J++;
	  Obra=MatrizServico[I][J];
	  J++;
	  Horas=MatrizServico[I][J];
	  printf("   %i	       %i	  %i       %i	 %.1f\n",Servico,Funcionario,Dia,Obra,Horas);
	  J=0;
	}
	system("pause");
}
//Tarefa 6 (Item 4 do Menu Principal) - Parte 1
void ConsultarObraDia(float MatrizServico[][4],int NumeroServicos)
{
	int I=0,J=1,Obra,Dia;
	float Horas,MatrizObraDia[5][7]={0},TotalObra[5]={0},Total[8]={0};
	for(I=0;I<NumeroServicos;I++)
	{
	  Dia=MatrizServico[I][J];
	  Dia--;
	  J++;
	  Obra=MatrizServico[I][J];
	  Obra--;
	  J++;
	  Horas=MatrizServico[I][J];
	  MatrizObraDia[Obra][Dia]=MatrizObraDia[Obra][Dia]+Horas;
	  TotalObra[Obra]=TotalObra[Obra]+Horas;
	  Total[Dia]=Total[Dia]+Horas;
	  Total[7]=Total[7]+Horas;
	  J=1;
	}
	printf("  *** HORAS POR OBRA E POR DIA ***\n");
	printf("\n");
	printf("              DIA\n");
	printf("\n");
	printf("OBRA#|  Seg  Ter  Qua  Qui  Sex  Sab  Dom  | TOTAL\n");
	printf("----------------------------------------------\n");
  for (I=0;I<=4;I++)
  {
    printf("  %i  |  %.1f  %.1f  %.1f  %.1f  %.1f  %.1f  %.1f  |  %.1f   \n",J,MatrizObraDia[I][0],MatrizObraDia[I][1],MatrizObraDia[I][2],MatrizObraDia[I][3],MatrizObraDia[I][4],MatrizObraDia[I][5],MatrizObraDia[I][6],TotalObra[I]);
    J++;
  }
	printf("----------------------------------------------\n");
	printf("TOTAL|  %.1f  %.1f  %.1f  %.1f  %.1f  %.1f  %.1f  |  %.1f\n",Total[0],Total[1],Total[2],Total[3],Total[4],Total[5],Total[6],Total[7]);
	system("pause");
}
//Tarefa 7 (Item 5 do Menu Principal) - Parte 1
void ConsultarFuncionarioObra(float MatrizServico[][4],int NumeroServicos)
{
	int I=0,J=0,Funcionario,Obra;
	float Horas,MatrizFuncionarioObra[10][5]={0},TotalFuncionario[10]={0},Total[6]={0};
	for (I=0;I<=9;I++)
	{
			MatrizFuncionarioObra[I][0]=0;
			MatrizFuncionarioObra[I][1]=0;
			MatrizFuncionarioObra[I][2]=0;
			MatrizFuncionarioObra[I][3]=0;
			MatrizFuncionarioObra[I][4]=0;
	}
	for(I=0;I<NumeroServicos;I++)
	{
	  Funcionario=MatrizServico[I][J];
	  Funcionario--;
	  J=2;
	  Obra=MatrizServico[I][J];
	  Obra--;
	  J++;
	  Horas=MatrizServico[I][J];
	  MatrizFuncionarioObra[Funcionario][Obra]=MatrizFuncionarioObra[Funcionario][Obra]+Horas;
	  TotalFuncionario[Funcionario]=TotalFuncionario[Funcionario]+Horas;
	  Total[Obra]=Total[Obra]+Horas;
	  Total[5]=Total[5]+Horas;
	  J=0;
	}
	printf("  *** HORAS POR FUNCIONARIO E POR OBRA ***\n");
	printf("\n");
	printf("              OBRA\n");
	printf("\n");
	printf("FUNC#|  1    2    3    4    5   | TOTAL\n");
	printf("----------------------------------------------\n");
	J=1;
  for (I=0;I<=8;I++)
  {
    printf("  %i |  %.1f  %.1f  %.1f  %.1f  %.1f  |  %.1f\n",J,MatrizFuncionarioObra[I][0],MatrizFuncionarioObra[I][1],MatrizFuncionarioObra[I][2],MatrizFuncionarioObra[I][3],MatrizFuncionarioObra[I][4],TotalFuncionario[I]);
    J++;
  }
  printf(" 10 |  %.1f  %.1f  %.1f  %.1f  %.1f  |  %.1f\n",MatrizFuncionarioObra[9][0],MatrizFuncionarioObra[9][1],MatrizFuncionarioObra[9][2],MatrizFuncionarioObra[9][3],MatrizFuncionarioObra[9][4],TotalFuncionario[9]);
	printf("----------------------------------------------\n");
	printf("TOTAL| %.1f  %.1f  %.1f  %.1f  %.1f |  %.1f\n",Total[0],Total[1],Total[2],Total[3],Total[4],Total[5]);
	system("pause");
}
//Tarefa 2 - Parte 2
float CalcularHoras(float MatrizServico[][4],int Escolha)
{
	int I=0,J=2,Obra;
	float Horas,TotalHoras=0;
	for (I=0;I<99;I++)
	{
		Obra=MatrizServico[I][J];
		J++;
		Horas=MatrizServico[I][J];
		if (Obra==Escolha)
		{
			TotalHoras=TotalHoras+Horas;
		}
		J=2;
	}
	return TotalHoras;
}
//Tarefa 3 - Parte 2
int HorasSemanais(float MatrizServico[][4],int Escolha)
{
	int Categoria;
	float HorasSemanais;
	HorasSemanais=CalcularHoras(MatrizServico,Escolha);
	if(HorasSemanais<50)
	{
		Categoria=1;
	}
	else
	{
		if(HorasSemanais>=50&&HorasSemanais<100)
		{
			Categoria=2;
		}
		else
		{
			if (HorasSemanais>=100&&HorasSemanais<250)
			{
				Categoria=3;
			}
			else
			{
				Categoria=4;
			}
		}
	}
	return Categoria;
}
//Tarefa 4 (Item 6 do Menu Principal) - Parte 2
float CalcularCusto(float MatrizServico[][4],float VetorMultiplicador[5],float VetorAcrescimo[7],int Escolha)
{
	int I=0,J=1,Dia,Categoria,Obra;
	float TotalHoras,CustoObra,Horas,Sabado=0,Domingo=0;
	TotalHoras=CalcularHoras(MatrizServico,Escolha);
	Categoria=HorasSemanais(MatrizServico,Escolha);
	VetorMultiplicador[0]=VetorMultiplicador[0]*VetorMultiplicador[Categoria];
	for (I=0;I<99;I++)
	{
		Dia=MatrizServico[I][J];
		J++;
		Obra=MatrizServico[I][J];
		J++;
		Horas=MatrizServico[I][J];
		if (Dia==6&&Escolha==Obra)
		{
			Sabado=Sabado+Horas;
		}
		if (Dia==7&&Escolha==Obra)
		{
			Domingo=Domingo+Horas;
		}
		J=1;
	}
	TotalHoras=TotalHoras-Sabado;
	TotalHoras=TotalHoras-Domingo;
	CustoObra=TotalHoras*VetorMultiplicador[0];
	if(Sabado>0)
	{
		Sabado=Sabado*VetorMultiplicador[0];
	  Sabado=Sabado*((VetorAcrescimo[5]/100)+1);
	}
	if(Domingo>0)
	{
		Domingo=Domingo*VetorMultiplicador[0];
	  Domingo=Domingo*((VetorAcrescimo[6]/100)+1);
	}
	CustoObra=CustoObra+Sabado+Domingo;
	return CustoObra;
}
//Tarefa 1 e 5 (Item 7 do Menu Principal) - Parte 2
void LerCusto(int Escolha,float TotalSemana[1],float MatrizServico[][4],float VetorMultiplicador[5],float VetorAcrescimo[7],char NomeMultiplicador[15],char NomeAcrescimo[15])
{
	FILE *PonteiroArquivo;
	int I=0;
	float ValorA,ValorB,TotalObra;
	char Vetor[45];
	PonteiroArquivo=fopen(NomeMultiplicador,"r");
	if(PonteiroArquivo==NULL)
	{
		printf("Ocorreu um erro! O arquivo de multiplicadores nao foi aberto!\n");
	  exit(1);
	}
	fgets(Vetor,45,PonteiroArquivo);
	fscanf(PonteiroArquivo,"%f",&ValorA);
	VetorMultiplicador[I]=ValorA;
	I++;
	fgets(Vetor,45,PonteiroArquivo);
	fgets(Vetor,45,PonteiroArquivo);
	fgets(Vetor,45,PonteiroArquivo);
	fgets(Vetor,45,PonteiroArquivo);
	while((fscanf(PonteiroArquivo,"%f%f",&ValorA,&ValorB))!=EOF)
	{
	  VetorMultiplicador[I]=ValorB;
	  I++;
  }
  I=0;
	fclose(PonteiroArquivo);
	PonteiroArquivo=fopen(NomeAcrescimo,"r");
	if(PonteiroArquivo==NULL)
	{
		printf("Ocorreu um erro! O arquivo de acrescimos nao foi aberto!\n");
	  exit(1);
	}
	fgets(Vetor,45,PonteiroArquivo);
	while((fscanf(PonteiroArquivo,"%f%f",&ValorA,&ValorB))!=EOF)
	{
	  VetorAcrescimo[I]=ValorB;
	  I++;
  }
  TotalObra=CalcularCusto(MatrizServico,VetorMultiplicador,VetorAcrescimo,Escolha);
  if (TotalSemana[0]==0)
  {
  	printf("O custo total da obra %i: %.2f\n",Escolha,TotalObra);
  	system("pause");
  }
  else
  {
  	TotalSemana[Escolha]=TotalObra;
  	if(Escolha==5)
  	{
  		TotalSemana[0]=TotalSemana[0]-1;
  		for(I=1;I<=5;I++)
  		{
  			TotalSemana[0]=TotalSemana[0]+TotalSemana[I];
  		}
  		printf("O custo total da semana: %.2f\n",TotalSemana[0]);
  		system("pause");
  	}
  }
  fclose(PonteiroArquivo);
}
int main()
{
	int Escolha,NumeroServicos;
	float MatrizServico[100][4]={0},VetorMultiplicador[5]={0},VetorAcrescimo[7]={0},TotalSemana[6]={0};
	char NomeServico[20],NomeMultiplicador[20],NomeAcrescimo[20];
	printf("(Preencha os campos a seguir sem adicionar a extencao de arquivo)\n");
	printf("Digite o nome do arquivo de servicos: ");
	gets(NomeServico);
	strcat(NomeServico,".txt");
	NumeroServicos=Carregar(NomeServico,MatrizServico);
	printf("Digite o nome do arquivo contendo os multiplicadores: ");
	gets(NomeMultiplicador);
	strcat(NomeMultiplicador,".txt");
	printf("Digite o nome do arquivo contendo acrescimos percentuais: ");
	gets(NomeAcrescimo);
	strcat(NomeAcrescimo,".txt");
	do
	{
		system("cls");
		printf("  ### G E R E N C I A D E S E R V I C O S ###\n");
		printf("  ------- M E N U P R I N C I P A L ---------\n");
		printf("\n");
		printf("(1)Cadastrar servico\n");
		printf("(2)Excluir servico\n");
		printf("(3)Mostrar servicos\n");
		printf("(4)Consultar horas trabalhadas por obra e dia de servico\n");
		printf("(5)Consultar horas trabalhadas por funcionario e por obra\n");
		printf("(6)Consultar o custo total de uma obra\n");
		printf("(7)Consulta o custo total da semana, de todas as obras\n");
		printf("(8)Fim\n");
		printf("\n");
		printf("Digite a funcionalidade escolhida: ");
		fflush(stdin);
		scanf("%i",&Escolha);
		system("cls");
		switch (Escolha)
		{
			case 1:NumeroServicos=Cadastrar(MatrizServico,NumeroServicos);
			break;
			case 2:NumeroServicos=Excluir(MatrizServico,NumeroServicos);
			break;
			case 3:Mostrar(MatrizServico,NumeroServicos);
			break;
			case 4:ConsultarObraDia(MatrizServico,NumeroServicos);
			break;
			case 5:ConsultarFuncionarioObra(MatrizServico,NumeroServicos);
			break;
			case 6:printf("Escolha uma obra (somente 1 ao 5): ");
			       scanf("%i",&Escolha);
			       if (Escolha>=1&&Escolha<=5)
			       {
			       		LerCusto(Escolha,TotalSemana,MatrizServico,VetorMultiplicador,VetorAcrescimo,NomeMultiplicador,NomeAcrescimo);
			       }
			       else
			       {
			       		printf("A obra digitada nao existe!\n");
			       		system("pause");
			       }
			break;
			case 7:TotalSemana[0]=1;
			       for(Escolha=1;Escolha<=5;Escolha++)
			       {
			      		LerCusto(Escolha,TotalSemana,MatrizServico,VetorMultiplicador,VetorAcrescimo,NomeMultiplicador,NomeAcrescimo);
			       }
			       TotalSemana[0]=0;
			break;
		}
	}while(Escolha!=8);
	Gravar(NomeServico,MatrizServico,NumeroServicos);
	system("Pause");
	return 0;
}
