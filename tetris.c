#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_FILA 5
#define TAM_PILHA 3

// STRUCT DA PEÇA

typedef struct {
    char nome;
    int id;
} Peca;
// ESTRUTURAS GLOBAIS

Peca fila[TAM_FILA];
int frente = 0;
int tras = 0;
int quantidade = 0;

Peca pilha[TAM_PILHA];
int topo = -1;

// Para desfazer
Peca ultimaFila;
Peca ultimaPilha;
int ultimaAcao = 0;
// GERA PECAS AUTOMATICAMENTE

Peca gerarPeca() {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca p;
    p.nome = tipos[rand() % 4];
    p.id = rand() % 1000;
    return p;
}
// FILA - ENQUEUE

void inserirFila(Peca p) {
    if (quantidade == TAM_FILA) {
        printf("Fila cheia!\n");
        return;
    }

    fila[tras] = p;
    tras = (tras + 1) % TAM_FILA;
    quantidade++;
}
// FILA - DEQUEUE

Peca removerFila() {
    Peca vazia = {'-', -1};

    if (quantidade == 0) {
        printf("Fila vazia!\n");
        return vazia;
    }

    Peca p = fila[frente];
    frente = (frente + 1) % TAM_FILA;
    quantidade--;
    return p;
}
// PILHA - PUSH

void push(Peca p) {
    if (topo == TAM_PILHA - 1) {
        printf("Pilha cheia!\n");
        return;
    }

    pilha[++topo] = p;
}
// PILHA - POP

Peca pop() {
    Peca vazia = {'-', -1};

    if (topo == -1) {
        printf("Pilha vazia!\n");
        return vazia;
    }

    return pilha[topo--];
}
// MOSTRAR FILA

void mostrarFila() {
    printf("\nFILA: ");

    if (quantidade == 0) {
        printf("(vazia)\n");
        return;
    }

    int i = frente;
    for (int c = 0; c < quantidade; c++) {
        printf("[%c | %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % TAM_FILA;
    }
    printf("\n");
}
// MOSTRAR PILHA

void mostrarPilha() {
    printf("PILHA: ");

    if (topo == -1) {
        printf("(vazia)\n");
        return;
    }

    for (int i = topo; i >= 0; i--) {
        printf("[%c | %d] ", pilha[i].nome, pilha[i].id);
    }
    printf("\n");
}
// DESFAZER ÚLTIMA AÇÃO

void desfazer() {
    if (ultimaAcao == 1) { 
        // desfaz jogar peça
        // recoloca na frente
        frente = (frente - 1 + TAM_FILA) % TAM_FILA;
        fila[frente] = ultimaFila;
        quantidade++;
        printf("Desfeito: jogar peça.\n");
    }
    else if (ultimaAcao == 2) { 
        // desfaz reservar
        pop();
        frente = (frente - 1 + TAM_FILA) % TAM_FILA;
        fila[frente] = ultimaFila;
        quantidade++;
        printf("Desfeito: reservar peça.\n");
    }
    else if (ultimaAcao == 3) { 
        // desfaz usar peça reservada
        push(ultimaPilha);
        removerFila();
        inserirFila(ultimaFila);
        printf("Desfeito: usar peça reservada.\n");
    }
    else {
        printf("Nenhuma jogada para desfazer.\n");
    }
}

//-----------------------------------------
// INVERTER FILA COM PILHA
//-----------------------------------------
void inverter() {
    Peca tempFila[TAM_FILA];
    int tempQ = quantidade;

    int i = frente;
    for (int c = 0; c < quantidade; c++) {
        tempFila[c] = fila[i];
        i = (i + 1) % TAM_FILA;
    }

    frente = 0;
    tras = 0;
    quantidade = 0;

    while (topo != -1) {
        inserirFila(pop());
    }

    for (int c = tempQ - 1; c >= 0; c--) {
        push(tempFila[c]);
    }

    printf("Fila e pilha invertidas!\n");
}

//-----------------------------------------
// MAIN
//-----------------------------------------
int main() {
    int opcao;

    srand(time(NULL));

    for (int i = 0; i < TAM_FILA; i++) {
        inserirFila(gerarPeca());
    }

    while (1) {
        printf("\n==== MENU NIVEL MESTRE ====\n");
        printf("1 - Jogar peça\n");
        printf("2 - Reservar peça\n");
        printf("3 - Usar peça reservada\n");
        printf("4 - Trocar peça (topo pilha) <-> (frente fila)\n");
        printf("5 - Desfazer última jogada\n");
        printf("6 - Inverter fila com pilha\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        ultimaAcao = 0;

        switch (opcao) {
            case 1: {
                ultimaFila = removerFila();
                inserirFila(gerarPeca());
                ultimaAcao = 1;
                break;
            }
            case 2: {
                ultimaFila = removerFila();
                push(ultimaFila);
                inserirFila(gerarPeca());
                ultimaAcao = 2;
                break;
            }
            case 3: {
                ultimaPilha = pop();
                ultimaFila = removerFila();
                inserirFila(gerarPeca());
                ultimaAcao = 3;
                break;
            }
            case 4: {
                if (topo != -1 && quantidade > 0) {
                    Peca temp = pilha[topo];
                    pilha[topo] = fila[frente];
                    fila[frente] = temp;
                    printf("Trocada com sucesso!\n");
                }
                break;
            }
            case 5:
                desfazer();
                break;
            case 6:
                inverter();
                break;
            case 0:
                printf("Encerrando...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }

        mostrarFila();
        mostrarPilha();
    }

    return 0;
}
