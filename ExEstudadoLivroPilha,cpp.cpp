#include <stdio.h>
#include <stdlib.h>

// Definindo o registro que representará cada elemento da pilha
struct PILHA {
    int num;
    PILHA *prox;

};

int main() {
    // A pilha está vazia, logo, o ponteiro topo tem o valor null
    // As operações de inserção e remoção acontecem no TOPO
    PILHA *topo = NULL;
    // O ponteiro aux é um ponteiro auxiliar
    PILHA *aux;

    // Apresentando o menu de opções
    int op;

    do {
        system("cls"); // Limpa a tela no Windows, use "clear" no Linux
        printf("\nMENU DE OPCOES\n");
        printf("1 - Inserir na pilha\n");
        printf("2 - Consultar toda a pilha\n");
        printf("3 - Remover da pilha\n");
        printf("4 - Esvaziar a pilha\n");
        printf("5 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);

        if (op < 1 || op > 5)
            printf("Opcao invalida!!\n");

        if (op == 1) { //0(1)
            printf("Digite o numero a ser inserido na pilha: ");
            PILHA *novo = (PILHA *)malloc(sizeof(PILHA));
            scanf("%d", &novo->num);
            novo->prox = topo;
            topo = novo;
            printf("Numero inserido na pilha!\n");
        }

        if (op == 2) { // 0(n)
            if (topo == NULL) {
                printf("Pilha vazia!!\n");
            } else {
                // A pilha contém elementos e estes serão mostrados
                // do último inserido ao primeiro
                printf("\nConsultando toda a pilha\n");
                aux = topo;
                while (aux != NULL) {
                    printf("%d ", aux->num);
                    aux = aux->prox;
                }
                printf("\n");
            }
        }

        if (op == 3) { //0 (1)
            if (topo == NULL) {
                printf("Pilha vazia!!\n");
            } else {
                // A pilha contém elementos e o último elemento inserido será removido
                aux = topo;
                printf("Numero %d removido\n", topo->num);
                topo = topo->prox;
                free(aux);
            }
        }

        if (op == 4) { // 0(n)
            if (topo == NULL) {
                printf("Pilha vazia!!\n");
            } else {
                // A pilha será esvaziada
                aux = topo;
                while (aux != NULL) {
                    topo = topo->prox;
                    free(aux);
                    aux = topo;
                }
                printf("Pilha esvaziada\n");
            }
        }

        if (op != 5) {
            system("pause"); // Pausa a execução para aguardar uma tecla ser pressionada
        }
    } while (op != 5);

    return 0;
}

