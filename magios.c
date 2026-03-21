#include <stdio.h>
#include <stdbool.h>

void ValidarRespuesta(char respuesta, char opcion_1_correcta, char opcion2, char opcion3, char opcion4){
    bool respuesta_validez = false;
    while(respuesta_validez == false){
        if(respuesta == opcion_1_correcta){
            printf("Correcto! +100 puntos.");
            respuesta_validez == true;
        }
        else if(respuesta == opcion2){
            printf("Incorrecto! Intente devuelta...  -20 puntos");
            respuesta_validez == true;
        }
        else if(respuesta == opcion3){
            printf("Incorrecto! Intente devuelta... -20 puntos");
            respuesta_validez == true;
        }
        else if(respuesta == opcion4){
            printf("Incorrecto! Intente devuelta... -20 puntos");
            respuesta_validez == true;
        }
        else{
            printf("Respuesta inválida... Intente devuelta");
        }
    }
   
}

int main() {
    const MAX_INTENTOS = 3;
    int intentos_del_usuario = 0;
    char respuesta_usuario = ".";
    bool respuesta_validez = true;
    while(intentos_del_usuario <= MAX_INTENTOS){
        printf("¿Quién fundó realmente Springfield?");
        scanf(" %c", &respuesta_usuario);
        ValidarRespuesta(respuesta_usuario, "J", "A", "S", "B");
        
        
    };
}

