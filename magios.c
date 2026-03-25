#include <stdio.h>
#include <stdbool.h>
const int ANIO_ACTUAL = 2026;
const int MES_ACTUAL = 3;
const int ANIO_MINIMO_DIGITOS = 1000;
const int ANIO_MAXIMO_DIGITOS = 9999;
const int ANIO_MINIMO = 1926;
const int MES_MINIMO_ANIO = 3;
const int MAX_INTENTOS = 3;

//FUNCIONES ATÓMICAS (SIMPLES)
void Identificar_Edad_Mayor_18(int edad_valida, int *puntos_pregunta3){
    printf("%i", edad_valida);
    if(!edad_valida){
        *puntos_pregunta3 = -1;
        printf("-RECHAZADO-\n");
    }
    else *puntos_pregunta3= (edad_valida * 2);
}

void Sumar_Puntos_Respuesta_Secreto(bool respuesta_validez_bool, int puntaje_a_sumar, int puntaje_a_restar, int *puntos_pregunta2){
    if(respuesta_validez_bool){
        *puntos_pregunta2 = puntaje_a_sumar;
    }
    else *puntos_pregunta2 = puntaje_a_restar;
}


void Validar_formato_ingreso_fecha(int* anio, int* mes){
    bool validez = false;
    while(!validez){
        validez = ((scanf("%d/%d", anio, mes)) == 2);
        if(validez == false){
            printf("Debe ingresar dos números validos (año y mes), entre una barra sin espacios! \n");
        }
    }
}
void Validar_Rango_Fecha_Ingresada(int* anio, int* mes){
    bool valido = false;
    while(!valido){
        Validar_formato_ingreso_fecha(anio, mes);
        
        if(*anio < 0){
            printf("EL año debe ser positivo!\nIntente devuelta:  ");
        }
        else if(*anio > ANIO_MAXIMO_DIGITOS || *anio < ANIO_MINIMO_DIGITOS){
            printf("El año debe ser de 4 digitos!\nIntente devuelta:  ");
        }           
        else if( (*anio == ANIO_MINIMO && *mes < MES_MINIMO_ANIO) || *anio < ANIO_MINIMO){
            printf("La fecha a ingresar no puede ser anterior a 1926/03...\nIntente devuelta:  ");
        }
        else if(*mes <= 0 || *mes > 12){
            printf("Asegúrese que el mes debe estar en el rango del mes 1 al 12!\nIntente devuelta: ");
        } 
        else if((*anio == ANIO_ACTUAL && *mes > MES_ACTUAL) || *anio > ANIO_ACTUAL){
            printf("La fecha a ingresar no puede superar la fecha actual: 2026/03...\nIntente devuelta:  ");
        }
        else{
            valido = true;
        }
    }
}

char Validar_Respuesta_Char_4Opciones(char respuesta_ingresada, char opcion_1, char opcion_2, char opcion_3, char opcion_4){
    bool respuesta_validez = false;
    while(respuesta_validez == false){
        if(respuesta_ingresada == opcion_1 || respuesta_ingresada == opcion_2 || respuesta_ingresada == opcion_3 || respuesta_ingresada == opcion_4 ){
            respuesta_validez = true;   
        }
        else{
            printf("Respuesta inválida... Intente devuelta: ");
            scanf(" %c", &respuesta_ingresada);
        }
    }
    return respuesta_ingresada;
   
}
char Validar_Respuesta_Char_2Opciones(char respuesta_ingresada, char opcion_1, char opcion_2){
    bool respuesta_validez = false;
    while(respuesta_validez == false){
        if(respuesta_ingresada == opcion_1 || respuesta_ingresada == opcion_2 ){
            respuesta_validez = true;   
        }
        else{
            printf("Respuesta inválida... Intente devuelta: ");
            scanf(" %c", &respuesta_ingresada);
        }
    }
    return respuesta_ingresada;
   
}
bool Validar_Respuesta_Bool(char respuesta){
    respuesta = Validar_Respuesta_Char_2Opciones(respuesta, 'S','N');
    return (respuesta == 'S');
}
void Calcular_Es_Mayor_18(int anio_usuario, int mes_usuario, int *edad){
    *edad = ANIO_ACTUAL - anio_usuario;
    if(MES_ACTUAL < mes_usuario){
        (*edad)--;
    };
}
int Validar_Respuesta_Int_Pregunta_4(int respuesta_ingresada_int){
    bool valido = false;
    while(!valido){
        if((scanf("%i", &respuesta_ingresada_int)) != 1){
            printf("Debes ingresar un número entero... intente devuelta:\n");
        }
        else valido = true;
    }
    return respuesta_ingresada_int;
}
int Validar_Respuesta_Rango_Pregunta_4(int respuesta_ingresada_int){
    bool valido = false;
    while(!valido){
        if(respuesta_ingresada_int < 0 || respuesta_ingresada_int > 12){
            printf("El número debe estar en el rango de 0 a 12!");
            respuesta_ingresada_int = Validar_Respuesta_Int_Pregunta_4(respuesta_ingresada_int);
        }
        else valido = true;
    }
}

