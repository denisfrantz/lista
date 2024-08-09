#include <stdio.h>
#include <stdlib.h>

void inverte_lista (lista *l) {
	nolista *noAtual = l->próximo;
	lista i;
	
	inicializa_lista (&i);
	
	while (!isvazia_lista (l)) {
		insereinicio_lista (&i, noAtual->elemento);
		noAtual = noAtual->próximo;
		removeinicio_lista (l);
	}
	l->proximo = i->próximo;
}

int main() {
	
	return 0;
}
