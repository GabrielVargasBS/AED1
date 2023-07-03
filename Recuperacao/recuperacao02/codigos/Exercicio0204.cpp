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
      cout << "\nExercicio0204 - Method01 - v0.0\n" << endl;
   
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
  Method02 - Inverter ordem de arranjo lido de arquivo
 */

void method02 ( )
{  
   // definir dado
      Array <int> array ( 10, 0 );

   // identificar
      cout << "\nExercicio0204 - Method02 - v0.0\n" << endl;
   
   // ler arranjo
      array.fread ( "DECRESCENTE.TXT" );
      
   // mostrar dados
      cout << "Original" << endl;
      array.print ( );
   
   // ordenar
      array = array.inverter( array );

   // mostrar dados
      cout << "Invertido" << endl;
      array.print  ( );
      array.fprint ( "INVERTIDOS.TXT" );

   // reciclar espaco
      array.free ( );

   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method02 ( )

/**
  Method03 - Encontrar segundo menor valor de arranjo
 */

void method03 ( )
{  
   // definir dado
      Array <int> array ( 10, 0 );

   // identificar
      cout << "\nExercicio0204 - Method03 - v0.0\n" << endl;
   
   // ler arranjo
      array.fread ( "DADOS1.TXT" );

   // mostrar segundo menor
      cout << "Segundo menor = " << array.menor( array, array.acharMenor( ) ) << endl;

   // reciclar espaco
      array.free ( );

   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method03 ( )

/**
  Method04 - Mostrar elementos comuns aos dois arranjos
             ( considerando que nao ha repeticao de elementos entre si )
             gravar quantidade de elementos exclusivos de algum arranjo
 */

void method04 ( )
{  
   // definir dado
      Array <int> array1 ( 10, 0 );
      Array <int> array2 ( 15, 0 );
      int result = 0;

      ofstream afile; afile.open ( "FILTRADOS.TXT" );

   // identificar
      cout << "\nExercicio0204 - Method04 - v0.0\n" << endl;
   
   // ler arranjo
      array1.fread ( "DADOS1.TXT" );
      array2.fread ( "DADOS2.TXT" );

   // filtrar
      cout << "Dados em comum: " << endl;
      result = array1.filtrar( array1, array2 );
   
   // mostrar e gravar resultado
      cout << "\nDados unicos = " << result << endl;
      afile << result << endl;
   
   // fechar arquivo
      afile.close ( );

   // reciclar espaco
      array1.free ( );
      array2.free ( );

   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method04 ( )

/**
  Method05 - 
 */

void method05 ( )
{  
   // identificar
      cout << endl << "Exercicio0204 - Method05 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method05 ( )

/**
  Method06 - 
 */

void method06 ( )
{  
   // identificar
      cout << endl << "Exercicio0204 - Method06 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method06 ( )

/**
  Method07 - 
 */

void method07 ( )
{  
   // identificar
      cout << endl << "Exercicio0204 - Method07 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method07 ( )

/**
  Method08 - 
 */

void method08 ( )
{  
   // identificar
      cout << endl << "Exercicio0204 - Method08 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method08 ( )

/**
 Method09 - 
 */

void method09 ( )
{  
   // identificar
      cout << endl << "Exercicio0204 - Method09 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method09 ( )

/**
 Method10 - 
 */

void method10 ( )
{  
   // identificar
      cout << endl << "Exercicio0204 - Method10 - v0.0" << endl;
      
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
               cout << "\nExercicio0204 - Programa - v0.0\n       " << endl;

            // mostrar opcoes
               cout << "Opcoes                                  " << endl;
               cout << "0  - parar                              " << endl;
               cout << "1  - ordenar arranjo decrescentemente   " << endl;
               cout << "2  - inverter arranjo lido de arquivo   " << endl;
               cout << "3  - procurar segundo menor valor       " << endl;
               cout << "4  - filtrar elementos de arranjos      " << endl;
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

Ira' ler de DADOS1.TXT e DADOS2.TXT os arranjos gravados

10
41
85
72
38
80
69
65
68
96
22


15
1
2
41
3
72
4
38
5
80
6
7
8
68
96
22


Arranjo1 com 10 elementos
Arranjo2 com 15 elementos

Em comum, ha' 7 elementos que pertencem a ambos
Logo, 3 do primeiro e 8 do segundo sao dados unicos = 11

*Esta funcao serve apenas para arranjos que, seguramente, nao repetem
seus elemetos. Ou seja, por exemplo, caso o arranjo1 apresentasse duas
vezes o numero 41, a contagem seria errada e, em "Dados em comum", repetiria
o 41. Caso o arranjo2 fosse formado apenas por 41, tambem daria erro, pois
apontaria o 41 como unico dado em comum, uma unica vez, e os outros elementos
nao entrariam para a conta.


Saida:

Dados em comum: 
41
72
38
80
68
96
22

Dados unicos = 11
---------------------------------------------- historico

Versao          Data          Modificacao
0.4             24/06         esboco

---------------------------------------------- testes

Versao       Teste
0.1          01.(OK)           identificacao de programa, ordenando  arranjo
0.2          01.(OK)           identificacao de programa, invertendo arranjo
0.3          01.(OK)           identificacao de programa, procurando menor
0.4          01.(OK)           identificacao de programa, filtrando elementos

*/