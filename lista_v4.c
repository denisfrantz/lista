#include <stdio.h>

typedef struct nolista {
	int elemento;
	struct nolista *anterior, *proximo; // indica o ponteiro para o �ltimo e primeiro n� da lista
} nolista, lista;

/* OPERAÇÕES BÁSICAS : ATRIBUTOS ********************************************/

void inicializa_lista (lista *l) {
	l->anterior = NULL; // indica o �ltimo n� da lista
	l->proximo = NULL; // indica o primeiro n� da lista
}

int isvazia_lista (lista *l) {
	if (l->proximo == NULL) return 1;
	return 0;
}

int ischeia_lista (lista *l) {
	return 0;
}

/* ENDEREÇOS PARA CONSULTA **************************************************/

nolista *addressprimeiro_lista (lista *l) {;}
nolista *addressultimo_lista (lista *l) {;}
nolista *addressproximo_lista (nolista *no) {;}
nolista *addressanterior_lista (lista *l, nolista *no) {;}
nolista *addresschave_lista (lista *l, int elemento) {;}
nolista *addressno_lista (lista *l, int noPosicao) {;}
nolista *addressnoanterior_lista (lista *l, int noposicao) {;}

/* OPERAÇÕES PARA ALOCAÇÃO DO NÓ E LIGAÇÃO NA LISTA *************************/

void setinicio_lista (lista *l, nolista *noInserir) {;}
void setfim_lista (lista *l, nolista *noInserir, nolista *ultimoNo) {;}
void setno_lista (lista *l, nolista *noInserir, nolista *noAnterior) {;}


/* OPERAÇÕES DE CONSULTA ****************************************************/

int getinicio_lista (lista *l) {;}
int getfim_lista (lista *l) {;}
int getchaveno_lista (lista *l, int no) {;}
int getnochave_lista (lista *l, int elemento) {;}
int gettamanho_lista (lista *l) {;}
int getquantidade_lista (lista *l, int elemento) {;}
int getnoinsercaoordenada_lista (lista *l, int elemento) {;}

/* OPERAÇÕES DE INSERÇÃO ****************************************************/

void insere_lista (lista *l, nolista *noProximo, nolista *noAnterior, int elemento) {;}

void insereinicio_lista (lista *l, int elemento) {
	nolista *noAlocado = (nolista *) malloc (sizeof(nolista));
	nolista *auxiliar = l->proximo;
	if (noAlocado) 	{ 
		noAlocado->elemento = elemento;
		noAlocado->anterior = NULL;
		if (isvazia_lista (l)) {
			noAlocado->proximo = NULL;
			l->anterior = noAlocado;
		}
		else {
			noAlocado->proximo = l->proximo;
			auxiliar->anterior = noAlocado;
		}
		l->proximo = noAlocado;
	}
}

void inserefim_lista (lista *l, int elemento) {
	nolista *noAlocado = (nolista *) malloc (sizeof(nolista));
	nolista *auxiliar = l->anterior;
	if (noAlocado) 	{ 
		noAlocado->elemento = elemento;
		noAlocado->proximo = NULL;
		if (isvazia_lista (l)) {
			noAlocado->anterior = NULL;
			l->proximo = l->anterior = noAlocado;
		}
		else {
			noAlocado->anterior = auxiliar;
			auxiliar->proximo = noAlocado;
		}
		l->anterior = noAlocado;
	}
}

void insereno_lista (lista *l, int elemento, int noposicao) {
	nolista *noAlocado = (nolista *) malloc (sizeof(nolista));
	nolista *noAtual = l->proximo;
	int no = 1;
	if (noAlocado) 	{ // por precaução caso não tenha sido alocado o NÓ
		noAlocado->elemento = elemento;
		if (isvazia_lista (l) || noposicao == 1) {
			noAlocado->proximo = l->proximo;
			l->proximo = noAlocado;
		}
		else {
			noAlocado->proximo = NULL;
			do {
				no++;
				if (no == noposicao) {
					noAlocado->proximo = noAtual->proximo;
					noAtual->proximo = (nolista *) noAlocado;
					break;
				}
				if (noAtual->proximo == NULL) {
					noAtual->proximo = (nolista *) noAlocado;
					break;
				}
				noAtual = (nolista *) noAtual->proximo;
			}
			while (noAtual);
		}
	}
}

void insereordenado_lista (lista *l, int elemento) {;}

/* OPERAÇÕES DE REMOÇÃO *****************************************************/

void retirano_lista (lista *l, nolista *noRemover, nolista *noProximo, nolista *noAnterior) {;}
void removeaddress_lista (lista *l, nolista *noRemover) {;}

void removeinicio_lista (lista *l) {
	nolista *noAtual = l->proximo;
	nolista *auxiliar;
	if (!isvazia_lista (l)) {
		if (l->proximo == l->anterior) {
			l->proximo = NULL;
			l->anterior = NULL;
		}	
		else {
			l->proximo = noAtual->proximo;
			auxiliar = noAtual->proximo;
			auxiliar->anterior = NULL;
		}
		free (noAtual);
	}
}

void removefim_lista (lista *l) {
	nolista *noAtual = l->anterior;
	nolista *auxiliar;
	if (!isvazia_lista (l)) {
		if (l->anterior == l->proximo) {
			l->anterior = NULL;
			l->proximo = NULL;
		}
		else {
			auxiliar = (nolista *) noAtual->anterior;
			auxiliar->proximo = NULL;
			l->anterior = auxiliar;
		}
		free (noAtual);
	}
}

