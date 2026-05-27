#include <iostream>
#include "conversao.h"
#include "validacao.h"
#include "interface.h"
#include "arquivo.h"

using namespace std;

int main() {
    int opcao;
    do {
        cout << "\n===== CONVERSOR COMPLETO =====\n";
        cout << "1 - Decimal -> Binario\n";
        cout << "2 - Decimal -> Octal\n";
        cout << "3 - Decimal -> Hexadecimal\n";
        cout << "4 - Binario -> Decimal\n";
        cout << "5 - Octal -> Decimal\n";
        cout << "6 - Hexadecimal -> Decimal\n";
        cout << "7 - Octal -> Hexadecimal\n";
        cout << "8 - Hexadecimal -> Octal\n";
        cout << "9 - Ativar/desativar modo Passo-a-Passo (Trace)\n";
        cout << "10 - Modo Batch (CSV)\n";
        cout << "11 - Quiz em Dupla\n";
        cout << "12 - Calculadora de Maximos\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao >= 1 && opcao <= 3) {
            string num;
            cout << "Digite o numero: ";
            cin >> num;
            int base = (opcao == 1) ? 2 : (opcao == 2) ? 8 : 16;
            cout << "Resultado: " << decimalParaBaseFracionario(num, base) << endl;
        }
        else if (opcao >= 4 && opcao <= 6) {
            string n;
            cout << "Digite o numero: ";
            cin >> n;
            int base = (opcao == 4) ? 2 : (opcao == 5) ? 8 : 16;

            if (base == 2 && !validoBinario(n)) { cout << "Erro: binario invalido\n"; continue; }
            if (base == 8 && !validoOctal(n)) { cout << "Erro: octal invalido\n"; continue; }
            if (base == 16 && !validoHex(n)) { cout << "Erro: hexadecimal invalido\n"; continue; }

            cout << "Resultado: " << baseParaDecimalFracionario(n, base) << endl;
        }
        else if (opcao == 7) {
            string oct;
            cout << "Digite o octal: ";
            cin >> oct;
            if (!validoOctal(oct)) { cout << "Erro: octal invalido\n"; continue; }
            cout << "Resultado: " << octalParaHexadecimal(oct) << endl;
        }
        else if (opcao == 8) {
            string hex;
            cout << "Digite o hexadecimal: ";
            cin >> hex;
            if (!validoHex(hex)) { cout << "Erro: hexadecimal invalido\n"; continue; }
            cout << "Resultado: " << hexadecimalParaOctal(hex) << endl;
        }
        else if (opcao == 9) {
            setTrace(!trace); 
            if (trace) {
                cout << "MODO TRACE ATIVADO\n";
            } else {
                cout << "MODO TRACE DESATIVADO\n";
            }
        }
        else if(opcao == 10) {
            modoBatch();
        }
        else if(opcao == 11) {
            modoQuiz();
        }
        else if(opcao == 12) {
            calculadoraMaximos();
        }
    } while (opcao != 0);

    return 0;
}
