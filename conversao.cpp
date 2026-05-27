#include "conversao.h"
#include "interface.h"
#include <iostream>
#include <string>

using namespace std;


int stringParaInt(string s) {
    int res = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            res = res * 10 + (c - '0');
        }
    }
    return res;
}

double stringParaDouble(string s) {
    double res = 0.0;
    double divisor = 10.0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            res += (c - '0') / divisor;
            divisor *= 10.0;
        }
    }
    return res;
}

string intParaString(long long n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s = char((n % 10) + '0') + s;
        n /= 10;
    }
    return s;
}

int caractereParaValor(char c) { 
    if (c >= '0' && c <= '9') return c - '0'; 
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return c - 'A' + 10; 
} 

char valorParaCaractere(int v) { 
    if (v < 10) return v + '0'; 
    return v - 10 + 'A'; 
} 

void separarNumero(string n, string &inteiro, string &fracao) { 
    size_t pos = n.find('.'); 
    if (pos == string::npos) pos = n.find(','); 
        
    if (pos == string::npos) { 
        inteiro = n; 
        fracao = ""; 
    } else { 
        inteiro = n.substr(0, pos); 
        fracao = n.substr(pos + 1); 
    } 
} 

string decimalParaBase(long long numero, int base) { 
    if (numero == 0) return "0"; 
    string r = ""; 
    if (trace) cout << "\n--- F7 TRACE F1 (divisoes sucessivas) ---\n";

    while (numero > 0) { 
        int resto = numero % base; 
        if (trace) cout << numero << " / " << base << " = " << numero / base << " resto " << resto << endl;
        r = string(1, valorParaCaractere(resto)) + r; 
        numero /= base; 
    } 
    if (trace) cout << "Resultado: " << r << endl; 
    return r; 
} 

int baseParaDecimal(string n, int base) { 
    int r = 0; 
    if (trace) cout << "\n--- F7 TRACE F2 (soma posicional) ---\n"; 
        
    for (char c : n) { 
        int v = caractereParaValor(c); 
        r = r * base + v; 
        if (trace) cout << "valor=" << v << " -> parcial=" << r << endl; 
    } 
    if (trace) cout << "Resultado: " << r << endl; 
    return r; 
} 
string binarioParaOctal(string bin) { 
    while (bin.size() % 3 != 0) bin = "0" + bin; 
    if (trace) cout << "\n--- F7 TRACE F3 (bin -> oct por grupos de 3) ---\n"; 
        
    string oct = ""; 
    for (size_t i = 0; i < bin.size(); i += 3) { 
        string g = bin.substr(i, 3); 
        char convertido = '0';
        if (g == "000") convertido = '0'; 
        else if (g == "001") convertido = '1'; 
        else if (g == "010") convertido = '2'; 
        else if (g == "011") convertido = '3'; 
        else if (g == "100") convertido = '4'; 
        else if (g == "101") convertido = '5'; 
        else if (g == "110") convertido = '6'; 
        else if (g == "111") convertido = '7'; 
        
        if (trace) cout << "Grupo binario: [" << g << "] -> Octal: " << convertido << endl;
        oct += convertido;
    } 
    
   
    while (oct.size() > 1 && oct[0] == '0') {
        oct = oct.substr(1);
    }
    
    return oct; 
} 

string binarioParaHexadecimal(string bin) { 
    while (bin.size() % 4 != 0) bin = "0" + bin; 
    if (trace) cout << "\n--- F7 TRACE F3 (bin -> hex por grupos de 4) ---\n"; 
        
    string hex = ""; 
    for (size_t i = 0; i < bin.size(); i += 4) { 
        string g = bin.substr(i, 4); 
        char convertido = '0';
        if (g == "0000") convertido = '0'; 
        else if (g == "0001") convertido = '1'; 
        else if (g == "0010") convertido = '2'; 
        else if (g == "0011") convertido = '3'; 
        else if (g == "0100") convertido = '4'; 
        else if (g == "0101") convertido = '5'; 
        else if (g == "0110") convertido = '6'; 
        else if (g == "0111") convertido = '7'; 
        else if (g == "1000") convertido = '8'; 
        else if (g == "1001") convertido = '9'; 
        else if (g == "1010") convertido = 'A'; 
        else if (g == "1011") convertido = 'B'; 
        else if (g == "1100") convertido = 'C'; 
        else if (g == "1101") convertido = 'D'; 
        else if (g == "1110") convertido = 'E'; 
        else if (g == "1111") convertido = 'F'; 
        
        if (trace) cout << "Grupo binario: [" << g << "] -> Hex: " << convertido << endl;
        hex += convertido;
    } 
    
    while (hex.size() > 1 && hex[0] == '0') {
        hex = hex.substr(1);
    }
    
    return hex; 
}

