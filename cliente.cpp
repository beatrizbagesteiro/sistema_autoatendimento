#include "cliente.hpp"
#include <iostream>
#include <sstream>
using namespace std;

Hamburguer selecionarHamburguer(const vector<Hamburguer> &opcoes)
{
    for (int i = 0; i < opcoes.size(); i++)
    {
        cout << "Opcao " << i+1 <<": " << endl;
        cout << "Nome: " << opcoes[i].nome << endl;
        cout << fixed << setprecision(2);
        cout << "Preco: R$ " << opcoes[i].preco << endl;  
        cout << "Descricao: " << opcoes[i].descricao << endl;
        cout << "-------------" << endl;
    }
    int burguer;
    
    cout << "Primeiro digite a opcao de hamburguer: ";
    cin >> burguer;

    Hamburguer pedido;
    for (int i = 0; i < opcoes.size(); i++)
    {
        if (i == burguer-1)
        {
            pedido.nome = opcoes[i].nome;
            pedido.preco = opcoes[i].preco;
            pedido.descricao = opcoes[i].descricao;
            
        }
        
    }

    return pedido;
}

Hamburguer selecionarAdicional(Hamburguer &burguer,const vector<Hamburguer> &opcoes)
{
    for (int i = 0; i < opcoes.size(); i++)
    {
        if (opcoes[i].nome == burguer.nome)
        {
            cout << "Adicionais" << endl;
            for (int j = 0; j < opcoes[i].adicionais.size(); j++)
            {
                cout << "Opcao " << j+1 <<": " << endl;
                cout << "Tipo: " << opcoes[i].adicionais[j].tipo << endl;
                cout << fixed << setprecision(2);  
                cout << "Preco: R$ " << opcoes[i].adicionais[j].preco << endl;  
            }
        }
        
    }
    
    
    string adicional;
    cout << "Agora digite a opcao de adicional. Caso escolha mais de um, separar opcoes com espaco: (Digite 0 se nao quiser adicional) ";
    cin.ignore();
    getline(cin, adicional);
    

    vector<int> a;
    if (adicional != "0")
    {
        istringstream iss(adicional);
        string temp;
        while(getline(iss, temp, ' ')){
            a.push_back(stoi(temp));
        }
    }

    if(!a.empty()){
        for (int i = 0; i < opcoes.size(); i++)
        {
            if (opcoes[i].nome == burguer.nome)
            {
                for(int adicional: a){
                burguer.adicionais.push_back(opcoes[i].adicionais[adicional-1]);
                }
            }
            
        }
        
        
    }
    return burguer;
}

Bebida selecionarBebida(const vector<Bebida> &opcoes)
{
    cout << "Selecione a bebida: " << endl;
    for (int i = 0; i < opcoes.size(); i++)
    {
        cout << "Opcao " << i+1 <<": " << endl;
        cout << "Nome: " << opcoes[i].nome << endl;
        cout << "Preco: " << opcoes[i].preco << endl;
        cout << "Descricao: " << opcoes[i].descricao << endl;
       
       cout << "-------------" << endl;
    }

    int b;
    cout << "Digite a opcao da bebida: (Digite 0 se não quiser bebida) ";
    cin >> b;

    Bebida bebida;

    if (b != 0)
    {
         for (int i = 0; i < opcoes.size(); i++)
        {
            if (i == b-1)
            {
                bebida.nome = opcoes[i].nome;
                bebida.preco = opcoes[i].preco;
                bebida.descricao = opcoes[i].descricao;
                char refil;
                cout << "Deseja refil (+R$5,00)? [S/N]" << endl;
                cin >> refil;

                if (tolower(refil) == 's')
                {
                    bebida.refil = true;
                }    
            }
        }
    }
   
    return bebida;
}

Sobremesa selecionarSobremesa(const vector<Sobremesa> &opcoes)
{
    cout << "Selecione a sobremesa: " << endl;
    for (int i = 0; i < opcoes.size(); i++)
    {
        cout << "Opcao " << i+1 <<": " << endl;
        cout << "Nome: " << opcoes[i].nome << endl;
        cout << "Preco: " << opcoes[i].preco << endl;
        cout << "Descricao: " << opcoes[i].descricao << endl;
       
       cout << "-------------" << endl;
    }

    int s;
    cout << "Digite a opcao de sobremesa: (Digite 0 se não quiser sobremesa)";
    cin >> s;

    Sobremesa sobremesa;

    if (s != 0)
    {
        for (int i = 0; i < opcoes.size(); i++)
        {
            if (i == s-1)
            {
                sobremesa.nome = opcoes[i].nome;
                sobremesa.preco = opcoes[i].preco;
                sobremesa.descricao = opcoes[i].descricao;
            }
        }
    }
    
    
    return sobremesa;
}

Pedido fazerPedido(const Hamburguer &burguer, const Bebida &bebida, const Sobremesa &sobremesa)
{
    Pedido pedido;
    pedido.burguer = burguer;
    pedido.bebida = bebida;
    pedido.sobremesa = sobremesa;
    
    return pedido; 
}

bool isBebidaEmpty(Bebida &bebida)
{
    return bebida.nome == "" && bebida.preco == 0.0 && bebida.descricao == "";

}

