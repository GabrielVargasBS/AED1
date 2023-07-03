/*
Exercicio03 - v0.0. - 09 / 05 / 2022
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
 Funcao para determinar se caractere e' operador logico & | !
 @return true, se for; false, caso contrario
 @param x - valor a ser testado
 */

bool eOperadorLogico ( char x )
{
   // definir dado local
      bool result  = false;

   // testar a condicao
      if ( ( x == '&') ||
           ( x == '|') ||
           ( x == '!') )         
      {
         result = true;
      } // end if

      return ( result );

} // end eOperadorLogico ( )

/**
 Funcao para determinar se caractere e' operador aritmrtico + - * / % 
 @return true, se for; false, caso contrario
 @param x - valor a ser testado
 */

bool eOperadorAritmetico ( char x )
{
   // definir dado local
      bool result  = false;

   // testar a condicao
      if ( ( x == '+') ||
           ( x == '-') ||
           ( x == '*') ||
           ( x == '/') ||
           ( x == '%') )         
      {
         result = true;
      } // end if

      return ( result );

} // end eOperadorAritmetico ( )

/**
 Funcao para determinar se caractere e' operador relacional > < =
 @return true, se for; false, caso contrario
 @param x - valor a ser testado
 */

bool eOperadorRelacional ( char x )
{
   // definir dado local
      bool result  = false;

   // testar a condicao
      if ( ( x == '<') ||
           ( x == '>') ||
           ( x == '=') )         
      {
         result = true;
      } // end if

      return ( result );

} // end eOperadorAritmetico ( )

/**
 Funcao para determinar se caractere e' separador (espaço, ponto, vírgula, ponto-e-vírgula, dois-pontos, sublinha, hifen)
 @return true, se for; false, caso contrario
 @param x - valor a ser testado
 */

bool eSeparador ( char x )
{
   // definir dado local
      bool result  = false;

   // testar a condicao
      if ( ( x == ' ') ||
           ( x == '.') ||
           ( x == ',') ||
           ( x == ';') ||
           ( x == ':') ||
           ( x == '_') )         
      {
         result = true;
      } // end if

      return ( result );

} // end eSeparador ( )

/**
 Funcao para determinar se caractere e' ( ) [ ] { }
 @return true, se for; false, caso contrario
 @param x - valor a ser testado
 */

bool eSeparadorDuplo ( char x )
{
   // definir dado local
      bool result  = false;

   // testar a condicao
      if ( ( x == '(') ||
           ( x == ')') ||
           ( x == '[') ||
           ( x == ']') ||
           ( x == '{') ||
           ( x == '}') )         
      {
         result = true;
      } // end if

      return ( result );

} // end eSeparadorDuplo ( )

/**
 Funcao para determinar se caractere e' letra.
 @return true, se letrs; false, se nao letra
 @param x - valor a ser testado
 */

bool eLetra ( char x )
{
   // definir dado local
      bool result = false;

   // testar a condicao
      if ( ( 'a' <= x && x <= 'z' ) || ( 'A' <= x && x <= 'Z' ) )
      {
         result = true;
      } // end if

      return ( result );

} // end eLetra ( )

/**
 Funcao para determinar se caractere e' digito.
 @return true, se digito; false, caso contrario
 @param x - valor a ser testado
 */

bool eDigito ( char x )
{
   // definir dado local
      bool result = false;

   // testar a condicao
      if ( '0' <= x && x <= '9' )
      {
         result = true;
      } // end if

      return ( result );

} // end eDigito ( )

/**
 qualSimbolo - Procedimento para ler cadeia de caracteres do teclado
               e dizer a que classe cada caractere pertece
 */