void removeno_lista (lista *l, int noposicao) {;}
void removechave_lista (lista *l, int elemento) {;}
void remove_lista (lista *l, int elemento) {;}
void remocao_lista (lista *l, int elemento) {;}

/* OUTRAS OPERAÇÕES *********************************************************/

void libera_lista (lista *l) {
	nolista *noAtual = l->proximo;
	nolista *anterior = NULL;
	if (!isvazia_lista (l)) {
		while (noAtual) {
			anterior = noAtual;
			noAtual = noAtual->proximo;
			free (anterior);
		}
		l->proximo = NULL;
		l->anterior = NULL;
	}
}

void liberano_lista (nolista *no) {;}
void removerecursivo_lista (lista *l) {;}
void removeajusta_lista (lista *l) {;}
void inverte_lista (lista *l) {;}

/* OPERAÇÕES COMPLEMENTARES *************************************************/

void inversao_lista (lista *l) {
	nolista *noAtual = l->proximo;
	nolista *auxiliar;
	if (!isvazia_lista (l)) {
		do {
			auxiliar = noAtual->proximo;
			noAtual->proximo = noAtual->anterior;
			noAtual->anterior = auxiliar;
			noAtual = auxiliar;
		} while (noAtual);
		auxiliar = l->proximo; 
		l->proximo = l->anterior;
		l->anterior = auxiliar;
	}
}

void exibeestrutura_lista (lista *l) {
	nolista *noAtual = l->proximo;
	nolista *anterior = NULL;
	int no = 1;
	printf ("\n&Lista: %x   &PrimeiroNo': %x  &UltimoNo': %x\n", &(*l), noAtual, l->anterior);
	if (!isvazia_lista (l)) {
		printf ("                                   Funcoes p/ Retorno de Enderecos");
		printf ("\nNo' &No'   Anterior Proximo Chave  &Anter. &Proxim &No'Ant &Chave");
		printf ("\n--  ------ -------- ------- -----  ------- ------- ------- -------\n");
		do {
			printf ("%2d %7x  %7x %7x ", no, noAtual, noAtual->anterior, noAtual->proximo);
			printf ("%5d  %7x ", noAtual->elemento, noAtual->anterior);
			printf ("%7x %7x ", noAtual->proximo, NULL);
			printf ("%7x\n", NULL);
			anterior = noAtual;
			noAtual = noAtual->proximo;
			no++;
		} while (noAtual);
	}
}

/****************************************************************************/

int main ( void ) {
	int opcao, operacao, elemento, no;
	lista l;
	inicializa_lista (&l);
    
    do {
		printf ("============ OPERACOES CONVENCIONAIS SOBRE A LISTA =============\n");
		printf ("Inserir:  1-Inicio  2-Fim   3-No'   4-Ordenado  10-Inverter[11]\n");
		printf ("Remover:  6-Inicio  7-Fim   8-No'   9-Elemento  12-Inicializar\n");
		printf ("Exibir.: 13-Inicio 14-Fim  15-No'  16-Tamanho   17-ElementoNo's\n");
		printf ("RemoveREPETIDOS(18-Elementos[19] 20-TodosOrdenando) 5-ESTRUTURA\n");
		printf ("21-RemoveRecursivamente    Informe a opcao (0-Sair): "); scanf  ("%d", &opcao);
        
		if (opcao == 5) exibeestrutura_lista (&l);
		
        if ((opcao > 0 && opcao < 6) && ischeia_lista (&l)) {
        	printf ("\nLista Cheia...\n\n");
        	continue;
        }
        
        if (opcao > 5 && isvazia_lista (&l)) {
        	printf ("\nLista Vazia...\n\n");
        	continue;
        }
		
		if ((opcao > 0 && opcao < 5) || opcao == 9 || (opcao > 16 && opcao < 20)) {
        	 printf ("Informe o Elemento: "); scanf ("%d", &elemento);
		}
		
		if (opcao == 3 || opcao == 8 || opcao == 15) {
			printf ("Informe o No': "); scanf  ("%d", &no);
		}
		
		if (opcao == 1) insereinicio_lista (&l, elemento);
		else if (opcao == 2) inserefim_lista (&l, elemento);
		else if (opcao == 3) insereno_lista (&l, elemento, no);
		else if (opcao == 4) insereordenado_lista (&l, elemento);
		else if (opcao == 6) removeinicio_lista (&l);
		else if (opcao == 7) removefim_lista (&l);
		else if (opcao == 8) removeno_lista (&l, no);
		else if (opcao == 9) removechave_lista (&l, elemento);
		else if (opcao == 10) inverte_lista (&l);
		else if (opcao == 11) inversao_lista (&l);
		else if (opcao == 12) libera_lista (&l);
		else if (opcao == 13) printf ("=> Primeiro Elemento: %d\n", getinicio_lista (&l));
		else if (opcao == 14) printf ("=> Ultimo Elemento: %d\n", getfim_lista (&l));

		else if (opcao == 15) {
				elemento = getchaveno_lista (&l, no);
				printf ("=> Elemento do %do.No' da lista: %d\n", no, elemento);
		}
		else if (opcao == 16) printf ("=> Tamanho (em Nos): %d\n", gettamanho_lista (&l));
		else if (opcao == 17) {;}
		else if (opcao == 18) remove_lista (&l, elemento);
		else if (opcao == 19) remocao_lista (&l, elemento);
		else if (opcao == 20) removeajusta_lista (&l);
		else if (opcao == 21) removerecursivo_lista (&l);
		
		if (opcao == 5) printf ("\n");
		else;
	} while ( opcao != 0 );
    return ( 0 );
}
