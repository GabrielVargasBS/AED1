/**
 * Classe Fracao.hpp
 * Autor: Gabriel Vargas Bento de Souza
 * Data: 07/2022
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Fracao;
using ref_Fracao = Fracao*;
using namespace std;

class Fracao {

    protected:

        int n;
        int d;
        ref_Fracao link;
    
    public:
        
        /**
         * Construtor padrao.
         */
        Fracao() {
            n = 0;
            d = 1;
            link = nullptr;
        }

        /**
         * Construtor alternativo.
         * @param a - numerador da fracao.
         * @param b - denominador da fracao.
         */
        Fracao(int a, int b) {
            n = a;

            // Validar denominador
            if (b != 0) d = b;
            else d = 1;
            
            link = nullptr;
        }

        /**
         * Construtor alternativo.
         * @param a - numerador da fracao.
         * @param b - denominador da fracao.
         * @param proxima - link para proxima fracao.
         */
        Fracao(int a, int b, ref_Fracao proxima) {
            n = a;

            // Validar denominador
            if (b != 0) d = b;
            else d = 1;
            
            link = proxima;
        }

        /**
         * Metodo para somar duas fracoes.
         * @param f - fracao a ser somada.
         * @return duas fracoes somadas.
         */
        ref_Fracao somar (ref_Fracao f) {

            ref_Fracao fracaoSomada = new Fracao();

            int parcela1 = this->n * f->d;
            int parcela2 = f->n * this->d;

            int num = parcela1 + parcela2;
            int den = this->d * f->d;

            // Testar se denominador e' valido
            if (den != 0) {
                fracaoSomada = new Fracao(num, den);
            }

            return fracaoSomada;
        }

        /**
         * Metodo para simplificar uma fracao.
         * @return fracaoSimplificada.
         */
        ref_Fracao simplificar() {
            int mdc = this->mdc();

            int num = this->n / mdc;
            int den = this->d / mdc;

            ref_Fracao fracaoSimplificada = new Fracao(num, den);
            fracaoSimplificada->link = this->link;

            return fracaoSimplificada;
        }

        /**
         * Metodo para comparar os valores de um array de fracoes e obter a 
         * maior fracao.
         * @param f - array de fracoes.
         * @return maior fracao contida no array.
         */
        ref_Fracao maior (ref_Fracao f[]) {

            // Obter tamanho do array
            int i = 0;
            while(f[i]->link != nullptr) {i++;}

            ref_Fracao maior;
            // Testar se denominador valido
            if (f[0]->d != 0) maior = f[0];
            else maior = new Fracao();

            int length = i;

            for(int i = 1; i < length; i++) {

                // Testar se denominador valido
                if (f[i]->d != 0) {

                    double maiorValor = (double)maior->n / (double)maior->d;
                    double valorAtual = (double)f[i]->n / (double)f[i]->d;

                    // Se maior, trocar
                    if(valorAtual > maiorValor) maior = f[i]; 
                }
            }

            return maior;
        }

        /**
         * Metodo para conectar uma fracao na outra.
         */
        void conectar (ref_Fracao f) {

            ref_Fracao cursor = this;
            
            while(cursor->link != nullptr) {
                cursor = cursor->link;
            }

            cursor->link = f;
        }

        /**
         * Metodo para obter a proxima fracao linkada.
         * @return link para a proxima fracao.
         */
        ref_Fracao proxima() {
            return this->link;
        }

        /**
         * Metodo para obter o MDC entre numerados e denominador da fracao.
         * @return resultado do MDC.
         */
        int mdc() {
            int result = 1;
            int max;

            if (this-> n > this-> d) {
                max = d;
            } else {
                max = n;
            }

            for(int i = max; i > 1; i--) {

                if(this->n % i == 0 && this->d % i == 0) {
                    result = i;
                    i = 0;
                }
            }

            return result;

        }

        /**
         * Metodo para comparar duas fracoes.
         * @return 1 se forem iguais; 0 se diferentes.
         */
        int comparar(ref_Fracao f) {

            ref_Fracao f1 = f->simplificar();
            ref_Fracao f2 = this->simplificar();

            int result;
            if (f1->n == f2->n && f1->d == f2->d)
                result = 1;
            else
                result = 0;

            return result;
        }

        /**
         * Metodo para ler array de fracoes de arquivo.
         * @param nome - nome do arquivo que se encontram as fracoes.
         * @param n - numero de fracoes existentes.
         * @param f - array de fracoes destino.
         */
        void ler (string nome, int n, ref_Fracao f[]) {

            ifstream arq;
            arq.open(nome);

            int num;
            int den;

            // Ler arquivo
            for(int i = 0; i < n; i++)
            {
                arq >> num;
                arq >> den;

                f[i] = new Fracao(num, den);
            }

            arq.close();
        }

        /**
         * Metodo para formatar uma fracao em string.
         * @return fracao como string.
         */
        string to_String() {
            ostringstream buffer;
            buffer << this->n << "/" << this->d;
            return (buffer.str());
        }
};