/* Suponha que você queira armazenar seus gastos mensais com água, energia elétrica e telefone, referentes ao ano passado.
Faça um algoritmo que leia estes gastos e depois:
mostre os meses em que houve mais gasto com água, luz e telefone e a média de gasto com cada categoria. */

// mes com maior gasto

#include <stdio.h>
#include <string.h>

typedef struct
{
	float agua;
	float energiaEletrica;
	float planoTelefonico;
} Contas;

float somaGastos(float agua, float energiaEletrica, float planoTelefonico)
{
	float somaGastos = (agua + energiaEletrica + planoTelefonico);
	return somaGastos;
}

float calculaMedia(float x, int y)
{
	float mediaAnual = x / y;
	return mediaAnual;
}

int main(void)
{
	// Alocação dinâmica de memória na heap para os 12 meses
	Contas *conta = (Contas *)malloc(12 * sizeof(Contas));
	if (conta == NULL)
	{
		printf("Erro de alocacao de memoria.\n");
		return 1;
	}

	float armazenaGastos[12];
	float maiorGastoMensal = 0;
	int indiceMesMaiorGastoGeral;

	float maiorGastoAgua = 0;
	float totalGastoAgua = 0;
	int indiceMesMaiorGastoAgua;

	float maiorGastoLuz = 0;
	float totalGastoLuz = 0;
	int indiceMesMaiorGastoLuz;

	float maiorGastoTelefone = 0;
	float totalGastoTelefone = 0;
	int indiceMesMaiorGastoTelefone;

	// Abre o arquivo CSV para leitura
	FILE *arquivo = fopen("gastos.csv", "r");
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo 'gastos.csv'. Verifique se ele existe no mesmo diretorio.\n");
		free(conta);
		return 1;
	}

	char linha[100];

	// Lê a primeira linha (cabeçalho) e a descarta, já que não contém valores numéricos
	if (fgets(linha, sizeof(linha), arquivo) == NULL)
	{
		printf("Arquivo vazio ou erro de leitura.\n");
		fclose(arquivo);
		free(conta);
		return 1;
	}

	int i = 0;
	// Lê as próximas linhas do CSV
	while (fgets(linha, sizeof(linha), arquivo) != NULL && i < 12)
	{
		// Extrai os valores das colunas usando sscanf buscando as vírgulas
		sscanf(linha, "%f,%f,%f", &conta[i].agua, &conta[i].energiaEletrica, &conta[i].planoTelefonico);

		// Acha mes de maior gasto e armazena o mes
		armazenaGastos[i] = somaGastos(conta[i].agua, conta[i].energiaEletrica, conta[i].planoTelefonico);
		if (maiorGastoMensal < armazenaGastos[i])
		{
			maiorGastoMensal = armazenaGastos[i];
			indiceMesMaiorGastoGeral = i;
		}

		// Acha mes de maior gasto de Agua
		if (maiorGastoAgua < conta[i].agua)
		{
			maiorGastoAgua = conta[i].agua;
			indiceMesMaiorGastoAgua = i;
		}

		// Acha mes de maior gasto de Energia Eletrica
		if (maiorGastoLuz < conta[i].energiaEletrica)
		{
			maiorGastoLuz = conta[i].energiaEletrica;
			indiceMesMaiorGastoLuz = i;
		}

		// Acha mes de maior gasto de Plano Telefonico
		if (maiorGastoTelefone < conta[i].planoTelefonico)
		{
			maiorGastoTelefone = conta[i].planoTelefonico;
			indiceMesMaiorGastoTelefone = i;
		}

		// Soma os totais das categorias
		totalGastoAgua += conta[i].agua;
		totalGastoLuz += conta[i].energiaEletrica;
		totalGastoTelefone += conta[i].planoTelefonico;

		// Incrementa
		i++;
	}

	// Fecha o arquivo
	fclose(arquivo);

	printf("----------------------\n");
	printf("Media anual do gasto em Agua: %.2f\n", calculaMedia(totalGastoAgua, 12));
	printf("Media anual do gasto em Energia Eletrica: %.2f\n", calculaMedia(totalGastoLuz, 12));
	printf("Media anual do gasto em Plano Telefonico: %.2f\n", calculaMedia(totalGastoTelefone, 12));
	printf("----------------------\n");
	printf("Valor do mes com o maior gasto em Agua: %d com %.2f\n", indiceMesMaiorGastoAgua + 1, conta[indiceMesMaiorGastoAgua].agua);
	printf("Valor do mes com o maior gasto em Energia Eletrica: %d com %.2f\n", indiceMesMaiorGastoLuz + 1, conta[indiceMesMaiorGastoLuz].energiaEletrica);
	printf("Valor do mes com o maior gasto em Plano Telefonico: %d com %.2f\n", indiceMesMaiorGastoTelefone + 1, conta[indiceMesMaiorGastoTelefone].planoTelefonico);
	printf("----------------------\n");
	printf("Mes com o maior valor gasto total: %d com %.2f\n", indiceMesMaiorGastoGeral + 1, somaGastos(conta[indiceMesMaiorGastoGeral].agua, conta[indiceMesMaiorGastoGeral].energiaEletrica, conta[indiceMesMaiorGastoGeral].planoTelefonico));
	printf("----------------------\n");

	// Libera memoria alocada
	free(conta);
	return 0;
}