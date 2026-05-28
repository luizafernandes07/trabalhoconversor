#include "validacao.h"
#include <string>

using namespace std;

bool validoBinario(string bin) {
    for (char c : bin)
        if (c != '0' && c != '1' && c != '.' && c != ',') return false;
    return true;
}

bool validoOctal(string oct) { 
    for (char c : oct) 
        if ((c < '0' || c > '7') && c != '.' && c != ',') return false; 
    return true; 
} 

bool validoHex(string hex) { 
    for (char c : hex) { 
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || c == '.' || c == ',')) 
            return false; 
    } 
    return true; 
}
