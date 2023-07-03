/*
Exercicio01 - v0.0. - 09 / 05 / 2022
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
 Method02 - 
 */

void method02 ( )
{  
    // identificar
       IO_id ( "Exercicio01 - Method02 - v0.0" );

    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method02 ( )

/**
 Method03 - 
 */

void method03 ( )
{  
    // identificar
       IO_id ( "Exercicio01 - Method03 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method03 ( )

/**
 Method04 - 
 */

void method04 ( )
{  
    // identificar
       IO_id ( "Exercicio01 - Method04 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method04 ( )

/**
 Method05 - 
 */

void method05 ( )
{  
    // identificar
       IO_id ( "Exercicio01 - Method05 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method05 ( )

/**
 Method06 - 
 */

void method06 ( )
{  
    // identificar
       IO_id ( "Exercicio01 - Method06 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method06 ( )

/**
 Method07 - 
 */

void method07 ( )
{  
    // identificar
       IO_id ( "Exercicio01 - Method07 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method07 ( )

/**
 Method08 - 
 */

void method08 ( )
{  
    // identificar
       IO_id ( "Exercicio01 - Method08 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method08 ( )

/**
 Method09 - 
 */

void method09 ( )
{  
    // identificar
       IO_id ( "Exercicio01 - Method09 - v0.0" );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method09 ( )

/**
 Method10 - 
 */

void method10 ( )
{  
    // identificar
       IO_id ( "Exercicio01 - Method10 - v0.0" );
       
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
               // IO_println ( "2 - " );
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



Para os valores inteiros, cujos divisores serao calculados:
a.) 0
b.) -22
c.) -121
d.) -1

Ira' solicitar, em seguida, novo valor



a.) quantidade = 1
numero  = { 12 }

Divisores de  12:   1   2   3   4   6  12



b.) quantidade = 2
numeros = { 1, 36 }

Divisores de   1:   1
Divisores de  36:   1   2   3   4   6   9  12  18  36



c.) quantidade = 5
numeros =  { 22, 121, 440, 581, 814 }

Divisores de  22:   1   2  11  22
Divisores de 121:   1  11 121
Divisores de 440:   1   2   4   5   8  10  11  20  22  40  44  55  88 110 220 440
Divisores de 581:   1   7  83 581
Divisores de 814:   1   2  11  22  37  74 407 814

*/
  
