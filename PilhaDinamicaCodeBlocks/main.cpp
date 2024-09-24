#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Pilha.h"

using namespace std;

int main() {
    char Expressao[100];
    char verificacao;

    Pilha_Construtor(); // Inicializa a pilha (implementada em "Pilha.h").

    // Solicita ao usu�rio que insira a express�o matem�tica a ser verificada e salva no vetor de caracteres Expressao.
    cout << "PROGRAMA VERIFICA EXPRESSAO COM PILHA" << endl << endl;
    cout << "Digite a Expressao matematica: ";
    fflush(stdin);
    cin.getline(Expressao, 100);

    // Verifica se alguma express�o foi digitada. Se sim, inicia as verifica��es das express�es; caso contr�rio,
    // exibe uma mensagem informando que nenhuma express�o foi digitada.
    if (strlen(Expressao) > 1) {
        for (int i = 0; i < strlen(Expressao); i++) {
            // Se o caractere for uma abertura de chave '{', colchete '[' ou par�ntese '(', empilha o caractere.
            if (Expressao[i] == '{' || Expressao[i] == '[' || Expressao[i] == '(') {
                if (!Pilha_Empilhar(Expressao[i])) {
                    cout << "Erro ao empilhar!" << endl;
                }
            }
            // Se o caractere for um fechamento ('}', ']', ')'), inicia a verifica��o correspondente para verificar se
            // possui um fechamento adequado, adicionando o caractere do topo da pilha na vari�vel de verifica��o e
            // comparando com seu fechamento.
            else if (Expressao[i] == '}' || Expressao[i] == ']' || Expressao[i] == ')') {
                Pilha_Topo(verificacao);

                // Processa chaves: verifica se o topo da pilha � uma chave e se o fechamento tamb�m � uma chave.
                // Se ambos forem verdadeiros, o elemento � desempilhado. Caso contr�rio, exibe uma mensagem de erro,
                // desempilha todos os elementos restantes (Fun��o Pilha_Destrutor()) da pilha e encerra o programa.
                if (verificacao == '{') {
                    if (Expressao[i] == '}') {
                        if (!Pilha_Desempilhar()) {
                            cout << "Erro ao desempilhar" << endl;
                        }
                    } else {
                        cout << endl << "Expressao Invalida";
                        Pilha_Destrutor();
                        exit(0);
                    }
                }
                // Processa colchetes: verifica se o topo da pilha � um colchete e se o fechamento tamb�m � um colchete.
                // Se ambos forem verdadeiros, o elemento � desempilhado. Caso contr�rio, exibe uma mensagem de erro,
                // desempilha todos os elementos restantes da pilha (Fun��o Pilha_Destrutor()) e encerra o programa.
                else if (verificacao == '[') {
                    if (Expressao[i] == ']') {
                        if (!Pilha_Desempilhar()) {
                            cout << "Erro ao desempilhar" << endl;
                        }
                    } else {
                        cout << endl << "Expressao Invalida";
                        Pilha_Destrutor();
                        exit(0);
                    }
                }
                // Processa par�nteses: verifica se o topo da pilha � um par�ntese e se o fechamento tamb�m � um par�ntese.
                // Se ambos forem verdadeiros, o elemento � desempilhado. Caso contr�rio, exibe uma mensagem de erro,
                // desempilha todos os elementos restantes da pilha (Fun��o Pilha_Destrutor()) e encerra o programa.
                else if (verificacao == '(') {
                    if (Expressao[i] == ')') {
                        if (!Pilha_Desempilhar()) {
                            cout << "Erro ao desempilhar" << endl;
                        }
                    } else {
                        cout << endl << "Expressao Invalida";
                        Pilha_Destrutor();
                        exit(0);
                    }
                }
            }
        }
        // Ap�s percorrer toda a express�o, verifica se a pilha est� vazia. Se estiver, a express�o � considerada v�lida.
        if (Pilha_Vazia()) {
            cout << endl << "Expressao Valida" << endl;
        }
    } else {
        cout << endl << "Nao foi digitada nenhuma expressao" << endl;
    }
    return 0;
}
