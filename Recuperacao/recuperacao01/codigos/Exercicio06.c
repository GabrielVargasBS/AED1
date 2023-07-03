/*
Exercicio06 - v0.0. - 12 / 05 / 2022
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

       int tamanho = 0;
       char simbolo = '@';

    // ler um valor inteiro do teclado
       text = IO_readln ( "Entre com uma cadeia de caracteres: " );
    
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
 Funcao para determinar se caractere e' letra maiuscula.
 @return true, se maiuscula; false, se nao maiuscula
 @param x - valor a ser testado
 */

bool isUpperCase ( char x )
{
   // definir dado local
      bool result = false;

   // testar a condicao
      if ( 'A' <= x && x <= 'Z' )
      {
         result = true;
      } // end if

      return ( result );

} // end isUpperCase ( )

/**
 Funcao para determinar se caractere e' letra minuscula.
 @return true, se minuscula; false, se nao minuscula
 @param x - valor a ser testado
 */

bool isLowerCase ( char x )
{
   // definir dado local
      bool result = false;

   // testar a condicao
      if ( 'a' <= x && x <= 'z' )
      {
         result = true;
      } // end if

      return ( result );

} // end isLowerCase ( )

/**
 contarSimbolos - Procedimento para ler cadeia de caracteres do teclado
                  e contar quantidade de caracteres de cada classe
 */

void contarSimbolos ( )
{
    // definir dados
       chars text = IO_new_chars ( STR_EMPTY );
       strcpy ( text, STR_EMPTY );

       int tamanho = 0;
       char simbolo = '@';

       // contadores
          int op = 0;
          int oa = 0;
          int or = 0;
          int s  = 0;
          int sd = 0;
          int lc = 0;
          int uc = 0;
          int d  = 0;
          int e  = 0;

    // ler um valor inteiro do teclado
       text = IO_readln ( "Entre com uma cadeia de caracteres: " );
    
    // calcular tamanho da cadeia
       tamanho = strlen ( text );

    // pausar
       IO_pause ( "Aperte ENTER para obter os resultados" );

    // repetir para tamanho calculado
       if ( tamanho > 0 )
       {
           for ( int i = 0; i < tamanho; i = i+1)
           {
               // separar caractere
                  simbolo = text[i];

               // testar caracteres
                  if ( eOperadorLogico (simbolo) )     { op = op+1; } // end if

                  else
                  if ( eOperadorAritmetico (simbolo) ) { oa = oa+1; } // end if

                  else
                  if ( eOperadorRelacional (simbolo) ) { or = or+1; } // end if

                  else
                  if ( eSeparador (simbolo) )          { s  = s +1; } // end if

                  else
                  if ( eSeparadorDuplo (simbolo) )     { sd = sd+1; } // end if

                  else
                  if ( isLowerCase (simbolo) )         { lc = lc+1; } // end if
                  
                  else
                  if ( isUpperCase (simbolo) )         { uc = uc+1; } // end if

                  else
                  if ( eDigito (simbolo) )             { d  = d +1; } // end if
                  
                  else                                 { e  = e +1; } // end if
           } // end for
        } // end if
        else
        {
            IO_printf ( "\nERRO: Cadeia Invalida!" );
        } // end else
    
    // mostrar quantidade
       IO_printf ( "Cadeia lida: \"%s\"\n", text );
       IO_printf ( "\nResultados:\n");

       if ( d  != 0 ) {IO_printf ( "\nDigitos               : %2d", d  );}
       if ( s  != 0 ) {IO_printf ( "\nSeparadores           : %2d", s  );}
       if ( uc != 0 ) {IO_printf ( "\nLetras Maiusculas     : %2d", uc );}
       if ( lc != 0 ) {IO_printf ( "\nLetras Minusculas     : %2d", lc );}
       if ( sd != 0 ) {IO_printf ( "\nSeparadores Duplos    : %2d", sd );}
       if ( op != 0 ) {IO_printf ( "\nOperadores Logicos    : %2d", op );}
       if ( e  != 0 ) {IO_printf ( "\nCaracteres Especiais  : %2d", e  );}
       if ( oa != 0 ) {IO_printf ( "\nOperadores Aritmeticos: %2d", oa );}
       if ( or != 0 ) {IO_printf ( "\nOperadores Relacionais: %2d", or );}

} // end contarSimbolos ( )

/**
 Method04 - Ler cadeia de caracteres e 
            contar cada tipo de caractere
 */