string octalParaBinario(string oct) { 
    string bin = ""; 
    if (trace) cout << "\n--- F7 TRACE F4 (oct -> bin) ---\n"; 
    for (char c : oct) { 
        string g = "";
        if (c == '0') g = "000"; 
        else if (c == '1') g = "001"; 
        else if (c == '2') g = "010"; 
        else if (c == '3') g = "011"; 
        else if (c == '4') g = "100"; 
        else if (c == '5') g = "101"; 
        else if (c == '6') g = "110"; 
        else if (c == '7') g = "111"; 
        if (trace) cout << "Digito Octal: " << c << " -> [" << g << "]" << endl;
        bin += g;
    } 
    return bin; 
} 

string hexadecimalParaBinario(string hex) { 
    string bin = ""; 
    if (trace) cout << "\n--- F7 TRACE F4 (hex -> bin) ---\n"; 
    for (char c : hex) { 
        string g = "";
        if (c == '0') g = "0000"; 
        else if (c == '1') g = "0001"; 
        else if (c == '2') g = "0010"; 
        else if (c == '3') g = "0011"; 
        else if (c == '4') g = "0100"; 
        else if (c == '5') g = "0101"; 
        else if (c == '6') g = "0110"; 
        else if (c == '7') g = "0111"; 
        else if (c == '8') g = "1000"; 
        else if (c == '9') g = "1001"; 
        else if (c == 'A' || c == 'a') g = "1010"; 
        else if (c == 'B' || c == 'b') g = "1011"; 
        else if (c == 'C' || c == 'c') g = "1100"; 
        else if (c == 'D' || c == 'd') g = "1101"; 
        else if (c == 'E' || c == 'e') g = "1110"; 
        else if (c == 'F' || c == 'f') g = "1111"; 
        if (trace) cout << "Digito Hex: " << c << " -> [" << g << "]" << endl;
        bin += g;
    } 
    return bin; 
} 

string octalParaHexadecimal(string oct) { return binarioParaHexadecimal(octalParaBinario(oct)); } 
string hexadecimalParaOctal(string hex) { return binarioParaOctal(hexadecimalParaBinario(hex)); } 

string decimalParaBaseFracionario(string numero, int base) { 
    string inteiroStr, fracStr; 
    separarNumero(numero, inteiroStr, fracStr); 
    
    int inteiro = stringParaInt(inteiroStr); 
    double frac = (fracStr == "" ? 0.0 : stringParaDouble(fracStr)); 
    
    string resultado = decimalParaBase(inteiro, base); 
    if (frac == 0) return resultado; 
        
    resultado += ","; 
    int count = 0; 
    
    if (trace) cout << "\n--- F7 TRACE F6 (fracionario) ---\n"; 
        
    while (frac > 0 && count < 16) { 
        frac *= base; 
        int dig = (int)frac; 
        if (trace) cout << "frac x base = " << frac << " digito=" << dig << endl; 
            
        resultado += valorParaCaractere(dig); 
        frac -= dig; 
        count++; 
    } 
    
    if (frac > 0) {
        resultado += " [TRUNCADO]";
    }
    
    return resultado; 
} 

double baseParaDecimalFracionario(string numero, int base) { 
    string inteiroStr, fracStr; 
    separarNumero(numero, inteiroStr, fracStr); 
    
    double resultado = 0; 
    for (char c : inteiroStr) resultado = resultado * base + caractereParaValor(c); 
        
    double fator = base; 
    for (char c : fracStr) { 
        resultado += caractereParaValor(c) / fator; 
        fator *= base; 
    } 
    return resultado; 
}
void calculadoraMaximos() {
    int k;
    cout << "\nQuantidade de bits: ";
    cin >> k;

    if(k <= 0) {
        cout << "Quantidade invalida!\n";
        return;
    }

    long long maximo = (1LL << k) - 1;

    cout << "\nMaior valor representavel com " << k << " bits:\n\n";
    cout << "Decimal     : " << maximo << endl;
    cout << "Binario     : " << decimalParaBase(maximo, 2) << endl;
    cout << "Octal       : " << decimalParaBase(maximo, 8) << endl;
    cout << "Hexadecimal : " << decimalParaBase(maximo, 16) << endl;
}
