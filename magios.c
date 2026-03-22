#include <stdio.h>
#include <stdbool.h>

//FUNCIONES ATÓMICAS (SIMPLES)
void Sumar_Puntos(int puntaje_positivo_respuesta, int* puntaje_total_usuario){
    printf("Correcto! +%d\n", puntaje_positivo_respuesta);
    *puntaje_total_usuario += puntaje_positivo_respuesta;
}
void Restar_Puntos(int puntaje_negativo_respuesta, int* puntaje_total_usuario){
    printf("Incorrecto... -%d\n", puntaje_negativo_respuesta);
    *puntaje_total_usuario -= puntaje_negativo_respuesta;
}
void Ingreso_Fecha_Formato_Valido(int* anio, int* mes){
    bool validez = true;
    while(validez){
        validez = (scanf("%d/%d", anio, mes)) == 2;
        if(validez == false){
            printf("Debe ingresar dos números validos (año y mes), entre una barra sin espacios! \n");
        }
    }
}
void Validar_Rango_Fecha_Ingresada(int* anio, int* mes){
    bool valido = false;
    Ingreso_Fecha_Valido(anio, mes);
    while(!valido){
        if(*anio > 9999 || *anio < 1000 || (*anio < 1926 && *mes < 3) || *anio < 1926){
            printf("La fecha es inválida, aseguresé que la fecha debe ser de 4 dígitos, positivos y no menor del 1926/3 \nIntente devuelta: ");
            Ingreso_Fecha_Formato_Valido(anio, mes);
        }
        else if(*mes <= 0 || *mes > 12){
            printf("Asegúrese que el mes debe estar en el rango del mes 1 al 12!\nIntente devuelta: ");
            Ingreso_Fecha_Formato_Valido(anio, mes);
        }
        else if((*anio > 2026 && *mes < 3) || *anio > 2026){
            printf("La fecha a ingresar no puede superar la fecha actual: 2026/03...\nIntente devuelta:  ");
            Ingreso_Fecha_Formato_Valido(anio, mes);
        }
        else{
            valido = true;
        }
    }
}

char Validar_Respuesta_Char(char respuesta_ingresada, char opcion_1, char opcion_2, char opcion_3, char opcion_4){
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
bool Validar_Respuesta_Bool(char respuesta){
    respuesta = Validar_Respuesta_Char(respuesta, 'S','N','0','0');
    return (respuesta == 'S');
}
bool Validar_Respuesta_Fecha(int anio_usuario, int mes_usuario){
    int anio_actual = 2026;
    int mes_actual = 3;
    int edad = 0;

    edad = anio_actual - anio_usuario;
    if(mes_actual < mes_usuario){
        edad--;
    };
    
    return (edad>=18);
}
// int Validar_Respuesta_Rango

void Corregir_Respuesta(char respuesta_ingesada, int* puntaje_total_usuario, int puntaje_positivo_respuesta, int puntaje_negativo_respuesta, char opcion_correcta, int MAX_INTENTOS, int* intentos_del_usuario){

    while(respuesta_ingesada != opcion_correcta && *intentos_del_usuario < MAX_INTENTOS){
    
        Restar_Puntos(puntaje_negativo_respuesta, puntaje_total_usuario);

        printf("Intente devuelta: ");
        scanf(" %c", &respuesta_ingesada);
        (*intentos_del_usuario)++;
        if( *intentos_del_usuario >= MAX_INTENTOS){
            printf("-RECHAZADO-\n");
            return;
        }
    }
    Sumar_Puntos(puntaje_positivo_respuesta, puntaje_total_usuario);
}



int main() {
    const int MAX_INTENTOS = 3;
    int intentos_del_usuario, puntaje_total_usuario = 0;
    int puntaje_a_sumar, puntaje_a_restar = 0;
    char respuesta_ingresada = '.';
    bool respuesta_validez = true;
    
    //pregunta 1
    printf("¿Quién fundó realmente Springfield? \n [J]  Jebediah Springfield \n [A] Los aliens \n [S] Los Magios \n [B] Sr. Burns\n");
    scanf(" %c", &respuesta_ingresada);
    puntaje_a_sumar = 100;
    puntaje_a_restar = 20;
    respuesta_ingresada = Validar_Respuesta_Char(respuesta_ingresada, 'J', 'A', 'S', 'B');
    Corregir_Respuesta(respuesta_ingresada, &puntaje_total_usuario, puntaje_a_sumar, puntaje_a_restar, 'J', MAX_INTENTOS, &intentos_del_usuario);
        
    //pregunta 2
    if(intentos_del_usuario < MAX_INTENTOS){
        printf("\n¿Promete mantener en secreto la existencia de los Magios?: \n[S] Sí \n[N] No\n");
        scanf(" %c", &respuesta_ingresada);
        puntaje_a_sumar = 50;
        puntaje_a_restar = 300;
        respuesta_validez = Validar_Respuesta_Bool(respuesta_ingresada);
        if(respuesta_validez){
            Sumar_Puntos(puntaje_a_sumar, &puntaje_total_usuario);
        }
        else{
            Restar_Puntos(puntaje_a_sumar, &puntaje_total_usuario);
        }
    }

    //pregunta 3
    if(intentos_del_usuario < MAX_INTENTOS){
        int anio, mes = 0;
        bool edad_valida = true;
        printf("\n¿Cuál es su fecha de nacimiento? (formato: yyyy/mm): \n");
        Validar_Rango_Fecha_Ingresada(&anio, &mes);
        edad_valida=Validar_Respuesta_Fecha(anio, mes);
        if(!edad_valida){
            intentos_del_usuario = 3;
            printf("-RECHAZADO-\n");
        };
    }
        
        
    
}

