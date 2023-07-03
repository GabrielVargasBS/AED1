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
      cout << "\nExercicio0208 - Method01 - v0.0\n" << endl;
   
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
      cout << "\nExercicio0208 - Method02 - v0.0\n" << endl;
   
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
      cout << "\nExercicio0208 - Method03 - v0.0\n" << endl;
   
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
      cout << "\nExercicio0208 - Method04 - v0.0\n" << endl;
   
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
  Method05 - Converter arranjo binario lido de cadeia de caracteres
             para numero decimal
 */

void method05 ( )
{  
   // definir dado
      Array <int> array1 ( 80, 0 );

   // identificar
      cout << "\nExercicio0205 - Method05 - v0.0\n" << endl;
   
   // ler arranjo
      array1 = array1.freadBinario ( "BINARIOS1.TXT" );
      cout << "\nArranjo gerado: "<< endl;
      array1.print ( );

   // obter valor decimal
      cout << "\nNumero em decimal = " << array1.paraDecimal ( ) << endl;

   // reciclar espaco
      array1.free ( );
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method05 ( )
/**
  Method06 - Ler matriz de arquivo e formata-la como tridiagonal crescente
 */

void method06 ( )
{  
   // definir dados
      Matrix <int> matriz ( 1, 1, 0 );
      int n = 0;

   // identificar
      cout << endl << "Exercicio0208 - Method06 - v0.0" << endl;
      
   // ler matriz de arquivo
      matriz.fread ( "MATRIZ1.TXT" );
      // matriz.fread ( "MATRIZ_1.TXT" );
      cout << "Matriz original" << endl;
      matriz.print ( );
   
   // ler novas dimensoes
      cout << endl << "Entre com a nova dimensao da matriz quadrada: ";
      cin >> n;
   
   // verificar se valor valido
      while ( n <= 1 || n > matriz.getRows( ) || n > matriz.getColumns( ) )
      {
          cout << endl << "ERRO: Dimensao Invalida!" << endl;
          cout << endl << "Entre com a nova dimensao da matriz quadrada: ";
          cin >> n;   
      } // end while

   // formatar matriz
      matriz.tridiagonalCrescente ( n );

   // mostrar dados
      cout << endl << "Tridiagonal crescente" << endl;
      matriz.print  ( );
      matriz.fprint ( "MATRIZ2.TXT" );

   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method06 ( )

/**
  Method07 - Ler matriz de arquivo e formata-la como tridiagonal decrescente
 */

void method07 ( )
{  
   // definir dados
      Matrix <int> matriz ( 1, 1, 0 );
      int n = 0;

   // identificar
      cout << endl << "Exercicio0208 - Method07 - v0.0" << endl;
      
   // ler matriz de arquivo
      matriz.fread ( "MATRIZ1.TXT" );
      // matriz.fread ( "MATRIZ_1.TXT" );
      cout << "Matriz original" << endl;
      matriz.print ( );
   
   // ler novas dimensoes
      cout << endl << "Entre com a nova dimensao da matriz quadrada: ";
      cin >> n;
   
   // verificar se valor valido
      while ( n <= 1 || n > matriz.getRows( ) || n > matriz.getColumns( ) )
      {
          cout << endl << "ERRO: Dimensao Invalida!" << endl;
          cout << endl << "Entre com a nova dimensao da matriz quadrada: ";
          cin >> n;   
      } // end while

   // formatar matriz
      matriz.tridiagonalDecrescente ( n );

   // mostrar dados
      cout << endl << "Tridiagonal decrescente" << endl;
      matriz.print  ( );
      matriz.fprint ( "MATRIZ2a.TXT" );

   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method07 ( )

/**
  Method08 - Testar se matriz apresenta caracteristica de potencias por linha.
 */

void method08 ( )
{  
   // definir dados
      Matrix <int> matriz1 ( 1, 1, 0 );
      Matrix <int> matriz2 ( 1, 1, 0 );

   // identificar
      cout << endl << "Exercicio0208 - Method08 - v0.0" << endl;
      
   // ler matriz de arquivo
      matriz1.fread ( "MATRIZ3.TXT" );
      cout << "\nMatriz_1" << endl;
      matriz1.print ( );

   // realizar teste de potencias por linha
      cout << endl << "Potencias por linha = " << matriz1.potenciaPorLinha( ) << endl;

   // ler matriz de arquivo
      matriz1.fread ( "MATRIZ1.TXT" );
      cout << "\nMatriz_2" << endl;
      matriz1.print ( );

   // realizar teste de potencias por linha
      cout << endl << "Potencias por linha = " << matriz2.potenciaPorLinha( ) << endl;

   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method08 ( )

/**
 Method09 - 
 */

void method09 ( )
{  
   // identificar
      cout << endl << "Exercicio0208 - Method09 - v0.0" << endl;
      
   // encerrar
      pause ( "Apertar ENTER para continuar" );

} // end method09 ( )

/**
 Method10 - 
 */

void method10 ( )
{  
   // identificar
      cout << endl << "Exercicio0208 - Method10 - v0.0" << endl;
      
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
               cout << "\nExercicio0208 - Programa - v0.0\n      " << endl;

            // mostrar opcoes
               cout << "Opcoes                                   " << endl;
               cout << "0  - parar                               " << endl;
               cout << "1  - ordenar arranjo decrescentemente    " << endl;
               cout << "2  - inverter arranjo lido de arquivo    " << endl;
               cout << "3  - procurar segundo menor valor        " << endl;
               cout << "4  - filtrar elementos de arranjos       " << endl;
               cout << "5  - converter arranjo binario em decimal" << endl;
               cout << "6  - matriz em tridiagonal crescente     " << endl;
               cout << "7  - matriz em tridiagonal decrescente   " << endl;
               cout << "8  - teste matriz potencias por linha    " << endl;
            // cout << "9  -                                     " << endl;
            // cout << "10 -                                     " << endl;

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

Ira' ler matriz de MATRIZ3.TXT:

Matriz_1

1       1       1       1      
1       2       4       8      
1       3       9       27     
1       4       16      64     


Potencias por linha = 1

Depois, ira' ler matriz de MATRIZ1.TXT:

Matriz_2

1       2       3       4
5       6       7       8
9       10      11      12
13      14      15      16


Potencias por linha = 0


---------------------------------------------- historico

Versao          Data          Modificacao
0.8             24/06         esboco

---------------------------------------------- testes

Versao       Teste
0.1          01.(OK)           identificacao de programa, ordenando  arranjo
0.2          01.(OK)           identificacao de programa, invertendo arranjo
0.3          01.(OK)           identificacao de programa, procurando menor
0.4          01.(OK)           identificacao de programa, filtrando elementos
0.5          01.(OK)           identificacao de programa, convertendo binario
0.6          01.(OK)           identificacao de programa, trigonal   crescente
0.7          01.(OK)           identificacao de programa, trigonal decrescente
0.8          01.(OK)           identificacao de programa, potencias por linha

*/