void qualSimbolo ( )
{
    // definir dados
       chars text = IO_new_chars ( STR_EMPTY );
       strcpy ( text, STR_EMPTY );

       int  tamanho = 0;
       char simbolo = '@';

    // ler um valor inteiro do teclado
       text    = IO_readln ( "Entre com uma cadeia de caracteres: " );
    
    // calcular tamanho da cadeia
       tamanho = strlen ( text );

    // pausar
       IO_pause ( "Aperte ENTER para obter os resultados" );
       IO_printf ( "Resultados:\n");

    // repetir para tamanho calculado
       if ( tamanho > 0 )
       {
           for ( int i = 0; i < tamanho; i = i+1)
           {
               // separar caractere
                  simbolo = text[i];

               // testar caracteres
                  if ( eOperadorLogico (simbolo) )
                  {
                      IO_printf ( "[%2d]: \"%c\"\t Caractere: OPERADOR LOGICO\n", i, simbolo );
                  } // end if

                  else
                  if ( eOperadorAritmetico (simbolo) )
                  {
                      IO_printf ( "[%2d]: \"%c\"\t Caractere: OPERADOR ARITMETICO\n", i, simbolo );
                  } // end if

                  else
                  if ( eOperadorRelacional (simbolo) )
                  {
                      IO_printf ( "[%2d]: \"%c\"\t Caractere: OPERADOR RELACIONAL\n", i, simbolo );
                  } // end if

                  else
                  if ( eSeparador (simbolo) )
                  {
                      IO_printf ( "[%2d]: \"%c\"\t Caractere: SEPARADOR\n", i, simbolo );
                  } // end if

                  else
                  if ( eSeparadorDuplo (simbolo) )
                  {
                      IO_printf ( "[%2d]: \"%c\"\t Caractere: SEPARADOR DUPLO\n", i, simbolo );
                  } // end if

                  else
                  if ( eLetra (simbolo) )
                  {
                      IO_printf ( "[%2d]: \"%c\"\t Caractere: LETRA\n", i, simbolo );
                  } // end if

                  else
                  if ( eDigito (simbolo) )
                  {
                      IO_printf ( "[%2d]: \"%c\"\t Caractere: DIGITO\n", i, simbolo );
                  } // end if
                  
                  else
                     IO_printf ( "[%2d]: \"%c\"\t Caractere: TIPO ESPECIAL\n", i, simbolo );

           } // end for
        } // end if
        else
        {
            IO_printf ( "\nERRO: Cadeia Invalida!" );
        } // end else

} // end qualSimbolo ( )

/**
 Method03 - Ler cadeia de caracteres e 
            classificar cada caractere
 */

