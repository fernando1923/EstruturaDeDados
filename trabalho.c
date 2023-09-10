#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração de ponteiros de arquivo para entrada e saída
    FILE *entrada, *saida;
    
    // Abre o arquivo de entrada "DadosEntrada.csv" para leitura
    entrada = fopen("DadosEntrada.csv", "r");
    // Abre o arquivo de saída "SituacaoFinal.csv" para escrita
    saida = fopen("SituacaoFinal.csv", "w");

    // Verifica se a abertura dos arquivos foi bem-sucedida
    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    // Declara uma matriz de caracteres para armazenar uma linha do arquivo de entrada
    char linha[1000];

    // Loop para ler cada linha do arquivo de entrada
    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        // Declara variáveis para armazenar os dados lidos da linha
        char nome[100], curso[100];
        float nota1, nota2;

        // Usa sscanf para extrair os valores da linha
        if (sscanf(linha, "%[^,],%*[^,],%[^,],%f,%f", nome, curso, &nota1, &nota2) != 4) {
            // Imprime uma mensagem de erro se a leitura falhar
            printf("Erro ao ler os dados da linha.\n");
            continue; // Continua para a próxima linha
        }

        // Calcula a média das notas
        float media = (nota1 + nota2) / 2.0;

        // Determina a situação com base na média
        const char *situacao = (media >= 7.0) ? "APROVADO" : "REPROVADO";

        // Escreve os resultados no arquivo de saída
        fprintf(saida, "%s, %.2f, %s\n", nome, media, situacao);
    }

    // Fecha os arquivos de entrada e saída
    fclose(entrada);
    fclose(saida);

    // Imprime uma mensagem de conclusão
    printf("Processamento concluído. Resultados gravados em SituacaoFinal.csv\n");

    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}
