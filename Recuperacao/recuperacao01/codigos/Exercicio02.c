/*
Exercicio02 - v0.0. - 09 / 05 / 2022
Author   : Gabriel Vargas Bento de Souza
Matricula: 778023
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
 divisores - Procedimento para ler (n) valores inteiros do teclado
             e dizer, para cada um, os seus divisores
 */

void divisores ( )
{
    // definir dados
       int n = 0;
       int x = 0;
       int i = 0;
       int array [80];

    // ler um valor inteiro do teclado
       n = IO_readint ( "Entre com uma quantidade: " );

    // testar se valor e' positivo
       while ( n <= 0 )
       {
           IO_println ( "ERRO: Valor invalido!" );
           n = IO_readint ( "\nEntre com uma quantidade positiva: " );
       } // end while

    // repetir para a quantidade de vezes informada
       do 
       {
           // ler valor do teclado
              x = IO_readint ( IO_concat ( IO_toString_d ( i ), ": ") );
           // testar se valor e' positivo
              while ( x <= 0 )
              {
                 IO_println ( " " );
                 IO_println ( "ERRO: Valor invalido! Entre com um numero positivo.\n" );
                 x = IO_readint ( IO_concat ( IO_toString_d ( i ), ": ") );
              } // end while
           // copiar para vetor
              array[i] = x;
           // passar ao proximo
              i = i+1;
       } while ( i < n );

    // pausar
       IO_pause ( "Aperte ENTER para mostrar os divisores" );

    // calcular divisores de cada numero lido
       for (int a = 0; a < n; a = a+1 )
       {
          // obter numero
             x = array[a];
             IO_printf ( "Divisores de %3d:", x );
          // calcular divisores
             for ( int b = 1; b <= x; b = b+1 )
             {
                if ( x % b == 0 )
                {
                   // mostrar divisor
                      IO_printf ( "%4d", b );
                } // end if
             } // end for
             // pular linha para o proximo
                IO_printf ( "\n");
       } // end for      
} // end divisores ( )

/**
 Method01 - Ler (n) numeros e mostrar seus divisores
 */

void method01 ( )
{
   // identificar
      IO_id ( "Exercicio01 - Method01 - v0.0" );
   
   // chamar procedimento auxiliar
      divisores ( );

   // encerrar
      IO_pause ( "Apertar ENTER para continuar" );

} // end method01 ( )

/**
 ePrimo - Procedimento para ler (n) valores inteiros do teclado
          e dizer, para cada um, se sao primos
 */

void ePrimo ( )
{
    // definir dados
       int n      = 0;
       int x      = 0;
       int i      = 0;
       int array [80];
       int cont   = 0;

    // ler um valor inteiro do teclado
       n = IO_readint ( "Entre com uma quantidade: " );

    // testar se valor e' positivo
       while ( n <= 0 )
       {
           IO_println ( "ERRO: Valor invalido!" );
           n = IO_readint ( "\nEntre com uma quantidade positiva: " );
       } // end while

    // repetir para a quantidade de vezes informada
       do 
       {
           // ler valor do teclado
              x = IO_readint ( IO_concat ( IO_toString_d ( i ), ": ") );
           // copiar para vetor
              array[i] = x;
           // passar ao proximo
              i = i+1;
       } while ( i < n );

    // pausar
       IO_pause ( "Aperte ENTER para obter os resultados" );
       IO_printf ( "Resultados:\n");

    // calcular divisores de cada numero lido
       for (int a = 0; a < n; a = a+1 )
       {
          // obter numero
             x = array[a];
             IO_printf ( "Numero = %4d", x );

          // considerar valores negativos
             if ( x < 0 )
             {
                 x = -x;
             } // end if
             
          // dividor valores
             for ( int b = 1; b <= x; b = b+1 )
             {
                if ( x % b == 0 )
                {
                   // contar divisores
                      cont = cont+1;
                } // end if
             } // end for

          // verificar se e' primo
             if ( cont == 2 )
             {
                IO_printf ( "\tprimo: SIM" );
             } // end if
             else
             {
                IO_printf ( "\tprimo: NAO" );
             } // end else

          // zerar contador
             cont = 0;
             
          // pular linha para o proximo
                IO_printf ( "\n");
       } // end for      
} // end ePrimo ( )

/**
 Method02 - ler (n) numeros e dizer se e' primo
 */

void method02 ( )
{  
    // identificar
       IO_id ( "Exercicio02 - Method02 - v0.0" );
       
    // chamar procedimento auxiliar
       ePrimo ( );

    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method02 ( )

/**
 Method03 - 
 */

void method03 ( )
{  
    // identificar
       IO_id ( "Exercicio03 - Method03 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method03 ( )

/**
 Method04 - 
 */

void method04 ( )
{  
    // identificar
       IO_id ( "Exercicio04 - Method04 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method04 ( )

/**
 Method05 - 
 */

void method05 ( )
{  
    // identificar
       IO_id ( "Exercicio05 - Method05 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method05 ( )

/**
 Method06 - 
 */

void method06 ( )
{  
    // identificar
       IO_id ( "Exercicio06 - Method06 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method06 ( )

/**
 Method07 - 
 */

void method07 ( )
{  
    // identificar
       IO_id ( "Exercicio07 - Method07 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method07 ( )

/**
 Method08 - 
 */

void method08 ( )
{  
    // identificar
       IO_id ( "Exercicio08 - Method08 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method08 ( )

/**
 Method09 - 
 */

void method09 ( )
{  
    // identificar
       IO_id ( "Exercicio09 - Method09 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method09 ( )

/**
 Method10 - 
 */

void method10 ( )
{  
    // identificar
       IO_id ( "Exercicio10 - Method10 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

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
               IO_id ( "Exercicio - Programa - v0.0" );

            // ler do teclado
               IO_println ( "Opcoes" );
               IO_println ( "0 - parar" );
               IO_println ( "1 - ler (n) numeros e mostrar os seus divisores " );
               IO_println ( "2 - ler (n) numeros e dizer se e' primo         " );
               // IO_println ( "3 - " );
               // IO_println ( "4 - " );
               // IO_println ( "5 - " );
               // IO_println ( "6 - " );
               // IO_println ( "7 - " );
               // IO_println ( "8 - " );
               // IO_println ( "9 - " );
               // IO_println ( "10 - " );
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
 ----------------------------- testes

Para a quantidade de termos:
a.) -1
b.)  0
c.) -3

Ira' solicitar, em seguida, novo valor


a.) quantidade = 1
numero  = { 7 }

Resultados:
Numero =    7   primo: SIM



b.) quantidade = 6
numeros = { -2, -1, 0, 1, 2, 3 }

Resultados:
Numero =   -2   primo: SIM
Numero =   -1   primo: NAO
Numero =    0   primo: NAO
Numero =    1   primo: NAO
Numero =    2   primo: SIM
Numero =    3   primo: SIM




c.) quantidade = 5
numeros =  { -293, -107, 153, 199, 811 }

Resultados:
Numero = -293   primo: SIM
Numero = -107   primo: SIM
Numero =  153   primo: NAO
Numero =  199   primo: SIM
Numero =  811   primo: SIM

*/
  
