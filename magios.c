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
    const int ANIO_ACTUAL = 2026;
    const int MES_ACTUAL = 3;
    const int ANIO_MINIMO_DIGITOS = 1000;
    const int ANIO_MAXIMO_DIGITOS = 9999;
    const int ANIO_MINIMO = 1926;
    const int MES_MINIMO_ANIO = 3;

    while(!valido){
        Ingreso_Fecha_Formato_Valido(anio, mes);
        
        if(*anio < 0){
            printf("EL año debe ser positivo!\nIntente devuelta:  ");
        }
        else if(*anio > ANIO_MAXIMO_DIGITOS || *anio < ANIO_MINIMO_DIGITOS){
            printf("El año debe ser de 4 digitos!\nIntente devuelta:  ");
        }           
        else if( (*anio == ANIO_MINIMO && *mes < MES_MINIMO_ANIO) || *anio < ANIO_MINIMO){
            printf("La fecha es inválida, aseguresé que la fecha debe ser de 4 dígitos, positivos y no menor del 1926/3 \nIntente devuelta: ");
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
int Validar_Respuesta_int(int respuesta_ingresada_int){
    bool valido = false;
    while(!valido){
        if((scanf("%i", &respuesta_ingresada_int)) != 1){
            printf("Debes ingresar un número entero... intente devuelta:\n");
        }
        else valido = true;
    }
    return respuesta_ingresada_int;
}
int Validar_Respuesta_rango_int(int respuesta_ingresada_int){
    bool valido = false;
    while(!valido){
        if(respuesta_ingresada_int > 0 || respuesta_ingresada_int > 12){
            printf("El número debe estar en el rango de 0 a 12!");
            respuesta_ingresada_int = Validar_Respuesta_int(respuesta_ingresada_int);
        }
        else valido = true;
    }
}

int Corregir_Respuesta(char respuesta_ingesada, int* puntaje_total_usuario, int puntaje_positivo_respuesta, int puntaje_negativo_respuesta, char opcion_correcta, int MAX_INTENTOS, int* intentos_del_usuario){
   int puntaje_usuario= 0; 
    while(respuesta_ingesada != opcion_correcta && *intentos_del_usuario < MAX_INTENTOS){
        puntaje_usuario -= puntaje_negativo_respuesta;
        printf("Intente devuelta: ");
        scanf(" %c", &respuesta_ingesada);
        respuesta_ingesada = Validar_Respuesta_Char_4Opciones(respuesta_ingesada, 'J', 'A', 'S', 'B');
        (*intentos_del_usuario)++;
        if( *intentos_del_usuario >= MAX_INTENTOS){
            printf("-RECHAZADO-\n");
            return;
        }
    }
    puntaje_usuario += puntaje_positivo_respuesta;
    return puntaje_usuario;
}

void Corregir_Respuesta_int(int respuesta_ingresada_int, int *puntaje_total_usuario){
    if(respuesta_ingresada_int == 0){
        *puntaje_total_usuario -= 100;
    }
    else if(respuesta_ingresada_int >= 1 && respuesta_ingresada_int <=3) {
        *puntaje_total_usuario += 10;
    }
    else if(respuesta_ingresada_int >= 4 && respuesta_ingresada_int <=6){
        *puntaje_total_usuario += 40;
    }
    else if(respuesta_ingresada_int >=7 && respuesta_ingresada_int <=9){
        *puntaje_total_usuario += 70;
    }
    else if(respuesta_ingresada_int >=10 && respuesta_ingresada_int <=12){
        *puntaje_total_usuario += 120;
    }
}

//final
void Determinar_Tipo_Mago(puntaje_total_usuario){
    if(puntaje_total_usuario )
}

int main() {
    const int MAX_INTENTOS = 3;
    int intentos_del_usuario=0;
    int puntaje_total_usuario = 0;
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
    puntos_pregunta1 = Corregir_Respuesta(respuesta_ingresada_char, &puntaje_total_usuario, puntaje_a_sumar, puntaje_a_restar, 'J', MAX_INTENTOS, &intentos_del_usuario);
        
    //pregunta 2
    printf("\n¿Promete mantener en secreto la existencia de los Magios?: \n[S] Sí \n[N] No\n");
    scanf(" %c", &respuesta_ingresada_char);
    puntaje_a_sumar = 50;
    puntaje_a_restar = 300;
    respuesta_validez_bool = Validar_Respuesta_Bool(respuesta_ingresada_char);
    if(respuesta_validez_bool){
        puntos_pregunta2 = puntaje_a_sumar;
    }
    else puntos_pregunta2 = puntaje_a_restar;
    
    

    //pregunta 3
    int anio, mes = 0;
    bool edad_valida = true;
    printf("\n¿Cuál es su fecha de nacimiento? (formato: yyyy/mm): \n");
    Validar_Rango_Fecha_Ingresada(&anio, &mes);
    edad_valida=Validar_Respuesta_Fecha(anio, mes);
    if(!edad_valida){
        intentos_del_usuario = 3;
        printf("-RECHAZADO-\n");
    }
    else{
        puntos_pregunta3= (edad_valida * 2);
    }
    
    
    //pregunta 4
    if(intentos_del_usuario == MAX_INTENTOS){
        printf("\n¿Cuántas donas estaría dispuesto a sacrificar para el Número Uno?:\n");
        respuesta_ingresada_int=Validar_Respuesta_int(respuesta_ingresada_int);
        respuesta_ingresada_int=Validar_Respuesta_rango_int(respuesta_ingresada_int);
        Corregir_Respuesta_int( respuesta_ingresada_int, &puntaje_total_usuario);
    }

    Determinar_Tipo_Mago(puntaje_total_usuario);
    
}

