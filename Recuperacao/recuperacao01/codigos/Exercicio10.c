/*
Exercicio09 - v0.0. - 12 / 05 / 2022
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

// funcao alterada no exercicio08, pois nao foi utilizada no exxercicio05
double obterMaior ( double a, double b, double c )
{
   // definir dado local
      double maior = 0.0;

   // atribuir o maior valor, mesmo sendo iguais
      if      ( c >= b && b >= a || c >= a && a >= b) {maior = c;}
      else if ( b >= c && c >= a || b >= a && a >= c) {maior = b;}
      else if ( a >= b && b >= c || a >= c && c >= b) {maior = a;}

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
 Funcao para determinar se valor real pertence a intervalo aberto.
 @return true, se pertencer; false, caso contrario
 @param x        - valor a ser testado
 @param inferior - limite inferior
 @param superior - limite superior
 */

bool pertenceAoIntervalo_real ( double x, double inferior, double superior )
{
    // definir dado local
       bool result = false;

    // testar a condicao
       if ( ( inferior < x ) && ( x < superior ) )
       {
           result = true;
       } // end if

       return ( result );
} // end pertenceAoIntervalo_real ( )

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
 porcentagem - Procedimento para ler dois valores reais do teclado,
                delimitar um intervalo aberto deles
                ler numeros reais ate' obter o 0.0
                separar os valores, dentro, acima e abaixo do intervalo
                calcular o percentual dos que estao acima e abaixo
 */

void porcentagem ( )
{
    // definir dados
       double a    = 0.0;
       double b    = 0.0;
       double x    = 0.0;
       int    i    = 0;
       int    in   = 0;
       int    up   = 0;
       int    down = 0;
       int    y    = 0;

    // ler um valor inteiro do teclado para intervalo
       a = IO_readdouble ( "Entre com valor para limite inferior: " );
       b = IO_readdouble ( "Entre com valor para limite superior: " );

    // testar se valor intervalo e' valido
       while ( a >= b )
       {
           IO_println        ( "\nERRO: Intervalo invalido!\n" );
           a = IO_readdouble ( "Entre com valor para limite inferior: " );
           b = IO_readdouble ( "Entre com valor para limite superior: " );
       } // end while

    // ler numeros
       IO_println ( "\nDigite os numeros (entre com \"0\" para PARAR):\n" );

    // repetir ate' ler o valor -1
       do 
       {
           // ler valor do teclado
              x = IO_readdouble ( IO_concat ( IO_toString_d ( i ), ": ") );
           // caso leia o zero, exclui-lo
              if ( x != 0.0 )
              {
                  // contar valores dentro do intervalo
                     if ( pertenceAoIntervalo_real ( x, a, b )) { in = in+1; }
                  // contar valores fora do intervalo (a cima e abaixo)
                     else if ( x >= b ) { up   = up  +1; }
                          else          { down = down+1; }
              } // end if
           // passar ao proximo
              i = i+1;
       } while ( x != 0.0 );

    // mostrar quantidade de valores dentro
       if ( in == 1) { IO_printf ( "\nHa' %d valor dentro do intervalo ]%lf ; %lf[",   in, a, b ); }
       else          { IO_printf ( "\nHa' %d valores dentro do intervalo ]%lf ; %lf[", in, a, b ); }

    // calcular porncentagem valores a cima e abaixo dos limites
       if ( up + down != 0 )
       {
           y = (int) 10000.0 * up / (up+down);
           IO_printf ( "\n\nDos %d valores fora do intervalo: ", up+down          );
           IO_printf ( "\n~ %.2lf %% sao maiores que %lf\n", 1.0*    y     / 100 , b );
           IO_printf (   "~ %.2lf %% sao menores que %lf\n", 1.0*(10000-y) / 100 , a );
       } // end if

       else IO_printf ( "\nHa' %d valores fora   do intervalo ]%lf ; %lf[\n", up+down, a, b );      
          
} // end porcentagem ( )

/**
 Method07 - Definir intervalo, 
            ler numeros e calcular porcentagem dos valores fora
 */

