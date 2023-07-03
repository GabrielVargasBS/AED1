/*
Prova01 - v0.0. - 03 / 05 / 2022
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
 Method01 - Encontrar formato em desaordo com resultado.
 */

void method01 ( )
{
     // identificar
       IO_id ( "Prova01 - Questao01" );

    // definir dados
       bool   b = false;
       double d = 0.0;
       char   c = '0';
       int    x = 0;

    // valores
       b = ( x <=  5 ) && ( d <= 1/2 );
       d = ( 7/8 + (int) (double) 3/4);
       c = (char) (((int) '0'+1 ) -48);
       x = (int) (M_PI * 1.0) / 3;

    // resultados
       IO_printf ( "\n b = %d", b );       // 1
       IO_printf ( "\n c = %d", c );       // 1
       IO_printf ( "\n d = %d", (int) d ); // 0
       IO_printf ( "\n x = %d", x );       // 1

    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method01 ( )

/**
 Method02 - Verificar saida esperada.
 */

void method02 ( )
{
    // identificar
       IO_id ( "Prova01 - Questao02" );
       
    // definir dados
       int x = 0;
       int y = 0;
       int n = 5;

    // valores
       y = n*(n+1)/2+1;

    // resultados
       for ( x=1; x<=n; x=x+1 )
       {
          y = y-x;
          IO_printf ( " %d", y );
       } // end for
       
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method02 ( )

/**
 Method03 - Encontrar duas funcoes para obter mesmo resultado (numeros impares).
 */

void method03 ( )
{
    // identificar
       IO_id ( "Prova01 - Questao03" );
       
    // definir dados
       int x = 0;
       
    // resultados
       for ( x=1; x<=5; x=x+1 )
       {
          IO_printf ( "\nx = %d", 2*x-1 );
       } // end for
       
       IO_printf ( "\n" );
       
       for ( x=1; x<=5*3; x=x+3 )
       {
           IO_printf ( "\nx = %d", x-x/3 );
       } // end for
       
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method03 ( )

/**
 Method04 - Verificar saida esperada.
 */

void method04 ( )
{
    // identificar
       IO_id ( "Prova01 - Questao04" );
       
    // definir dados
       int a     = 10;
       int b     = 20;
       int c     = 30;
       int maior = 0;
       
    // resultados
       if      ( c > b > a || c > a > b) {maior = c;}
       else if ( b > c > a || b > a > c) {maior = b;}
       else if ( a > b > c || a > c > b) {maior = a;}
       IO_printf ( "\nMaior = %d ", maior );
       
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method14 ( )

/**
 Method05 - Encontrar saida esperada.
 */

void method05 ( )
{
    // identificar
       IO_id ( "Prova01 - Questao05" );

    // declarar valores
       int x = 0;
       int y = 0;
       
    // resultados
       for ( x=1; x<=5; x=x+1 )
       {
         for (y=(x+1)/3; y>0; y = y - 1 ) { printf ( " " ); }
         for (y=1; y<=x/2+1;  y = y + 1 ) { printf ( "%d ", y ); }
         printf ("\n");
       } // end for
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );
       
} // end method05 ( )

/**
 mercosul - Funcao para determinar se placa e' do modelo mercosul.
 @return true, se for; false, caso contrario
 @param text - placa a ser testada
 */

 bool mercosul ( chars text )
 {
        // definir dados
           bool resultado = false;
           int  tamanho   = strlen (text);

        // verificar tamanho da placa
           if ( tamanho == 7 )
           {
               // verificar caracteres
                  if ( ( text[3] >= '0' && text[3] <= '9') &&
                       ( text[5] >= '0' && text[5] <= '9') &&
                       ( text[6] >= '0' && text[6] <= '9') &&
                       ( text[0] >= 'A' && text[0] <= 'Z') &&
                       ( text[1] >= 'A' && text[1] <= 'Z') &&
                       ( text[2] >= 'A' && text[2] <= 'Z') &&
                       ( text[4] >= 'A' && text[4] <= 'Z')  )
                  { 
                       // mudar resultado
                          resultado = true;
                  } // end if
           } // end if

        // retornar resultado
           return ( resultado );

 } // end mercosul ( )

/**
 Method06 - Ler uma placa e dizer se ela pertence ao padrao mercosul.
 */

void method06 ( )
{
    // definir dados
       bool  resultado = 0;
       chars text = IO_new_chars (STR_SIZE);

    // identificar
       IO_id ( "Prova01 - Questao06a" );
       
    // ler do teclado
       text = IO_readstring ( "Utilizando numeros e letras maiusculas, entre com uma placa: " );

    // chamar funcao
       resultado = mercosul ( text );

    // mostrar resultado
       if ( resultado == false)
       {
           IO_printf ( "\nA placa [%s] nao pertence ao formato mercosul", text );
       } // end if
       else
       {
           IO_printf ( "\nA placa [%s] pertence ao formato mercosul", text );
       } // end else
           
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method06 ( )

/**
 Method07 - Ler varias placas ate' encontrar a 00000000 e
            contar quantas atendem ao padrao Mercosul
 */

void method07 ( )
{
    // definir dados
       chars placa = IO_new_chars (STR_SIZE);
       int   total = 0;

    // identificar
       IO_id ( "Prova01 - Questao06b" );
       
    // ler do teclado
       placa = IO_readstring ( "Entre com uma placa  : " );

    // testar placa
       while ( strcmp ("0000000", placa ) != 0 )
       {
           // mostrar placa e resultado teste
              IO_printf ( "Placa = [%7s]\tTeste = [%1d]\n", placa, mercosul (placa) );
           
           // testar se placa pertence ao padrao
              if ( mercosul (placa) )
              {
                  // contar 
                     total = total + 1;
              } // end if
          
          // ler nova placa
             placa = IO_readstring ( "\nEntre com outra placa: " );
       } // end while
    
    // mostrar total de placas mercosul
       IO_printf ( "\nTotal de placas Mercosul = %d", total );

    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method07 ( )

/**
 isArmstrong - Funcao para determinar se valor e' Numero de Armstrong
 @return true, se for; false, caso contrario
 @param n        - numero a ser testado
 @param potencia - quantidade de digitos do numero
 */

 bool isArmstrong ( int n )
 {
        // definir dados
           int    numero   = 0;
           int    copia1   = 0; // copiar para salvar numero de entrada
           double tamanho  = 0.0;
           int    copia2   = 0; // copiar para salvar tamanho palavra (valor inteiro)
           int    resto    = 0;
           double soma     = 0.0;
           bool   resposta = false;
        
        // copiar numero
           copia1 = n;
           numero = n;

        // obter tamanho do numero
           do
           {
               // dividir por multiplos de dez ate' zerar o resto
                  tamanho = tamanho + 1.0;
                  resto   = copia1 % (int) pow ( 10.0, tamanho );
           } while ( resto != n );
           //IO_printf ("\ntamanho = %lf", tamanho );
           
        // copiar tamanho
           copia2 = (int) tamanho;
           //IO_printf ("\ntamanhocopia = %d", copia2 );

        // verificar se valor e' Armstrong
           if ( n == 1 )  // definir para 1
           {
               // definir para numero = 0
                  resposta = true;
           } // end if

           if ( n > 1 )
           {
               // separar digitos do numero e somar valores
                  for ( int x = 0; tamanho > x; x = x + 1 )
                  {
                      // separar
                         copia1 = copia1 % (int) pow ( 10.0, copia2-1 );
                         numero = numero / (int) pow ( 10.0, copia2-1 );
                         //IO_printf ( "\ncopia1 = %d", copia1);
                         //IO_printf ( "\nnumero = %d", numero);

                      // somar
                         soma   = soma + pow ( 1.0 * numero, tamanho );
                         //IO_printf ( "\nsoma = %lf", soma);

                      // passar ao proximo valor
                         numero = copia1;
                         copia2 = copia2-1;
                  } // end for
           } // end if

        // testar soma
           if ( soma == n )
           {
               resposta = true;
           } // end if

        // retornar resultado
           return ( resposta );

 } // end isArmstrong ( )

/**
 Method08 - Ler um numero e dizer se ele e' do tipo Armstrong
 */

void method08 ( )
{
    // definir dados
       bool resultado = 0;
       int  numero    = 0;

    // identificar
       IO_id ( "Prova01 - Questao07a" );
       
    // ler do teclado
       numero   = IO_readint ( "Entre com um numero: " );

    // chamar funcao
       resultado = isArmstrong ( numero );

    // mostrar resultado
       if ( resultado == false)
       {
           IO_printf ( "\nO numero [%d] nao e' Armstrong", numero );
       } // end if
       else
       {
           IO_printf ( "\nO numero [%d] e' Armstrong", numero );
       } // end else
           
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method08 ( )

/**
 countArmstrong - Funcao para contar e mostrar numeros de Armstrong no intervalo [0, 999]
 @return quantidade de numeros de Armstrong no intervalo
 */

 int countArmstrong ( void )
 {
    // definir dados
        int x        = 0;
        int contador = 0;

    // repetir
        for ( x = 0; x <= 999; x = x + 1 )
        {
            if ( isArmstrong (x) )
            {
                // mostrar
                    IO_printf ( "\nNumero = %d", x );

                // contar
                    contador = contador + 1;
            } // end if
        } // end for

    // retornar
       return ( contador );

 } // end countArmstrong ( )

/**
 Method09 - mostrar e contar os numeros de Armstrong pertencentes ao intervalo [0:999]
 */

void method09 ( )
{
    // definir dado
       int x  = 0;

    // identificar
       IO_id ( "Prova01 - Questao07b" );

    // chamar funcao
       x = countArmstrong ( );

    // mostrar quantidade
       IO_printf ( "\n\nHa' %d numeros de Armstrong no intervalo [0:999]", x );
           
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method09 ( )

/**
 somatorio_a - Funcao para somar as (n) primeiras fracoes da sequencia:
               1/1 + 1/3 - 1/2 + 1/5 + 1/7 - 1/4 + ...
 @return soma das fracoes
 @param n - quantidade de termos
 */

 double somatorio_a ( int n )
 {
        // definir dados
           double soma = 0.0;

        // somar fracoes
           if ( n == 1 )   // definir para n = 1
           {
               soma = soma + 1.0;
               // IO_printf ( "\nSoma = %lf", soma );
           } // end if
           
           else
           if ( n == 2 )   // definir para n = 2
           {
               soma = soma + 1.0 + 1.0/3.0;
               // IO_printf ( "\nSoma = %lf", soma );
           } // end if
           
           else
           if ( ( n >= 3 ) && ( n % 3 == 0 ) )
           {
               do
               {
                   // encontrar os numeros de posicoes: 3, 6, 9 ...
                      soma = soma - 1.0 / (1.0 * (  n  - (n/3) ) );
                      n = n-1;
                      // IO_printf ( "\nSoma = %lf", soma );

                   // encontrar os numeros de posicoes: 2, 5, 8 ...
                      soma = soma + 1.0 / (1.0 * ( n+1 + (n/3) ) );
                      n = n-1;
                      // IO_printf ( "\nSoma = %lf", soma );

                   // encontrar os numeros de posicoes: 1, 4, 7 ...
                      soma = soma + 1.0 / (1.0 * (  n  + (n/3) ) );
                      n = n-1;
                      // IO_printf ( "\nSoma = %lf", soma );
               } while ( n > 0 );              
           } // end if

           else
           if ( ( n >= 4 ) && ( (n-1) % 3 == 0 ) )
           {
               soma = soma + 1.0 / (1.0 * (  n  + (n/3) ) );
               n = n-1;
               // IO_printf ( "\nSoma = %lf", soma );

               do
               {
                   // encontrar os numeros de posicoes: 3, 6, 9 ...
                      soma = soma - 1.0 / (1.0 * (  n  - (n/3) ) );
                      n = n-1;
                      // IO_printf ( "\nSoma = %lf", soma );

                   // encontrar os numeros de posicoes: 2, 5, 8 ...
                      soma = soma + 1.0 / (1.0 * ( n+1 + (n/3) ) );
                      n = n-1;
                      // IO_printf ( "\nSoma = %lf", soma );

                   // encontrar os numeros de posicoes: 1, 4, 7 ...
                      soma = soma + 1.0 / (1.0 * (  n  + (n/3) ) );
                      n = n-1;
                      /// IO_printf ( "\nSoma = %lf", soma );
               } while ( n > 0 ); 
           } // end if
           
           else
           if ( ( n >= 5 ) && ( (n-2) % 3 == 0 ) )
           {
               soma = soma + 1.0 / (1.0 * ( n+1 + (n/3) ) );
               n = n-1;
               soma = soma + 1.0 / (1.0 * (  n  + (n/3) ) );
               n = n-1;
               // IO_printf ( "\nSoma = %lf", soma );

               do
               {
                   // encontrar os numeros de posicoes: 3, 6, 9 ...
                      soma = soma - 1.0 / (1.0 * (  n  - (n/3) ) );
                      n = n-1;
                      // IO_printf ( "\nSoma = %lf", soma );

                   // encontrar os numeros de posicoes: 2, 5, 8 ...
                      soma = soma + 1.0 / (1.0 * ( n+1 + (n/3) ) );
                      n = n-1;
                      // IO_printf ( "\nSoma = %lf", soma );

                   // encontrar os numeros de posicoes: 1, 4, 7 ...
                      soma = soma + 1.0 / (1.0 * (  n  + (n/3) ) );
                      n = n-1;
                      // IO_printf ( "\nSoma = %lf", soma );
               } while ( n > 0 ); 
           }

        // retornar resultado
           return ( soma );

 } // end somatorio_a ( )

/**
 somatorio_b - Funcao para somar as (n) primeiras fracoes da sequencia:
               1/1 + 1/3 - 1/2 + 1/5 + 1/7 - 1/4 + ...
 @return soma das fracoes
 @param n - quantidade de termos
 */

 double somatorio_b ( int n )
 {
   // definir dados
      double soma  =  0.0;
      double impar =  1.0;
      double par   = -2.0;

   // somar fracoes
      for ( int x=1; x<=n; x=x+1 )
      {
         if ( x % 3 != 0 )
         {
            soma  = soma  + 1.0 / impar; 
            impar = impar + 2.0;
         } // end if

         else
         {
            soma = soma + 1.0 / par; 
            par  = par  - 2.0;
         } // end else
      } // end for
           
   // retornar resultado
      return ( soma );

 } // end somatorio_b ( )

/**
 Method10 - somar (n) primeiras fracoes da sequencia: 1/1 + 1/3 - 1/2 + 1/5 + 1/7 - 1/4 + ...
 */

void method10 ( )
{
    // definir dado
       int    n = 0;
       double x = 0.0;
       double y = 0.0;

    // identificar
       IO_id ( "Prova01 - Questao08a" );
    
    // ler do teclado
       n = IO_readint ( "Entre com a quantidade de termos: " );
    
    // testar quantidade 
       while ( n <= 0 )
       {
           IO_printf ( "ERRO: valor invalido!" );
           n = IO_readint ( "\n\nEntre com a quantidade de termos: " );
       } // end while

    // chamar funcoes (ambas obtem o mesmo resultado)
       x = somatorio_a ( n );
       y = somatorio_b ( n );    // melhor alternativa

    // mostrar soma 
       IO_printf ( "\nA soma para %d termos e' %lf", n, x );
       IO_printf ( "\nA soma para %d termos e' %lf", n, y );
           
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method10 ( )

/**
 Method11 - calcular, para os (k) primeiros valores naturais,
            as respectivas somas de suas fracoes
 */

void method11 ( )
{
    // definir dados
       int    k      = 0;
       int    contar = 0;
       double soma   = 0.0;

    // identificar
       IO_id ( "Prova01 - Questao08b" );
       
    // ler do teclado
       k = IO_readint ( "Entre com a quantidade de termos: " );
    
    // testar quantidade 
       while ( k <= 0 )
       {
           IO_printf ( "ERRO: valor invalido!" );
           k = IO_readint ( "\n\nEntre com a quantidade de termos: " );
       } // end while

    // repetir
       soma = somatorio_b ( k );
    
    // mostrar soma
       IO_printf ( "\nA soma para os %d primeiros valores naturais e' = %lf", k, soma );

    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method11 ( )

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
               IO_println ( "1  - questao 1  " );
               IO_println ( "2  - questao 2  " );
               IO_println ( "3  - questao 3  " );
               IO_println ( "4  - questao 4  " );
               IO_println ( "5  - questao 5  " );
               IO_println ( "6  - questao 6a " );
               IO_println ( "7  - questao 6b " );
               IO_println ( "8  - questao 7a " );
               IO_println ( "9  - questao 7b " );
               IO_println ( "10 - questao 8a " );
               IO_println ( "11 - questao 8b " );
               IO_println ( " " );

               x =  IO_readint ( "Entrar com uma opcao: " );

            // testar valor
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
                
                case 11:
                   method11 ( );
                   break;

               default:
                   IO_pause ( "ERRO: Valor invalido!" );
                   break;
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
