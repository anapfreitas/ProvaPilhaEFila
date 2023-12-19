#include<stdio.h>

struct No { //define uma estrutura chamada No

    int valor;  //variável inteira chamada valor dentro da estrutura No. Esta variável é usada para armazenar o valor do nó
    No *prox;   //declara um ponteiro para No chamado prox dentro da estrutura No. Este ponteiro é usado para apontar para o próximo nó na fila

    No() {  //construtor padrão para a estrutura No
        valor = 0;  //incializa valor como 0
        prox = NULL; // e prox com NULL
    }

    No(int _valor) {    //construtor sobrecarregado para a estrutura No que aceita um parâmetro inteiro
        valor = _valor; // inicializa valor com o valor passado como argumento (_valor)
        prox = NULL;    // e o próximo como NULL
    }

};
// fila = insere no FIM e remove no INICIO, logo, o primeiro elemento a ser inserido será o primeiro a ser removido
struct Fila {

    No *inicio, *fim;   //Essas são duas variáveis do tipo ponteiro para No. inicio e fim são usados para representar o início e o fim da fila
    int n;           // Esta é uma variável inteira usada para manter o controle do número de elementos na fila.

    Fila() {    //Este é o construtor da fila
        inicio = NULL;  //Ele inicializa inicio e fim como NULL e n como 0. Isso significa que a fila está vazia no momento da criação
        fim = NULL;
        n = 0;
    }

    bool vazia() { // O(1)  //Esta é uma função que verifica se a fila está vazia
        return inicio == NULL;  // Ela retorna true se inicio for NULL (ou seja, não há elementos na fila), e false caso contrário
    }

    void inserir(int valor) { // O(1)   //Esta é uma função que insere um novo valor na fila

        n++;    //Incrementa o contador n para refletir o novo elemento sendo adicionado
        No *novo = new No(valor);   //Cria um novo nó com o valor fornecido

        if (vazia()) {  //Se a fila estiver vazia (verificado pela função vazia()), o novo nó se torna o início e o fim da fila
            inicio = novo;
            fim = novo;
            return;
        }

        fim->prox = novo;   //Se a fila não estiver vazia, o novo nó é adicionado no fim da fila // O ponteiro prox do último nó é atualizado para apontar para o novo nó
        fim = novo;    //e o ponteiro fim é atualizado para apontar para o novo nó.

    }

    void imprimir() { // O(n)   //Esta é uma função que imprime todos os valores na fila.

        No *aux = inicio;   //Cria um ponteiro auxiliar que aponta para o início da fila.

        while (aux != NULL) {   //Enquanto o ponteiro auxiliar não for NULL (ou seja, enquanto não chegarmos ao fim da fila)
            printf("%d -> ", aux->valor);   //imprime o valor do nó atual seguido por ‘->’.
            aux = aux->prox;    //Atualiza o ponteiro auxiliar para apontar para o próximo nó na fila.
        }

        printf("\n");

    }

    int tamanho() { // O(1) // Esta é uma função que retorna o número de elementos na fila
        return n;   //retorna o valor n, que é atualizado sempre que um elemento é inserido ou removido da fila
    }

    void remover() { // O(1)    //função que remove um elemento do início da fila

        if (tamanho() <= 1) {   //Se o tamanho da fila for 1 ou menos
            delete(inicio); // ela deleta o nó no início da fila
            inicio = NULL;  //atualiza os ponteiros, inicio para NULL
            fim = NULL;     // fim para NULL
            n = 0;  // e n para 0
            return;
        }
        // Se o tamanho da fila for maior que 1:
        No *r = inicio; //cria um novo ponteiro r e faz com que ele aponte para o mesmo nó que o ponteiro inicio está apontando. Isso significa que r agora está apontando para o primeiro nó na fila
        inicio = inicio->prox;  //atualiza o ponteiro inicio para apontar para o segundo nó na fila. O operador -> é usado para acessar o membro prox do nó para o qual inicio está apontando. Então, inicio->prox é o segundo nó na fila
        delete(r);  //deleta o nó para o qual r está apontando. Como r estava apontando para o primeiro nó na fila, isso efetivamente remove o primeiro nó da fila
        n--;    //decrementa o valor de n em 1. Como n está sendo usado para rastrear o número de elementos na fila, isso atualiza n para refletir o fato de que um elemento foi removido da fila
    }

};

int main() {

    int n; //declarando a variável n que irá receber o valor digitado pelo o usuário
    scanf("%d", &n); //leitura do valor n //armazenando o valor na variável n //indica o tamanho do baralho

    Fila f; //cria uma instância da estrutura de dados Fila chamada f

    for (int i = 1; i <= n; i++){ //laço de repetição que será incrementado até que i seja menor ou igual a n //baralho numerado de 1 até n
        f.inserir(i);   //inserção de valores na Fila, ou seja, inserindo valores no baralho
    }

    while(f.tamanho() > 1){ //enquanto, o tamanho da fila F for maior do que um
        printf("%d\n", f.inicio->valor); //imprime o valor do primeiro elemento na fila
        f.remover(); //remove o primeiro elemento da fila
        f.inserir(f.inicio->valor); //f.inicio->valor obtém o valor do novo primeiro elemento da fila (que costumava ser o segundo elemento antes da remoção) //A função f.inserir(f.inicio->valor); então insere esse valor no final da fila
        f.remover(); //remove o primeiro elemento da fila
    }

    printf("Restante: %d\n", f.inicio->valor); //imprime o valor da carta restante
    return 0;
}