void method03 ( )
{  
    // identificar
       IO_id ( "Exercicio03 - Method03 - v0.0" );
    
    // chamar procedimento auxiliar
       qualSimbolo ( );
       
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
               IO_println ( "1 - ler (n) numeros e mostrar os seus divisores          " );
               IO_println ( "2 - ler (n) numeros e dizer se e' primo                  " );
               IO_println ( "3 - ler cadeia de caracteres e classificar cada caractere" );
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

Cadeia de teste:

ABCdefUVWxyz0123456789&!|+-*%/><= .;,:_{}[]()@#$§

Resultado:
[ 0]: "A"        Caractere: LETRA
[ 1]: "B"        Caractere: LETRA
[ 2]: "C"        Caractere: LETRA
[ 3]: "d"        Caractere: LETRA
[ 4]: "e"        Caractere: LETRA
[ 5]: "f"        Caractere: LETRA
[ 6]: "U"        Caractere: LETRA
[ 7]: "V"        Caractere: LETRA
[ 8]: "W"        Caractere: LETRA
[ 9]: "x"        Caractere: LETRA
[10]: "y"        Caractere: LETRA
[11]: "z"        Caractere: LETRA
[12]: "0"        Caractere: DIGITO
[13]: "1"        Caractere: DIGITO
[14]: "2"        Caractere: DIGITO
[15]: "3"        Caractere: DIGITO
[16]: "4"        Caractere: DIGITO
[17]: "5"        Caractere: DIGITO
[18]: "6"        Caractere: DIGITO
[19]: "7"        Caractere: DIGITO
[20]: "8"        Caractere: DIGITO
[21]: "9"        Caractere: DIGITO
[22]: "&"        Caractere: OPERADOR LOGICO
[23]: "!"        Caractere: OPERADOR LOGICO
[24]: "|"        Caractere: OPERADOR LOGICO
[25]: "+"        Caractere: OPERADOR ARITMETICO
[26]: "-"        Caractere: OPERADOR ARITMETICO
[27]: "*"        Caractere: OPERADOR ARITMETICO
[28]: "%"        Caractere: OPERADOR ARITMETICO
[29]: "/"        Caractere: OPERADOR ARITMETICO
[30]: ">"        Caractere: OPERADOR RELACIONAL
[31]: "<"        Caractere: OPERADOR RELACIONAL
[32]: "="        Caractere: OPERADOR RELACIONAL
[33]: " "        Caractere: SEPARADOR
[34]: "."        Caractere: SEPARADOR
[35]: ";"        Caractere: SEPARADOR
[36]: ","        Caractere: SEPARADOR
[37]: ":"        Caractere: SEPARADOR
[38]: "_"        Caractere: SEPARADOR
[39]: "{"        Caractere: SEPARADOR DUPLO
[40]: "}"        Caractere: SEPARADOR DUPLO
[41]: "["        Caractere: SEPARADOR DUPLO
[42]: "]"        Caractere: SEPARADOR DUPLO
[43]: "("        Caractere: SEPARADOR DUPLO
[44]: ")"        Caractere: SEPARADOR DUPLO
[45]: "@"        Caractere: TIPO ESPECIAL
[46]: "#"        Caractere: TIPO ESPECIAL
[47]: "$"        Caractere: TIPO ESPECIAL
[48]: "§"        Caractere: TIPO ESPECIAL


    // repetir para tamanho calculado
       if ( tamanho > 0 )
       {
           for ( int i = 0; i < tamanho; i = i+1)
           {
               // separar caractere
                  simbolo = text[i];

               // testar caracteres
                  if ( eOperadorLogico (simbolo) )
                  {
                      IO_printf ( "[%2d]: \"%c\"\t Caractere: OPERADOR LOGICO\n", i, simbolo );
                  } // end if (operador logico)

                  else
                  {
                     if ( eOperadorAritmetico (simbolo) )
                     {
                        IO_printf ( "[%2d]: \"%c\"\t Caractere: OPERADOR ARITMETICO\n", i, simbolo );
                     } // end if (operador aritmetico)

                     else
                     {
                        if ( eOperadorRelacional (simbolo) )
                        {
                           IO_printf ( "[%2d]: \"%c\"\t Caractere: OPERADOR RELACIONAL\n", i, simbolo );
                        } // end if (operador relacional)

                        else
                        {
                           if ( eSeparador (simbolo) )
                           {
                              IO_printf ( "[%2d]: \"%c\"\t Caractere: SEPARADOR\n", i, simbolo );
                           } // end if (separador)

                           else
                           {
                              if ( eSeparadorDuplo (simbolo) )
                              {
                                 IO_printf ( "[%2d]: \"%c\"\t Caractere: SEPARADOR DUPLO\n", i, simbolo );
                              } // end if (separador duplo)

                              else
                              {
                                 if ( eLetra (simbolo) )
                                 {
                                    IO_printf ( "[%2d]: \"%c\"\t Caractere: LETRA\n", i, simbolo );
                                 } // end if (letra)

                                 else
                                 {
                                    if ( eDigito (simbolo) )
                                    {
                                       IO_printf ( "[%2d]: \"%c\"\t Caractere: DIGITO\n", i, simbolo );
                                    } // end if (digito)

                                    else
                                    {
                                       IO_printf ( "[%2d]: \"%c\"\t Caractere: TIPO ESPECIAL\n", i, simbolo );
                                    } // end else (nao: digito)
                                 } // end else (nao: letra)
                              } // end else (nao: separador duplo)
                           } // end else (nao: separador)
                        } // end else (nao: operador relacional)
                     } // end else (nao: operador aritmetico)
                  } // end else (nao: operador logico)
           } // end for
        } // end if
        else
        {
            IO_printf ( "\nERRO: Cadeia Invalida!" );
        } // end else

*/
  
