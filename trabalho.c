#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração de ponteiros de arquivo para entrada e saída
    FILE *entrada, *saida;

    // Abre o arquivo de entrada "DadosEntrada.csv" para leitura
    entrada = fopen("DadosEntrada.csv", "r");

    // Verifica se a abertura do arquivo de entrada foi bem-sucedida
    if (entrada == NULL) {
        // Imprime uma mensagem de erro e encerra o programa com código de erro
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Abre o arquivo de saída "SituacaoFinal.csv" para escrita
    saida = fopen("SituacaoFinal.csv", "w");

    // Verifica se a abertura do arquivo de saída foi bem-sucedida
    if (saida == NULL) {
        // Imprime uma mensagem de erro e fecha o arquivo de entrada antes de encerrar o programa
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(entrada);
        return 1;
    }

    // Resto do código permanece inalterado
    char linha[1000];

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        char nome[100], curso[100];
        float nota1, nota2;

        if (sscanf(linha, "%[^,],%*[^,],%[^,],%f,%f", nome, curso, &nota1, &nota2) != 4) {
            printf("Erro ao ler os dados da linha.\n");
            continue;
        }

        float media = (nota1 + nota2) / 2.0;
        const char *situacao = (media >= 7.0) ? "APROVADO" : "REPROVADO";

        fprintf(saida, "%s, %.2f, %s\n", nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    printf("Processamento concluído. Resultados gravados em SituacaoFinal.csv\n");

    return 0;
}
