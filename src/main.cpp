//
//  main.cpp
//
//  Created by Márcio Sarroglia Pinho on 31/10/21.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "LinkedListOfString.h"

LinkedListOfString Cabecalhos;
LinkedListOfString ListaDeRuas;

// ***********************************************************
// Esta funcao recebe a 1a. linha do CSV e separa os nomes das
// colunas colocando-os na lista "Cabecalhos"
// O retorno eh o nro de campos da linha(nro de colunas do CSV)
// ***********************************************************
int LeCabecalhos(string L)
{
    // cout << "Linha:" << L << "*"<< endl;
    stringstream S;
    S.str(L);
    string palavra;
    int cont = 0;

    // passa em cada uma das palavras separadas do ';'
    while (getline(S, palavra, ';'))
    {
        Cabecalhos.add(palavra);
        cont++;
    }
    cout << "Nro de campos:" << cont << endl;
    return cont;
}
// ***********************************************************
// Esta funcao recebe uma linha do CSV e separa os dados das
// colunas colocando alguns deles na lista "Acidentes".
// O retorno eh o nro de campos da linha(nro de colunas do CSV)
// ***********************************************************
int DivideLinha(string L)
{
    stringstream S;
    S.str(L);
    string palavra;

    // Busca o indice da coluna que tem os campos de interesse
    // na lista de Cabecalhos
    int indLogradouro = Cabecalhos.indexOf("log1");
    // cout << "Indice da coluna Logradouro:"  << indLogradouro << endl;

    int indDia_sem = Cabecalhos.indexOf("dia_sem");
    int indtTipo_acid = Cabecalhos.indexOf("tipo_acid");

    int indMoto = Cabecalhos.indexOf("moto");
    int indAuto = Cabecalhos.indexOf("auto");
    int indTaxi = Cabecalhos.indexOf("taxi");
    int indOnibusUrb = Cabecalhos.indexOf("onibus_urb");
    int indOnibusMet = Cabecalhos.indexOf("onibus_met");
    int indOnibusInt = Cabecalhos.indexOf("onibus_int");
    int indCaminhao = Cabecalhos.indexOf("caminhao");
    int indCarroca = Cabecalhos.indexOf("carroca");
    int indBicicleta = Cabecalhos.indexOf("bicicleta");
    int indLotacao = Cabecalhos.indexOf("lotacao");
    int indOutroVeic = Cabecalhos.indexOf("outro");

    // Exercício B.1)
    // Obtenha os índices de cada coluna que sera necessario trabalho

    // Passa em cada uma das palavras separadas do ';'
    // A cada passo deste laco, a variavel 'palavra' tem uma das
    // palavras da linha
    // Qdo a coluna da palavra eh igual a uma das colunas de
    // interesse, coloca a palavra na frase de saida
    string NomeDaRua;
    string dia_sem;
    string tipo_acid;
    int moto = 0;
    int nVeiculos = 0;
    int cont = 0;

    while (getline(S, palavra, ';'))
    {
        // Exercício B.2)
        // Armazenar os dados que estão em uma linha do arquivo
        if (cont == indLogradouro)
            NomeDaRua = palavra;

        if (cont == indAuto)
            nVeiculos += atoi(palavra.c_str());

        if (cont == indDia_sem)
            dia_sem = palavra;

        if (cont == indtTipo_acid)
            tipo_acid = palavra;

        if (cont == indMoto)
        {
            moto += atoi(palavra.c_str());
            nVeiculos += atoi(palavra.c_str());
        }

        if (cont == indTaxi)
            nVeiculos += atoi(palavra.c_str());

        if (cont == indOnibusUrb)
            nVeiculos += atoi(palavra.c_str());

        if (cont == indOnibusMet)
            nVeiculos += atoi(palavra.c_str());

        if (cont == indOnibusInt)
            nVeiculos += atoi(palavra.c_str());

        if (cont == indCaminhao)
            nVeiculos += atoi(palavra.c_str());

        if (cont == indCarroca)
            nVeiculos += atoi(palavra.c_str());

        if (cont == indBicicleta)
            nVeiculos += atoi(palavra.c_str());

        if (cont == indLotacao)
            nVeiculos += atoi(palavra.c_str());

        if (cont == indOutroVeic)
            nVeiculos += atoi(palavra.c_str());

        cont++; // conta qtos campos já foram lidos na linha
    }
    // Exercício C.2
    // Substitua a chamada do método a seguir pelo novo método add,
    // que recebe todos dados obtidos em uma linha
    ListaDeRuas.add(NomeDaRua, dia_sem, nVeiculos, moto, tipo_acid); // Coloca a rua na lista de ruas

    // ListaDeRuas.addIncreasingOrder(NomeDaRua);

    // cout << "Nro de campos:" << cont << endl;
    return cont; // retorna o nro de palavras da linha
}

