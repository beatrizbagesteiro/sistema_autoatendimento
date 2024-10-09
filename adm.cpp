#include "adm.hpp"
#include <string>
#include <iostream>
using namespace std;

Hamburguer cadastrarBurguer(string nome, double preco, string descricao)
{

    Hamburguer burguer;
    burguer.nome = nome;
    burguer.preco = preco;
    burguer.descricao = descricao;

    vector<AdicionaisBurguer> adicionais;
    cout << "Cadastrando adicionais..." << endl;
    for (int i = 0; i < 2; i++)
    {
        adicionais.push_back(cadastrarAdicional());
    }
    
    burguer.adicionais = adicionais;

    return burguer;
}

AdicionaisBurguer cadastrarAdicional()
{
    AdicionaisBurguer adicional;
    string tipo;
    double preco;
    cout << "Informe o tipo do adicional: ";
    cin.ignore();
    getline(cin,tipo);
    adicional.tipo = tipo;
    cout << "Informe o preco do adicional: ";
    cin >> preco;
    adicional.preco = preco;

    return adicional;
}

Sobremesa cadastrarSobremesa(string nome, double preco, string descricao)
{
    Sobremesa s;
    s.nome = nome;
    s.preco = preco;
    s.descricao = descricao;
    return s;
}

Bebida cadastrarBebida(string nome, double preco, string descricao)
{
    Bebida b;
    b.nome = nome;
    b.preco = preco;
    b.descricao = descricao;
    return b;
}
