#include <stdio.h>
#include <stdbool.h>

void ValidarRespuesta(char respuesta_ingresada, char opcion_1, char opcion_2, char opcion_3, char opcion_4){
    bool respuesta_validez = false;
    while(respuesta_validez == false){
        if(respuesta_ingresada != opcion_1 && respuesta_ingresada != opcion_2 && respuesta_ingresada != opcion_3 && respuesta_ingresada !=opcion_4 ){
            return;
        }
        else{
            printf("Respuesta inválida... Intente devuelta");
        }
    }
   
}

int main() {
    const MAX_INTENTOS = 3;
    int intentos_del_usuario = 0;
    char respuesta_ingresada = ".";
    bool respuesta_validez = true;
    int puntaje_total_usuario = 0;
    while(intentos_del_usuario <= MAX_INTENTOS){
        printf("¿Quién fundó realmente Springfield?");
        scanf(" %c", &respuesta_ingresada);
        ValidarRespuesta(respuesta_ingresada, 'J', 'A', 'S', 'B');
        CorregirRespuesta(respuesta_ingresada, 'J', 'A', 'S', 'B');
        
    };
}

