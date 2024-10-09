#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include "adm.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>
using namespace std;

struct Pedido{
    Hamburguer burguer;
    Bebida bebida;
    bool refil = false;
    Sobremesa sobremesa;
};



Hamburguer selecionarHamburguer(const vector<Hamburguer> &opcoes);
Hamburguer selecionarAdicional(Hamburguer &burguer,const vector<Hamburguer> &opcoes);
Bebida selecionarBebida(const vector<Bebida> &opcoes);
Sobremesa selecionarSobremesa(const vector<Sobremesa> &opcoes);
Pedido fazerPedido(const Hamburguer &burguer, const Bebida &bebida, const Sobremesa &sobremesa);
bool isBebidaEmpty(Bebida &bebida);
bool isSobremesaEmpty(Sobremesa &sobremesa);
bool revisarPedido(Pedido &pedido, const vector<Hamburguer> &burguer, const vector<Bebida> &bebidas, const vector<Sobremesa> &sobremesas);
void atualizarPedido(Pedido &pedido, const vector<Hamburguer> &burguer, const vector<Bebida> &bebidas, const vector<Sobremesa> &sobremesas);
void realizarPagamento();
#endif