void method07 ( )
{  
    // identificar
       IO_id ( "Exercicio07 - Method07 - v0.0" );

    // chamar procedimento auxiliar
       porcentagem ( );
       
    // encerrar
       IO_pause ( "Apertar ENTER para continuar" );

} // end method07 ( )

/**
 Funcao para determinar se valores estao em ordem crescente
 @return true, se estiverem; false, caso contrario
 @param x - valor a ser testado
 @param y - valor a ser testado
 @param z - valor a ser testado
 */

bool crescente ( double x, double y, double z )
{
   // definir dado local
      bool result = false;

   // testar a condicao (se e somente se os 3 valores forem distintos)
      if ( x < y && y < z )
      {
          result = true;
      } // end if

      return ( result );

} // end crescente ( )

/**
 Funcao para determinar se valores estao em ordem decrescente
 @return true, se estiverem; false, caso contrario
 @param x - valor a ser testado
 @param y - valor a ser testado
 @param z - valor a ser testado
 */

bool decrescente ( double x, double y, double z )
{
   // definir dado local
      bool result = false;

   // testar a condicao (se e somente se os 3 valores forem distintos)
      if ( x > y && y > z )
      {
          result = true;
      } // end if

      return ( result );

} // end decrescente ( )

/**
 Funcao para calcular o menor valor real entre 3
 @return maior valor
 @param a - valor a ser testado 1
 @param b - valor a ser testado 2
 @param c - valor a ser testado 3
 */

double obterMenor ( double a, double b, double c )
{
   // definir dado local
      double menor = 0.0;

   // atribuir o menor valor, mesmo sendo iguais
      if      ( c <= b && b <= a || c <= a && a <= b) {menor = c;}
      else if ( b <= c && c <= a || b <= a && a <= c) {menor = b;}
      else if ( a <= b && b <= c || a <= c && c <= b) {menor = a;}

   // retornar
      return ( menor );

} // end obterMenor ( )

/**
 estaOrdenado - Procedimento para ler tres valores reais do teclado,
                dizer se estao ordenados
                caso contrario, mostrar o maior e o menor
 */

void estaOrdenado ( )
{
    // definir dados
       double x    = 0.0;
       double y    = 0.0;
       double z    = 0.0;

    // ler valores do teclado
       IO_println ( "Entre com tres numeros:" );
       x = IO_readdouble ( "1: " );
       y = IO_readdouble ( "2: " );
       z = IO_readdouble ( "3: " );

    // testar se valor esta' ordenado
       if ( crescente ( x, y, z ) )
       {
           IO_printf ( "\nOs valores estao em ordem crescente" );
       } // end if
       
       else
       {
           if ( decrescente ( x, y, z ) )
           {
               IO_printf ( "\nOs valores estao em ordem decrescente" );
           } // end if

           else
           {
               IO_println ( "\nOs valores nao sao difentes e/ou nao estao ordenados" );
               IO_printf ( "\nO maior numero e': %lf", obterMaior ( x, y, z ) );
               IO_printf ( "\nO menor numero e': %lf", obterMenor ( x, y, z ) );
           } // end else
       } // end else

} // end estaOrdenado ( )

/**
 Method08 - Ler 3 valores do teclado,
            dizer se esta ordenado ou 
            dizer o maior e o menor valor
 */

