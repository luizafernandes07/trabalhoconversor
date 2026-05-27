#include "arquivo.h"
#include "conversao.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void modoBatch() {
    ifstream entrada("dados/entrada.csv");
    if(!entrada.is_open()) {
        cout << "Erro ao abrir dados/entrada.csv\n";
        return;
    }

    ofstream saida("dados/saida.csv");
    string linha;

    while(getline(entrada, linha)) {
        stringstream ss(linha);
        string valor, origemStr, destinoStr;

        getline(ss, valor, ';');
        getline(ss, origemStr, ';');
        getline(ss, destinoStr, ';');

        int origem = stringParaInt(origemStr);
        int destino = stringParaInt(destinoStr);

        string resultado;

        if(destino == 10) {
            
            double dec = baseParaDecimalFracionario(valor, origem);
            resultado = intParaString((long long)dec);
        }
        else if(origem == 10) {
            resultado = decimalParaBaseFracionario(valor, destino);
        }
        else {
            double decimal = baseParaDecimalFracionario(valor, origem);
            resultado = decimalParaBaseFracionario(intParaString((long long)decimal), destino);
        }

        saida << valor << ";" << origem << ";" << resultado << ";" << destino << "\n";
    }

    entrada.close();
    saida.close();
    cout << "Arquivo dados/saida.csv gerado com sucesso!\n";
}
