# Conversor de Bases Numéricas Avançado

Trabalho prático desenvolvido para a disciplina de **Introdução à Computação**. O projeto consiste em um sistema capaz de converter números entre diferentes bases numéricas de forma totalmente autoral, sem a utilização de funções prontas de conversão de tipos da biblioteca padrão (como `std::stoi`, `std::stod` ou `std::to_string`).

## 👥 Integrantes
* **Ana Júlia Piva de Oliveira Gurita**
* **Luiza Mara Fernandes Costa**

# Linguagem escolhida por nós

- C++

## 🎥 Link da Apresentação em Vídeo
A apresentação prática do sistema em funcionamento e a explicação detalhada do código podem ser assistidas no YouTube:
👉 [Vídeo de Demonstração do Projeto](https://youtu.be/FIfUfuy4hC4?si=3qv--DvllCTTVI8_)

---

## 🛠️ Especificações do Projeto

### Bases Suportadas:
* **Binária (2)**
* **Octal (8)**
* **Decimal (10)**
* **Hexadecimal (16)**

### Recursos Implementados:
* Suporte completo a **números inteiros** e **números fracionários**.
* **Modo Interativo:** Menu completo via terminal com 12 opções de controle.
* **Modo Passo a Passo (Trace):** Exibição detalhada da memória e dos cálculos matemáticos intermediários.
* **Modo Batch:** Processamento em lote de múltiplos dados via arquivo CSV.
* **Calculadora de Máximos:** Cálculo do maior valor representável dado um limite finito de bits.

---

## 🚀 Instruções de Execução Passo a Passo

### 1. Compilação e Execução do Programa Principal (Menu Interativo)
Para compilar todo o sistema modularizado e gerar o executável do conversor, execute no terminal:
```bash
g++ main.cpp conversao.cpp validacao.cpp interface.cpp arquivo.cpp -o Conversor.exe
.\Conversor.exe

### 1. Execução da Suíte de Testes Automatizados (Comando Único)
Execução da Suíte de Testes Automatizados (Comando Único)
Para compilar e rodar a nossa suíte contendo os 32 casos de teste estruturados com a diretiva assert, utilize o comando abaixo:

##codigo da conversão

###bibliotecas
- iostream: usado para entrada e saída (cin e cout)
- string: usado para manipular textos
- conversao.h: declarações das funções de conversão
- interface.h: controle da interface e variável trace

### int stringParaInt(string s)
- conversao manual de string para inteiro
- transforma uma string numérica em inteiro sem usar std::stoi

### int res = 0
- cria a variável que vai guardar o resultado 

### for(char c : s)
- faz percorrer cada caractere da string

### if (c >= '0' && c <= '9')
- verifica se o caractere realmente e um número

### res = res * 10 + (c - '0')
- acontece a construção do número

### double stringParaDouble(string s)
- conversão manual d string para double 
-transforma a parte fracionária em decimal

### string intParaString(long long n)
- conversão manual de inteiro para string
- transforma um número em texto sem usar o to_string

### Conversão entre caractere e valor

#### int caractereParaValor(char c)
- transforma caractere para valor

#### char valorParaCaractere(int v)
- transforma valor para caractere

### void separarNumero(string n, string &inteiro, string &fracao)
- separa a parte inteira e a parte fracionária

### string decimalParaBase(long long numero, int base)
- conversão decimal para base qualquer
- para isso, foi usado o metodo das divisões sucessivas

### int baseParaDecimal(string n, int base)
- conversão de qualquer base(2, 8 ou 16) para base decimal
- usando a soma posicional

### string binarioParaOctal(string bin)
- conversão de binario para octal
- usando o agrupamento de 3 bits
 
### while (oct.size() > 1 && oct[0] == '0')
- correção utilizada para remover zeros a esquerda
 
### string binarioParaHexadecimal(string bin)
- conversão de binario para hexadecimal
- usando o agrupamento de 4 bits
 
### string octalParaBinario(string oct)
- conversão de octal para binario
- transformando cada digito octal em 3 bits
 
### string hexadecimalParaBinario(string hex)
- conversão de hexadecimal para binario
- transformando cada digito hexadecimal em 4 bits
 
### string octalParaHexadecimal(string oct)
- conversao de octal para hexadecimal
- passa o numero octal para binario, que depois é convertido em hexadecimal

### string hexadecimalParaOctal(string hex)
- conversao de hexadecimal para octal
- passa o numero hexadecimal para binario, que depois é convertido em octal 

### string decimalParaBaseFracionario(string numero, int base)
- conversão fracionária
- usando o metodo de multiplicações sucessivas

### double baseParaDecimalFracionario(string numero, int base)
- conversão fracionária para base decimal
- usando a soma posicional normal

### void calculadoraMaximos()
- descobre o maior valor possível com k bits
- usando a fórmula: (2^k - 1)

# Algoritmos Utilizados

## Decimal → Binário

- divisões sucessivas para a parte inteira
- multiplicações sucessivas para a parte fracionária

## Binário → Decimal

- somatório posicional

## Octal ↔ Hexadecimal

- conversão usando binário intermediário
- agrupamento de bits

# Modo Batch

O programa lê um arquivo `entrada.csv` no formato:

```csv
valor;base_origem;base_destino
1010;2;10
7F;16;2
25.5;10;2
```

E gera `saida.csv`:

```csv
valor;base_origem;resultado;base_destino
1010;2;10;10
7F;16;1111111;2
25.5;10;11001.1;2
```

# Como tratamos das limitações conhecidas

No programa foi especificado os números e letras válidos para cada base, então:

- para a base 8, se for digitado qualquer número que não pertencer a base octal, irá gerar a mensagem número inválido
- para a base 16, se for digitado qualquer número/letra que não pertencer a base hexadecimal, irá gerar a mensagem número inválido

Exemplo1:

Entrada: número octal 97655

Saída: número octal inválido

Exemplo2:

Entrada: número hexadecimal 12GA34

Saída: número hexadecimal inválido

# Exemplos que usamos para teste

##F1: Decimal -> Binario / Octal / Hexadecimal 
- decimal para base 2 (0 = 0)
- decimal para base 2 (13 = 1101)
- decimal para base 8 (64 = 100)
- decimal para base 16 (255 = FF)

##F2: Binario / Octal / Hexadecimal -> Decimal
- base 2 para decimal(1101 = 13)
- base 8 para decimal(100 = 64)
- base 16 para decimal(FF = 255)
- base 16 para decimal(ff = 255)

##F3: Binario <-> Octal / Hexadecimal (Agrupamento direto)
- binario para octal(11010 = 32) 
- binario para hexadecimal(11111011 = FB)
- octal para binario(32 = 011010)
- hexadecimal para binario(FB = 11111011)

##F4: Octal <-> Hexadecimal (Binario intermediario)
- octal para hexadecimal(77 = 3F)
- hexadecimal para octal(3F = 77)

##F5: Validacao de Entrada de Acordo com a Base
- validoBinario(10101 = válido) 
- validoBinario(10201 = inválido) // Erro: dígito 2
- validoOctal(752 = válido)
- validoOctal(782 = inválido) // Erro: dígito 8
- validoHex(A3F = válido)
- validoHex(A3G = inválido) // Erro: dígito G

##F6: Suporte a Fracionarios e Truncamento (Ate 16 casas)
- decimal para base 2 fracionario(10.625 = 1010,101)
- decimal para base 2 fracionario(0.1 = 0,0001100110011001 [TRUNCADO])

##Casos de Borda e Estresse Adicionais (Totalizando 32 testes)
- decimal Para Base 2 (1 = 1)
- base 2 Para Decimal(1 = 1)
- binario Para Hexadecimal(0 = 0)
- hexadecimal Para Binario(0 = 0000)
- validoHex(abcdef = válido)
- validoBinario(10 = válido)
