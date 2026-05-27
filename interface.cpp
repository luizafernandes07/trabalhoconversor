#include "interface.h"
#include "conversao.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool trace = false; 

void setTrace(bool ativo) { 
    trace = ativo; 
} 

void modoQuiz() {
    srand(time(NULL));
    int nivel;
    int pontos = 0;

    cout << "\n================= QUIZ EM DUPLA =================" << endl;
    cout << "Escolha o nivel de dificuldade para a dupla:" << endl;
    cout << "1 - Nivel 1 (Magnitude: 0 a 15)      [Até 4 bits]" << endl;
    cout << "2 - Nivel 2 (Magnitude: 0 a 255)     [Até 8 bits]" << endl;
    cout << "3 - Nivel 3 (Magnitude: 0 a 4095)    [Até 12 bits]" << endl;
    cout << "4 - Nivel 4 (Magnitude: 0 a 65535)   [Até 16 bits]" << endl;
    cout << "5 - Nivel 5 (Magnitude: 0 a 1048575) [Até 20 bits]" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Escolha o nivel (1-5): ";
    cin >> nivel;

    int maximo = 15;
    
    switch (nivel) {
        case 1: maximo = 15; break;
        case 2: maximo = 255; break;
        case 3: maximo = 4095; break;
        case 4: maximo = 65535; break;
        case 5: maximo = 1048575; break;
        default:
            cout << "Nivel invalido! Retornando ao menu principal.\n";
            return;
    }

    cout << "\nIniciando o Quiz no Nivel " << nivel << " (Valores ate " << maximo << ")." << endl;
    cout << "Preparem-se, serao 5 perguntas!\n" << endl;

    for(int i = 1; i <= 5; i++) {
        int numero = rand() % (maximo + 1);
        int bases[3] = {2, 8, 16};
        int baseDestino = bases[rand() % 3];

        bool estadoOriginalTrace = trace; 

        setTrace(false); 
        string respostaCorreta = decimalParaBase(numero, baseDestino);

        string respostaDupla;
        cout << "[Pergunta " << i << "/5] Convertam o valor " << numero << " (decimal) para a base " << baseDestino << ": ";
        cin >> respostaDupla;

      
        if (estadoOriginalTrace) {
            cout << "\n>>> [PASSO A PASSO DA RESOLUÇÃO]:";
            setTrace(true);
            decimalParaBase(numero, baseDestino); 
            cout << "-------------------------------------------------";
        }

        setTrace(estadoOriginalTrace); 

        for (char &c : respostaDupla) {
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A'; 
            }
        }
        
        if(respostaDupla == respostaCorreta) {
            cout << "\n>> Correto! Muito bem.\n" << endl;
            pontos++;
        } else {
            cout << "\n>> Errado! A resposta correta era: " << respostaCorreta << "\n" << endl;
        }
    }
    
    cout << "=================================================" << endl;
    cout << "FIM DO QUIZ! Pontuacao Final da Dupla: " << pontos << "/5" << endl;
    cout << "=================================================" << endl;
}
