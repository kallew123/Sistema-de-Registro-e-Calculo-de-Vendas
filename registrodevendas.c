#include <stdio.h>

void registrar_vendas(int vendas, char nome_produto[][50], int quant_vendida[], float preco_unit[]);
void resultado(int vendas, char nome_produto[][50], int quant_vendida[], float preco_unit[], float total_vendas_produto[], float total_vendas);
void linha();

int main(void){

    int vendas;
    do
    {
        printf("Quantas vendas serao registradas (max 100): ");
        scanf("%d", &vendas);
    } while (vendas < 1 || vendas > 100);

    linha();

    char nome_produto[100][50];
    int quant_vendida[100];
    float preco_unit[100];
    float total_vendas_produto[100];
    float total_vendas ;
    registrar_vendas(vendas, nome_produto, quant_vendida, preco_unit);
    resultado(vendas, nome_produto, quant_vendida, preco_unit, total_vendas_produto, total_vendas);
    getchar();
    printf("Pressione Enter para sair...");
    getchar();
    return 0;

}

void registrar_vendas(int vendas, char nome_produto[][50], int quant_vendida[], float preco_unit[]){
    
    for (int i = 0; i < vendas; i++)
    {
        do
        {
        printf("Nome do produto: ");
        scanf("%s", nome_produto[i]);
        printf("Quantidade vendida: ");
        scanf("%d", &quant_vendida[i]);
        printf("Preco unitario: ");
        scanf("%f", &preco_unit[i]);
        getchar();
        linha();
        } while (quant_vendida[i] < 0 || preco_unit[i] < 0);
    }
}

void resultado(int vendas, char nome_produto[][50], int quant_vendida[], float preco_unit[], float total_vendas_produto[], float total_vendas){
    printf("=========================================\n");
    printf("%-8s |%-6s |%-6s |%-10s\n", "Produto", "Quantidade", "Preco", "Total");
    linha();
    total_vendas = 0;
    for (int i = 0; i < vendas; i++)
    {
        total_vendas_produto[i] = quant_vendida[i] * preco_unit[i];
        printf("%-6s |%-6d |%-6.2f |%.2f\n", nome_produto[i], quant_vendida[i], preco_unit[i], total_vendas_produto[i]);
        total_vendas = total_vendas + total_vendas_produto[i];
    }
    printf("=========================================\n");
    printf("Vendas totais: %.2f\n", total_vendas);
    
}

void linha(){
    printf("\n");
}
