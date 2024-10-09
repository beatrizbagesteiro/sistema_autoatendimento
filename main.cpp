#include <iostream>
#include <vector>
#include <string>
#include "adm.hpp"
#include "cliente.hpp"

vector<Hamburguer> opcoesBurguer;
vector<Bebida> opcoesBebida;
vector<Sobremesa> opcoesSobremesa;
int main(){

    /*
    
    vector<Hamburguer> opcoesBurguer = {
        {"Cheeseburger", {{"Queijo extra", 2.00}, {"Bacon", 3.00}}, 15.50, "Hambúrguer clássico com queijo e carne"},
        {"Chickenburger", {{"Maionese especial", 1.50}, {"Alface crocante", 1.00}}, 14.00, "Hambúrguer de frango grelhado"},
        {"Veggieburger", {{"Molho especial", 1.00}, {"Tomate fresco", 1.00}}, 13.00, "Hambúrguer vegetariano com grão-de-bico"}
    };

    
    vector<Bebida> opcoesBebida = {
        {"Coca-Cola", 5.00},
        {"Suco de Laranja", 6.00},
        {"Água", 3.00}
    };

    
    vector<Sobremesa> opcoesSobremesa = {
        {"Sorvete de Chocolate", 7.00},
        {"Torta de Limão", 8.50}
    };
    */
    

   bool finalizar = false;
    do
    {
        int opcaoModo;
        cout << "1 - Modo administracao" << endl;
        cout << "2 - Modo cliente" << endl;
        cin >> opcaoModo;
        system("cls");
        switch (opcaoModo)
        {
        case 1:
            {
            int opcao;
            cout << "1 - Cadastrar produtos" << endl;
            cout << "2 - Desligar totem" << endl;
            cin >> opcao;
            system("cls");
            if (opcao == 1)
            {
                cout << "Cadastrando hamburguer..." << endl;
                for (int i = 0; i < 1; i++)
                {
                    string nome, descricao;
                    double preco;
                    cout << "Informe o nome do hamburguer: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "Informe a descricao do hamburguer: ";
                    getline(cin, descricao);
                    cout << "Informe o preco do hamburguer: ";
                    cin >> preco;
                    cin.clear();
                    opcoesBurguer.push_back(cadastrarBurguer(nome, preco, descricao));
                }

                    
                for (int i = 0; i < 1; i++)
                {
                    string nome, descricao;
                    double preco;
                    cout << "Informe o nome da bebida: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "Informe a descricao da bebida: ";
                    getline(cin, descricao);
                    cout << "Informe o preco da bebida: ";
                    cin >> preco;
                    cin.clear();
                    opcoesBebida.push_back(cadastrarBebida(nome,preco,descricao));
                        
                }
                    
                
                for (int i = 0; i < 1; i++)
                {
                    string nome, descricao;
                    double preco;
                    cout << "Informe o nome da sobremesa: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "Informe a descricao da sobremesa: ";
                    getline(cin, descricao);
                    cout << "Informe o preco da sobremesa: ";
                    cin >> preco;
                    cin.clear();
                    opcoesSobremesa.push_back(cadastrarSobremesa(nome,preco,descricao));
                    opcaoModo = 2;

                }
            

            }else{
                cout << "Finalizando...." << endl;
                finalizar = true;
            }
        
            break;
            }
        case 2:
            {
            Hamburguer h = selecionarHamburguer(opcoesBurguer);
            h = selecionarAdicional(h, opcoesBurguer);
            system("cls");
            Bebida b = selecionarBebida(opcoesBebida);
            system("cls");
            Sobremesa s = selecionarSobremesa(opcoesSobremesa);
            system("cls");
            Pedido pedido = fazerPedido(h,b,s);
            revisarPedido(pedido, opcoesBurguer,opcoesBebida, opcoesSobremesa);
            system("cls");
            break;
            }
        default:
            cout << "Opcao invalida" << endl;
            break;
        }
    } while (!finalizar);
    
    return 0;
}