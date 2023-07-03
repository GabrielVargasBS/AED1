/*
Prova02 - v0.0. - 21 / 06 / 2022
Author: Gabriel Vargas Bento de Souza
*/

// dependencias
   #include "io.h"

/**
 Method00 - Nao faz nada.
 */

void method00 ( )
{
    // nao faz nada
} // end method00 ( )

/**
 Method01 - Verificar saida esperada.
 */

void method01 ( )
{
     // identificar
       IO_id ( "Prova02 - Questao01" );

    // definir dados
       int array[ ] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
       int x = 0;
       int y = 0;
       int z = 0;

    // alterar ordem arranjo
       for ( x = 3; x < 7; x = x+1 )
       {
          z = array[x];
          for ( y = x; y < 10; y = y+1 )
          {
             array[ y ] = array[y+1];
          } // end for
          array[y-1] = z;
       } // end for

    // mostrar novo arranjo
       for ( x = 0; x < 10; x = x+1 )
       {
          printf ( "%d ", array[x] );
       }

    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method01 ( )

/**
 Method02 - Verificar saida esperada.
 */

void method02 ( )
{
    // identificar
       IO_id ( "Prova02 - Questao02" );
       
    // definir dados
       int array[ ][3] = { {0, 1, 2},
                           {3, 4, 5},
                           {6, 7, 8} };
       int x = 0;
       int y = 0;
       int z = 0;

    // alterar ordem arranjo
       for ( x = 0; x < 3; x = x+1 )
       {
          z = array[2-x][2-x];
          for ( y = 2; y >= 0; y = y-1 )
          {
             array[y][x] = array[x][y];
             if ( x == y )
             {
                array[x][y] = z;
             } // end if
          } // end for
       } // end for

    // mostrar nova matriz
       for ( x = 0; x < 3; x = x+1 )
       {
          for ( y = 0; y < 3; y = y+1 )
          {
             printf ( "%d\t", array[x][y] );
          } // end for
          printf ( "\n" );
       } // end for
       
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method02 ( )

char* substring ( int start, int end, char* source )
{
   // definir dados
      char *destiny = NULL;
      int   x       = 0;
      int   y       = 0;

   // alocar espaco
      destiny = malloc ( strlen(source) * sizeof(char) );
      destiny[0] = '\0';

   // copiar nova palavra
      for ( x = start; x < end; x = x+1 )
      {
         destiny[y] = source[x];
         y = y+1;
      } // end for
   
   // retornar palavra
      return ( destiny );
} // end substring ( )

/**
 Method03 - Verificar saida correta esperada.
 */

void method03 ( )
{
    // identificar
       IO_id ( "Prova02 - Questao03" );
       
    // chamar funcao auxiliar
       printf ( "%s\n", substring ( 1, 4, "abcde" ) );
       printf ( "%s\n", substring ( 4, 6, "abcde" ) ); // unica com o '\0'
       printf ( "%s\n", substring ( 0, 3, "abcde" ) );
       printf ( "%s\n", substring ( 3, 5, "abcde" ) );
       
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method03 ( )

int f04 ( int x, char *s )
{
   // definir dados
      int result = 0;
   
   // verificar condicao
      if ( 0 <= x && x < strlen (s) )
      {
         result = ( s[x] == '0' || s[x] == '1' ) && f04 ( x+1, s );
      } // end if

      else
      {
         result = 1;
      } // end else
   
   // retornar resultado
      return ( result );
} // end f04 ( )

/**
 Method04 - Verificar saida FALSA esperada.
 */

void method04 ( )
{
    // identificar
       IO_id ( "Prova02 - Questao04" );
       
    // chamar funcao auxiliar
       printf ( "Result = %d\n", f04 ( 3, "01|O" ) );
       printf ( "Result = %d\n", f04 ( 2, "0|10" ) );
       printf ( "Result = %d\n", f04 ( 1, "O101" ) );
       printf ( "Result = %d\n", f04 ( 0, "0101" ) );
       
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method04 ( )

int f05 ( char *s1, char *s2 )
{
   // definir dados
      int result = 0;
      int x      = 0;
      int y      = 0;
      int z      = 0;
   
   // verificar condicao
      for ( x = 0; x < strlen(s1); x = x+1 )
      {
         for ( y = 1; y < strlen(s2); y = y+1 )
         {
            if ( s1[x] == s2[y] )
            {
               z = z+1;
               y = strlen(s2);
            } // end if
         } // end for
      } // end for
   
   // obter resultado
      result = ( z == strlen(s1) );
   
   // retornar resultado
      return ( result );
} // end f05 ( )

/**
 Method05 - Verificar saida VERDADEIRA esperada.
 */

void method05 ( )
{
    // identificar
       IO_id ( "Prova02 - Questao05" );

    // chamar funcao auxiliar
       printf ( "Result = %d\n", f05 ( "alice"  , "celia"   ) );
       printf ( "Result = %d\n", f05 ( "aroma"  , "amora"   ) );
       printf ( "Result = %d\n", f05 ( "pato"   , "apto"    ) );
       printf ( "Result = %d\n", f05 ( "alegria", "galeria" ) );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );
       
} // end method05 ( )

struct s_ac
{
   int  a;
   char c;
}; // end struct

/**
 Method06 - Verificar saida esperada.
 */

void method06 ( )
{
    // definir dados
       struct s_ac s [5];
       int         x = 0;
       int         y = 0;

    // identificar
       IO_id ( "Prova02 - Questao06" );
       
    // popular struct
       for ( x = 0; x < 5; x = x+1 )
       {
          s[x].a = x;
          s[x].c = (char)( 'A' + x );
       } // end for

    // mostrar resultados
       while ( x > 0 )
       {
          y = 5;
          while ( y > 0 )
          {
             if ( x-1 == s[y-1].a )
             {
                printf ( "%d%c", s[y-1].a, s[y-1].c );
                y = 0;
             } // end if
             y = y-2;
          } // end while
          x = x-1;
       } // end while
           
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method06 ( )

int f07 ( char *s )
{
   // definir dados
      int achar = 0;
      int x     = 0;
   
   // verificar do uso de hifen
      for ( x = 0; x < strlen(s); x = x+1 )
      {
         if ( s[x] == '-' )
         {
            if (    0 <= x && x < strlen(s) && 
                 (( s[x-1] == s[x+1]        && 
                    s[x+1] == 'r'     )     || 
                  ( s[x-1] == 'i'    ))      )
            {
               achar = 1;
            } // end if
         } // end if
      } // end for
   
   // retornar resultado
      return ( achar );

} // end f07 ( )

/**
 Method07 - Verificar saida FALSA esperada.
 */

void method07 ( )
{
    // identificar
       IO_id ( "Prova02 - Questao07" );
       
    // chamar funcao auxiliar
       printf ( "Result = %d\n", f07 ( "anti-horario"      ) );
       printf ( "Result = %d\n", f07 ( "inter-relacao"     ) );
       printf ( "Result = %d\n", f07 ( "super-homem"       ) );
       printf ( "Result = %d\n", f07 ( "anti-inflamatorio" ) );
       
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method07 ( )

/**
 writeDoubles    - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x        - quantidade de valores
*/

void writeDoubles ( chars fileName, int x )
{
   // definir dados
      FILE* arquivo = fopen ( fileName, "wt" );
      int   y       = 0;

   // gravar quantidade de valores
   // IO_fprintf ( arquivo, "%d\n", x );
   
   // repetir para a quantidade de dados
      for ( y = 1; y <= x; y = y + 1 )
      {
         // gravar valor
            IO_fprintf ( arquivo, "%lf\n", (0.1*y) );
      } // end for

   // fechar arquivo (INDISPENSAVEL para gravacao)
      fclose ( arquivo );

} // end writeDoubles ( )

/**
 media - Procedimento para receber nome de arquivo e, caso tenha qtd impar de
         numeros reais, acrescentar media de tres termos ao final
 @param fileName - nome do arquivo
 */

void media ( char *fileName )
{
   // definir dados
      FILE*  arquivo = fopen ( fileName, "rt" );
      double x       = 0.0;
      int    i       = 0;
      double media   = 0.0;

   // ler arquivo (arriscar primeira leitura)   
      fscanf ( arquivo, "%lf", &x );

   // repetir enquanto nao chegou ao fim
      while ( !( feof (arquivo ) ) )
      {
         i = i+1;
         fscanf ( arquivo, "%lf", &x );
      } // end while
   
   // fechar arquivo
      fclose ( arquivo );
   
   // testar se quantidade de dados e' impar
   // e ha, no minimo, tres termos
      if ( i % 2 != 0 && i >= 3)
      {
         // abrir arquivo novamente
            FILE*  arquiv = fopen ( fileName, "rt" );
            double a = 0.0;
            double b  =0.0;
         
         // ler primeira linha do arquivo
            fscanf ( arquiv, "%lf", &a );

         // ler proximas ate' o valor do meio
            for ( int k = 0; k < i/2; k = k+1 )
            {
               // obter valor do meio
                  fscanf ( arquiv, "%lf", &b );
            } // end for
         
         // fechar arquivo
            fclose ( arquiv );

         // abrir arquivo novamente para adicionar media
            FILE*  arq = fopen ( fileName, "at" );
         
         // obter media
            printf ( "x = %lf\n", x );
            printf ( "a = %lf\n", a );
            printf ( "b = %lf\n", b );

            media = ( ( x + a + b ) / 3.0 );
            fprintf ( arq, "%lf", media );

         // fechar arquivo
            fclose ( arq );

         // mensagem de gravacao
            printf ( "\nArquivo salvo com sucesso!\n" );
      } // end if

      else
      {
         // mensagem de erro
            printf ( "\nERRO: Numero de dados invalido!\n" );
      } // end else

} // end media ( )

/**
 Method08 - Salvar media em arquivo
 */

void method08 ( )
{
    // identificar
       IO_id ( "Prova02 - Questao08" );
    
    // criar arquivo
       writeDoubles ( "DADOS.TXT", 9 );
       
    // chamar funcao auxiliar
       media  ( "DADOS.TXT" );

    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method08 ( )

/**
 somarMatrix     - Funcao para receber matriz inteira e retornar razao entre:
                   soma dos termos abaixo da diagonal secundaria e
                   soma dos termos acima da diagonal principal menos um
 @param matrix   - matriz inteira
 @param rows     - numero de linhas
 @param columns  - numero de colunas
 */

double somarMatrix ( int rows, int columns, int matrix[][columns] )
{
   // definir dados
      int soma1     = 0;
      int soma2     = 0;
      double result = 0.0;

   // testar se matriz e' quadrada e dimensoes validas
      if ( rows == columns && rows > 0 )
      {
         // obter dados da matriz
            for ( int x = 0; x < rows; x = x+1 )
            {
               for ( int y = 0; y < columns; y = y+1 )
               {
                  // testar se abaixo da diagonal secundaria
                     if ( x+y >= columns )
                     {
                        soma1 = soma1 + matrix[x][y];
                     } // end if
                  
                  // teste se acima da diagonal principal
                     if ( y > x )
                     {
                        soma2 = soma2 + matrix[x][y];
                     } // end if
               } // end for
            } // end for
         
         // obter resposta
            soma2 = soma2 - 1;

            printf ( "\nAbaixo diagonal secundaria  = %d", soma1 );
            printf ( "\nAcima diagonal principal -1 = %d", soma2 );

            if ( soma2 != 0 )
            {
               result = ( (1.0 * soma1) / (1.0 * soma2) );
            } // end if
            else
            {
               printf ( "\nERRO: Soma invalida!\n" );
            } // end else
      } // end if

      else
      {
         printf ( "ERRO: Matrix invalida!" );
      } // end else
   
   // retornar soma
      return ( result );

} // end somarMatrix ( )

/**
 Method09 - Obter soma solicitada dos elementos da matriz
 */

void method09 ( )
{
    // definir dado
       int matrix[ ][3] = { {0, 1, 2},
                            {3, 4, 5},
                            {6, 7, 8} };

    // identificar
       IO_id ( "Prova02 - Questao09" );

    // mostrar matriz
       printf ( "Matriz\n" );
       for ( int x = 0; x < 3; x = x+1 )
       {
          for ( int y = 0; y < 3; y = y+1 )
          {
             printf ( "%d\t", matrix[x][y] );
          } // end for
          printf ( "\n" );
       } // end for

    // mostrar resultado
       printf ( "\n\nRazao = %lf", somarMatrix ( 3, 3, matrix ) );
           
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method09 ( )

/**
 troca    - Procedimento para receber dois valores inteiros passados por
            referencia e, caso primeiros maior que segundo, trocar de
            variaveis
 @param x - primeiro valor
 @param y - segundo valor
*/

void troca ( int *x, int *y )
{
   // definir dados
      int a = *x;
      int b = *y;

   // verificar troca
      if ( a > b )
      {
         *x = b;
         *y = a;
      } // end if

} // end troca ( )

/**
 Method10 - Trocar variaveis passadas por referencia.
 */

void method10 ( )
{
    // definir dado
       int *x = 10;
       int *y = 5;

    // identificar
       IO_id ( "Prova02 - Questao10" );
    
    // mostrar valor atual
       printf ( "\nAntes:\n" );
       printf ( "x = %d\n", x );
       printf ( "y = %d\n", y ); 
    
    // chamar procedimento auxiliar
       troca ( &x, &y );

    // mostrar novo valor
       printf ( "\nDepois:\n" );
       printf ( "x = %d\n", x );
       printf ( "y = %d\n", y ); 
           
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method10 ( )

/**
 Method11 - Default
 */

void method11 ( )
{
    IO_pause ( "ERRO: Valor invalido!" );

} // end method10 ( )

/*
 Funcao principal.
 @return codigo de encerramento
*/

int main ( )
{
    // definir dado
       int x = 0;

    // repetir ate desejar parar
       do
       {
            // identificar
               IO_id ( "Prova AED1 - Programa - v0.0" );

            // ler do teclado
               IO_println ( "Opcoes:" );
               IO_println ( "0  - parar" );
               IO_println ( "1  - questao 1 " );
               IO_println ( "2  - questao 2 " );
               IO_println ( "3  - questao 3 " );
               IO_println ( "4  - questao 4 " );
               IO_println ( "5  - questao 5 " );
               IO_println ( "6  - questao 6 " );
               IO_println ( "7  - questao 7 " );
               IO_println ( "8  - questao 8 " );
               IO_println ( "9  - questao 9 " );
               IO_println ( "10 - questao 10" );
               IO_println ( " " );

               x =  IO_readint ( "Entrar com uma opcao: " );

            // testar valor
               switch ( x )
               {
                  case 0 : method00 ( ); break;
                  case 1 : method01 ( ); break;
                  case 2 : method02 ( ); break;
                  case 3 : method03 ( ); break;
                  case 4 : method04 ( ); break;
                  case 5 : method05 ( ); break;
                  case 6 : method06 ( ); break;
                  case 7 : method07 ( ); break;
                  case 8 : method08 ( ); break;
                  case 9 : method09 ( ); break;
                  case 10: method10 ( ); break;
                  default: method11 ( ); break;

               } // end switch

       } while ( x != 0 );

    // encerrar
       IO_pause ( "Apertar ENTER para terminar" );
       return ( 0 );

} // end main ( )

/*
 ----------------------------- documentacao complementar
 ----------------------------- notas / observacoes / comentarios
 ----------------------------- previsao de testes
------------------------------ testes
*/
