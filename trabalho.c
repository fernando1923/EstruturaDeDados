#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // Declaração de ponteiros de arquivo para entrada e saída
    FILE *entrada, *saida;

    // Abre o arquivo de entrada "DadosEntrada.csv" para leitura
    entrada = fopen("DadosEntrada.csv", "r");

    // Verifica se a abertura do arquivo de entrada foi bem-sucedida
    if (entrada == NULL) 
    {
        // Imprime uma mensagem de erro e encerra o programa com código de erro
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Abre o arquivo de saída "SituacaoFinal.csv" para escrita
    saida = fopen("SituacaoFinal.csv", "w");

    // Verifica se a abertura do arquivo de saída foi bem-sucedida
    if (saida == NULL) 
    {
        // Imprime uma mensagem de erro e fecha o arquivo de entrada antes de encerrar o programa
        printf("Erro ao criar o arquivo de saida.\n");
        fclose(entrada);
        return 1;
    }


    // Declaração de um buffer de linha para armazenar cada linha lida do arquivo de entrada
    char linha[1000];

    // Loop para ler cada linha do arquivo de entrada e processá-la
    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        char nome[100], curso[100];
        float nota1, nota2;

        // Tenta extrair dados da linha no formato esperado (nome, telefone, curso, nota1, nota2)
        if (sscanf(linha, "%[^,],%*[^,],%[^,],%f,%f", nome, curso, &nota1, &nota2) != 4) 
        {
            // Se a linha não estiver no formato esperado, pule para a próxima iteração do loop
            continue;
        }

        // Calcula a média das notas
        float media = (nota1 + nota2) / 2.0;

        // Determina a situação do aluno com base na média das notas
        const char *situacao = (media >= 7.0) ? "APROVADO" : "REPROVADO";

        // Escreve os resultados no arquivo de saída no formato: nome, média, situação
        fprintf(saida, "%s, %.2f, %s\n", nome, media, situacao);
    }

    // Fecha os arquivos de entrada e saída
    fclose(entrada);
    fclose(saida);

    // Exibe uma mensagem de conclusão do processamento
    printf("Processamento concluido. Resultados gravados em SituacaoFinal.csv\n");

    // Retorna 0 para indicar que o programa foi concluído com sucesso
    return 0;
}
