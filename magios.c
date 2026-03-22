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

// bool Validar_Respuesta_Fecha
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
    int intentos_del_usuario = 0;
    char respuesta_ingresada = '.';
    bool respuesta_validez = true;
    int puntaje_total_usuario = 0;
    int puntaje_a_sumar = 0;
    int puntaje_a_restar = 0;
    
    //pregunta 1
    printf("¿Quién fundó realmente Springfield? \n [J]  Jebediah Springfield \n [A] Los aliens \n [S] Los Magios \n [B] Sr. Burns\n");
    scanf(" %c", &respuesta_ingresada);
    puntaje_a_sumar = 100;
    puntaje_a_restar = 20;
    respuesta_ingresada = Validar_Respuesta_Char(respuesta_ingresada, 'J', 'A', 'S', 'B');
    Corregir_Respuesta(respuesta_ingresada, &puntaje_total_usuario, 100,20, 'J', MAX_INTENTOS, &intentos_del_usuario);
        
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
    if(intentos_del_usuario < MAX_INTENTOS){
        printf("\n¿Cuál es su fecha de nacimiento? (formato: yyyy/mm): \n");
        scanf(" %c", &respuesta_ingresada);
    }
        
        
    
}

