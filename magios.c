#include <stdio.h>
#include <stdbool.h>
/*CONSTANTES*/
const int ANIO_ACTUAL = 2026;
const int MES_ACTUAL = 3;
const int NUMERO_DE_FINALIZAR_PROGRAMA = -1;
//Pregunta 1
const int PUNTAJE_A_SUMAR_PREGUNTA_1 = 100;
const int PUNTAJE_A_RESTAR_PREGUNTA_1 = 20;
const char JEBEDIAH = 'J';
const char BURNS = 'B';
const char MAGIOS = 'S';
const char ALIENS = 'A';
//Pregunta 2
const int PUNTAJE_A_SUMAR_PREGUNTA_2 = 50;
const int PUNTAJE_A_RESTAR_PREGUNTA_2 = 300;
const char SI = 'S';
const char NO = 'N';
//Pregunta 3
const int ANIO_MINIMO_DIGITOS = 1000;
const int ANIO_MAXIMO_DIGITOS = 9999;
const int ANIO_MINIMO = 1926;
const int MES_MINIMO_ANIO = 3;
const int MAX_INTENTOS = 3;
//Pregunta 4
const int PUNTOS_MAXIMOS_DONAS = 120;
const int PUNTOS_MINIMOS_DONAS = -100;
const int PUNTOS_DONAS_1_3 = 10;
const int PUNTOS_DONAS_4_6 = 40;
const int PUNTOS_DONAS_7_9 = 70;    
//--------------------------------------------------//

/*****FUNCIONES******/
//pregunta 1

void preguntar_pregunta_1(char *respuesta_ingresada_char){
    printf("¿Quién fundó realmente Springfield? \n [J]  Jebediah Springfield \n [A] Los aliens \n [S] Los Magios \n [B] Sr. Burns\n");
    scanf(" %c", respuesta_ingresada_char);
}
void preguntar_devuelta_incorrecta_1(char *respuesta_ingesada){
    printf("RESPUESTA INCORRECTA... Intente devuelta: ");
    scanf(" %c", respuesta_ingesada);
}
void preguntar_devuelta_invalido(char *respuesta_ingresada){
    printf("Respuesta inválida... Intente devuelta: ");
    scanf(" %c", respuesta_ingresada);
}

