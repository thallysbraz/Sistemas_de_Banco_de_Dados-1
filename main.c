#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#ifdef WIN32
    #define LIMPA_TELA system("cls")
#else
    #define LIMPA_TELA system("clear")
#endif

typedef struct carro CARRO;

struct carro {
    int idCarro;
    int ano, anoModelo;
    char marca[100];
    char modelo[100];
    char renach[100];
    char renavan[100];
    char chassi[100];
    char cor[50];
    char typeVeiculo[100];
    char placa[100];
};

typedef struct pessoa PESSOA;

struct pessoa {
    int Id;
    //char Idade;
    //char Nome[100];
    char Sobrenome[100];
    char Cpf[20];
    char Endereco[100];
    char dataNascimento[100];
    CARRO car;
};

void cabecalho();
void inputCarro();
void listar();

int main() {
    setlocale(LC_ALL, "Portuguese");
    //setlocale(LC_ALL, "");
    int option;

    do {
        cabecalho();

        printf("1 - Cadastrar\n");
        printf("2 - Listar todos os registros\n");
        printf("3 - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                inputCarro();
                break;
            case 2:
                listar();
                break;
            case 3:
                printf("Finalizando programa!");
                getch();
                break;
            default:
                printf("Opção inválida!");
                getch();
                break;
        }

    } while (option != 3);

    return 0;
}

void cabecalho() {
    system("cls");
    printf("===================\n");
    printf("Informações\n");
    printf("===================\n\n");
}

void inputCarro() {
    cabecalho();
    FILE *arquivo;
    FILE *arquivo2;

    PESSOA person;
    arquivo = fopen("banco.txt", "ab");

    if(arquivo == NULL) {
        printf("PROBLEMAS COM BANCO DE DADOS");
    }
    else {
        int count = 0;
        int veiculoId = 0;

        arquivo2 = fopen("banco.txt", "rb");

        if(arquivo2 == NULL) {
            printf("PROBLEMAS AO CARREGAR O BANCO DE DADOS");
        }
        
        while (fread(&person, sizeof(PESSOA), 1, arquivo2) == 1) { 
            count = person.Id;
            veiculoId = person.car.idCarro;
        }

        if(count == NULL || count == 0 || veiculoId == NULL || veiculoId == 0){
            count = 0;
            veiculoId = 0;
        }

        do {
            fflush(stdin);
            printf("digite o nome completo: ");
            gets(person.Sobrenome);

            fflush(stdin);
            printf("digite o cpf: ");
            gets(person.Cpf);

            fflush(stdin);
            printf("digite a data de nascimento, no formato dia/mês/ano: ");
            gets(person.dataNascimento);

            fflush(stdin);
            printf("digite o endereço: ");
            gets(person.Endereco);

            //atribuindo Id auto increment;
            person.Id = count + 1;
            printf("\nInforme os dados do veiculo\n");

            //atribuindo Id auto increment ao veiculo;
            person.car.idCarro = veiculoId + 1;

            fflush(stdin);
            printf("digite a placa: ");
            gets(person.car.placa);

            fflush(stdin);
            printf("digite o ano do veiculo: ");
            //gets(person.car.placa);
            scanf("%d", &person.car.ano);

            fflush(stdin);
            printf("digite a marca: ");
            gets(person.car.marca);

            fflush(stdin);
            printf("digite o modelo: ");
            gets(person.car.modelo);

            fflush(stdin);
            printf("digite o ano do modelo: ");
            scanf("%d", &person.car.anoModelo);

            fflush(stdin);
            printf("digite a renach: ");
            gets(person.car.renach);

            fflush(stdin);
            printf("digite a renavan: ");
            gets(person.car.renavan);

            fflush(stdin);
            printf("digite o código do chassi: ");
            gets(person.car.chassi);

            fflush(stdin);
            printf("digite a cor predonimante do veiculo: ");
            gets(person.car.cor);

            fwrite(&person, sizeof(PESSOA), 1, arquivo);

            printf("deseja continuar?(s/n)");

            } while (getche() == "s");
        
        fclose(arquivo);
    }
}

void listar(){
    FILE *arquivo;
    PESSOA person;
    arquivo = fopen("banco.txt", "rb");
    cabecalho();
    if(arquivo == NULL) {
        printf("PROBLEMAS AO CARREGAR O BANCO DE DADOS");
    }
    else {
        while (fread(&person, sizeof(PESSOA), 1, arquivo) == 1) {
            printf("Dados do proprietário\n\n");
            printf("Id: %d\n", person.Id);
            printf("Nome: %s\n", person.Sobrenome);
            printf("Cpf: %s\n", person.Cpf);
            printf("Data de nascimento: %s\n", person.dataNascimento);
            printf("Endereço: %s\n", person.Endereco);
            printf("\nDados do veiculo\n\n");
            printf("Id do Veiculo: %d\n", person.car.idCarro);
            printf("Placa: %s\n", person.car.placa);
            printf("Marca: %s\n", person.car.marca);
            printf("Ano do veiculo: %d\n", person.car.ano);
            printf("Modelo: %s\n", person.car.modelo);
            printf("Ano do modelo: %d\n", person.car.anoModelo);
            printf("Renach: %s\n", person.car.renach);
            printf("Renavan: %s\n", person.car.renavan);
            printf("Chassi: %s\n", person.car.chassi);
            printf("Cor: %s\n", person.car.cor);
            printf("\n----------------\n\n");
        }
    }
    fclose(arquivo);
    getch();
};