#include<stdio.h>

struct No {

    int valor;  //cada NO tem um valor inteiro
    No *prox;   // e um ponteiro prox apontando para o pr�ximo NO

    No() {      //construtor padr�o // chamado quando um novo No � criado sem nenhum argumento
        valor = 0;  // inicializa com o valor 0
        prox = NULL;    // e o pr�ximo com NULL
    }

    No(int _valor) { //construtor sobrecarregado // chamado quando um novo NO � criado com um argumento inteiro
        valor = _valor; //inicializa valor com _valor
        prox = NULL;    //prox com NULL
    }

};
// primeiro elemento inserido ser� o �ltimo a ser removido
struct Pilha {

    No *inicio; //ponteiro inicio apontando para o primeiro NO
    int n;      // n = mant�m o n�mero de elementos na pilha

    Pilha() {   //construtor padr�o
        inicio = NULL;  //inicializa inicio com NULL
        n = 0;          // ||  e n com 0
    }

    bool vazia() { // O(1)    // verifica se a pilha est� vazia
        return inicio == NULL;  //retorna verdadeiro se inicio for null
    }                           // caso contr�rio, retorna falso

    void inserir(int valor) { // O(1)   // insere um novo NO com valor no in�cio da pilha

        n++;
        No *novo = new No(valor);   // cria um novo NO com o valor fornecido

        if (vazia()) {      // se a pilha estiver vazia
            inicio = novo;  // define inicio como o novo NO
            return;
        }
        //caso contr�rio, insere o novo NO no in�cio da pilha
        novo->prox = inicio;  // atualizando o ponteiro prox do novo NO para apontar para o NO anteriormente no in�cio da pilha
        inicio = novo;

    }

    void imprimir() { // O(n)   // imprime todos os valores na pilha

        No *aux = inicio;   // come�a com o NO no in�cio da pilha e continua seguindo os ponteiros prox at� chegar ao final da pilha (NULL)

        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->prox;
        }

        printf("\n");

    }

    int tamanho() { // O(1) // retorna os n�meros de elementos na pilha
        return n;
    }

    void remover() { // O(1)    //remove o No do in�cio da pilha

        if (tamanho() <= 1) {   // se a pilha tiver um ou nenhum elemento
            delete(inicio);     // deleta o No no in�cio e define com NULL
            inicio = NULL;
            n = 0;
            return;
        }
        // caso contr�rio:
        No *r = inicio; // move o ponteiro inicio para o segundo NO na pilha
        inicio = inicio->prox;
        delete(r);  // e ent�o deleta o primeiro NO
        n--;
    }

};

int main() {

    Pilha p;

    p.inserir(1);
    p.inserir(2);
    p.inserir(3);
    p.remover();

    p.imprimir();

    return 0;
}
