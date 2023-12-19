#include<stdio.h>
#include<string.h> //importanto a biblioteca de String

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

    char tmp[1000]; // declara uma vari�vel de array de caracteres chamada tmp com espa�o para 1000 caracteres. Esta vari�vel ser� usada para armazenar a string de entrada
    int valido = 1; // declara uma vari�vel inteira chamada valido e a inicializa com 1 (para quando a express�o for v�lida)
    scanf("%s", tmp); //l� uma string do usu�rio e a armazena na vari�vel tmp
    Pilha p;    //cria uma inst�ncia da estrutura de dados Pilha chamada p

    for (int i = 0; i < strlen(tmp); i++) {  //loop que percorre cada caractere na string de entrada //Dentro deste loop for, temos v�rias condi��es if e else if que verificam o caractere atual na string de entrada:
        if (tmp[i] == '{') {    //verifica se o caractere atual � uma chave {
            if (!p.vazia()) {   //verifica se a pilha est� vazia
                valido = 0; //se n�o for, a vari�vel valido � definida como 0
                break; //e o loop e interrompido
            }
            p.inserir('{'); //se for o caractere certo e inserido na pilha
        } else if (tmp[i] == '[') { //verifica se o caractere atual � um colchetes [
            if (!p.vazia() && p.inicio->valor != '{') { //verifica se a pilha p n�o est� vazia. A fun��o vazia() retorna true se a pilha estiver vazia e false se n�o estiver. O operador ! inverte esse valor, ent�o !p.vazia() � true se a pilha n�o estiver vazia e false se estiver
                //p.inicio->valor != '{': Esta parte da condi��o verifica se o valor do primeiro elemento na pilha n�o � igual a {. p.inicio->valor obt�m o valor do primeiro elemento na pilha e != '{' verifica se esse valor n�o � igual a {
                valido = 0; //se a pilha n�o estiver vazia e o valor do primeiro elemento na pilha n�o for {), ent�o a vari�vel valido � definida como 0, ou seja, express�o inv�lida
                break; //interrompe o loop atual. Ent�o, se a condi��o if for verdadeira, o loop ser� interrompido e o programa continuar� na primeira linha de c�digo ap�s o loop
            }
            p.inserir('['); //se ambas condi��es forem falsas, o caractere '[' � inserido na pilha
        } else if (tmp[i] == '(') { //� uma condi��o else if que verifica se o caractere atual na string de entrada � '('. Se for, o c�digo dentro das chaves { ... } � executado
            if (!p.vazia() && p.inicio->valor != '{' && p.inicio->valor != '[') { //verifica se a pilha p n�o est� vazia //Verifica se o valor do primeiro elemento na pilha n�o � '{' //Verifica se o valor do primeiro elemento na pilha n�o � '['
                //Se todas essas condi��es forem verdadeiras, o c�digo dentro das chaves { ... } � executado
                valido = 0; //define a vari�vel valido como 0. Isso indica que a string de entrada n�o � v�lida (ou seja, os par�nteses n�o est�o corretamente aninhados e fechados)
                break; // interrompe o loop atual. Ent�o, se a condi��o if for verdadeira, o loop ser� interrompido e o programa continuar� na primeira linha de c�digo ap�s o loop
            }
            p.inserir('('); //insere o caractere '(' na pilha p. Isso s� acontece se a condi��o if for falsa (ou seja, se a pilha estiver vazia ou se o valor do primeiro elemento na pilha for '{' ou '[').
        } else if (tmp[i] == '}') { //verifica se o caractere atual na string de entrada � '}'. Se for, o c�digo dentro das chaves { ... } � executado
            if (p.vazia() || p.inicio->valor != '{') { //Verifica se a pilha p est� vazia. Verifica se o valor do primeiro elemento na pilha n�o � '{'. Se qualquer uma dessas condi��es for verdadeira, o c�digo dentro das chaves { ... } � executado
                valido = 0;
                break; //interrompe o loop atual. Ent�o, se a condi��o if for verdadeira, o loop ser� interrompido e o programa continuar� na primeira linha de c�digo ap�s o loop
            }
            p.remover(); //remove o primeiro elemento da pilha p. Isso s� acontece se a condi��o if for falsa (ou seja, se a pilha n�o estiver vazia e o valor do primeiro elemento na pilha for '{').
        } else if (tmp[i] == ']') { //verifica se o caractere atual na string de entrada � ']'
            if (p.vazia() || p.inicio->valor != '[') {
                valido = 0;
                break;
            }
            p.remover(); //remove o primeiro elemento da pilha p. Isso s� acontece se a condi��o if for falsa (ou seja, se a pilha n�o estiver vazia e o valor do primeiro elemento na pilha for '[')
        } else if (tmp[i] == ')') { //verifica se o caractere atual � ')'
            if (p.vazia() || p.inicio->valor != '(') {
                valido = 0;
                break;
            }
            p.remover(); //remove o primeiro elemento da pilha p. Isso s� acontece se a condi��o if for falsa (ou seja, se a pilha n�o estiver vazia e o valor do primeiro elemento na pilha for '(')
        }
    }

    if (!p.vazia()) { //verifica se a pilha p n�o est� vazia. O operador ! inverte esse valor, ent�o !p.vazia() � true se a pilha n�o estiver vazia e false se estiver
        valido = 0; //Se a condi��o if for verdadeira (ou seja, se a pilha n�o estiver vazia), ent�o a vari�vel valido � definida como 0
        //Isso indica que a string de entrada n�o � v�lida (ou seja, os par�nteses n�o est�o corretamente aninhados e fechados).
    }

    printf("%d\n", valido); //imprime o valor da vari�vel valido. Se valido for 1, isso significa que a string de entrada � v�lida (ou seja, todos os par�nteses est�o corretamente aninhados e fechados)
                            //Se valido for 0, isso significa que a string de entrada n�o � v�lida.

    return 0;
}

