#include<stdio.h>
#include<string.h> //importanto a biblioteca de String

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

    char tmp[1000]; // declara uma variável de array de caracteres chamada tmp com espaço para 1000 caracteres. Esta variável será usada para armazenar a string de entrada
    int valido = 1; // declara uma variável inteira chamada valido e a inicializa com 1 (para quando a expressão for válida)
    scanf("%s", tmp); //lê uma string do usuário e a armazena na variável tmp
    Pilha p;    //cria uma instância da estrutura de dados Pilha chamada p

    for (int i = 0; i < strlen(tmp); i++) {  //loop que percorre cada caractere na string de entrada //Dentro deste loop for, temos várias condições if e else if que verificam o caractere atual na string de entrada:
        if (tmp[i] == '{') {    //verifica se o caractere atual é uma chave {
            if (!p.vazia()) {   //verifica se a pilha está vazia
                valido = 0; //se não for, a variável valido é definida como 0
                break; //e o loop e interrompido
            }
            p.inserir('{'); //se for o caractere certo e inserido na pilha
        } else if (tmp[i] == '[') { //verifica se o caractere atual é um colchetes [
            if (!p.vazia() && p.inicio->valor != '{') { //verifica se a pilha p não está vazia. A função vazia() retorna true se a pilha estiver vazia e false se não estiver. O operador ! inverte esse valor, então !p.vazia() é true se a pilha não estiver vazia e false se estiver
                //p.inicio->valor != '{': Esta parte da condição verifica se o valor do primeiro elemento na pilha não é igual a {. p.inicio->valor obtém o valor do primeiro elemento na pilha e != '{' verifica se esse valor não é igual a {
                valido = 0; //se a pilha não estiver vazia e o valor do primeiro elemento na pilha não for {), então a variável valido é definida como 0, ou seja, expressão inválida
                break; //interrompe o loop atual. Então, se a condição if for verdadeira, o loop será interrompido e o programa continuará na primeira linha de código após o loop
            }
            p.inserir('['); //se ambas condições forem falsas, o caractere '[' é inserido na pilha
        } else if (tmp[i] == '(') { //é uma condição else if que verifica se o caractere atual na string de entrada é '('. Se for, o código dentro das chaves { ... } é executado
            if (!p.vazia() && p.inicio->valor != '{' && p.inicio->valor != '[') { //verifica se a pilha p não está vazia //Verifica se o valor do primeiro elemento na pilha não é '{' //Verifica se o valor do primeiro elemento na pilha não é '['
                //Se todas essas condições forem verdadeiras, o código dentro das chaves { ... } é executado
                valido = 0; //define a variável valido como 0. Isso indica que a string de entrada não é válida (ou seja, os parênteses não estão corretamente aninhados e fechados)
                break; // interrompe o loop atual. Então, se a condição if for verdadeira, o loop será interrompido e o programa continuará na primeira linha de código após o loop
            }
            p.inserir('('); //insere o caractere '(' na pilha p. Isso só acontece se a condição if for falsa (ou seja, se a pilha estiver vazia ou se o valor do primeiro elemento na pilha for '{' ou '[').
        } else if (tmp[i] == '}') { //verifica se o caractere atual na string de entrada é '}'. Se for, o código dentro das chaves { ... } é executado
            if (p.vazia() || p.inicio->valor != '{') { //Verifica se a pilha p está vazia. Verifica se o valor do primeiro elemento na pilha não é '{'. Se qualquer uma dessas condições for verdadeira, o código dentro das chaves { ... } é executado
                valido = 0;
                break; //interrompe o loop atual. Então, se a condição if for verdadeira, o loop será interrompido e o programa continuará na primeira linha de código após o loop
            }
            p.remover(); //remove o primeiro elemento da pilha p. Isso só acontece se a condição if for falsa (ou seja, se a pilha não estiver vazia e o valor do primeiro elemento na pilha for '{').
        } else if (tmp[i] == ']') { //verifica se o caractere atual na string de entrada é ']'
            if (p.vazia() || p.inicio->valor != '[') {
                valido = 0;
                break;
            }
            p.remover(); //remove o primeiro elemento da pilha p. Isso só acontece se a condição if for falsa (ou seja, se a pilha não estiver vazia e o valor do primeiro elemento na pilha for '[')
        } else if (tmp[i] == ')') { //verifica se o caractere atual é ')'
            if (p.vazia() || p.inicio->valor != '(') {
                valido = 0;
                break;
            }
            p.remover(); //remove o primeiro elemento da pilha p. Isso só acontece se a condição if for falsa (ou seja, se a pilha não estiver vazia e o valor do primeiro elemento na pilha for '(')
        }
    }

    if (!p.vazia()) { //verifica se a pilha p não está vazia. O operador ! inverte esse valor, então !p.vazia() é true se a pilha não estiver vazia e false se estiver
        valido = 0; //Se a condição if for verdadeira (ou seja, se a pilha não estiver vazia), então a variável valido é definida como 0
        //Isso indica que a string de entrada não é válida (ou seja, os parênteses não estão corretamente aninhados e fechados).
    }

    printf("%d\n", valido); //imprime o valor da variável valido. Se valido for 1, isso significa que a string de entrada é válida (ou seja, todos os parênteses estão corretamente aninhados e fechados)
                            //Se valido for 0, isso significa que a string de entrada não é válida.

    return 0;
}