bool isSobremesaEmpty(Sobremesa &sobremesa)
{
    return sobremesa.nome == "" && sobremesa.preco == 0.0 && sobremesa.descricao == "";
}

bool revisarPedido(Pedido &pedido, const vector<Hamburguer> &burguer, const vector<Bebida> &bebidas, const vector<Sobremesa> &sobremesas)
{
    cout << "REVISAR PEDIDO" << endl;
    double totalBurguer = 0;
    cout << "*Hamburguer*" << endl;
    cout << "Nome: " << pedido.burguer.nome << endl;
    cout << fixed << setprecision(2);
    cout << "Preco: R$" << pedido.burguer.preco << endl;
    cout << "Descricao: " << pedido.burguer.descricao << endl;

    totalBurguer = pedido.burguer.preco;

    if (!pedido.burguer.adicionais.empty())
    {
        cout << "*Adicionais*" << endl;
        for (AdicionaisBurguer adicionais: pedido.burguer.adicionais)
        {
            cout << "Tipo: " << adicionais.tipo << endl;
            cout << fixed << setprecision(2);
            cout << "Preco: R$" << adicionais.preco << endl;
            totalBurguer+= adicionais.preco;
        }
        
    }else{
        cout << "Nenhum adicional adicionado!" << endl;
    }
    cout << "Total: R$" << totalBurguer;
    cout << endl;
    cout << "-------------" << endl;

    cout << "*Bebida*" << endl;
    double totBebida=0;

    if(!isBebidaEmpty(pedido.bebida)){
        cout << "Tipo: " << pedido.bebida.nome << endl;
        cout << fixed << setprecision(2);
        cout << "Preco: R$" << pedido.bebida.preco << endl;
        cout << "Descricao: " << pedido.bebida.descricao << endl;
        totBebida = pedido.bebida.preco;
        if(pedido.bebida.refil){
            cout << "Refil: Sim (+R$5,00)" << endl;
            totBebida += 5.00;
        }else{
            cout << "Refil: Não" << endl;
        }
        cout << "Total: R$" << totBebida;
    }else{
        cout << "Nenhuma bebida adicionada!" << endl;
    }
    cout << endl;
    cout << "-------------" << endl;

    double totSobremesa=0;
    cout << "*Sobremesa*" << endl;
    if (!isSobremesaEmpty(pedido.sobremesa))
    {
        cout << "Nome: " << pedido.sobremesa.nome << endl;
        cout << fixed << setprecision(2);
        cout << "Preco: R$" << pedido.sobremesa.preco << endl;
        cout << "Descricao: " << pedido.sobremesa.descricao << endl;
        totSobremesa = pedido.sobremesa.preco;
        cout << "Total: R$" << totSobremesa;
    }else{
        cout << "Nenhuma sobremesa adicionada!" << endl;
    }
    cout << endl;
    cout << "-------------" << endl;

    cout << "Total do pedido: R$" << totalBurguer+totBebida+totSobremesa;
    cout << endl;
    cout << "-------------" << endl;
    
    char editar;
    cout << "Gostaria de editar o pedido? [s/n]" << endl;
    cin>>editar;

    if (tolower(editar) == 's')
    {
        atualizarPedido(pedido, burguer,bebidas,sobremesas);
        return true;
    }else if(tolower(editar) == 'n'){
        realizarPagamento();
        return false;
    }

    cout << "Opcao invalida, mantendo o pedido como está." << endl;
    return false; 
}


void atualizarPedido(Pedido &pedido, const vector<Hamburguer> &burguer, const vector<Bebida> &bebidas, const vector<Sobremesa> &sobremesas)
{
    int opcao;
    while(opcao != 5){

        do
        {
            cout << "O que gostaria de atualizar? " << endl;
            cout << "1 - Hamburguer" << endl;
            cout << "2 - Hamburguer adicionais" << endl;
            cout << "3 - Bebida" << endl;
            cout << "4 - Sobremesa" << endl;
            cout << "5 - Sair" << endl;
            cin >> opcao;

            if (opcao < 0 && opcao > 4)
            {
                cout << "Opcao invalida" << endl;
            }
            
        } while (opcao < 0 && opcao > 5);


        if (opcao != 5)
        {
            switch (opcao)
            {
            case 1:
                pedido.burguer = selecionarHamburguer(burguer);
                break;
            case 2:
                pedido.burguer = selecionarAdicional(pedido.burguer, burguer);
                break;
            case 3:
                pedido.bebida = selecionarBebida(bebidas);
                break;
            case 4:
                pedido.sobremesa = selecionarSobremesa(sobremesas);
                break;
            default:
                break;
            }
            
            bool r = revisarPedido(pedido, burguer, bebidas, sobremesas);
            if (!r)
            {
                opcao = 5;
            }
            
        }
        
    }

}

void realizarPagamento()
{
    int opcao;
    cout << "Selecione uma forma de pagamento: " << endl;
    cout << "1 - Cartão de credito" << endl;
    cout << "2 - Cartão de debito" << endl;
    cout << "3 - Pix" << endl;
    cin >> opcao;

    cout << "Realizando pagamento..." << endl;

    srand(time(0));  
    int senha = rand() % 100 + 1;
    cout << "Sua senha eh: " << senha << endl;
    cout << "Agradecemos sua compra!" << endl;

}