// ***********************************************************
// Abre o arquivo e processa cada uma das linhas
// ***********************************************************
void LeArquivo(const char *filename)
{
    ifstream arquivo;
    string linha;

    arquivo.open(filename, ios::in);
    if (!arquivo)
    {
        cout << "Erro na abertura do arquivo '" << filename << endl;
        exit(1);
    }
    // Le a linha de cabecalho
    getline(arquivo, linha);
    if (arquivo.eof())
    {
        cout << "Erro na leitura do cabecalho do arquivo" << filename << endl;
        exit(1);
    }

    int nroDeCampos = LeCabecalhos(linha);
    // cout << "Lista de Cabecalhos:" << endl;
    // Cabecalhos.ImprimeLista();

    do
    {
        // le uma linha do arquivo
        getline(arquivo, linha);
        if (arquivo.eof()) // acabou o arquivo?
            break;         // encerra o loop

        // divide a linha em campos e coloca os campos de interesse na lista de acidentes
        int n = DivideLinha(linha);

        // Caso o nro de campos da linha seja diferente do nro de
        // campos do cabecalho, a linha te erro.
        if (n != nroDeCampos)
        {
            cout << "Linha com nro invalido de campos" << endl;
            cout << "Nro de campos lidos: " << n << endl;
            cout << "Linha lida:" << linha << endl;
            exit(1);
        }

    } while (true);
    cout << "Leitura concluida" << endl;

    cout << "Lista de Ruas:" << endl;
    // ListaDeRuas.ImprimeLista();
}

int main(int argc, const char *argv[])
{
    LeArquivo("./data/PequenoComRepeticoes.csv");

    int op = 0;
    do
    {
        cout << "===========================================================================================================" << endl;
        cout << "DIGITE 1 PARA IMPRIMIR A LISTA" << endl;
        cout << "DIGITE 2 PARA LISTAR QUAIS OS 20 LOGRADOUROS COM MAIOR NUMERO DE ACIDENTES" << endl;
        cout << "DIGITE 3 PARA REMOVER UM TIPO DE ACIDENTE" << endl;
        cout << "DIGITE 4 PARA LISTAR OS 10 ACIDENTES COM MAIOR NUMERO DE VEICULOS" << endl;
        cout << "DIGITE 5 PARA LISTAR A QUANTIDADE DE ACIDENTES ENVOLVENDO MOTOCICLETAS" << endl;
        cout << "DIGITE 6 PARA IDENTIFICAR EM UM LOGRADOURO ESPECIFICO, O DIA DA SEMANA COM MAIOR NUMERO DE ACIDENTES" << endl;
        cout << "DIGITE 9 PARA ENCERRAR O PROGRAMA" << endl;
        cout << "===========================================================================================================" << endl;

        cin >> op;
        string logradouro;
        string tipo_acid;
        if (op == 1)
            ListaDeRuas.ImprimeLista();

        if (op == 2)
            cout << ListaDeRuas.Maiores20();

        if (op == 3)
        {
            cout << "DIGITE O TIPO DE ACIDENTE DESEJADO DESEJADO\n";
            cin.ignore();
            getline(cin, tipo_acid);
            ListaDeRuas.RemoveAcidentes(tipo_acid);
            cout << "ACIDENTES DO TIPO: " << tipo_acid << " REMOVIDOS"<<endl;
        }
        if (op == 4)
        {
            cout <<ListaDeRuas.maioresacidentes10()<<endl;
            
        }
        if (op == 5)
        {
            cout <<"EXISTEM " <<ListaDeRuas.num_acid_motos()<< " ACIDENTES ENVOLVENDO MOTOCICLETAS NA LISTA"<<endl;
        }
        if (op == 6)
        {
            cout << "DIGITE O LOGRADOURO DESEJADO" << endl;
            cin.ignore();
            getline(cin, logradouro);
            cout << ListaDeRuas.dia_mais_acidentes(logradouro)<<endl;
        }
        if (op < 0 && op > 6)
            cout << "OPCAO INVALIDA" << endl;
    }while (op < 9);

    cout<<"Obrigado por utilizar a consulta de acidentes!"<<endl;

    return 0;
}
