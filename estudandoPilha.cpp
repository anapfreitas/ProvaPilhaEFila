#include<stdio.h>

struct No {

    int valor;  //cada NO tem um valor inteiro
    No *prox;   // e um ponteiro prox apontando para o próximo NO

    No() {      //construtor padrão // chamado quando um novo No é criado sem nenhum argumento
        valor = 0;  // inicializa com o valor 0
        prox = NULL;    // e o próximo com NULL
    }

    No(int _valor) { //construtor sobrecarregado // chamado quando um novo NO é criado com um argumento inteiro
        valor = _valor; //inicializa valor com _valor
        prox = NULL;    //prox com NULL
    }

};
// primeiro elemento inserido será o último a ser removido
struct Pilha {

    No *inicio; //ponteiro inicio apontando para o primeiro NO
    int n;      // n = mantém o número de elementos na pilha

    Pilha() {   //construtor padrão
        inicio = NULL;  //inicializa inicio com NULL
        n = 0;          // ||  e n com 0
    }

    bool vazia() { // O(1)    // verifica se a pilha está vazia
        return inicio == NULL;  //retorna verdadeiro se inicio for null
    }                           // caso contrário, retorna falso

    void inserir(int valor) { // O(1)   // insere um novo NO com valor no início da pilha

        n++;
        No *novo = new No(valor);   // cria um novo NO com o valor fornecido

        if (vazia()) {      // se a pilha estiver vazia
            inicio = novo;  // define inicio como o novo NO
            return;
        }
        //caso contrário, insere o novo NO no início da pilha
        novo->prox = inicio;  // atualizando o ponteiro prox do novo NO para apontar para o NO anteriormente no início da pilha
        inicio = novo;

    }

    void imprimir() { // O(n)   // imprime todos os valores na pilha

        No *aux = inicio;   // começa com o NO no início da pilha e continua seguindo os ponteiros prox até chegar ao final da pilha (NULL)

        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->prox;
        }

        printf("\n");

    }

    int tamanho() { // O(1) // retorna os números de elementos na pilha
        return n;
    }

    void remover() { // O(1)    //remove o No do início da pilha

        if (tamanho() <= 1) {   // se a pilha tiver um ou nenhum elemento
            delete(inicio);     // deleta o No no início e define com NULL
            inicio = NULL;
            n = 0;
            return;
        }
        // caso contrário:
        No *r = inicio; // move o ponteiro inicio para o segundo NO na pilha
        inicio = inicio->prox;
        delete(r);  // e então deleta o primeiro NO
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
