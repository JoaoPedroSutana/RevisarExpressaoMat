#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Pilha.h"

using namespace std;

int main() {
    char Expressao[100];
    char verificacao;

    Pilha_Construtor(); // Inicializa a pilha (implementada em "Pilha.h").

    // Solicita ao usuário que insira a expressão matemática a ser verificada e salva no vetor de caracteres Expressao.
    cout << "PROGRAMA VERIFICA EXPRESSAO COM PILHA" << endl << endl;
    cout << "Digite a Expressao matematica: ";
    fflush(stdin);
    cin.getline(Expressao, 100);

    // Verifica se alguma expressão foi digitada. Se sim, inicia as verificações das expressões; caso contrário,
    // exibe uma mensagem informando que nenhuma expressão foi digitada.
    if (strlen(Expressao) > 1) {
        for (int i = 0; i < strlen(Expressao); i++) {
            // Se o caractere for uma abertura de chave '{', colchete '[' ou parêntese '(', empilha o caractere.
            if (Expressao[i] == '{' || Expressao[i] == '[' || Expressao[i] == '(') {
                if (!Pilha_Empilhar(Expressao[i])) {
                    cout << "Erro ao empilhar!" << endl;
                }
            }
            // Se o caractere for um fechamento ('}', ']', ')'), inicia a verificação correspondente para verificar se
            // possui um fechamento adequado, adicionando o caractere do topo da pilha na variável de verificação e
            // comparando com seu fechamento.
            else if (Expressao[i] == '}' || Expressao[i] == ']' || Expressao[i] == ')') {
                Pilha_Topo(verificacao);

                // Processa chaves: verifica se o topo da pilha é uma chave e se o fechamento também é uma chave.
                // Se ambos forem verdadeiros, o elemento é desempilhado. Caso contrário, exibe uma mensagem de erro,
                // desempilha todos os elementos restantes (Função Pilha_Destrutor()) da pilha e encerra o programa.
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
                // Processa colchetes: verifica se o topo da pilha é um colchete e se o fechamento também é um colchete.
                // Se ambos forem verdadeiros, o elemento é desempilhado. Caso contrário, exibe uma mensagem de erro,
                // desempilha todos os elementos restantes da pilha (Função Pilha_Destrutor()) e encerra o programa.
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
                // Processa parênteses: verifica se o topo da pilha é um parêntese e se o fechamento também é um parêntese.
                // Se ambos forem verdadeiros, o elemento é desempilhado. Caso contrário, exibe uma mensagem de erro,
                // desempilha todos os elementos restantes da pilha (Função Pilha_Destrutor()) e encerra o programa.
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
        // Após percorrer toda a expressão, verifica se a pilha está vazia. Se estiver, a expressão é considerada válida.
        if (Pilha_Vazia()) {
            cout << endl << "Expressao Valida" << endl;
        }
    } else {
        cout << endl << "Nao foi digitada nenhuma expressao" << endl;
    }
    return 0;
}
