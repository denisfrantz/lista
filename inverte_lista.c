#include <stdio.h>
#include <stdlib.h>

void inverte_lista (lista *l) {
	nolista *noAtual = l->pr�ximo;
	lista i;
	
	inicializa_lista (&i);
	
	while (!isvazia_lista (l)) {
		insereinicio_lista (&i, noAtual->elemento);
		noAtual = noAtual->pr�ximo;
		removeinicio_lista (l);
	}
	l->proximo = i->pr�ximo;
}

int main() {
	
	return 0;
}