/*
    PRE: Las opciones deben ser caracteres válidos y distintos
    POS: Devuelve el carácter válido ingresado por el usuario, es decir, que es igual a alguna de las opciones ingresadas por parámentro
*/
char validar_respuesta_char_4_opciones(char respuesta_ingresada){
    bool respuesta_validez = false;
    while(respuesta_validez == false){
        if(respuesta_ingresada == JEBEDIAH || respuesta_ingresada == ALIENS || respuesta_ingresada == MAGIOS || respuesta_ingresada == BURNS ){
            respuesta_validez = true;   
        }
        else{
            preguntar_devuelta_invalido(char *respuesta_ingresada);
        }
    }
    return respuesta_ingresada;
   
}
/*
    PRE: La respuesta que se ingresa debe ser un carácter válido (ser una de las opciones de respuesta) y debe entrar la opcion correcta.
    POS: Según la respuesta ingresada por el usuario, se van a restar o sumar puntos. En caso de que la repsuetsa es incorrecta, se le va a pedir al usuario que ingrese una nueva respuesta hasta que ingrese la correcta. En caso de que el usuario use los 3 intentos (el máximo) , se le asigna el puntaje -1 para finalizar el programa.
*/
void corregir_respuesta_pregunta_1(char respuesta_ingesada, int *puntos_pregunta1 ){
    int intentos_del_usuario=1;
    
    while(respuesta_ingesada != opcion_correcta && intentos_del_usuario < MAX_INTENTOS){
        *puntos_pregunta1 -= PUNTAJE_A_RESTAR_PREGUNTA_1;
        preguntar_devuelta_incorrecta_1(char &respuesta_ingesada);
        respuesta_ingesada = validar_respuesta_char_4_opciones(respuesta_ingesada);
        if(respuesta_ingesada != JEBEDIAH){
            intentos_del_usuario++;
        }
        if( intentos_del_usuario == MAX_INTENTOS ){
            printf("-RECHAZADO-\n");
            *puntos_pregunta1 = NUMERO_DE_FINALIZAR_PROGRAMA;
        }
    }
    if(respuesta_ingesada == JEBEDIAH){
        *puntos_pregunta1 += PUNTAJE_A_SUMAR_PREGUNTA_1;
    }
}
//pregunta 2
void preguntar_pregunta_2(char *respuesta_ingresada_char){
    printf("\n¿Promete mantener en secreto la existencia de los Magios?: \n[S] Sí \n[N] No\n");
    scanf(" %c", respuesta_ingresada_char);
}
/*
    PRE: Las opciones deben ser caracteres válidos y distintos.
    POS: Devuelve un carácter válido ingresado por el usuario. Si ingresa un carácter inválido, se le va a pedir que ingrese una nueva respuesta hasta que ingrese una válida, sin contar ningun intento como incorrecto.
*/
char validar_respuesta_char_2_opciones(char respuesta_ingresada){
    bool respuesta_validez = false;
    while(respuesta_validez == false){
        if((respuesta_ingresada == SI)|| (respuesta_ingresada == NO )){
            respuesta_validez = true;   
        }
        else{
            preguntar_devuelta_invalido(&respuesta_ingresada);
        }
    }
    return respuesta_ingresada;
   
}
/*
    PRE: La respuesta que se ingresa debe ser un carácter válido (ser una de las opciones de respuesta) y debe ser un booleano que indique sí o no, V o F.
    POS: Devuelve un valor booleano según la respuesta ingresada. Si la repsuesta es "S", va a devolver un true, sino un false.
*/
bool identificar_respuesta_bool_pregunta_3(char respuesta){
    respuesta = validar_respuesta_char_2_opciones(respuesta);
    return (respuesta == SI);
}
/*
    PRE: La respuetsa ingresada debe ser válida (ser un carácter entre las opciones de resppuesta) y booleano que indique sí si o no.
    POS: Según la respuesta booleana, se van a restar o sumar puntos.
*/
void sumar_puntos_respuesta_bool_pregunta_2(bool respuesta_validez_bool, int *puntos_pregunta2){
    if(respuesta_validez_bool){
        *puntos_pregunta2 = PUNTAJE_A_SUMAR_PREGUNTA_2;
    }
    else *puntos_pregunta2 = -(PUNTAJE_A_RESTAR_PREGUNTA_2);
    printf("PUNTAJE PREGUNTA 2: %i\n", *puntos_pregunta2);
}
//pregunta 3
/*
    PRE: El año y el mes del usuario deben ser número enteros y respetar el orden de ingreso indicado (año/mes).
    POS: se valida infinitamente el formato de ingreso de la fecha, hasta que el usuario ingrese un formato correcto, es decir, dos números enteros separados por una barra sin espacios
*/
void validar_ingreso_positivo_fecha(int* anio, int* mes){
    bool validez = false;
    while(!validez){
        scanf("%d/%d", anio, mes);
        if(*anio < 0 || *mes < 0){
            printf("Debe ingresar dos números enteros positivos!\n Intente devuelta: ");
        }
        else validez = true;
    }
}
/*
    PRE: El año y el mes del usuario deben ser número enteros y respetar el orden de ingreso indicado (año/mes).
    POS: se valida infinitamente el rango de la fecha ingresada, hasta que el usuario ingrese un rango válido. Se devuelve el año y el mes una vez termine el ciclo de validición.
*/
void validar_rango_fecha_ingresada(int* anio, int* mes){
    bool valido = false;
    while(!valido){
        validar_ingreso_positivo_fecha(anio, mes);
        
        if(*anio < 0){
            printf("EL año debe ser positivo!\nIntente devuelta:  ");
        }
        else if((*anio > ANIO_MAXIMO_DIGITOS) || (*anio < ANIO_MINIMO_DIGITOS)){
            printf("El año debe ser de 4 digitos!\nIntente devuelta:  ");
        }           
        else if( (*anio == ANIO_MINIMO) && (*mes < MES_MINIMO_ANIO) || (*anio < ANIO_MINIMO) ){
            printf("La fecha a ingresar no puede ser anterior a 1926/03...\nIntente devuelta:  ");
        }
        else if((*mes <= 0)|| (*mes > 12)){
            printf("Asegúrese que el mes debe estar en el rango del mes 1 al 12!\nIntente devuelta: ");
        } 
        else if(((*anio == ANIO_ACTUAL) && (*mes > MES_ACTUAL)) || (*anio > ANIO_ACTUAL)){
            printf("La fecha a ingresar no puede superar la fecha actual: 2026/03...\nIntente devuelta:  ");
        }
        else{
            valido = true;
        }
    }
}
/*
    PRE: El año y el mes del usuario deben ser número enteros y respetar el orden de ingreso indicado (año/mes). 
    POS: Se calcula la edad del usuario y se devuelve. Ya sea mayor o menor a 18 años, se devuelve la edad calculada.
*/
void calcular_edad(int anio_usuario, int mes_usuario, int *edad){
    *edad = ANIO_ACTUAL - anio_usuario;
    if(MES_ACTUAL < mes_usuario){
        (*edad)--;
    };
}
/*
    PRE: La edad del usuario debe ser un número entero
    POS: Si la edad del usuario es menor a 18 años, se le asigna el puntaje -1 para finalizar el programa. Si la edad es mayor o igual a 18 años, se multiplica por dos y se asigna al puntaje de la pregunta 3.
*/
void corregir_edad_mayor_18_pregunta_3(int edad_valida, int *puntos_pregunta3){
    if(edad_valida < 18){
        *puntos_pregunta3 = NUMERO_DE_FINALIZAR_PROGRAMA;
        printf("-RECHAZADO-\n");
    }
    else *puntos_pregunta3= (edad_valida * 2);
}