void Corregir_Respuesta(char respuesta_ingesada, int puntaje_positivo_respuesta, int puntaje_negativo_respuesta, char opcion_correcta, int intentos_del_usuario, int *puntos_pregunta1 ){
   int puntaje_usuario= 0;
   intentos_del_usuario++;
    while(respuesta_ingesada != opcion_correcta && intentos_del_usuario < MAX_INTENTOS){
        *puntos_pregunta1 -= puntaje_negativo_respuesta;
        printf("RESPUESTA INCORRECTA... Intente devuelta: ");
        scanf(" %c", &respuesta_ingesada);
        respuesta_ingesada = Validar_Respuesta_Char_4Opciones(respuesta_ingesada, 'J', 'A', 'S', 'B');
        (intentos_del_usuario)++;

        if( intentos_del_usuario >= MAX_INTENTOS){
            printf("-RECHAZADO-\n");
            *puntos_pregunta1 = -1;
        }
    }
    if(respuesta_ingesada == opcion_correcta){
        *puntos_pregunta1 += puntaje_positivo_respuesta;
    }
}
void Corregir_Respuesta_Pregunta_4(int respuesta_ingresada_int, int *puntos_pregunta4){
   printf("%i", respuesta_ingresada_int);
    if(respuesta_ingresada_int == 0){
        *puntos_pregunta4 = -100;
    }
    else if(respuesta_ingresada_int >= 1 && respuesta_ingresada_int <=3) {
        *puntos_pregunta4 = 10;
    }
    else if(respuesta_ingresada_int >= 4 && respuesta_ingresada_int <=6){
        *puntos_pregunta4 = 40;
    }
    else if(respuesta_ingresada_int >=7 && respuesta_ingresada_int <=9){
        *puntos_pregunta4 = 70;
    }
    else if(respuesta_ingresada_int >=10 && respuesta_ingresada_int <=12){
        *puntos_pregunta4 = 120;
    }
}

//final
void Determinar_Tipo_Mago(int puntos_pregunta1,int puntos_pregunta2, int puntos_pregunta3, int puntos_pregunta4){

    printf("%i\n", puntos_pregunta4); 
    int puntaje_final_usuario = puntos_pregunta1 + puntos_pregunta2 + puntos_pregunta3 + puntos_pregunta4;
    if( puntaje_final_usuario < 0 ) printf("Según tus respuestas, tu estado es..... -RECHAZADO- ");
    else if ( puntaje_final_usuario > 0 && puntaje_final_usuario <= 150 ) printf("Según tus respuestas, tu estado es..... -ASPIRANTE- \n");
    else if ( puntaje_final_usuario >= 151 && puntaje_final_usuario <= 250 ) printf("Según tus respuestas, tu estado es..... -MAGIO NOVATO- \n");
    else if ( puntaje_final_usuario >= 251 && puntaje_final_usuario <= 349 ) printf("Según tus respuestas, tu estado es..... -MAGIO-\n ");
    else if ( puntaje_final_usuario >= 350 ) printf("Según tus respuestas, tu estado es..... -LIDER SUPREMO- \n ");
}   

int main() {
    
    int intentos_del_usuario=0;
    int puntaje_a_sumar = 0;
    int puntaje_a_restar = 0;
    char respuesta_ingresada_char = '.';
    bool respuesta_validez_bool = true;
    int respuesta_ingresada_int = 0;
    int puntos_pregunta1 = 0;
    int puntos_pregunta2 = 0;
    int puntos_pregunta3 = 0;
    int puntos_pregunta4 = 0;
    
    //pregunta 1
    printf("¿Quién fundó realmente Springfield? \n [J]  Jebediah Springfield \n [A] Los aliens \n [S] Los Magios \n [B] Sr. Burns\n");
    scanf(" %c", &respuesta_ingresada_char);
    puntaje_a_sumar = 100;
    puntaje_a_restar = 20;

    respuesta_ingresada_char = Validar_Respuesta_Char_4Opciones(respuesta_ingresada_char, 'J', 'A', 'S', 'B');
    Corregir_Respuesta(respuesta_ingresada_char, puntaje_a_sumar, puntaje_a_restar, 'J', intentos_del_usuario, &puntos_pregunta1);
    printf("\nPuntos obtenidos en la pregunta 1: %i\n", puntos_pregunta1);


    if(puntos_pregunta1 != -1){

        //pregunta 2
        printf("\n¿Promete mantener en secreto la existencia de los Magios?: \n[S] Sí \n[N] No\n");
        scanf(" %c", &respuesta_ingresada_char);
        puntaje_a_sumar = 50;
        puntaje_a_restar = 300;
        respuesta_validez_bool = Validar_Respuesta_Bool(respuesta_ingresada_char);
        Sumar_Puntos_Respuesta_Secreto(respuesta_validez_bool, puntaje_a_sumar, puntaje_a_restar, &puntos_pregunta2);
        printf("\nPuntos obtenidos en la pregunta 2: %i\n", puntos_pregunta2);
        
        //pregunta 3
        int anio, mes = 0;
        int edad_valida = true;

        printf("\n¿Cuál es su fecha de nacimiento? (formato: yyyy/mm): \n");
        Validar_Rango_Fecha_Ingresada(&anio, &mes);
        Calcular_Es_Mayor_18(anio, mes, &edad_valida);
        Identificar_Edad_Mayor_18(edad_valida, &puntos_pregunta3);
        printf("\nPuntos obtenidos en la pregunta 3: %i\n", puntos_pregunta3);
        
        if(puntos_pregunta3 != -1){
            
            //pregunta 4
            
                printf("\n¿Cuántas donas estaría dispuesto a sacrificar para el Número Uno?:\n");
                respuesta_ingresada_int=Validar_Respuesta_Int_Pregunta_4(respuesta_ingresada_int);
                respuesta_ingresada_int=Validar_Respuesta_Rango_Pregunta_4(respuesta_ingresada_int);
                Corregir_Respuesta_Pregunta_4(respuesta_ingresada_int, &puntos_pregunta4);
                printf("\nPuntos obtenidos en la pregunta 4: %i\n", puntos_pregunta4);
            

            Determinar_Tipo_Mago(puntos_pregunta1, puntos_pregunta2, puntos_pregunta3, puntos_pregunta4);
        }    
    }
}

