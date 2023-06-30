/**
 * Prova03.cpp
 * Autor: Gabriel Vargas Bento de Souza
 * Data: 07/2022
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include "Fracao.hpp"

using namespace std;

char* f01 (const char* s) {
    int   n           = strlen(s) - 1;
    char *r  = (char*) calloc(n, sizeof(char));
    char *ps = (char*) s+n;
    char *pr =         r+n;

    *(pr+1) = '\0';
    while(ps - (char*)s > 0) { 
        *pr = *ps;
        pr--;
        ps--;
    }
    *(pr+n) = *s;

    return (pr+1);
}

char* f02 (const char* s) {
    int   n  = strlen(s) - 1;
    char *r  = (char*) calloc(n, sizeof(char));
    char *ps = (char*) s+n-1;
    char *pr =         r+n;

    *(pr+1) = '\0';
    while(ps - (char*)s >= 0) { 
        *pr = *ps;
        pr--;
        ps--;
    }

    return (pr+1);
}

char* f03 (const char* s) {
    int   n  = strlen(s);
    char *r  = (char*) calloc(n, sizeof(char));
    char *ps = (char*) s+1;
    char *pr =         r;

    while(*ps) { 
        *pr = *ps;
        pr++;
        ps++;
    }
    *pr = '\0';

    return (r);
}

char* f04 (const char* s) {
    int   n  = strlen(s);
    char *r  = (char*) calloc(n, sizeof(char));
    char *ps = (char*) s;
    char *pr =         r;

    do { 
        *pr = *ps;
        ++pr;
        ++ps;
    } while(s+n/2-ps > 0);

    ps = ps+1;

    while(*ps) { 
        *pr = *ps;
        pr++;
        ps++;
    }
    *pr = '\0';

    return (r);
}

void method_01(void) {

    cout << "\nf01 = [" << f01("01234567") << "]";
    cout << "\nf02 = [" << f02("01234567") << "]";
    cout << "\nf03 = [" << f03("01234567") << "]";
    cout << "\nf04 = [" << f04("01234567") << "]";

}

void method_02(void) {

    ref_Fracao f1 = new Fracao(2,3);
    ref_Fracao f2 = new Fracao(4,9);
    ref_Fracao f3 = new Fracao();
    ref_Fracao f4[5];
    ref_Fracao f5 = new Fracao(1,1,nullptr);

    f4[0] -> ler("A03.txt", 5, f4);

    for(int x = 0; x < 5; x++) {
        f5->conectar(f4[x]);
    }

    cout << "01. f1 = " << f1->to_String() << "\n";
    cout << "02. f2 = " << f2->to_String() << "\n";
    cout << "03. f3 = " << f3->to_String() << "\n";

    f3 = f3->somar(f1);
    cout << "04. f3 = " << f3->to_String() << "\n";
    
    f3 = f3->somar(f2);
    cout << "05. f3 = " << f3->to_String() << "\n";

    cout << "06. MDC = " << f3->mdc() << "\n";
    cout << "07. f3 = " << f3->simplificar()->to_String() << "\n";
    
    cout << "08. ?= " << f1->comparar(f2) << "\n";
    cout << "09. >= " << f4[0]->maior(f4)->to_String() << "\n";

    while(f5) {
        cout << "10. f5 = " << f5->to_String() << "\n";
        f5 = f5->proxima();
    }

}

int main(void) {

    cout << "\n\nQuestao 1:" << endl;
    method_01();

    cout << "\n\nQuestao 2:" << endl;
    method_02();

    return 0;
}