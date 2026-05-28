#ifndef CONVERSAO_H
#define CONVERSAO_H

#include <string>

int stringParaInt(std::string s);
double stringParaDouble(std::string s);
std::string intParaString(long long n);

int caractereParaValor(char c);
char valorParaCaractere(int v);
void separarNumero(std::string n, std::string &inteiro, std::string &fracao);

std::string decimalParaBase(long long numero, int base);
int baseParaDecimal(std::string n, int base);

std::string binarioParaOctal(std::string bin);
std::string binarioParaHexadecimal(std::string bin);
std::string octalParaBinario(std::string oct);
std::string hexadecimalParaBinario(std::string hex);
std::string octalParaHexadecimal(std::string oct);
std::string hexadecimalParaOctal(std::string hex);

std::string decimalParaBaseFracionario(std::string numero, int base);
double baseParaDecimalFracionario(std::string numero, int base);

void calculadoraMaximos();

#endif
