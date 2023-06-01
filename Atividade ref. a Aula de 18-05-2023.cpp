#include <iostream>
#include <queue>

using namespace std;

queue<int> senhasGeradas;
queue<int> senhasAtendidas;

void gerarSenha() {
    static int proximaSenha = 1;
    senhasGeradas.push(proximaSenha++);
    cout << "Senha gerada: " << proximaSenha - 1 << endl;
}

void realizarAtendimento() {
    if (senhasGeradas.empty()) {
        cout << "Não há senhas aguardando atendimento." << endl;
        return;
    }

    int senha = senhasGeradas.front();
    senhasGeradas.pop();
    senhasAtendidas.push(senha);

    cout << "Senha em atendimento: " << senha << endl;
}

int main() {
    int opcao = -1;

    while (!senhasGeradas.empty() || opcao != 0) {
        cout << "Quantidade de senhas aguardando atendimento: " << senhasGeradas.size() << endl;
        cout << "Selecione uma opção:" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Realizar atendimento" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0:
                if (!senhasGeradas.empty()) {
                    cout << "Ainda há senhas aguardando atendimento. Encerre-as primeiro." << endl;
                    opcao = -1;
                }
                break;
            case 1:
                gerarSenha();
                break;
            case 2:
                realizarAtendimento();
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    cout << "Quantidade de senhas atendidas: " << senhasAtendidas.size() << endl;

    return 0;
}
