#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

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
    PESSOA person;
    arquivo = fopen("banco.txt", "ab");
    int count = 1;
    int veiculoId = 1;
    
    if(arquivo == NULL) {
        printf("PROBLEMAS COM BANCO DE DADOS");
    }

    else {
        do {
            /*fflush(stdin);
            printf("digite o nome: ");
            gets(person.Nome);*/
            //scanf("%[^\n]", person.Nome);
            
            //printf("Nome porra: %s", person.Nome);
            
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
            person.Id = count;
            printf("\nInforme os dados do veiculo\n");

            //atribuindo Id auto increment ao veiculo;
            person.car.idCarro = veiculoId;

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

            count++;
            veiculoId++;

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
            printf("Nome: %s\n", person.Sobrenome);
            printf("Cpf: %s\n", person.Cpf);
            printf("Data de nascimento: %s\n", person.dataNascimento);
            printf("Endereço: %s\n", person.Endereco);
            printf("\nDados do veiculo\n\n");
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
/* 

struc data {
    int dia, mes, ano
}
struct contato {
    char nome[30], 
    fone[15];
    DATA aniv;
}

{
    int idCarro;
    int ano, modelo;
    char marca[100];
    char renach[100];
    char placa[100];
}

{
    int Id;
    char Idade;
    char Nome[100];
    char Sobrenome[100];
    char Cpf[20];
    char Endereco[100];
    CARRO car;
}
*/