#include <stdio.h>

int main() {

    char nome[50];
    int valor1, valor2, soma;

    printf("Bem-vindo ao Desafio Codigo da Ilha\n");

    // 1) Declarar nome do personagem
    printf("Digite o nome do seu personagem: ");
    fgets(nome, sizeof(nome), stdin);

    // 2) Somar dois valores inteiros
    printf("\nAgora digite dois valores inteiros para somar:\n");
    printf("Digite o primeiro valor: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%d", &valor2);

    soma = valor1 + valor2;

    // 3) Exibir os dados
    printf("\n--- RESULTADO DO NIVEL NOVATO ---\n");
    printf("Nome do personagem: %s", nome);
    printf("Primeiro valor: %d\n", valor1);
    printf("Segundo valor: %d\n", valor2);
    printf("Soma dos valores: %d\n", soma);
    printf("----------------------------------\n");

    return 0;
}
