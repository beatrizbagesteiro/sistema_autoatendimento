#ifndef ADM_HPP
#define ADM_HPP
#include <string>
#include <vector>
using namespace std;

struct AdicionaisBurguer{
    string tipo;
    double preco;
};

struct Hamburguer {
    string nome;
    vector<AdicionaisBurguer> adicionais;
    double preco;
    string descricao;
};

struct Sobremesa {
    string nome = "";
    double preco = 0.0;
    string descricao = "";
};

struct Bebida {
    string nome = "";
    double preco = 0.0;
    string descricao = "";
    bool refil = false;
};

Hamburguer cadastrarBurguer(string nome, double preco, string descricao);
AdicionaisBurguer cadastrarAdicional();
Sobremesa cadastrarSobremesa(string nome, double preco, string descricao);
Bebida cadastrarBebida(string nome, double preco, string descricao);
#endif