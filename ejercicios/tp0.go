package ejercicios

const (
	VALOR_INVALIDO = -1
	VALOR_NULO     = 0
)

// Swap intercambia dos valores enteros.
func Swap(x *int, y *int) {
	*x, *y = *y, *x
}

// Maximo devuelve la posición del mayor elemento del arreglo, o -1 si el el arreglo es de largo 0. Si el máximo
// elemento aparece más de una vez, se debe devolver la primera posición en que ocurre.
func Maximo(vector []int) int {
	posicionMaximoElemento := VALOR_NULO
	if len(vector) != VALOR_NULO {
		for i := VALOR_NULO; i < len(vector); i++ {
			if vector[i] > vector[posicionMaximoElemento] {
				posicionMaximoElemento = i
			}
		}
		return posicionMaximoElemento
	}
	return -1
}

// Comparar compara dos arreglos de longitud especificada.
// Devuelve -1 si el primer arreglo es menor que el segundo; 0 si son iguales; o 1 si el primero es el mayor.
// Un arreglo es menor a otro cuando al compararlos elemento a elemento, el primer elemento en el que difieren
// no existe o es menor.
func Comparar(vector1 []int, vector2 []int) int {
	primerMayor, primerMenor := false, false

	for i:=0; i < len(vector1); i++ {
		for j:=0; j < len(vector2); j++ {
			if vector1[i] != vector2[j] {
				if vector1[i] < vector2[j] {
					primerMenor = true
				} else if vector1[i] > vector2[j] {
					primerMayor = true
				}
			}
		}
	}
	if primerMayor{
		return -1
	} else if primerMenor{
		return 1
	}
	return 0
}

// Seleccion ordena el arreglo recibido mediante el algoritmo de selección.
func Seleccion(vector []int) {
	for i := len(vector) - 1; i > VALOR_NULO; i-- {
		vectorSiguiente := vector[:i+1]
		posicionMaximoElemento := Maximo(vectorSiguiente)
		Swap(&vector[i], &vector[posicionMaximoElemento])
	}
}

// Suma devuelve la suma de los elementos de un arreglo. En caso de no tener elementos, debe devolver 0.
// Esta función debe implementarse de forma RECURSIVA. Se puede usar una función auxiliar (que sea
// la recursiva).
func Suma(vector []int) int {
	if len(vector)!=VALOR_NULO {
		numeroActual := vector[0]
		sliceSiguiente := vector[1:]
		return numeroActual + Suma(sliceSiguiente)
	}
	return 0
}

// EsCadenaCapicua devuelve si la cadena es un palíndromo. Es decir, si se lee igual al derecho que al revés.
// Esta función debe implementarse de forma RECURSIVA. Se puede usar una función auxiliar (que sea
// la recursiva).
func EsPalindromo(primerIndice int, ultimoIndice int, cadena string ) bool {
	esCadenaPalindromo := false
	if primerIndice >= ultimoIndice {
		esCadenaPalindromo = true	
	} else if primerIndice == VALOR_NULO && ultimoIndice == VALOR_NULO {
		esCadenaPalindromo = true
	} else {
		if cadena[primerIndice] == cadena[ultimoIndice] {
			return EsPalindromo(primerIndice+1, ultimoIndice-1, cadena)
		}
	}
	return esCadenaPalindromo
}
func EsCadenaCapicua(cadena string) bool {
	EsCapicua := EsPalindromo(VALOR_NULO, len(cadena)-1, cadena)
	return EsCapicua
}