#include <iostream>
#include <cassert>
#include <string>
#include "conversao.h"
#include "validacao.h"

using namespace std;

bool trace = false; 
void setTrace(bool ativo) { trace = ativo; }

void rodarTestes() {
    cout << "Iniciando suite automatizada de testes (32 casos)...\n" << endl;

    
    assert(decimalParaBase(0, 2) == "0");
    assert(decimalParaBase(13, 2) == "1101");
    assert(decimalParaBase(64, 8) == "100");
    assert(decimalParaBase(255, 16) == "FF");
    cout << "[OK] Requisito F1 (Divisoes sucessivas inteiras) validado!" << endl;

    assert(baseParaDecimal("1101", 2) == 13);
    assert(baseParaDecimal("100", 8) == 64);
    assert(baseParaDecimal("FF", 16) == 255);
    assert(baseParaDecimal("ff", 16) == 255); // Case insensitivity no parser
    cout << "[OK] Requisito F2 (Somatorio posicional inteiro) validado!" << endl;

    assert(binarioParaOctal("11010") == "32"); 
    assert(binarioParaHexadecimal("11111011") == "FB");
    assert(octalParaBinario("32") == "011010");
    assert(hexadecimalParaBinario("FB") == "11111011");
    cout << "[OK] Requisito F3 (Agrupamento direto de bits sem passar por dec) validado!" << endl;

    
    assert(octalParaHexadecimal("77") == "3F");
    assert(hexadecimalParaOctal("3F") == "77");
    cout << "[OK] Requisito F4 (Octal <-> Hexadecimal via binario) validado!" << endl;

    assert(validoBinario("10101") == true);
    assert(validoBinario("10201") == false); // Erro: dígito 2
    assert(validoOctal("752") == true);
    assert(validoOctal("782") == false);  // Erro: dígito 8
    assert(validoHex("A3F") == true);
    assert(validoHex("A3G") == false);   // Erro: dígito G
    cout << "[OK] Requisito F5 (Validacao estrita de escopo de base) validado!" << endl;

   
    assert(decimalParaBaseFracionario("10.625", 2) == "1010,101");
    assert(decimalParaBaseFracionario("0.1", 2) == "0,0001100110011001 [TRUNCADO]"); // Dízima gerando flag de truncamento
    
    assert(baseParaDecimalFracionario("10.625", 10) == 10.625);
    assert(baseParaDecimalFracionario("10,625", 10) == 10.625);
    cout << "[OK] Requisito F6 (Flutuantes, parser de delimitadores e Truncamento) validado!" << endl;

    assert(stringParaDouble("125") == 0.125);
    assert(intParaString(9876) == "9876");
    assert(caractereParaValor('F') == 15);
    assert(valorParaCaractere(11) == 'B');
    cout << "[OK] Restricao Central (Processamento manual de tipos banidos) validado!" << endl;

    assert(decimalParaBase(1, 2) == "1");
    assert(baseParaDecimal("1", 2) == 1);
    assert(binarioParaHexadecimal("0") == "0");
    assert(hexadecimalParaBinario("0") == "0000");
    assert(validoHex("abcdef") == true);
    assert(validoBinario("10,11") == true);

    cout << "\n==================================================" << endl;
    cout << " Parabens! Todos os 32 casos de teste passaram com sucesso!" << endl;
    cout << "==================================================" << endl;
}

int main() {
    rodarTestes();
    return 0;
}
