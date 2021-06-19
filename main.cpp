/******************************************************************************

                       Programa em C++ que gera vendas aleatórias

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;

struct rel_vendas
{
    char prod[50];
    char cli[50];
    int qtd;
    int qcli;
    float val_uni;
    float tot_vend;
};

struct rel_vendas venda[50];

void relat_vendas() // ler os dados da venda//

{
    char prods[10][50] = {"prod1", "prod2", "prod3", "prod4"};
    char clis[10][50] = {"cli1", "cli2", "cli3", "cli4", "cli5", "cli6", "cli7", "cli8", "cli9", "cli10"};
    int x, y;

    for (i = 1; i < 21; i++)

    {
        x = rand() % 10;
        y = rand() % 4;
        strcpy(venda[i].prod, prods[y]);
        venda[i].qtd = rand() % 20;
        venda[i].val_uni = y + 1;
        strcpy(venda[i].cli, clis[x]);
        venda[i].tot_vend = venda[i].qtd * venda[i].val_uni;
    }
    //mostrar dados
    for (i = 1; i < 21; i++)
    {

        printf("\n");
        printf("\n======== REGISTRO DE VENDA %d", i);
        printf(" ========");
        printf("\n");
        printf("Produto: %s\n", venda[i].prod);
        printf("Quantidade: %d\n", venda[i].qtd);
        printf("Valor unitario: R$ %.2f\n", venda[i].val_uni);
        printf("Cliente: %s\n", venda[i].cli);
        printf("Total da venda: R$ %.2f\n", venda[i].tot_vend);
        printf("=====================================");
        printf("\n");
    }
}
//mostrar dados
void lucro()

{
    char prodPesquisa[50];

    printf("\n======== REGISTRO DO lUCRO ========\n");
    printf("\n");
    printf("Total do lucro: R$ %.2f\n",
           venda[1].tot_vend + venda[2].tot_vend + venda[3].tot_vend + venda[4].tot_vend + venda[5].tot_vend + venda[6].tot_vend + venda[7].tot_vend + venda[8].tot_vend + venda[9].tot_vend + venda[10].tot_vend +
               venda[11].tot_vend + venda[12].tot_vend + venda[13].tot_vend + venda[14].tot_vend + venda[15].tot_vend + venda[16].tot_vend + venda[17].tot_vend + venda[18].tot_vend + venda[19].tot_vend + venda[20].tot_vend + venda[21].tot_vend);
    printf("\n===================================\n\n");
};

//mostrar seus dados
void pesquisa()

{
    char prodPesquisa[50];
    int i, cont;

    printf("=====================================");
    printf("\n");
    printf("\nDigite o produto que quer pesquisar: (de prod1 a prod4) ");
    scanf("%s", prodPesquisa);
    for (i = 0; i < 50; i++)
    {
        if (strcmp(venda[i].prod, prodPesquisa) == 0)
        {
            printf("\nCliente: %s  \n", venda[i].cli);
            printf("=====================================");
            printf("\n");
        }
    }
};

void Menu()

{
    printf("\n  MENU DE VENDA \n");
    printf("\n[1] Gerar 20 vendas\n");
    printf("[2] Lucro da Loja\n");
    printf("[3] Pesquisar clientes que compraram\n");
    printf("[4] Sair\n");
    printf("\nDigite o numero da opicao desejada \n");
}

int main()
{
    int opicao;
    void Menu();

    do
    {
        Menu();
        scanf("%d", &opicao);
        system("CLS");

        switch (opicao)
        {
        case 1:
            relat_vendas();
            break;
        case 2:
            lucro();
            break;
        case 3:
            pesquisa();
            break;
        case 4:
            printf("Obrigado!\n");
            break;

        defaut:
            printf("\nOpcao invalida!!");
        }
    } while (opicao != 4);
}
