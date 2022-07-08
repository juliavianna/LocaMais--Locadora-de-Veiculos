#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
        int opcao = 7;


    while (opcao != 0) {

        system("cls");
        printf("****LocaMAIS - Veiculos****");
        printf("\nDigite sua opcao : \n");
        printf("\n1 - Cadastrar Cliente");
        printf("\n2 - Cadastrar Veiculo");
        printf("\n3 - Locacao");
        printf("\n4 - Listar Clientes");
        printf("\n5 - Listar Veiculos");
        printf("\n6 - Listar Locacoes");
        printf("\n7 - Pesquisar Cliente/Veiculo");




        printf("\n0 - fim\n");
        scanf("%d",&opcao);
        if (opcao == 1) CadastrarCliente();
        if (opcao == 2) CadastrarVeiculo();
        if (opcao == 3) locacao();
        if (opcao == 4) listarClientes();
        if (opcao == 5) listarVeiculos();
        if (opcao == 6) listarLocacao();
        if (opcao == 7) pesquisarCliente();


        if (opcao == 6) {
//            if (t == 0) { t = 1; strcpy(s,"on");}
//            else { t = 0; strcpy(s,"off");}
        } else { printf("\n\n"); system("pause"); }
    }
    return 0;
}
int CadastrarCliente (int cliente)
{
    FILE *pArqCliente;
    pArqCliente = fopen("clienteAperfeicoado.txt","a");

    char nome[30], endereco[30], telefone[15], codigoCliente[15], cpf[15], resp[1];
    cpf==codigoCliente;
    srand(time(NULL));
    int resposta;
    printf("\n--CADASTRO DE CLIENTES--\n");

    repeat:
    printf("nao use espacos, para separar palavras use - ou _\n");
    printf("\Informe o CPF: ");
    scanf("%s", &codigoCliente);   //o cpf é o codigo da pessoa
    printf("\nNome: ");
    scanf("%s", &nome);
    printf("\nEndereco: ");
    scanf("%s", &endereco);
    printf("\nTelefone: ");
    scanf("%s", &telefone);

           fprintf(pArqCliente, " cliente %s %s %s %s\n", codigoCliente, nome, endereco, telefone);

    printf("\n\nCADASTRO DO CLIENTE REALIZADO COM SUCESSO!");

    printf("\nDigite 1 para cadastrar outro cliente \n");
    scanf("%d", &resposta);
    if(resposta==1){
        goto repeat;
    }
    else{
        printf("fim.");
    }
    fclose(pArqCliente);
}

int CadastrarVeiculo (int veiculo)
{
    FILE *pArqVeiculo;
    pArqVeiculo = fopen("veiculoAperfeicoado.txt","a");

    int ocupantes;
    float diaria;
    char modelo[20], cor[15], codigoVeiculo[15], placa[20];
    int resposta;

    placa==codigoVeiculo;
    srand(time(NULL));
    cad:
    printf("\n--CADASTRO DE VEICULOS--\n");
    printf("nao use espacos, para separar palavras use - ou _\n");
    printf("\nModelo: ");
    scanf("%s", &modelo);
    printf("\nPlaca: ");
    scanf("%s", &codigoVeiculo);    //a placa é o codigo do carro
    printf("\nQuantidade de Ocupantes: ");
    scanf("%d", &ocupantes);
    printf("\nCor: ");
    scanf("%s", &cor);
    printf("valor da diaria: ");
    scanf("%f", &diaria);

            fprintf(pArqVeiculo, " veiculo codigo:%s modelo:%s cor:%s ocupantes:%d diaria: RS%.2f\n", codigoVeiculo, modelo, cor, ocupantes, diaria );
            fputc('\n', pArqVeiculo);

    printf("\nCADASTRO REALIZADO\n");

    printf("\ndigite 1 para cadastrar outro veiculo \n");
    scanf("%d", &resposta);
    if(resposta==1){
        goto cad;
    }
    else
        printf("fim.");
    fclose(pArqVeiculo);
}
int listarClientes (int codigoCliente){
        FILE *pArqCliente;
        pArqCliente = fopen("clienteAperfeicoado.txt","r");
        char tudo[70];
        printf("**Clientes**\n");
        while(fgets(tudo,70,pArqCliente)!=NULL)
            printf("%s", tudo);

        fclose(pArqCliente);
}

int listarVeiculos (int codigoVeiculo){
        FILE *pArqVeiculo;
        pArqVeiculo = fopen("veiculoAperfeicoado.txt","r");
        char tudo[70];
        printf("**Veiculos**\n");
        while(fgets(tudo,70,pArqVeiculo)!=NULL)
            printf("%s", tudo);

        fclose(pArqVeiculo);
}

int locacao (int codigoVeiculo, int codigoCliente)
{
    FILE *pArqLocacao;
    pArqLocacao = fopen("locacaoAperfeicoado.txt","a");

    char codigoC[20], codigoV[20],dataRetirada[10],dataDevolucao[10];
    int diaria, total, dias;

    printf("**LOCACAO**\n");

    printf("digite o codigo do cliente: ");
    scanf("%s", &codigoC);
    printf("digite o codigo do veiculo: ");
    scanf("%s", &codigoV);
    printf("quantidade de dias: ");
    scanf("%d", &dias);
    printf("Data da retirada: ");
    scanf("%s", &dataRetirada);
    printf("Data da devolucao: ");
    scanf("%s", &dataDevolucao);
    printf("Valor da diaria do veiculo:");
    scanf("%d", &diaria);
    total= diaria*dias;
    printf("total: %d", total);
        fprintf(pArqLocacao, "Cliente:%s Veiculo:%s ¨Dias:%d Retirada:%s Devolucao:%s total:%d\n",codigoC, codigoV, dias, dataRetirada, dataDevolucao );
        fputc('\n', pArqLocacao);
    fclose(pArqLocacao);
}

int listarLocacao (int codigoVeiculo)
{
        FILE *pArqLocacao;
        pArqLocacao = fopen("locacaoAperfeicoado.txt","r");
        char tudo[70];
        printf("**Locacoes**\n");
        while(fgets(tudo,70,pArqLocacao)!=NULL)
            printf("%s", tudo);

        fclose(pArqLocacao);
}

int pesquisarCliente()
{//pesquisar por cliente, por veiculo, listar todos os clientes e listar todos os veiculos
    FILE *pArqCliente;
    pArqCliente = fopen("clienteAperfeicoado.txt","rt");//rt pq é so pra ler
    if(pArqCliente == NULL)
       printf("Erro, nao foi possivel abrir o arquivo\n");
    char codigo[11] = {};
    char nome[30] = {};
    char endereco[30] = {};
    char telefone[10] = {};;
    char codigopes[11] = {};

    cad:
    printf("digite o codigo do cliente: ");
    scanf(" %s", codigopes);
    while(fscanf(pArqCliente, "%s %s %s %s", codigo, nome, endereco, telefone) != EOF){
       if(atoi(codigo) == atoi(codigopes)){
          printf("\nLinha:  %s %s %s %s", codigo, nome, endereco, telefone);
          break;
        }
    }
    if(atoi(codigo) != atoi(codigopes)){
         printf("O codigo digitado nao corresponde a nenhum cliente.\n");
    }
    fclose(pArqCliente);
}

