#include <stdio.h>
#include <stdlib.h>
  
struct Produto
{
  char descrição[50];
  float preco;
};

struct Comanda
{
  int codigo;
  struct Produto listaDeProdutos[100];
  float tmpInicio;
  float tmpFim;
};

struct Fila {

	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens; 

};

void criarFila( struct Fila *f, int c ) { 

	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 

}

void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int remover( struct Fila *f ) { // pega o item do comeÃ§o da fila

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

int estaVazia( struct Fila *f ) { // retorna verdadeiro se a fila estÃ¡ vazia

	return (f->nItens==0);

}

int estaCheia( struct Fila *f ) { // retorna verdadeiro se a fila estÃ¡ cheia

	return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%.2f\t",f->dados[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");

}

void main () {

	int opcao, capa;
	float valor;
	struct Fila umaFila;

	// cria a fila
	printf("\nCapacidade da fila? ");
	scanf("%d",&capa);
	criarFila(&umaFila, capa);

	// apresenta menu
	while( 1 ){

		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: // insere elemento
				if (estaCheia(&umaFila)){

					printf("\nFila Cheia!!!\n\n");

				}
				else {

					printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					inserir(&umaFila,valor);

				}

				break;

			case 2: // remove elemento
				if (estaVazia(&umaFila)){

					printf("\nFila vazia!!!\n\n");

				}
				else {

					valor = remover(&umaFila);
					printf("\n%1f removido com sucesso\n\n", valor) ; 

				}
				break;

				case 3: // mostrar fila
					if (estaVazia(&umaFila)){

						printf("\nFila vazia!!!\n\n");

					}
					else {

						printf("\nConteudo da fila => ");
						mostrarFila(&umaFila);

					}
					break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}
}

#include <stdio.h>
#include <time.h> //necessÃ¡rio para usar localtime() e struct tm
int main(void)
{
  //ponteiro para struct que armazena data e hora  
  struct tm *data_hora_atual;     
  
  //variÃ¡vel do tipo time_t para armazenar o tempo em segundos  
  time_t segundos;
  
  //obtendo o tempo em segundos  
  time(&segundos);   
  
  //para converter de segundos para o tempo local  
  //utilizamos a funÃ§Ã£o localtime  
  data_hora_atual = localtime(&segundos);  
  
  //para acessar os membros de uma struct usando o ponteiro
  //utilizamos o operador -> no nosso caso temos: 
  //data_hora_atual->membro_da_struct
  
  //Acessando dados convertidos para a struct data_hora_atual  
  printf("\nDia..........: %d\n", data_hora_atual->tm_mday);  
  
  //para retornar o mÃªs corretamente devemos adicionar +1 
  //como vemos abaixo
  printf("\nMes..........: %d\n", data_hora_atual->tm_mon+1);
  
  //para retornar o ano corretamente devemos adicionar 1900 
  //como vemos abaixo
  printf("\nAno..........: %d\n\n", data_hora_atual->tm_year+1900);  
  
  printf("\nDia do ano...: %d\n", data_hora_atual->tm_yday);  
  printf("\nDia da semana: %d\n\n", data_hora_atual->tm_wday);
    
  /* Obtendo os valores da struct data_hora_atual  
    e formatando a saÃ­da de dados no formato 
    hora: minuto: segundo
     
  Para nÃ£o ficar um printf muito longo em uma Ãºnica linha
  de comando, quebrei a impressÃ£o em 3 partes mostrando
  uma informaÃ§Ã£o em cada linha 
  */  
  printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora   
  printf("%d:",data_hora_atual->tm_min);//minuto
  printf("%d\n",data_hora_atual->tm_sec);//segundo  
  
  /* Obtendo os valores da struct data_hora_atual  
     e formatando a saÃ­da de dados no formato dia/mes/ano 
     
     Para nÃ£o ficar um printf muito longo em uma Ãºnica 
     linha de comando, quebrei a impressÃ£o em 3 partes
     sendo uma informaÃ§Ã£o em cada linha   
  */  
  //dia do mÃªs
  printf("\nData ........: %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1); //mÃªs
  printf("%d\n\n",data_hora_atual->tm_year+1900); //ano
  
  return 0;
}