void method04 ( )
{  
    // identificar
       IO_id ( "Exercicio04 - Method04 - v0.0" );
    
    // chamar procedimento auxiliar
       contarSimbolos ( );
       
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method04 ( )

/**
 Funcao para calcular a media de (n) valores dentro de um vetor
 @return media
 @param i     - tamanho do vetor
 @param soma  - vetor
 */

double obterMedia ( int i, double soma )
{
   // definir dado local
      double media = 0.0;

   // obter media
      if ( i !=  0) 
      {
          media = soma / (1.0*i); 
      } // end if

   // retornar media
      return ( media );

} // end obterMedia ( )

/**
 Funcao para calcular o maior valor real entre 3
 @return maior valor
 @param a - valor a ser testado 1
 @param b - valor a ser testado 2
 @param c - valor a ser testado 3
 */

double obterMaior ( double a, double b, double c )
{
   // definir dado local
      double maior = 0.0;

   // atribuir um dos valores
      if      ( c > b && b > a || c > a && a >= b) {maior = c;}
      else if ( b > c && c > a || b > a && a >= c) {maior = b;}
      else if ( a > b && b > c || a > c && c >= b) {maior = a;}

   // retornar
      return ( maior );

} // end obterMaior ( )

/**
 media - Procedimento para ler (n) valores inteiros do teclado
         calcular a media para os valores:           x < -23.75
                                           -23.75 <= x <= 65.25
                                            65.25 <  x
         dizer qual media e' a maior de todas
 */

void media ( )
{
    // definir dados
       int    n       =  0;
       double x       =0.0;
       double maior   =0.0;

       // para menor que -23.75
          double sa      =0.0;
          int    ia      =  0;

       // para maior que 65.25
          double sb      =0.0;
          int    ib      =  0;

       // para [-23.75 ; 65.25]
          double sc      =0.0;
          int    ic      =  0;

    // ler um valor inteiro do teclado
       n = IO_readint ( "Entre com uma quantidade: " );

    // testar se valor e' positivo
       while ( n <= 0 )
       {
           IO_println ( "ERRO: Valor invalido!" );
           n = IO_readint ( "\nEntre com uma quantidade positiva: " );
       } // end while

    // repetir para a quantidade de vezes informada
       for ( int i = 1; i <= n; i = i+1 )
       {
           // ler valor do teclado
              x = IO_readdouble ( IO_concat ( IO_toString_d ( i ), ": ") );

           // somar valores
              if       ( x < -23.75 ) { sa = sa + x; ia = ia + 1; }
              else if  ( x >  65.25 ) { sb = sb + x; ib = ib + 1; }
                   else               { sc = sc + x; ic = ic + 1; }
       } // end for

    // pausar
       IO_pause ( "Aperte ENTER para obter resultado" );
       IO_printf ( "Resultados:\n" );

    // obter medias
       if ( ia != 0 ) { IO_printf ( "\nMedia para x < -23.75       = %lf", obterMedia(ia, sa) );}
       else             IO_printf ( "\nMedia para x < -23.75       = null" );

       if ( ic != 0 ) { IO_printf ( "\nMedia para x [-23.75;65.25] = %lf", obterMedia(ic, sc) );}
       else             IO_printf ( "\nMedia para x [-23.75;65.25] = null" );

       if ( ib != 0 ) { IO_printf ( "\nMedia para x >  65.25       = %lf", obterMedia(ib, sb) );}
       else             IO_printf ( "\nMedia para x >  65.25       = null" );

    // mostrar maior valor 
    // a media nunca sera superior ao maior valor da sequencia
       if       ( sb != 0 ) { IO_printf ( "\n\nA maior media e' para valores > 65.25             " );}
       else if  ( sa == 0 ) { IO_printf ( "\n\nA maior media e' para valores entre [-23.75;65.25]" );}
            else            { IO_printf ( "\n\nA maior media e' para valores < -23.75            " );}
} // end media ( )

/**
 Method05 - Ler (n) valores reais
            agrupar em 3 casos
            calcular a media de cada um
            dizer qual media e' a maior
 */

void method05 ( )
{  
    // identificar
       IO_id ( "Exercicio05 - Method05 - v0.0" );
    
    // chamar procedimento auxiliar
       media ( );
       
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method05 ( )

/**
 Funcao para determinar se valor inteiro pertence a intervalo aberto.
 @return true, se pertencer; false, caso contrario
 @param x        - valor a ser testado
 @param inferior - limite inferior
 @param superior - limite superior
 */

bool pertenceAoIntervalo ( int x, int inferior, int superior )
{
    // definir dado local
       bool result = false;

    // testar a condicao
       if ( ( inferior < x ) && ( x < superior ) )
       {
           result = true;
       } // end if

       return ( result );
} // end pertenceAoIntervalo ( )

/**
 Funcao para determinar se valor inteiro e' impar.
 @return true, se impar; false, se par
 @param x - valor a ser testado
 */

bool impar ( int x )
{
   // definir dado local
      bool result = false;

   // testar a condicao
      if ( x % 2 != 0 )
      {
         result = true;
      } // end if

      return ( result );

} // end impar ( )

/**
 somaInversos - Procedimento para ler dois valores do teclado,
                delimitar um intervalo aberto deles
                ler numeros inteiros ate' obter o -1
                calcular a spma dos cubos dos inversos dos impares
 */

void somaInversos ( )
{
    // definir dados
       int    a    = 0;
       int    b    = 0;
       int    x    = 0;
       int    i    = 0;
       double soma = 0.0;

    // ler um valor inteiro do teclado para intervalo
       a = IO_readint ( "Entre com valor para limite inferior: " );
       b = IO_readint ( "Entre com valor para limite superior: " );

    // testar se valor intervalo e' valido
       while ( a >= b )
       {
           IO_println     ( "\nERRO: Intervalo invalido!\n" );
           a = IO_readint ( "Entre com valor para limite inferior: " );
           b = IO_readint ( "Entre com valor para limite superior: " );
       } // end while

    // ler numeros
       IO_println ( "\nDigite os numeros (entre com \"-1\" para PARAR):\n" );

    // repetir ate' ler o valor -1
       do 
       {
           // ler valor do teclado
              x = IO_readint ( IO_concat ( IO_toString_d ( i ), ": ") );
           // testar se valor pertence ao intervalo e se e' impar
              if ( pertenceAoIntervalo ( x, a, b ) && impar ( x ) )
              {
                  // realizar a soma dos cubos dos inversos
                     soma = soma + pow ( 1.0*x, -3.0 );
              } // end if
           // passar ao proximo
              i = i+1;
       } while ( x != -1 );

    // mostrar soma
       IO_printf ( "\nA soma dos inversos dos cubos dos numero impares lidos = %lf\n", soma );
          
} // end somaInversos ( )

/**
 Method06 - Definir intervalo, 
            ler numeros e calcular soma de (1/x^3), se x impar
 */

void method06 ( )
{  
    // identificar
       IO_id ( "Exercicio06 - Method06 - v0.0" );

    // chamar procedimento auxiliar
       somaInversos ( );

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
               IO_println ( "1 - ler (n) numeros e mostrar os seus divisores                          " );
               IO_println ( "2 - ler (n) numeros e dizer se e' primo                                  " );
               IO_println ( "3 - ler cadeia de caracteres e classificar cada caractere                " );
               IO_println ( "4 - ler cadeia de caracteres e contar cada tipo de caractere             " );
               IO_println ( "5 - ler e agrupar (n) numeros em 3 casos, dizer qual tem maior media     " );
               IO_println ( "6 - definir intervalo, ler numeros e calcular soma de (1/x^3), se x impar" );
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

Para intervalos inexistentes, serao solicitados novos valores!

a = 20
b = 60

Valores: -20, -11, 0, 1, 10, 21, 36, 51, 70, 80, -1

Valores que atendem 'as condicoes: 21, 51

Soma = 1/21^3 + 1/51^3 = 0.000115518

A soma dos inversos dos cubos dos numero impares lidos = 0.000116


a = -100
b = 100

Valores: -20, -11, 0, 1, 10, 21, 36, 51, 70, 80, -1

Valores que atendem 'as condicoes: 21, 51

Soma = 1/(-11^3) + 1/1^3 + 1/21^3 + 1/51^3 + 1/(-1^3) = 0.000635798

A soma dos inversos dos cubos dos numero impares lidos = 0.000636

a = 5
b = 15

Valores: -20, -11, 0, 1, 10, 21, 36, 51, 70, 80, -1

Valores que atendem 'as condicoes: { }

Soma = 0.000000

A soma dos inversos dos cubos dos numero impares lidos = 0.000000

*/
  
