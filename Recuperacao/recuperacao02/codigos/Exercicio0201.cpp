/*
  Exercicio02 - v 0.0. - 12 / 06 / 2022
  Author: Gabriel Vargas Bento de Souza
*/

// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres

// --------------------------------------------------------- definicoes globais

void pause ( std::string text )
{
    std::string dummy;
    std::cin.clear ( );
    std::cout << std::endl << text;
    std::cin.ignore( );
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;

}  // end pause ( )

// ---------------------------------------------------------- classes / pacotes

#include "myarray.hpp"
#include "mymatrix.hpp"

using namespace std;

// -------------------------------------------------------------------- metodos

/**
  Method00 - Nao faz nada.
 */

void method00 ( )
{
    // nao faz nada
} // end method00 ( )

/**
  Method01 - Testar se valores do arranjo estao em ordem decrescente e,
             caso nao estejam, ordena-los
*/

void method01 ( )
{
   // definir dado
      Array <int> array ( 10, 0 );

   // identificar
      cout << "\nExercicio0201 - Method01 - v0.0\n" << endl;
   
   // ler arranjo
      array.fread ( "DADOS1.TXT" );
      
   // mostrar dados
      cout << "Original" << endl;
      array.print ( );
   
   // ordenar
      array = array.ordenarDecrescente( array );

   // mostrar dados
      cout << "Decrescente" << endl;
      array.print  ( );
      array.fprint ( "DECRESCENTE.TXT" );

   // reciclar espaco
      array.free ( );

   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method01 ( ) 

/**
  Method02 - 
 */

void method02 ( )
{  
   // identificar
      cout << endl << "Exercicio0201 - Method02 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method02 ( )

/**
  Method03 - 
 */

void method03 ( )
{  
   // identificar
      cout << endl << "Exercicio0201 - Method03 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method03 ( )

/**
  Method04 - 
 */

void method04 ( )
{  
   // identificar
      cout << endl << "Exercicio0201 - Method04 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method04 ( )

/**
  Method05 - 
 */

void method05 ( )
{  
   // identificar
      cout << endl << "Exercicio0201 - Method05 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method05 ( )

/**
  Method06 - 
 */

void method06 ( )
{  
   // identificar
      cout << endl << "Exercicio0201 - Method06 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method06 ( )

/**
  Method07 - 
 */

void method07 ( )
{  
   // identificar
      cout << endl << "Exercicio0201 - Method07 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method07 ( )

/**
  Method08 - 
 */

void method08 ( )
{  
   // identificar
      cout << endl << "Exercicio0201 - Method08 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method08 ( )

/**
 Method09 - 
 */

void method09 ( )
{  
   // identificar
      cout << endl << "Exercicio0201 - Method09 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method09 ( )

/**
 Method10 - 
 */

void method10 ( )
{  
   // identificar
      cout << endl << "Exercicio0201 - Method10 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method10 ( )

// ------------------------------------------------------------- acao principal

/**
  Funcao principal.
  @return codigo de encerramento
*/

int main ( int argc, char** argv )
{
    // definir dado
       int x = 0;
    
    // repetir ate desejar parar
       do
       {
            // identificar
               cout << "\nExercicio0201 - Programa - v0.0\n       " << endl;

            // mostrar opcoes
               cout << "Opcoes                                  " << endl;
               cout << "0  - parar                              " << endl;
               cout << "1  - ordenar arranjo decrescentemente   " << endl;
            // cout << "2  -                                    " << endl;
            // cout << "3  -                                    " << endl;
            // cout << "4  -                                    " << endl;
            // cout << "5  -                                    " << endl;
            // cout << "6  -                                    " << endl;
            // cout << "7  -                                    " << endl;
            // cout << "8  -                                    " << endl;
            // cout << "9  -                                    " << endl;
            // cout << "10 -                                    " << endl;

            // ler do teclado
               cout << endl << "Entrar com uma opcao: ";
               cin >> x;
            
            // escolher acao
               switch ( x )
               {
               case 0:
                   method00 ( );
                   break;

                case 1:
                   method01 ( );
                   break;

                case 2:
                   method02 ( );
                   break;

                case 3:
                   method03 ( );
                   break;

                case 4:
                   method04 ( );
                   break;

                case 5:
                   method05 ( );
                   break;

                case 6:
                   method06 ( );
                   break;

                case 7:
                   method07 ( );
                   break;

                case 8:
                   method08 ( );
                   break;

                case 9:
                   method09 ( );
                   break;

                case 10:
                   method10 ( );
                   break;
               
               default:
                   cout << endl << "ERRO: Valor invalido!" << endl;
                   break;
               } // end switch

       } while ( x != 0 );
    
    // encerrar
       pause ( "Apertar ENTER para terminar" );
       return ( 0 );
       
} // end main ( )


/*

---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

Ira' ler de DADOS1.TXT o arranjo gerado randomicamente
e mostrar na tela:

Original

  0 :        41
  1 :        85
  2 :        72
  3 :        38
  4 :        80
  5 :        69
  6 :        65
  7 :        68
  8 :        96
  9 :        22

Em seguida, utilizando as funcoes "decrescente" (definida no ed11) e
"ordenarDecrescente", sera' ordenado o arranjo.

Decrescente

  0 :        96
  1 :        85
  2 :        80
  3 :        72
  4 :        69
  5 :        68
  6 :        65
  7 :        41
  8 :        38
  9 :        22

Para testes, foram utilizados arquivos com quantidades diferentes de
termos fora da ordem. Alem disso, um contador e um getchar para ter controle
de cada uma das trocas.

---------------------------------------------- historico

Versao          Data          Modificacao
0.1             24/06         esboco

---------------------------------------------- testes

Versao       Teste
0.1          01.(OK)           identificacao de programa, ordenando arranjo

*/