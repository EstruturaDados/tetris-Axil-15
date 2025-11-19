#include <stdio.h>

int main() {

    char nome[50];
    int valor1, valor2, soma;

    printf("Bem-vindo(a) ao Desafio Codigo da Ilha\n");

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
    printf("Nome do personagem: %s", nome);
    printf("Primeiro valor: %d\n", valor1);
    printf("Segundo valor: %d\n", valor2);
    printf("Soma dos valores: %d\n", soma);
    printf("----------------------------------\n\n");


    float altura;
    int idade;

    // 1) Usuário deve informar idade e altura
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura (em metros, exemplo 1.75): ");
    scanf("%f", &altura);

    // 2) Estrutura condicional: verificar se pode entrar na caverna

    if (idade >= 18 && altura >= 1.60) {
        printf("Voce esta apto para entrar na caverna misteriosa!\n");
    } else {
        printf("Voce NAO esta apto para entrar na caverna misteriosa.\n");
        printf("Requisitos: idade >= 18 e altura >= 1.60\n");
    }

    printf("--------------------------------------\n");

    return 0;
}
