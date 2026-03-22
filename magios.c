#include <stdio.h>
#include <stdbool.h>

char Validar_Respuesta_Char(char respuesta_ingresada, char opcion_1, char opcion_2, char opcion_3, char opcion_4){
    bool respuesta_validez = false;
    while(respuesta_validez == false){
        if(respuesta_ingresada == opcion_1 || respuesta_ingresada == opcion_2 || respuesta_ingresada == opcion_3 || respuesta_ingresada ==opcion_4 ){
            respuesta_validez = true;   
        }
        else{
            printf("Respuesta inválida... Intente devuelta");
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
    
        printf("Incorrecto... -%d\n", puntaje_negativo_respuesta);
        *puntaje_total_usuario -= puntaje_negativo_respuesta;

        printf("Intente devuelta: ");
        scanf(" %c", &respuesta_ingesada);
        (*intentos_del_usuario)++;
        if( intentos_del_usuario >= MAX_INTENTOS){
            printf("-RECHAZADO-");
            return;
        }
        
    }
    printf("Correcto! +%d\n", puntaje_positivo_respuesta);
    *puntaje_total_usuario += puntaje_positivo_respuesta;


}

int main() {
    const int MAX_INTENTOS = 3;
    int intentos_del_usuario = 0;
    char respuesta_ingresada = '.';
    bool respuesta_validez = true;
    int puntaje_total_usuario = 0;
    
        printf("¿Quién fundó realmente Springfield? \n J) \n A) \n S) \n B)");
        scanf(" %c", &respuesta_ingresada);
        respuesta_ingresada = Validar_Respuesta_Char(respuesta_ingresada, 'J', 'A', 'S', 'B');
        Corregir_Respuesta(respuesta_ingresada, &puntaje_total_usuario, 100,20, 'J', MAX_INTENTOS, &intentos_del_usuario);

        if(intentos_del_usuario <= MAX_INTENTOS){
            printf("\n¿Promete mantener en secreto la existencia de los Magios? [S/N]: ");
            scanf(" %c", &respuesta_ingresada);
            bool respuesta_bool = Validar_Respuesta_Bool(respuesta_ingresada);
            if(respuesta_bool){
                puntaje_total_usuario += 50;
            }
            else{
                puntaje_total_usuario -= 300;
            }
        }
        
        
    
}