//pregunta 4
/*
    PRE: La respuesta ingresada debe ser un número entero.
    POS: se valida infinitamente el ingreso del entero hasta que el usuario ingrese un número entero válido. Se devuelve el número entero ingresado por el usuario una vez termine el ciclo de validación.
*/
int validar_respuesta_int_pregunta_4(int respuesta_ingresada_int){
    bool valido = false;
    while(!valido){
        
        if((scanf("%i", &respuesta_ingresada_int)!= 1){
            printf("Debes ingresar un número entero... intente devuelta:\n");
        }
        else valido = true;
    }
    return respuesta_ingresada_int;
}
/*
    PRE: La respuesta ingresada debe ser un número entero válido.
    POS: se valida infinitamente el rango ( 0-12 ) del número ingresado por el usuario, hasta que el usuario ingrese un número dentro del rango. Se devuelve el número entero ingresado por el usuario una vez termine el ciclo de validación. En el caso de no ingresar un número valido, se el pide que vuelva a ingresar un número, y se valida nuevamente para evitar errores.
*/
int validar_respuesta_rango_pregunta_4(int respuesta_ingresada_int){
    bool valido = false;
    while(!valido){
        if(respuesta_ingresada_int < 0 || respuesta_ingresada_int > 12){
            printf("El número debe estar en el rango de 0 a 12!");
            respuesta_ingresada_int = validar_respuesta_int_pregunta_4(respuesta_ingresada_int);
        }
        else valido = true;
    }
    return respuesta_ingresada_int;
}
/*
    PRE: La respuesta ingresada debe ser un número entero válido dentro del rango de 0 a 12.
    POS: Según el número de donas ingresado por el usuario, se asigna una cantidad de puntos determinada. 
*/
void corregir_respuesta_pregunta_4(int respuesta_ingresada_int, int *puntos_pregunta4){
    if(respuesta_ingresada_int == 0){
        *puntos_pregunta4 = PUNTOS_MINIMOS_DONAS;
    }
    else if((respuesta_ingresada_int >= 1) && (respuesta_ingresada_int <=3)) {
        *puntos_pregunta4 = PUNTOS_DONAS_1_3;
    }
    else if((respuesta_ingresada_int >= 4) && (respuesta_ingresada_int <=6)){
        *puntos_pregunta4 = PUNTOS_DONAS_4_6;
    }
    else if((respuesta_ingresada_int >=7) && (respuesta_ingresada_int <=9)){
        *puntos_pregunta4 = PUNTOS_DONAS_7_9;
    }
    else if((respuesta_ingresada_int >=10) && (respuesta_ingresada_int <=12)){
        *puntos_pregunta4 = PUNTOS_MAXIMOS_DONAS;
    }
}

//final
/*
    PRE: -.
    POS: Se suman los puntos de cada pregunta para obtener el puntaje final del usuario, y se le asigna un estado de magio al usuario.
*/
void determinar_tipo_mago(int puntos_pregunta1,int puntos_pregunta2, int puntos_pregunta3, int puntos_pregunta4){
    int puntaje_final_usuario = puntos_pregunta1 + puntos_pregunta2 + puntos_pregunta3 + puntos_pregunta4;
    if( puntaje_final_usuario < 0 ) printf("Según tus respuestas, tu estado es..... -RECHAZADO- ");
    else if( (puntaje_final_usuario >= 0) && (puntaje_final_usuario <= 150) ){
        printf("Según tus respuestas, tu estado es..... -ASPIRANTE- \n");
    }
    else if ( (puntaje_final_usuario > 150) && (puntaje_final_usuario <= 250) ){
        printf("Según tus respuestas, tu estado es..... -MAGIO NOVATO- \n");
    }
    else if ( (puntaje_final_usuario > 250) && (puntaje_final_usuario <= 349) ){
        printf("Según tus respuestas, tu estado es..... -MAGIO-\n ");
    }
    else if ( puntaje_final_usuario > 349 ){
        printf("Según tus respuestas, tu estado es..... -LIDER SUPREMO- \n ")
    }
    printf("SU PUNTAJE FINAL HA SIDO: %i\n", puntaje_final_usuario); 
}   

int main() {
    
    char respuesta_ingresada_char = '.';
    bool respuesta_validez_bool = true;
    int respuesta_ingresada_int = 0;
    int puntos_pregunta1 = 0;
    int puntos_pregunta2 = 0;
    int puntos_pregunta3 = 0;
    int puntos_pregunta4 = 0;
    int anio = 0;
    int mes = 0;
    int edad = 0;
    
    //pregunta 1
    preguntar_pregunta_1(&respuesta_ingresada_char)
    respuesta_ingresada_char = validar_respuesta_char_4_opciones(respuesta_ingresada_char);
    corregir_respuesta_pregunta_1(respuesta_ingresada_char, JEBEDIAH, &puntos_pregunta1);
    
    if(puntos_pregunta1 != NUMERO_DE_FINALIZAR_PROGRAMA){
        //pregunta 2
        
        respuesta_validez_bool = identificar_respuesta_bool_pregunta_3(respuesta_ingresada_char);
        sumar_puntos_respuesta_bool_pregunta_2(respuesta_validez_bool, &puntos_pregunta2);
    
        //pregunta 3
        printf("\n¿Cuál es su fecha de nacimiento? (formato: yyyy/mm): \n");
        validar_rango_fecha_ingresada(&anio, &mes);
        calcular_edad(anio, mes, &edad);
        corregir_edad_mayor_18_pregunta_3(edad, &puntos_pregunta3);
        
        if(puntos_pregunta3 != NUMERO_DE_FINALIZAR_PROGRAMA){
            //pregunta 4
            printf("\n¿Cuántas donas estaría dispuesto a sacrificar para el Número Uno?:\n");
            respuesta_ingresada_int=validar_respuesta_int_pregunta_4(respuesta_ingresada_int);
            respuesta_ingresada_int=validar_respuesta_rango_pregunta_4(respuesta_ingresada_int);
            corregir_respuesta_pregunta_4(respuesta_ingresada_int, &puntos_pregunta4);
            //FINAL
            determinar_tipo_mago(puntos_pregunta1, puntos_pregunta2, puntos_pregunta3, puntos_pregunta4);
        }    
    }
}

