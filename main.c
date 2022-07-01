#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
        int opcao = 7;


    while (opcao != 0) {

        system("cls");
        printf("****LocaMAIS****");
        printf("\nDigite sua opção : \n");
        printf("\n1 - Cadastrar Cliente");
        printf("\n2 - Cadastrar Veiculo");
        printf("\n3 - Locacao");
        printf("\n4 - Dar Baixa na Locacao");
        printf("\n5 - Pesquisar");
        printf("\n6 - Pesquisar Locacoes de um Cliente");
        printf("\n7 - Calcular quantos pontos um cliente possui");


        printf("\n0 - fim\n");
        scanf("%d",&opcao);
        if (opcao == 1) CadastrarCliente();
        if (opcao == 2) CadastrarVeiculo();
        if (opcao == 3) Locacao();
        if (opcao == 4) darBaixa();
        if (opcao == 5) pesquisar();
        if (opcao == 6) locacoesCliente();
        if (opcao == 7) calcularPontos();



        if (opcao == 9) {
//            if (t == 0) { t = 1; strcpy(s,"on");}
//            else { t = 0; strcpy(s,"off");}
        } else { printf("\n\n"); system("pause"); }
    }
    return 0;
}
int CadastrarCliente (int cliente)
{

    char nome, endereco, telefone, codigoCliente, cpf, resposta;
    cpf==codigoCliente;
    srand(time(NULL));
    cad:

    printf("\n--CADASTRO DE CLIENTES--\n");

    printf("\Informe o CPF");
    scanf("%d", &codigoCliente);   //o cpf é o codigo da pessoa
    printf("\nNome: ");
    scanf("%s", &nome);
    printf("\nEndereco: ");
    scanf("%s", &endereco);
    printf("\nTelefone: ");
    scanf("%s", &telefone);
    //função pra incluir registro na tabela
    printf("\n\nCADASTRO DO CLIENTE REALIZADO");

    printf("\ndigite 1 para cadastrar outro cliente \n");
    scanf("%d", &resposta);
    if(resposta==1){
        goto cad;
    }

}

int CadastrarVeiculo (int veiculo){

    int ocupantes;
    float diaria;
    char modelo, cor, codigoVeiculo, resposta;
    char placa;

    placa==codigoVeiculo;
    srand(time(NULL));
    cad:
    printf("\n--CADASTRO DE VEICULOS--\n");

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

    printf("\nCADASTRO REALIZADO\n");
    printf("%.2f", diaria);
    printf("\ndigite 1 para cadastrar outro veiculo \n");
    scanf("%d", &resposta);
    if(resposta==1){
        goto cad;
    }
}

int Locacao (int locacao){

    int codigoCliente, ocupantes, diasdeLocacao, valorTotal, resposta;
    char diaRetirada, diaDevolucao;
    printf("\n--CADASTRO DA LOCACAO--\n");

    cad:
    printf("digite o codigo do cliente: ");
    scanf("%d", &codigoCliente);
    /*fazer um if pra se o codigo do cliente nao existir
    printf("o cliente nao foi encontrado no sistema, digite novamente")
    goto cad;
    */
    printf("digite por quantos dias o carro sera alugado: ");
    scanf("%d", &diasdeLocacao);
    printf("Dia da retirada do veiculo: ");
    scanf("%s", &diaRetirada);
    printf("Dia da devolucao do veiculo: ");
    scanf("%s", &diaDevolucao);
    printf("Quantidade de ocupantes necesarios: ");
    scanf("%d", &ocupantes);

//    valorTotal= cadastroLocacao(valordaLocacao);

    printf("\nDigite 1 se deseja contratar um seguro para o carro\n");
    scanf("%d", &resposta);
    if(resposta==1)
        valorTotal=valorTotal+50;

    printf("CADASTRO REALIZADO\n valor total: RS%d", valorTotal);
}

void cadastroLocacao(float diaria)
{
    int diasdeLocacao, valordaLocacao;

    valordaLocacao = diasdeLocacao * diaria;
    return valordaLocacao;
}

int darBaixa(int valorTotal)//mostrar valor a ser pago(e se tiver multa calcular), mudar o status do veiculo(de alugado p disponivel)
{
    char diaDevolucao;
    int dataEntrega, diferenca, multa, valortotal;

    printf("--DAR BAIXA EM UM VEICULO--");

    printf("insira a data em que o veiculo foi entregue");
    if(dataEntrega=!diaDevolucao);
        diferenca= dataEntrega-diaDevolucao;
        multa= valorTotal*0,05;// multa sozinha
        multa= valorTotal+multa;//multa aplicada no valor antes da multa
        multa= multa+(diferenca*30);//multa mais a taxa de atrasos por dia

}

int pesquisar(int codigoCliente, int codigoVeiculo)
{

}
int locacoesCliente (int codigoCliente)
{
    int codigo;
    printf("--PESQUISAR LOCACOES DE UM CLIENTE--");
    cod:
    printf("\nCodigo do cliente: ");
    scanf("%d", &codigo);
    if(codigo!=codigoCliente){
        //tem q varrer o banco de dados e procurar se esse codigo digitado existe, se nao existir
        printf("Esse cliente nao existe, digite o codigo novamente");
        goto cod;
    }
}


int calcularPontos (int diasdeLocacao )
{
    int pontos, totalPontos;

    pontos= diasdeLocacao * 10;
    totalPontos= pontos+totalPontos;
    if (totalPontos>=500)
        printf("este cliente possui mais de 500 pontos e por isso esta elegivel para ganhar o kit LocaMais");
    else
        printf("o cliente possui %d pontos", totalPontos);
}

