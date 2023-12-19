#include<stdio.h>

struct No { //define uma estrutura chamada No

    int valor;  //vari�vel inteira chamada valor dentro da estrutura No. Esta vari�vel � usada para armazenar o valor do n�
    No *prox;   //declara um ponteiro para No chamado prox dentro da estrutura No. Este ponteiro � usado para apontar para o pr�ximo n� na fila

    No() {  //construtor padr�o para a estrutura No
        valor = 0;  //incializa valor como 0
        prox = NULL; // e prox com NULL
    }

    No(int _valor) {    //construtor sobrecarregado para a estrutura No que aceita um par�metro inteiro
        valor = _valor; // inicializa valor com o valor passado como argumento (_valor)
        prox = NULL;    // e o pr�ximo como NULL
    }

};
// fila = insere no FIM e remove no INICIO, logo, o primeiro elemento a ser inserido ser� o primeiro a ser removido
struct Fila {

    No *inicio, *fim;   //Essas s�o duas vari�veis do tipo ponteiro para No. inicio e fim s�o usados para representar o in�cio e o fim da fila
    int n;           // Esta � uma vari�vel inteira usada para manter o controle do n�mero de elementos na fila.

    Fila() {    //Este � o construtor da fila
        inicio = NULL;  //Ele inicializa inicio e fim como NULL e n como 0. Isso significa que a fila est� vazia no momento da cria��o
        fim = NULL;
        n = 0;
    }

    bool vazia() { // O(1)  //Esta � uma fun��o que verifica se a fila est� vazia
        return inicio == NULL;  // Ela retorna true se inicio for NULL (ou seja, n�o h� elementos na fila), e false caso contr�rio
    }

    void inserir(int valor) { // O(1)   //Esta � uma fun��o que insere um novo valor na fila

        n++;    //Incrementa o contador n para refletir o novo elemento sendo adicionado
        No *novo = new No(valor);   //Cria um novo n� com o valor fornecido

        if (vazia()) {  //Se a fila estiver vazia (verificado pela fun��o vazia()), o novo n� se torna o in�cio e o fim da fila
            inicio = novo;
            fim = novo;
            return;
        }

        fim->prox = novo;   //Se a fila n�o estiver vazia, o novo n� � adicionado no fim da fila // O ponteiro prox do �ltimo n� � atualizado para apontar para o novo n�
        fim = novo;    //e o ponteiro fim � atualizado para apontar para o novo n�.

    }

    void imprimir() { // O(n)   //Esta � uma fun��o que imprime todos os valores na fila.

        No *aux = inicio;   //Cria um ponteiro auxiliar que aponta para o in�cio da fila.

        while (aux != NULL) {   //Enquanto o ponteiro auxiliar n�o for NULL (ou seja, enquanto n�o chegarmos ao fim da fila)
            printf("%d -> ", aux->valor);   //imprime o valor do n� atual seguido por �->�.
            aux = aux->prox;    //Atualiza o ponteiro auxiliar para apontar para o pr�ximo n� na fila.
        }

        printf("\n");

    }

    int tamanho() { // O(1) // Esta � uma fun��o que retorna o n�mero de elementos na fila
        return n;   //retorna o valor n, que � atualizado sempre que um elemento � inserido ou removido da fila
    }

    void remover() { // O(1)    //fun��o que remove um elemento do in�cio da fila

        if (tamanho() <= 1) {   //Se o tamanho da fila for 1 ou menos
            delete(inicio); // ela deleta o n� no in�cio da fila
            inicio = NULL;  //atualiza os ponteiros, inicio para NULL
            fim = NULL;     // fim para NULL
            n = 0;  // e n para 0
            return;
        }
        // Se o tamanho da fila for maior que 1:
        No *r = inicio; //cria um novo ponteiro r e faz com que ele aponte para o mesmo n� que o ponteiro inicio est� apontando. Isso significa que r agora est� apontando para o primeiro n� na fila
        inicio = inicio->prox;  //atualiza o ponteiro inicio para apontar para o segundo n� na fila. O operador -> � usado para acessar o membro prox do n� para o qual inicio est� apontando. Ent�o, inicio->prox � o segundo n� na fila
        delete(r);  //deleta o n� para o qual r est� apontando. Como r estava apontando para o primeiro n� na fila, isso efetivamente remove o primeiro n� da fila
        n--;    //decrementa o valor de n em 1. Como n est� sendo usado para rastrear o n�mero de elementos na fila, isso atualiza n para refletir o fato de que um elemento foi removido da fila
    }

};

int main() {

    int n; //declarando a vari�vel n que ir� receber o valor digitado pelo o usu�rio
    scanf("%d", &n); //leitura do valor n //armazenando o valor na vari�vel n //indica o tamanho do baralho

    Fila f; //cria uma inst�ncia da estrutura de dados Fila chamada f

    for (int i = 1; i <= n; i++){ //la�o de repeti��o que ser� incrementado at� que i seja menor ou igual a n //baralho numerado de 1 at� n
        f.inserir(i);   //inser��o de valores na Fila, ou seja, inserindo valores no baralho
    }

    while(f.tamanho() > 1){ //enquanto, o tamanho da fila F for maior do que um
        printf("%d\n", f.inicio->valor); //imprime o valor do primeiro elemento na fila
        f.remover(); //remove o primeiro elemento da fila
        f.inserir(f.inicio->valor); //f.inicio->valor obt�m o valor do novo primeiro elemento da fila (que costumava ser o segundo elemento antes da remo��o) //A fun��o f.inserir(f.inicio->valor); ent�o insere esse valor no final da fila
        f.remover(); //remove o primeiro elemento da fila
    }

    printf("Restante: %d\n", f.inicio->valor); //imprime o valor da carta restante
    return 0;
}
