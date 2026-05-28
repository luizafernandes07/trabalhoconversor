
# 🔢 Conversor de Bases Numéricas Avançado

Trabalho prático desenvolvido para a disciplina de **Introdução à Computação**. O projeto consiste em um sistema capaz de converter números entre diferentes bases numéricas de forma totalmente autoral, sem a utilização de funções prontas de conversão de tipos da biblioteca padrão (como `std::stoi`, `std::stod` ou `std::to_string`).

## 👥 Integrantes
* **Ana Júlia Piva de Oliveira Gurita**
* **Luiza Mara Fernandes Costa**

## 🛠️ Tecnologia Utilizada
* **Linguagem:** C++

## 🎥 Link da Apresentação em Vídeo
A apresentação prática do sistema em funcionamento e a explicação detalhada do código podem ser assistidas no YouTube:
👉 [Vídeo de Demonstração do Projeto](https://youtu.be/FIfUfuy4hC4?si=3qv--DvllCTTVI8_)

---

## 🎯 Especificações do Projeto

### Bases Suportadas:
* **Binária (2)**
* **Octal (8)**
* **Decimal (10)**
* **Hexadecimal (16)**

### Recursos Implementados:
* ➕ Suporte completo a **números inteiros** e **números fracionários**.
* 🖥️ **Modo Interativo:** Menu completo via terminal com 12 opções de controle.
* 🔍 **Modo Passo a Passo (Trace):** Exibição detalhada da memória e dos cálculos matemáticos intermediários.
* 📂 **Modo Batch:** Processamento em lote de múltiplos dados via arquivo CSV.
* 🧮 **Calculadora de Máximos:** Cálculo do maior valor representável dado um limite finito de bits.

---

## 🚀 Instruções de Execução

### 1. Compilação e Execução do Programa Principal (Menu Interativo)
Para compilar todo o sistema modularizado e gerar o executável do conversor, execute no seu terminal:
```bash
g++ main.cpp conversao.cpp validacao.cpp interface.cpp arquivo.cpp -o Conversor.exe
.\Conversor.exe

```

### 2. Execução da Suíte de Testes Automatizados (Comando Único)

Para compilar e rodar a nossa suíte contendo os 32 casos de teste estruturados com a diretiva `assert`, utilize o comando abaixo:

```bash
g++ testes.cpp conversao.cpp validacao.cpp arquivo.cpp -o Testes.exe
.\Testes.exe

```

---

## 📑 Documentação do Código (Funções de Conversão)

### 📚 Bibliotecas Utilizadas

* `<iostream>`: Usado para entrada e saída de dados (`cin` e `cout`).
* `<string>`: Usado para manipular cadeias de caracteres textuais.
* `"conversao.h"`: Contém as declarações das funções de conversão de bases.
* `"interface.h"`: Responsável pelo controle da interface de usuário e variáveis do modo `trace`.

### ⚙️ Funções Auxiliares de Tipo

* **`int stringParaInt(string s)`**
* Conversão manual de string numérica para inteiro (sem utilizar `std::stoi`).
* Percorre cada caractere (`for(char c : s)`), valida se está no intervalo `'0'` a `'9'`, e constrói o valor através de acumuladores matemáticos: `res = res * 10 + (c - '0')`.


* **`double stringParaDouble(string s)`**
* Conversão manual de string para ponto flutuante (`double`), tratando a parte fracionária em decimal.


* **`string intParaString(long long n)`**
* Conversão manual de inteiro para string (sem utilizar `std::to_string`).



### 🔀 Conversão entre Caractere e Valor

* **`int caractereParaValor(char c)`**: Transforma um caractere alfanumérico no seu respectivo valor numérico (útil para letras em hexadecimal como 'A' $\rightarrow$ 10).
* **`char valorParaCaractere(int v)`**: Transforma um valor numérico em seu respectivo caractere (ex: 11 $\rightarrow$ 'B').

### 🧮 Funções de Manipulação e Conversão de Bases

* **`void separarNumero(string n, string &inteiro, string &fracao)`**
* Separa a parte inteira da parte fracionária dividindo a string original pelo delimitador de ponto/vírgula.


* **`string decimalParaBase(long long numero, int base)`**
* Conversão da parte inteira de decimal para qualquer base usando o método das **divisões sucessivas**.


* **`int baseParaDecimal(string n, int base)`**
* Conversão de qualquer base de origem para decimal através da **soma posicional**.


* **`string binarioParaOctal(string bin)`**
* Converte de binário para octal utilizando o **agrupamento de 3 bits**. Conta com correção interna para remover zeros à esquerda.


* **`string binarioParaHexadecimal(string bin)`**
* Converte de binário para hexadecimal utilizando o **agrupamento de 4 bits**.


* **`string octalParaBinario(string oct)`**
* Transforma cada dígito octal individualmente em 3 bits equivalentes.


* **`string hexadecimalParaBinario(string hex)`**
* Transforma cada dígito hexadecimal individualmente em 4 bits equivalentes.


* **`string octalParaHexadecimal(string oct)`**
* Conversão indireta: converte o número octal para binário intermediário e, em seguida, converte o binário para hexadecimal.


* **`string hexadecimalParaOctal(string hex)`**
* Conversão indireta: converte o número hexadecimal para binário intermediário e, em seguida, converte o binário para octal.



### 📄 Conversões de Números Fracionários

* **`string decimalParaBaseFracionario(string numero, int base)`**
* Realiza a conversão fracionária utilizando o método das **multiplicações sucessivas**.


* **`double baseParaDecimalFracionario(string numero, int base)`**
* Converte uma parte fracionária de qualquer base para decimal usando a **soma posicional fracionária**.



### 📐 Outros Recursos

* **`void calculadoraMaximos()`**
* Descobre o maior valor possível representável em um sistema com um limite de $k$ bits usando a fórmula matemática: $(2^k - 1)$.



---

## 🧠 Algoritmos Utilizados

1. **Decimal → Outras Bases**
* Parte Inteira: Divisões sucessivas pela base de destino até que o quociente seja zero. O resto das divisões lido de baixo para cima forma o número convertido.
* Parte Fracionária: Multiplicações sucessivas pela base de destino, onde a parte inteira gerada vira o dígito correspondente.


2. **Outras Bases → Decimal**
* Somatório posicional clássico, onde cada dígito é multiplicado por $\text{base}^{\text{posição}}$.


3. **Octal ↔ Hexadecimal**
* Utiliza o binário como passo intermediário, efetuando o agrupamento direto de bits (3 bits para octal e 4 bits para hexadecimal).



---

## 📂 Modo Batch (Processamento em Lote)

O programa aceita o processamento em lote por meio da leitura de um arquivo chamado `entrada.csv`.

**Formato do arquivo `entrada.csv`:**

```csv
valor;base_origem;base_destino
1010;2;10
7F;16;2
25.5;10;2

```

O processamento gera automaticamente o arquivo `saida.csv` com o resultado:

```csv
valor;base_origem;resultado;base_destino
1010;2;10;10
7F;16;11111111;2
25.5;10;11001.1;2

```

---

## 🚫 Tratamento de Limitações e Validações

O sistema faz a checagem rigorosa dos caracteres aceitos para cada respectiva base:

* **Base 8 (Octal):** Se houver dígitos fora do intervalo `[0-7]`, gera erro de número inválido.
* **Base 16 (Hexadecimal):** Se houver caracteres fora do intervalo `[0-9]` e `[A-F]` / `[a-f]`, gera erro.

### Exemplos Práticos:

* **Entrada:** Número octal `97655` $\rightarrow$ **Saída:** `Número octal inválido!` *(O dígito 9 é inválido)*
* **Entrada:** Número hexadecimal `12GA34` $\rightarrow$ **Saída:** `Número hexadecimal inválido!` *(O caractere G é inválido)*

---

## 🧪 Casos de Teste Utilizados (32 Testes Automatizados)

Abaixo estão listados os principais cenários validados na nossa suíte de testes:

| Categoria de Teste | Entrada | Saída Esperada / Status |
| --- | --- | --- |
| **F1: Decimal $\rightarrow$ Outras Bases** | Decimal: `0`, `13`, `64`, `255` | Binário: `0`, `1101`<br>

<br>Octal: `100`<br>

<br>Hexadecimal: `FF` |
| **F2: Outras Bases $\rightarrow$ Decimal** | Binário: `1101`<br>

<br>Octal: `100`<br>

<br>Hexadecimal: `FF` ou `ff` | Decimal: `13`<br>

<br>Decimal: `64`<br>

<br>Decimal: `255` |
| **F3: Binário ↔ Octal / Hexadecimal** | Binário: `11010`<br>

<br>Binário: `11111011`<br>

<br>Octal: `32`<br>

<br>Hexadecimal: `FB` | Octal: `32`<br>

<br>Hexadecimal: `FB`<br>

<br>Binário: `011010`<br>

<br>Binário: `11111011` |
| **F4: Octal ↔ Hexadecimal** | Octal: `77`<br>

<br>Hexadecimal: `3F` | Hexadecimal: `3F`<br>

<br>Octal: `77` |
| **F5: Validação de Entrada** | Binário: `10101` vs `10201`<br>

<br>Octal: `752` vs `782`<br>

<br>Hexadecimal: `A3F` vs `A3G` | `Válido` vs `Inválido` (Dígito 2)<br>

<br>`Válido` vs `Inválido` (Dígito 8)<br>

<br>`Válido` vs `Inválido` (Dígito G) |
| **F6: Fracionários e Truncamento** | Decimal: `10.625`<br>

<br>Decimal: `0.1` (até 16 casas) | Binário: `1010,101`<br>

<br>Binário: `0,0001100110011001` [Truncado] |
| **Borda e Estresse** | Vários casos (`0`, `1`, `abcdef`) | Comportamento validado e estável |

```

### O que mudou:
1. **Fechamento de Blocos:** O bloco de código da seção "Instruções de Execução" não tinha sido fechado no seu texto, quebrando a exibição do restante do documento.
2. **Estrutura de Títulos:** Padronizei os níveis dos títulos (`#`, `##`, `###`) para que a barra lateral de navegação do GitHub ou GitLab consiga criar o índice perfeitamente.
3. **Tabela de Testes:** A seção de exemplos de teste ficava muito extensa em texto corrido; formatei-a em uma tabela Markdown profissional, tornando-a muito mais fácil de compreender.
4. **Markdown Matemático:** Usei formatação de fórmulas em blocos de texto (ex: $2^k - 1$) para ficar com renderização limpa.

```
