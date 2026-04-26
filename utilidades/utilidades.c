////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE IMPORTACIÓN: FICHEROS NECESARIOS A INCLUIR
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "utilidades.h"   // Mi propia colección de subprogramas útiles.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE MACROS, CONSTANTES Y VARIABLES GLOBALES: PARA USO GLOBAL.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char MSJxERROR[] = "¡VALOR NO VÁLIDO!";  // Mensaje de error.
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";  // Mensaje de pausa.

int codigoError; // VARIABLE GLOBAL: Visible por todos los subprogramas.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE CÓDIGO: CUERPOS DE LOS SUBPROGRAMAS DECLARADOS ANTES.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarINTRO (void);
//    void descartarEntrada (void);
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void esperarINTRO (void) 
{
  vaciarBuffer();  
}


void descartarEntrada (void) 
{
  vaciarBuffer();  
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void vaciarBuffer (void);
//
//  USO:
//
//    Programa que espera que el usuario pulse teclas a la espera de INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que va pidiendo letras del buffer de teclado y no
//    termina hasta que detecta que ha encontrado un "INTRO". Cualquier
//    otro código ASCII introducido por el usuario se descarta.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      comunicarse con el sistema operativo y con el hardware del teclado.
//
////////////////////////////////////////////////////////////////////////////////

void vaciarBuffer (void)  
{
  // ENTER CREADO EN DEFINE = ASCII(10) = 0x0A
  
  // MEDIANTE BUCLE DO-WHILE:
  char letra; 
  do
  {
    letra = getchar(); 
  } while (letra != ENTER);  
  
  // MEDIANTE BUBLE WHILE:
  // while (getchar() != '\n')   ; 
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void borrarPantalla (void);
//    void limpiarPantalla (void);
//
//  USO:
//
//    Borra completamente el contenido visible de la pantalla (terminal).
//
//  DETALLES:
//
//  Ejecuta el comando del sistema operativo definido en la macro BORRAR
//  (normalmente "cls" en Windows y "clear" en Linux/Mac). Es la función 
//  base a la que llaman todos los alias de borrado de pantalla. 
//  Permite de disponer de dos nobre distintos para la misma acción.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    limpiarPantalla()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void borrarPantalla (void) 
{
  limpiarPantalla();  
}

void limpiarPantalla (void)  
{
  system(BORRAR);  
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void bajar (int nlineas);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    Crea tantas líneas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el código ASCII de salto de línea '\n'.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void bajar (int nlineas)  
{
  while(nlineas>0)  
  {
    printf("\n");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
    
    nlineas--;  
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void abajo (int nfils);
//
//  USO:
//
//    Sinónimo de bajar(). Desplaza el cursor hacia abajo nfils líneas.
//
//  DETALLES:
//
//    Igual que bajar(). Delega todo el trabajo en esa función.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Número de líneas en blanco a insertar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void abajo (int nfils) 
{
  bajar(nfils);  
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void saltar (int nfils);
//
//  USO:
//
//    Sinónimo de bajar(). Desplaza el cursor hacia abajo nfils líneas.
//
//  DETALLES:
//
//    Alias semántico de bajar(). Delega todo el trabajo en esa función.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Número de líneas en blanco a insertar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void saltar (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarFils (int nfils);
//
//  USO:
//
//    Sinónimo de bajar(). Desplaza el cursor hacia abajo nfils líneas.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils — Número de líneas a bajar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarFils (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarV (int nfils);
//
//  USO:
//
//    Sinónimo de bajar(). Desplaza el cursor verticalmente nfils líneas.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils — Número de líneas a bajar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarV (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarY (int nfils);
//
//  USO:
//
//    Sinónimo de bajar(). Desplaza el cursor en el eje Y nfils posiciones.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils — Número de líneas a bajar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarY (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void indentar (int ncolumnas);
//
//  USO:
//
//    Desplaza el cursor hacia la derecha tantas columnas como se le indique,
//    insertando espacios en blanco.
//
//  DETALLES:
//
//    Genera tantos espacios en blanco como se reciba en el parámetro. Usa
//    printf(" ") directamente en lugar de mostrar() para evitar recursión.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncolumnas
//
//      Número de espacios en blanco que se insertarán por pantalla.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Función estándar de C para imprimir texto por pantalla.
//      Se usa directamente para evitar recursión con mostrar().
//
////////////////////////////////////////////////////////////////////////////////

void indentar (int ncolumnas)
{
  for(int i=0; i<ncolumnas; i++)
  {
    printf(" ");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void derecha (int ncols);
//
//  USO:
//
//    Sinónimo de indentar(). Desplaza el cursor a la derecha ncols columnas.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols — Número de columnas (espacios) a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void derecha (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void tabular (int ncols);
//
//  USO:
//
//    Sinónimo de indentar(). Desplaza el cursor a la derecha ncols columnas.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols — Número de columnas (espacios) a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void tabular (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarCols (int ncols);
//
//  USO:
//
//    Sinónimo de indentar(). Desplaza el cursor a la derecha ncols columnas.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols — Número de columnas a desplazar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarCols (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarX (int ncols);
//
//  USO:
//
//    Sinónimo de indentar(). Desplaza el cursor en el eje X ncols posiciones.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols — Número de columnas a desplazar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarX (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarH (int ncols);
//
//  USO:
//
//    Sinónimo de indentar(). Desplaza el cursor horizontalmente ncols columnas.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols — Número de columnas a desplazar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarH (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void posicionar (int nfils, int ncols);
//
//  USO:
//
//    Desplaza el cursor tanto verticalmente como horizontalmente, permitiendo
//    situar el punto de escritura en una posición aproximada de la pantalla.
//
//  DETALLES:
//
//    Combina bajar() e indentar() para producir un desplazamiento en las dos
//    dimensiones. No usa coordenadas absolutas de terminal sino que desplaza
//    el cursor desde donde esté en ese momento.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Número de líneas hacia abajo que se desplazará el cursor.
//
//    ncols
//
//      Número de columnas hacia la derecha que se desplazará el cursor.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Se encarga del desplazamiento vertical.
//
//    tabular()
//
//      Se encarga del desplazamiento horizontal.
//
////////////////////////////////////////////////////////////////////////////////

void posicionar (int nfils, int ncols)
{
  bajar(nfils);
  tabular(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazar (int nfils, int ncols);
//
//  USO:
//
//    Sinónimo de posicionar(). Desplaza el cursor vertical y horizontalmente.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils — Número de líneas hacia abajo.
//    ncols — Número de columnas hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazar (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarXY (int nfils, int ncols);
//
//  USO:
//
//    Sinónimo de posicionar(). Desplaza el cursor en los ejes X e Y.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils — Desplazamiento en el eje Y (filas hacia abajo).
//    ncols — Desplazamiento en el eje X (columnas hacia la derecha).
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarXY (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoSegundos (int segundosmax);
//
//  USO:
//
//    Produce una espera activa de aproximadamente segundosmax segundos,
//    sin depender de funciones del sistema operativo.
//
//  DETALLES:
//
//    La espera se consigue con tres bucles anidados vacíos. El número de
//    iteraciones está ajustado para que la duración total se acerque a un
//    segundo por cada vuelta del bucle exterior. El resultado no es muy
//    preciso porque depende de la velocidad del procesador y del compilador.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundosmax
//
//      Número aproximado de segundos que durará la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna. Trabaja de forma autónoma con bucles vacíos.
//
////////////////////////////////////////////////////////////////////////////////

void retardoSegundos (int segundosmax)
{
  // POSIBILIDAD: Poner en función de la que usa milisegundos.
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for(int nseg=0; nseg < segundosmax ; nseg++)
  {
    for(int j=0; j<100; j++)
      for(int j=0; j<1000; j++)
        for(int k=0; k<1000; k++)   ;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoMilisegundos (int milisegundosmax);
//
//  USO:
//
//    Produce una espera activa de aproximadamente milisegundosmax milisegundos,
//    sin depender de funciones del sistema operativo.
//
//  DETALLES:
//
//    Igual que retardoSegundos() pero calibrado para milisegundos. Usa dos
//    bucles anidados vacíos. El resultado tampoco es muy preciso porque
//    depende de la velocidad del procesador.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundosmax
//
//      Número aproximado de milisegundos que durará la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna. Trabaja de forma autónoma con bucles vacíos.
//
////////////////////////////////////////////////////////////////////////////////

void retardoMilisegundos (int milisegundosmax)
{
  int i, j;
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for (int nmiliseg=0; nmiliseg<milisegundosmax ; nmiliseg++)
    for (i=0; i<100; i++)
      for (j=0; j<1000; j++)   ;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retrasoMilisegundos (int milisegundos);
//
//  USO:
//
//    Produce una espera activa de exactamente milisegundos milisegundos,
//    medida con el reloj interno del procesador.
//
//  DETALLES:
//
//    A diferencia de retardoMilisegundos(), este sí es preciso porque usa
//    clock() para medir cuánto tiempo ha pasado de verdad. El bucle no para
//    hasta que se ha superado el tiempo pedido. El inconveniente es que
//    consume CPU durante todo el tiempo que dura la espera.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Número de milisegundos exactos que durará la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    clock()
//
//      Función estándar de C que devuelve el número de ciclos de reloj del
//      procesador transcurridos desde el inicio del programa. Dividiendo
//      por CLOCKS_PER_SEC se obtiene el tiempo en segundos.
//
////////////////////////////////////////////////////////////////////////////////

void retrasoMilisegundos (int milisegundos)
{
  double e = 0;

  clock_t t0 = clock();   // clock_t es un tipo interno equivalente a UINT32.
  
  do
  {
    
    e = 1000*(double)(clock()-t0)/CLOCKS_PER_SEC;

  } while (e<milisegundos);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarSegundos (int segundos);
//
//  USO:
//
//    Produce una espera pasiva de exactamente segundos segundos, delegando
//    en el sistema operativo la gestión del tiempo.
//
//  DETALLES:
//
//    Al contrario que los retardos por bucles, aquí el proceso queda
//    suspendido y no gasta CPU durante la espera. La función que se usa
//    cambia según el sistema operativo: Sleep() en Windows (que recibe
//    milisegundos) y sleep() en Linux o Mac.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundos
//
//      Número de segundos que durará la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep() [Windows]
//
//      Función de la API de Windows que suspende el proceso el tiempo
//      indicado en milisegundos. Se multiplica por 1000 para convertir.
//
//    sleep() [Linux/Mac]
//
//      Función POSIX que suspende el proceso el tiempo indicado en segundos.
//
////////////////////////////////////////////////////////////////////////////////

void esperarSegundos (int segundos)
{
  #ifdef SO_WINDOWS
    Sleep(segundos*1000);
  #else
    sleep(segundos);
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarMilisegundos (int milisegundos);
//
//  USO:
//
//    Produce una espera pasiva de exactamente milisegundos milisegundos,
//    delegando en el sistema operativo la gestión del tiempo.
//
//  DETALLES:
//
//    Igual que esperarSegundos() pero con precisión de milisegundos.
//    En Linux/Mac se usa usleep(), que trabaja en microsegundos, así que
//    hay que multiplicar por 1000 para pasar de milisegundos.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Número de milisegundos que durará la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep() [Windows]
//
//      Función de la API de Windows que suspende el proceso el tiempo
//      indicado en milisegundos.
//
//    usleep() [Linux/Mac]
//
//      Función POSIX que suspende el proceso el tiempo indicado en
//      microsegundos. Se multiplica por 1000 para convertir desde ms.
//
////////////////////////////////////////////////////////////////////////////////

void esperarMilisegundos (int milisegundos)
{
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);   // Alternativa: nanosleep() de "time.h".
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausa (void);
//
//  USO:
//
//    Muestra el mensaje de pausa estándar y espera a que el usuario pulse INTRO.
//
//  DETALLES:
//
//    Es la versión más simple de las pausas: llama a pausaEstandar() con
//    los valores de posición que se han decidido por defecto (1 fila y
//    2 columnas de margen).
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaEstandar()
//
//      Se delega toda la carga de trabajo a esta función con valores fijos.
//
////////////////////////////////////////////////////////////////////////////////

void pausa (void)
{
  pausaEstandar(1, 2);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaEstandar (int nfils, int ncols);
//
//  USO:
//
//    Muestra el mensaje de pausa estándar en la posición indicada y espera
//    a que el usuario pulse INTRO.
//
//  DETALLES:
//
//    Muestra la cadena global MSJxPAUSA en la posición que se le indique
//    y sin salto de línea al final. Delega en pausaGenerica() todo el
//    trabajo, pasando FALSE en el parámetro de nueva línea.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Número de líneas de desplazamiento vertical antes del mensaje.
//
//    ncols
//
//      Número de columnas de desplazamiento horizontal antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaGenerica()
//
//      Se delega toda la carga de trabajo, pasando el mensaje estándar
//      y FALSE para no añadir nueva línea al final.
//
////////////////////////////////////////////////////////////////////////////////

void pausaEstandar (int nfils, int ncols)
{
  pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//
//    Muestra un mensaje configurable en la posición indicada y espera a que
//    el usuario pulse INTRO.
//
//  DETALLES:
//
//    Es la función base de la que dependen todas las pausas. Permite elegir
//    qué texto mostrar, en qué posición y si se añade o no un salto de
//    línea al final. El texto lo imprime mensaje_x_y() y la espera la
//    gestiona esperarINTRO().
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Cadena de texto que se mostrará como mensaje de pausa.
//
//    nfils
//
//      Número de líneas de desplazamiento vertical antes del mensaje.
//
//    ncols
//
//      Número de columnas de desplazamiento horizontal antes del mensaje.
//
//    nuevalinea
//
//      Si es TRUE, añade un '\n' al final del mensaje. Si es FALSE, no.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Se encarga de mostrar el mensaje en la posición indicada.
//
//    esperarINTRO()
//
//      Se encarga de bloquear el programa hasta que el usuario pulse INTRO.
//
////////////////////////////////////////////////////////////////////////////////

void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  mensaje_x_y(msjtxt, nfils, ncols, nuevalinea);

  esperarINTRO();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void texto (char msjtxt[]);
//
//  USO:
//
//    Muestra una cadena de texto por pantalla seguida automáticamente de
//    un salto de línea.
//
//  DETALLES:
//
//    Envoltorio simple de puts(). La diferencia con printf() es que puts()
//    ya mete el '\n' solo al final, así que no hace falta ponerlo a mano.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Cadena de texto terminada en '\0' que se mostrará por pantalla.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    puts()
//
//      Función estándar de C que imprime una cadena seguida de '\n'.
//
////////////////////////////////////////////////////////////////////////////////

void texto (char msjtxt[])
{
  puts(msjtxt);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void separar (void);
//
//  USO:
//
//    Inserta una línea en blanco en pantalla, actuando como separador visual.
//
//  DETALLES:
//
//    Inserta una línea en blanco en pantalla para separar visualmente
//    distintas partes del contenido.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar()
//
//      Se delega la impresión del salto de línea a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void separar()
{
  mostrar("\n");
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void nuevaLinea (void);
//
//  USO:
//
//    Baja el cursor exactamente una línea, insertando una línea en blanco.
//
//  DETALLES:
//
//    Es simplemente saltar() con el valor 1 fijo. Se usa cuando se quiere
//    dejar una línea en blanco y no hace falta pasar ningún parámetro.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
//      Se delega el desplazamiento de una línea a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void nuevaLinea (void)
{
  saltar(1);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar (char msjtxt[]);
//
//  USO:
//
//    Muestra una cadena de texto por pantalla en la posición actual del cursor,
//    sin ningún desplazamiento previo y sin añadir nueva línea al final.
//
//  DETALLES:
//
//    Es la versión más simple de mostrar_x_y(), con los desplazamientos
//    a cero. Es la función de impresión más usada de la librería para
//    textos que no necesitan posicionamiento especial.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Cadena de texto terminada en '\0' que se mostrará por pantalla.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar_x_y()
//
//      Se delega el trabajo con desplazamientos 0 en filas y columnas.
//
////////////////////////////////////////////////////////////////////////////////

void mostrar (char msjtxt[])
{
  mostrar_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra una cadena de texto por pantalla tras desplazarse nfils líneas
//    y ncols columnas, sin añadir nueva línea al final.
//
//  DETALLES:
//
//    Envoltorio de mensaje_x_y() que fija nuevalinea a FALSE. Sirve para
//    los casos más habituales en que no hace falta añadir '\n' al final
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt — Cadena de texto terminada en '\0' que se mostrará por pantalla.
//    nfils  — Número de líneas de desplazamiento vertical antes del texto.
//    ncols  — Número de columnas de desplazamiento horizontal antes del texto.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Se delega todo el trabajo pasando FALSE para el parámetro nuevalinea.
//
////////////////////////////////////////////////////////////////////////////////

void mostrar_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir (char msjtxt[]);
//    void escribir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Sinónimos de mostrar() y mostrar_x_y() respectivamente.
//
//  DETALLES:
//
//    Se comportan exactamente igual. Solo existen para poder usar el nombre
//    que resulte más natural en cada situación.
//
//  PARÁMETROS DE ENTRADA / VALOR DE SALIDA / FUNCIONES DE LAS QUE DEPENDE:
//
//    Idénticos a mostrar() y mostrar_x_y().
//
////////////////////////////////////////////////////////////////////////////////

void escribir (char msjtxt[])
{
  escribir_x_y (msjtxt, 0, 0);
}


void escribir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir (char msjtxt[]);
//    void imprimir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Sinónimos de mostrar() y mostrar_x_y() respectivamente.
//
//  DETALLES:
//
//    Se comportan exactamente igual. Solo existen para poder usar el nombre
//    que resulte más natural en cada situación.
//
//  PARÁMETROS DE ENTRADA / VALOR DE SALIDA / FUNCIONES DE LAS QUE DEPENDE:
//
//    Idénticos a mostrar() y mostrar_x_y().
//
////////////////////////////////////////////////////////////////////////////////

void imprimir (char msjtxt[])
{
  imprimir_x_y (msjtxt, 0, 0);
}


void imprimir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra una cadena de texto en pantalla tras desplazarse nfils líneas
//    y ncols columnas, sin añadir nueva línea al final.
//
//  DETALLES:
//
//    Envoltorio de mensaje_x_y() con nuevalinea fijado a FALSE. Es la
//    versión de tres parámetros pensada para cuando no se necesita el
//    parámetro booleano.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt — Cadena de texto terminada en '\0' que se mostrará.
//    nfils  — Número de líneas de desplazamiento vertical antes del texto.
//    ncols  — Número de columnas de desplazamiento horizontal antes del texto.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Se delega todo el trabajo pasando FALSE para el parámetro nuevalinea.
//
////////////////////////////////////////////////////////////////////////////////

void mensaje (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//
//    Función NÚCLEO de impresión de la librería. Muestra una cadena de texto
//    en pantalla tras desplazarse nfils líneas y ncols columnas, con la
//    opción de añadir o no una nueva línea al final.
//
//  DETALLES:
//
//    Es la función base sobre la que se apoyan todas las demás funciones de
//    impresión de esta librería. Todas las demás acaban llamando a esta.
//    Primero baja las filas, luego tabula las columnas y finalmente imprime
//    el texto. El salto de línea final es opcional.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Cadena de texto terminada en '\0' que se mostrará por pantalla.
//
//    nfils
//
//      Número de líneas de desplazamiento vertical previo al texto.
//
//    ncols
//
//      Número de columnas de desplazamiento horizontal previo al texto.
//
//    nuevalinea
//
//      Si es TRUE, añade un '\n' al final del texto. Si es FALSE, no.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
//      Produce el desplazamiento vertical previo al texto.
//
//    tabular()
//
//      Produce el desplazamiento horizontal previo al texto.
//
//    printf()
//
//      Imprime la cadena de texto y, opcionalmente, el '\n' final.
//
////////////////////////////////////////////////////////////////////////////////

void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  
  if (nuevalinea)   printf("\n");   // ALTERNATIVA: if (nuevalinea)   putchar(ENTER);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void iniciaAleatorizador (void);
//
//  USO:
//
//    Inicializa el generador de números pseudoaleatorios con una semilla
//    distinta en cada ejecución del programa.
//
//  DETALLES:
//
//    Llama a srand() con el tiempo actual como semilla. Así, cada vez que
//    se ejecuta el programa la semilla es diferente y la secuencia de
//    números que genera rand() también cambia. Hay que llamarla una sola
//    vez antes de empezar a usar generaAleatorioEntero().
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    srand()
//
//      Función estándar de C que fija la semilla del generador de números
//      pseudoaleatorios.
//
//    time()
//
//      Función estándar de C que devuelve el tiempo actual del sistema en
//      segundos. Se usa como semilla variable para srand().
//
////////////////////////////////////////////////////////////////////////////////

void iniciaAleatorizador (void)
{
  srand(time(NULL));
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int generaAleatorioEntero (int limite);
//
//  USO:
//
//    Genera un número entero pseudoaleatorio entre 0 y limite-1 (inclusive).
//
//  DETALLES:
//
//    Aplica el operador módulo al resultado de rand() para limitar el rango
//    al intervalo [0, limite-1]. Para que la secuencia sea impredecible hay
//    que haber llamado antes a iniciaAleatorizador().
//
//  PARÁMETROS DE ENTRADA:
//
//    limite
//
//      Cota superior (no incluida) del rango de valores posibles.
//      El resultado estará siempre en [0, limite-1].
//
//  VALOR DE SALIDA:
//
//    Devuelve un entero pseudoaleatorio en el rango [0, limite-1].
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    rand()
//
//      Función estándar de C que devuelve un número pseudoaleatorio entre
//      0 y RAND_MAX. Se limita su rango con el operador módulo.
//
////////////////////////////////////////////////////////////////////////////////

int generaAleatorioEntero (int limite)
{
  // Generará un número entre 0 y limite - 1, nunca llega a limite.
  return (rand() % limite);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerEntero (void);
//
//  USO:
//
//    Sustitución mejorada de scanf() que impide que queden letras almacenadas
//    en el buffer de teclado para posteriores operaciones de entrada de datos.
//
//  DETALLES:
//
//    La función scanf() no retira el código ASCII de la letra INTRO del buffer
//    de teclado ni posibles letras después de un texto que se pueda convertir
//    en una cantidad. Nos ayudamos de otra función creada en esta librería,
//    vaciarBuffer() para ello. No muestra ningún mensaje por pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    Devuelve al exterior el valor entero que a su vez ha recibido en la
//    variable "valor" de la función scanf(), mediante paso por referencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      leer caracteres del teclado y convertirlos en la cantidad entera.
//
////////////////////////////////////////////////////////////////////////////////

int obtenerEntero (void)
{
  int valor;
  
  scanf("%d", &valor);
  vaciarBuffer();

  return valor;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerCaracterASCII (void);
//
//  USO:
//
//    Sinónimo de obtenerLetra(). Lee un carácter ASCII estándar del teclado.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter ASCII leído, o '\0' si es un carácter extendido.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra() — Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerCaracterASCII()
{
  return obtenerLetra();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerLetra (void);
//
//  USO:
//
//    Lee un único carácter ASCII estándar del teclado y limpia el buffer
//    de entrada para evitar problemas en lecturas posteriores.
//
//  DETALLES:
//
//    Lee un carácter con getchar() y comprueba que sea ASCII estándar.
//    Si es un carácter extendido (mayor de 127),
//    devuelve '\0'. Si el usuario escribió más de un carácter antes del
//    INTRO, el buffer se limpia con vaciarBuffer(). Si solo se pulsó INTRO,
//    no llama a vaciarBuffer() porque el buffer ya está vacío.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter ASCII leído (0-127), o '\0' si es extendido.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Función estándar de C que lee un carácter del buffer de teclado.
//
//    vaciarBuffer()
//
//      Limpia el buffer de teclado si quedan caracteres tras la lectura.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerLetra (void)   // Sólo ASCII VÁLIDO.
{
  char letra, valida;
  
  letra = getchar();
  
  if (letra < 128)
    valida = letra; // Devolveremos la letra
  else
    valida = '\0';  // Devolveremos la letra nula.
  
  // VACIAMOS POSIBLES CÓDIGOS EN EL BUFFER.
  //   Se incluye el INTRO EXTRA y una posible escritura de múltiples letras.
  if (letra != ENTER)   vaciarBuffer();

  return valida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEntero (char msjtxt[], int ncols);
//
//  USO:
//
//    Muestra un mensaje en pantalla para pedir un dato entero al usuario. El
//    mensaje es configurable y desplazable un número de caracteres desde la
//    izquierda de la pantalla.
//
//  DETALLES:
//
//    Es como un printf() más un scanf(), mejorados. Puede desplazarse el texto
//    recibido mediante un segundo dato entero. También impide problemas del
//    buffer de teclado con scanf(). Para ello, delega el emitir el mensaje por
//    pantalla a las funciones msj() y mostrar(), y la toma del dato entero a la
//    función obtenerEntero().
//
//  PARÁMETROS DE ENTRADA:
//
//    mensaje
//
//      Variable de tipo vector de caracteres donde se recibirá el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    tabs
//
//      Variable entera donde se recibirá del exterior el número de espacios en
//      blanco a añadir antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa donde se invoque, un valor entero que a su vez esta
//    función ha recibido desde la función obtenerEntero().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    msj()
//
//      Se encarga efectivamente de mostrar el mensaje.
//
//    mostrar()
//
//      Usada para añadir en pantalla un texto adicional después del mensaje.
//
//    obtenerEntero()
//
//      Es la función que se encarga en la práctica de obtener la cantidad.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEntero (char msjtxt[], int ncols)
{
  mensaje(msjtxt, 0, ncols);
  mostrar(": ");
  
  return obtenerEntero();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Pide al usuario un número entero no negativo, repitiendo la petición
//    hasta que introduzca un valor válido (>= 0).
//
//  DETALLES:
//
//    Bucle do-while que sigue pidiendo el dato mientras sea negativo. Si
//    mostrarerror es TRUE muestra el mensaje de error estándar cuando el
//    usuario mete algo inválido. El cero se considera válido.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto del mensaje de petición que se mostrará al usuario.
//
//    ncols
//
//      Número de columnas de desplazamiento horizontal antes del mensaje.
//
//    mostrarerror
//
//      Si es TRUE, muestra MSJxERROR cuando el valor introducido es negativo.
//      Si es FALSE, simplemente repite la petición sin avisar al usuario.
//
//  VALOR DE SALIDA:
//
//    Devuelve el primer entero no negativo introducido por el usuario.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()       — Muestra el texto de petición en la posición indicada.
//    mostrar()       — Añade ": " como indicador de campo de entrada.
//    obtenerEntero() — Lee y devuelve el entero introducido por el usuario.
//    nuevaLinea()    — Inserta líneas en blanco antes y después del error.
//    mensaje_x_y()   — Muestra el mensaje de error con sangría adicional.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < 0)
      {
        nuevaLinea();  // Linea en blanco.
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);  // Mensaje de error.
        nuevaLinea();  // Linea en blanco.
      } 
    }
    
  } while (num < 0);
  
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror,
//                              int min, int max);
//
//  USO:
//
//    Pide al usuario un número entero dentro del intervalo [min, max],
//    repitiendo la petición hasta que el valor introducido sea válido.
//
//  DETALLES:
//
//    Bucle do-while que sigue pidiendo mientras el número esté fuera del
//    rango [min, max]. Muestra el intervalo válido entre corchetes junto
//    al mensaje. Si mostrarerror es TRUE muestra MSJxERROR cuando el valor
//    no está dentro del intervalo.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto del mensaje de petición que se mostrará al usuario.
//
//    ncols
//
//      Número de columnas de desplazamiento horizontal antes del mensaje.
//
//    mostrarerror
//
//      Si es TRUE, muestra MSJxERROR cuando el valor no está en [min, max].
//
//    min
//
//      Límite inferior del intervalo válido (incluido).
//
//    max
//
//      Límite superior del intervalo válido (incluido).
//
//  VALOR DE SALIDA:
//
//    Devuelve el primer entero dentro del intervalo [min, max] introducido.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()       — Muestra el texto de petición en la posición indicada.
//    printf()        — Muestra el intervalo válido entre corchetes.
//    obtenerEntero() — Lee y devuelve el entero introducido por el usuario.
//    nuevaLinea()    — Inserta líneas en blanco alrededor del mensaje de error.
//    mensaje_x_y()   — Muestra el mensaje de error con sangría adicional.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < min || num > max)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < min || num > max);
  
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra);
//
//  USO:
//
//    Pide al usuario que introduzca una letra concreta, repitiendo la
//    petición hasta que pulse exactamente la letra esperada.
//
//  DETALLES:
//
//    La comparación no distingue mayúsculas de minúsculas: tanto la letra
//    esperada como la que teclea el usuario se convierten a mayúsculas antes
//    de comparar. Si mostrarerror es TRUE muestra el mensaje de error cuando
//    la letra no coincide.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto del mensaje de petición que se mostrará al usuario.
//
//    ncols
//
//      Número de columnas de desplazamiento horizontal antes del mensaje.
//
//    mostrarerror
//
//      Si es TRUE, muestra MSJxERROR cuando la letra no coincide con la esperada.
//
//    letra
//
//      La letra exacta que se espera que introduzca el usuario.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra validada (siempre en mayúsculas).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()      — Convierte caracteres a mayúsculas para la comparación.
//    mensaje()      — Muestra el texto de petición en la posición indicada.
//    mostrar()      — Añade ": " como indicador de campo de entrada.
//    obtenerLetra() — Lee y devuelve el carácter introducido por el usuario.
//    nuevaLinea()   — Inserta líneas en blanco alrededor del mensaje de error.
//    mensaje_x_y()  — Muestra el mensaje de error con sangría adicional.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
{
  char pedida;
  
  letra = toupper(letra);
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    
    pedida = obtenerLetra();
    pedida = toupper(pedida);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != pedida)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != pedida);
  
  return pedida;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Pide al usuario que confirme o rechace una acción pulsando S (sí) o N
//    (no), repitiendo la petición hasta recibir una respuesta válida.
//
//  DETALLES:
//
//    Muestra junto al mensaje las opciones en formato [S/N]. La comparación
//    no distingue mayúsculas de minúsculas. Las constantes SI y NO deben
//    estar definidas en la cabecera (normalmente 'S' y 'N'). Si mostrarerror
//    es TRUE muestra MSJxERROR cuando el usuario no pulsa ni S ni N.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto del mensaje de confirmación que se mostrará al usuario.
//
//    ncols
//
//      Número de columnas de desplazamiento horizontal antes del mensaje.
//
//    mostrarerror
//
//      Si es TRUE, muestra MSJxERROR cuando la letra no es SI ni NO.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter SI o NO introducido por el usuario (en mayúsculas).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()      — Muestra el texto de petición en la posición indicada.
//    printf()       — Muestra las opciones [S/N] junto al mensaje.
//    obtenerLetra() — Lee y devuelve el carácter introducido por el usuario.
//    toupper()      — Convierte la respuesta a mayúscula para la comparación.
//    nuevaLinea()   — Inserta líneas en blanco alrededor del mensaje de error.
//    mensaje_x_y()  — Muestra el mensaje de error con sangría adicional.
//
////////////////////////////////////////////////////////////////////////////////

int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
{
  char letra;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    
    letra = obtenerLetra();
    letra = toupper(letra);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != SI && letra != NO)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != SI && letra != NO);
  
  return letra;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas);
//
//  USO:
//
//    Comprueba si dos caracteres son iguales, con o sin distinción de
//    mayúsculas y minúsculas según el parámetro recibido.
//
//  DETALLES:
//
//    Si sensibleamayusculas es FALSE convierte los dos caracteres a mayúsculas
//    antes de comparar, así 'a' y 'A' se consideran iguales. Si es TRUE la
//    comparación distingue entre mayúsculas y minúsculas.
//
//  PARÁMETROS DE ENTRADA:
//
//    original
//
//      Carácter de referencia con el que se comparará.
//
//    dada
//
//      Carácter introducido por el usuario que se va a validar.
//
//    sensibleamayusculas
//
//      Si es TRUE, distingue mayúsculas de minúsculas en la comparación.
//      Si es FALSE, ignora la diferencia entre mayúsculas y minúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve TRUE si los dos caracteres son iguales (según el criterio
//    indicado), o FALSE si son distintos.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//
//      Convierte un carácter a mayúsculas cuando la comparación no es
//      sensible a mayúsculas/minúsculas.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
{
  if (!sensibleamayusculas)
  {
    original = toupper(original);
      dada   = toupper(dada);
  }
  
  return (original == dada);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraConjunto (char letra, char seleccion[],
//                                  boolean sensibleamayusculas);
//
//  USO:
//
//    Comprueba si un carácter pertenece a un conjunto de caracteres válidos
//    definido en una cadena de texto.
//
//  DETALLES:
//
//    Recorre la cadena seleccion[] comparando cada elemento con la letra
//    recibida usando validarLetraUnica(). En cuanto encuentra una coincidencia
//    para de buscar y devuelve TRUE. Si llega al final sin encontrar nada
//    devuelve FALSE.
//
//  PARÁMETROS DE ENTRADA:
//
//    letra
//
//      Carácter introducido por el usuario que se va a validar.
//
//    seleccion[]
//
//      Cadena de caracteres que contiene todas las opciones válidas.
//
//    sensibleamayusculas
//
//      Si es TRUE, distingue mayúsculas de minúsculas en la comparación.
//      Si es FALSE, ignora la diferencia.
//
//  VALOR DE SALIDA:
//
//    Devuelve TRUE si la letra está en el conjunto, FALSE si no lo está.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//
//      Obtiene la longitud de la cadena de opciones para recorrerla.
//
//    validarLetraUnica()
//
//      Realiza cada comparación individual letra a letra.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
{
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  
  for(int i = 0; i < largo ; i++)
  {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas))
    {
      resultado = TRUE;
      break;
    }
  }
  
  return resultado;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char *cadenaOpcionesDisponibles (char entrada[]);
//
//  USO:
//
//    Transforma una cadena de opciones como "ABC" en la cadena formateada
//    "A/B/C" para mostrarla al usuario como opciones separadas por '/'.
//
//  DETALLES:
//
//    Reserva memoria dinámica para la cadena resultado. El tamaño que hace
//    falta es el doble del original: cada letra ocupa su posición más un
//    separador '/', y el último '/' se sustituye por '\0'. El que llame a
//    esta función es responsable de liberar la memoria con free() después.
//
//    Ejemplo: "ABC" → "A/B/C"  (3 letras + 2 separadores + '\0')
//
//  PARÁMETROS DE ENTRADA:
//
//    entrada[]
//
//      Cadena de caracteres con las opciones válidas (ej: "SNQR").
//      Si es NULL, devuelve NULL inmediatamente.
//
//  VALOR DE SALIDA:
//
//    Devuelve un puntero a la cadena formateada reservada dinámicamente,
//    o NULL si la entrada era NULL o si malloc() falló.
//    El programa invocante debe liberar la memoria con free().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//
//      Obtiene la longitud de la cadena de entrada.
//
//    malloc()
//
//      Reserva la memoria dinámica necesaria para la cadena resultado.
//
////////////////////////////////////////////////////////////////////////////////

char *cadenaOpcionesDisponibles (char entrada[])
{
  if (entrada == NULL) return NULL;   // Si no dan nada, petas máximus ...
  
  char *textoinicial, *textofinal;
  
  textoinicial = entrada;
  
  int largoinicial, largofinal;
  
  largoinicial = strlen(textoinicial);

  if (largoinicial == 0)
  {
    // Nos dan cadena vacía, así que generamos vacía. Pero consideramos el '\0'.
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  }
  else
  {
    // CASO 1: "A" -> "A" => largo 2 = 1 (letra) + 1 ('\0')
    // CASO 2: "ABC" -> "A/B/C" => largo 6 = 3 (letras) + 2 (sepadores) +1 ('\0'); 
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    
    if (textofinal != NULL)
    {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++)
      {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      
      // Sustituimos la última '/' por un ' 0'.
      j--;
      textofinal[j] = '\0';
    }
  }

  return textofinal;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror,
//                             char seleccion[], boolean sensibleamayusculas);
//
//  USO:
//
//    Pide al usuario que introduzca una letra perteneciente a un conjunto
//    de opciones válidas, repitiendo la petición hasta recibir una válida.
//
//  DETALLES:
//
//    Genera automáticamente la cadena de opciones formateada (por ejemplo
//    "A/B/C") con cadenaOpcionesDisponibles(). Valida la letra leída con
//    validarLetraConjunto(). Al terminar libera la memoria con free(). Si
//    sensibleamayusculas es FALSE siempre devuelve la letra en mayúscula.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Texto del mensaje de petición que se mostrará al usuario.
//
//    ncols
//
//      Número de columnas de desplazamiento horizontal antes del mensaje.
//
//    mostrarerror
//
//      Si es TRUE, muestra MSJxERROR cuando la letra no está en el conjunto.
//
//    seleccion[]
//
//      Cadena con los caracteres válidos que puede introducir el usuario.
//
//    sensibleamayusculas
//
//      Si es TRUE, distingue mayúsculas de minúsculas en la validación.
//      Si es FALSE, ignora la diferencia y devuelve siempre mayúscula.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra validada. Si sensibleamayusculas es FALSE, siempre
//    en mayúsculas.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    cadenaOpcionesDisponibles() — Genera la cadena "A/B/C" de opciones.
//    mensaje()                   — Muestra el texto de petición.
//    mostrar()                   — Muestra los corchetes y separadores.
//    printf()                    — Muestra las opciones formateadas.
//    obtenerLetra()              — Lee el carácter introducido por el usuario.
//    validarLetraConjunto()      — Valida si la letra está en el conjunto.
//    nuevaLinea()                — Inserta líneas en blanco para el error.
//    mensaje_x_y()               — Muestra el mensaje de error con sangría.
//    free()                      — Libera la memoria reservada dinámicamente.
//    toupper()                   — Convierte a mayúscula si no es sensible.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
{
  // HACER: Evitar que falle con «seleccion» a valor NULL.
  
  // Usar «cadenaOpcionesDisponibles()» implica luego liberar memoria con «free()».
  char *editada = cadenaOpcionesDisponibles(seleccion);
  
  char letra;
  
  boolean validada;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    
    letra = obtenerLetra();

    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    
    if (mostrarerror)
    {
      if (!validada)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  
  // Liberamos la memoria para cadena modificada.
  free(editada);
  
  // Si no era sensible a mayúsculas, siempre la devolvemos mayúscula.
  if (!sensibleamayusculas)   letra = toupper(letra);
  
  return letra;
}



#ifdef SO_WINDOWS

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN (WINDOWS):
//
//    char obtenerTeclaInteractiva (void);
//
//  USO:
//
//    Lee una tecla del teclado de forma interactiva (sin eco, sin esperar
//    INTRO), detectando también las teclas especiales como las flechas.
//
//  DETALLES:
//
//    Usa _getch() de <conio.h>, que es propia de Windows. Cuando el usuario
//    pulsa una tecla especial (flechas, F1,...) Windows manda dos bytes: el
//    primero es 0 o 224 indicando que viene algo especial, y el segundo es
//    el código concreto de la tecla. Las teclas normales mandan directamente
//    su código ASCII.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    Devuelve el código de la tecla pulsada. Para teclas especiales
//    devuelve la constante correspondiente (TECLA_ARRIBA, TECLA_ABAJO,
//    TECLA_IZQUIERDA, TECLA_DERECHA, TECLA_NULA).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    _getch()
//
//      Función de <conio.h> que lee un carácter del teclado sin eco
//      y sin esperar INTRO. Bloqueante por defecto en Windows.
//
////////////////////////////////////////////////////////////////////////////////

#include <conio.h>

char obtenerTeclaInteractiva(void)
{
  int caracter = _getch();   // En Windows, getch() ya es bloqueante por defecto.

  if (caracter == 0 || caracter == 224)
  {
    // Tecla especial, depende de un segundo código. Lo leemos.
    caracter = _getch();
    
    switch(caracter)
    {
      case 72: caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
      case 80: caracter = TECLA_ABAJO;     break;   // Flecha Abajo
      case 75: caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
      case 77: caracter = TECLA_DERECHA;   break;   // Flecha Derecha
      default: caracter = TECLA_NULA;               // Tecla nula.
    }
    else
    {
      // Normalización de teclas conflictivas no estándar.
      switch(caracter)
      {
        case 13: caracter = TECLA_ENTER;
        case 8:  caracter = TECLA_RETROCESO;
      }
    }
    
    return (char)caracter;
}

#else

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN (LINUX/MAC):
//
//    int obtenerTeclaInteractiva (void);
//
//  USO:
//
//    Lee una tecla del teclado de forma interactiva (sin eco, sin esperar
//    INTRO), detectando también las teclas especiales como las flechas.
//
//  DETALLES:
//
//    En Linux/Mac el terminal funciona en modo canónico por defecto: acumula
//    lo que se escribe hasta que se pulsa INTRO. Para distinguir si tras el
//    ESC vienen más bytes o era solo ESC, se pone momentáneamente en modo
//    no bloqueante. Al terminar restaura todo como estaba.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno.
//
//  VALOR DE SALIDA:
//
//    Devuelve el código de la tecla pulsada. Para teclas especiales
//    devuelve la constante correspondiente (TECLA_ARRIBA, TECLA_ABAJO,
//    TECLA_IZQUIERDA, TECLA_DERECHA, TECLA_ESCAPE, TECLA_NULA).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    tcgetattr() / tcsetattr()
//
//      Obtienen y aplican la configuración del terminal (modo raw/canónico).
//
//    getchar()
//
//      Lee bytes del teclado una vez el terminal está en modo raw.
//
//    fcntl()
//
//      Activa/desactiva el modo no bloqueante del descriptor de entrada
//      para detectar si el ESC va seguido de más bytes.
//
////////////////////////////////////////////////////////////////////////////////

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int obtenerTeclaInteractiva(void)
{
  struct termios terminaloriginal, terminalnueva;
  int caracter;

  // 1. Obtenemos la configuración actual de la terminal.
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;

  // 2. Desactivamos el modo canónico (espera de INTRO) y el ECO (ver la tecla al pulsar).
  terminalnueva.c_lflag &= ~(ICANON | ECHO); // Quitamos espera de INTRO y eco
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  
  // 3. El programa se detiene aquí hasta recibir un carácter.
  // Las flechas envían una secuencia de escape: 27 (ESC), 91 ('['), y una letra.
  caracter = getchar();
  
  if (caracter == ESCAPE)
  {
    // Cambiamos a NO BLOQUEANTE un instante para ver si hay bytes extra
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    
    // Pedimos a ver si hay otro caracter.
    int siguiente = getchar();
    
    // ¿Es '[' (91)?
    if (siguiente == '[')
    {
      // Lo desechamos simplemente no usando "siguiente".

      // Pedimos el tercer código de caracter generado.
      caracter = getchar();
      
      while ((siguiente = getchar()) != EOF && siguiente != -1);

      switch(caracter)
      {
        case 'A': caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
        case 'B': caracter = TECLA_ABAJO;     break;   // Flecha Abajo
        case 'D': caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
        case 'C': caracter = TECLA_DERECHA;   break;   // Flecha Derecha
        default:  caracter = TECLA_NULA;      break;
      }
    }
    else
    {
      if (siguiente == EOF || siguiente == -1)
      {
        // Era sólo la tecla ESCAPE.
        caracter = TECLA_ESCAPE;
      }
      else
      {
        // Era una secuencia no contemplada.
        caracter = TECLA_NULA;
      }
    }

    // Restauramos el modo BLOQUEANTE de la terminal.
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }

  // 4. Restauramos la configuración original antes de salir.
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  
  return caracter;
}

#endif
