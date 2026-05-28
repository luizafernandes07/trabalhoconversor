# Conversor de Bases Numéricas Avançado

Trabalho prático desenvolvido para a disciplina de **Introdução à Computação**. O projeto consiste em um sistema capaz de converter números entre diferentes bases numéricas de forma totalmente autoral, sem a utilização de funções prontas de conversão de tipos da biblioteca padrão (como `std::stoi`, `std::stod` ou `std::to_string`).

## 👥 Integrantes
* **Ana Júlia Piva de Oliveira Gurita**
* **Luiza Mara Fernandes Costa**

## 🎥 Link da Apresentação em Vídeo
A demonstração prática do sistema em funcionamento e a explicação detalhada do código podem ser assistidas no YouTube:
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
