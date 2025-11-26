#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

// -------------------------------------------------------------
// Struct Item
// Armazena os dados de cada item da mochila.
// -------------------------------------------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// -------------------------------------------------------------
// Variáveis globais
// -------------------------------------------------------------
Item mochila[MAX_ITENS];
int numItens = 0;

// -------------------------------------------------------------
// Função: inserirItem
// Adiciona um item à mochila, se houver espaço disponível.
// -------------------------------------------------------------
void inserirItem() {
    if (numItens >= MAX_ITENS) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\n=== CADASTRAR ITEM ===\n");
    printf("Nome do item: ");
    scanf("%s", novo.nome);

    printf("Tipo do item (arma, municao, cura, ferramenta): ");
    scanf("%s", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[numItens] = novo;
    numItens++;

    printf("\nItem cadastrado com sucesso!\n");
}

// -------------------------------------------------------------
// Função: removerItem
// Remove um item da mochila pelo nome.
// -------------------------------------------------------------
void removerItem() {
    if (numItens == 0) {
        printf("\nA mochila está vazia! Nada para remover.\n");
        return;
    }

    char nome[30];
    printf("\n=== REMOVER ITEM ===\n");
    printf("Informe o nome do item que deseja remover: ");
    scanf("%s", nome);

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            // Desloca os itens para preencher a lacuna
            for (int j = i; j < numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            numItens--;
            printf("\nItem removido com sucesso!\n");
            return;
        }
    }

    printf("\nItem não encontrado!\n");
}

// -------------------------------------------------------------
// Função: listarItens
// Exibe uma tabela com todos os itens da mochila.
// -------------------------------------------------------------
void listarItens() {
    printf("\n=== ITENS NA MOCHILA ===\n");

    if (numItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < numItens; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Nome: %s\n", mochila[i].nome);
        printf("  Tipo: %s\n", mochila[i].tipo);
        printf("  Quantidade: %d\n", mochila[i].quantidade);
        printf("----------------------------\n");
    }
}

// -------------------------------------------------------------
// Função: buscarItem
// Realiza busca sequencial por nome e exibe os dados do item.
// -------------------------------------------------------------
void buscarItem() {
    char nome[30];
    printf("\n=== BUSCAR ITEM ===\n");
    printf("Informe o nome do item: ");
    scanf("%s", nome);

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("\nItem não encontrado.\n");
}

// -------------------------------------------------------------
// Função principal
// Menu do sistema de inventário
// -------------------------------------------------------------
int main() {
    int opcao;

    do {
        printf("\n===== MOCHILA DE LOOT – NIVEL INICIANTE =====\n");
        printf("1 - Adicionar um item\n");
        printf("2 - Remover um item\n");
       	printf("3 - Listar todos os itens\n");
        printf("4 - Buscar um item por nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