void method08 ( )
{  
    // identificar
       IO_id ( "Exercicio08 - Method08 - v0.0" );

    // chamar procedimento auxiliar
       estaOrdenado ( );
              
    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method08 ( )

/**
 estaOrdenado_char - Procedimento para ler tres caracteres do teclado,
                      dizer se estao ordenados
                      crescente ou decrescentemente
 */

void estaOrdenado_char ( )
{
    // definir dados
       char x  = '_';
       char y  = '_';
       char z  = '_';

    // ler valores do teclado
       IO_println ( "Entre com tres caracteres separadamente:" );
       x = IO_readchar ( "1: " );
       y = IO_readchar ( "2: " );
       z = IO_readchar ( "3: " );

    // testar se valor esta' ordenado
       if ( crescente ( (double)x, (double)y, (double)z ) )
       {
           IO_printf ( "\nOs caracteres estao em ordem crescente" );
       } // end if
       
       else
       {
           if ( decrescente ( (double)x, (double)y, (double)z ) )
           {
               IO_printf ( "\nOs caracteres estao em ordem decrescente" );
           } // end if

           else
           {
               IO_println ( "\nOs caracteres nao sao difentes e/ou nao estao ordenados pela tabela ASCII" );
           } // end else
       } // end else

} // end estaOrdenado_char ( )

/**
 Method09 - Ler 3 caracteres do teclado,
            dizer se esta ordenado ou nao
 */

void method09 ( )
{  
    // identificar
       IO_id ( "Exercicio09 - Method09 - v0.0" );

    // chamar procedimento auxiliar    
       estaOrdenado_char ( );

    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

} // end method09 ( )

/**
 Funcao para determinar se cadeia esta em ordem crescente
 @return true, se estiverem; false, caso contrario
 @param x - cadeia a ser testada
 @param y - cadeia a ser testada
 @param z - cadeia a ser testada
 */

bool crescente_chars ( chars x, chars y, chars z )
{
   // definir dado local
      bool result = false;

   // testar a condicao
      if ( strcmp ( x, y ) < 0 && strcmp ( y, z ) < 0)
      {
          result = true;
      } // end if

      return ( result );

} // end crescente_chars ( )

/**
 Funcao para determinar se valores estao em ordem decrescente
 @return true, se estiverem; false, caso contrario
 @param x - cadeia a ser testada
 @param y - cadeia a ser testada
 @param z - cadeia a ser testada
 */

bool decrescente_chars ( chars x, chars y, chars z )
{
   // definir dado local
      bool result = false;

   // testar a condicao
      if ( strcmp ( x, y ) > 0 && strcmp ( y, z ) > 0)
      {
          result = true;
      } // end if

      return ( result );

} // end decrescente_chars ( )

/**
 Funcao para calcular o cadeia de caracteres de menor valor
 @return maior valor
 @param a - cadeia de caracteres a ser testado 1
 @param b - cadeia de caracteres a ser testado 2
 @param c - cadeia de caracteres a ser testado 3
 */

chars obterMenor_chars ( chars a, chars b, chars c )
{
   // definir dadocadeia de caracteres 
      chars menor = IO_new_chars (STR_SIZE);
      strcpy ( menor, STR_EMPTY );


   // atribuir o menor valor, mesmo sendo iguais
      if ( (strcmp (c,b) <= 0 && strcmp (b,a) <= 0) || 
           (strcmp (c,a) <= 0 && strcmp (a,b) <= 0) )
        {
            strcpy ( menor, c );
        } // end if

      else
      if ( (strcmp (b,c) <= 0 && strcmp (c,a) <= 0) || 
            (strcmp (b,a) <= 0 && strcmp (a,c) <= 0) )
        {
            strcpy ( menor, b );
        } // end if

       else
       if ( (strcmp (a,b) <= 0 && strcmp (b,c) <= 0) || 
            (strcmp (a,c) <= 0 && strcmp (c,b) <= 0) )
        {
            strcpy ( menor, a );
        } // end if

   // retornar
      return ( menor );

} // end obterMenor_chars ( )

/**
 Funcao para calcular o cadeia de caracteres de maior valor
 @return maior valor
 @param a - cadeia de caracteres a ser testado 1
 @param b - cadeia de caracteres a ser testado 2
 @param c - cadeia de caracteres a ser testado 3
 */

chars obterMaior_chars ( chars a, chars b, chars c )
{
   // definir dadocadeia de caracteres 
      chars maior = IO_new_chars (STR_SIZE);
      strcpy ( maior, STR_EMPTY );


   // atribuir o menor valor, mesmo sendo iguais
      if ( (strcmp (c,b) >= 0 && strcmp (b,a) >= 0) || 
           (strcmp (c,a) >= 0 && strcmp (a,b) >= 0) )
        {
            strcpy ( maior, c );
        } // end i

      else
      if ( (strcmp (b,c) >= 0 && strcmp (c,a) >= 0) || 
           (strcmp (b,a) >= 0 && strcmp (a,c) >= 0) )
        {
            strcpy ( maior, b );
        } // end if

       else
       if ( (strcmp (a,b) >= 0 && strcmp (b,c) >= 0) || 
            (strcmp (a,c) >= 0 && strcmp (c,b) >= 0) )
        {
            strcpy ( maior, a );
        } // end if

   // retornar
      return ( maior );

} // end obterMaior_chars ( )

/**
 estaOrdenado_chars - Procedimento para ler tres cadeias de caracteres,
                      dizer se estao ordenados
                      crescente ou decrescentemente
 */

void estaOrdenado_chars ( )
{
    // definir dados
       chars x  = IO_new_chars (STR_SIZE);
       chars y  = IO_new_chars (STR_SIZE);
       chars z  = IO_new_chars (STR_SIZE);

       strcpy ( x, STR_EMPTY );
       strcpy ( y, STR_EMPTY );
       strcpy ( z, STR_EMPTY );

    // ler valores do teclado
       IO_println ( "Entre com tres cadeias de caracteres:" );
       x = IO_readstring ( "1: " );
       y = IO_readstring ( "2: " );
       z = IO_readstring ( "3: " );

    // testar se valor esta' ordenado
       if ( crescente_chars (x, y, z) )
       {
           IO_printf ( "\nAs cadeias de caracteres estao em ordem crescente" );
       } // end if
       
       else
       {
           if ( decrescente_chars (x, y, z) )
           {
               IO_printf ( "\nAs cadeias de caracteres estao em ordem decrescente" );
           } // end if

           else
           {
               IO_println ( "\nAs cadeias de caracteres nao sao difentes e/ou nao estao ordenadas" );
               IO_printf ( "\nA cadeia de maior valor e': %s", obterMaior_chars ( x, y, z ) );
               IO_printf ( "\nA cadeia de menor valor e': %s", obterMenor_chars ( x, y, z ) );
           } // end else
       } // end else

} // end estaOrdenado_chars ( )

/**
 Method10 - Ler 3 cadeias de caracteres do teclado,
            dizer se esta ordenado ou 
            dizer a maior e a menor cadeia
 */

void method10 ( )
{  
    // identificar
       IO_id ( "Exercicio10 - Method10 - v0.0" );

    // chamar procedimento auxiliar    
       estaOrdenado_chars ( );       

    // encerrar
       IO_pause ( "\nApertar ENTER para continuar" );

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
               IO_println ( "0  - parar" );
               IO_println ( "1  - ler (n) numeros e mostrar os seus divisores                              " );
               IO_println ( "2  - ler (n) numeros e dizer se e' primo                                      " );
               IO_println ( "3  - ler cadeia de caracteres e classificar cada caractere                    " );
               IO_println ( "4  - ler cadeia de caracteres e contar cada tipo de caractere                 " );
               IO_println ( "5  - ler e agrupar (n) numeros em 3 casos, dizer qual tem maior media         " );
               IO_println ( "6  - definir intervalo, ler numeros e calcular soma de (1/x^3), se x impar    " );
               IO_println ( "7  - definir intervalo, ler numeros e calcular porcentagens dos que fora dele " );
               IO_println ( "8  - ler 3 numeros reais e dizer se estao ordenados ou qual menor e qual maior" );
               IO_println ( "9  - ler 3 caracteres e dizer se estao ordenados ou nao de acordo com a ASCII"  );
               IO_println ( "10 - ler 3 cadeias e dizer se estao ordenadas ou nao de acordo com a ASCII    " );
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

x = '123', y = 'ABC', z = 'abc'
As cadeias de caracteres estao em ordem crescente


x = 'abc', y = 'ABC', z = '123'
As cadeias de caracteres estao em ordem decrescente


x = 'A1', y = 'A1', z = 'A1'
As cadeias de caracteres nao sao difentes e/ou nao estao ordenadas

A cadeia de maior valor e': A1
A cadeia de menor valor e': A1


x = 'b2', y = 'A1', z = 'A1'
As cadeias de caracteres nao sao difentes e/ou nao estao ordenadas

A cadeia de maior valor e': b2
A cadeia de menor valor e': A1


x = 'b2', y = 'b2', z = 'A1'
As cadeias de caracteres nao sao difentes e/ou nao estao ordenadas

A cadeia de maior valor e': b2
A cadeia de menor valor e': A1

*/