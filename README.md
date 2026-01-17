# Push_swap

*Este proyecto ha sido creado como parte del currículum de 42 por aarogarc.*

## Descripción

Push_swap es un proyecto de algoritmos de ordenación que consiste en ordenar una pila de números enteros utilizando un conjunto limitado de operaciones, con el objetivo de hacerlo en el menor número de movimientos posible.

El programa trabaja con dos pilas (pila A y pila B) y debe ordenar los números en la pila A en orden ascendente utilizando únicamente las siguientes operaciones:
- **sa/sb/ss**: intercambiar los dos primeros elementos de la pila
- **pa/pb**: mover el primer elemento de una pila a otra
- **ra/rb/rr**: rotar la pila hacia arriba (el primer elemento se convierte en el último)
- **rra/rrb/rrr**: rotar la pila hacia abajo (el último elemento se convierte en el primero)

La implementación utiliza diferentes estrategias de ordenación según el número de elementos:
- **2-3 elementos**: algoritmos de ordenación directa optimizados
- **4-5 elementos**: ordenación manual optimizada con uso temporal de la pila B
- **Conjuntos grandes**: algoritmo radix sort usando representación binaria

El desafío radica no solo en ordenar correctamente, sino en minimizar el número total de operaciones, lo que lo convierte en un excelente ejercicio de optimización algorítmica.

## Instrucciones

### Compilación

Para compilar el proyecto, ejecuta:

```bash
make
```

Esto generará el ejecutable `push_swap`.

Para compilar también el bonus (checker):
```bash
make bonus
```

Esto generará ambos ejecutables: `push_swap` y `checker`.

Para limpiar los archivos objeto:
```bash
make clean
```

Para limpiar todo, incluyendo el ejecutable:
```bash
make fclean
```

Para recompilar desde cero:
```bash
make re
```

### Ejecución

#### Push_swap

El programa acepta como argumentos una lista de números enteros:

```bash
./push_swap 4 67 3 87 23
```

También acepta argumentos entre comillas:
```bash
./push_swap "4 67 3 87 23"
```

O una combinación de ambos formatos:
```bash
./push_swap 4 67 "3 87" 23
```

El programa imprimirá en la salida estándar la secuencia de operaciones necesarias para ordenar los números.

#### Checker (Bonus)

El programa `checker` verifica si una secuencia de operaciones ordena correctamente la pila. Lee las operaciones desde la entrada estándar y muestra "OK" si la pila queda ordenada, o "KO" en caso contrario.

Uso básico:
```bash
./checker 4 67 3 87 23
sa
pb
pb
ra
pa
pa
# Presiona Ctrl+D para finalizar la entrada
```

Combinado con push_swap:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# Salida: OK (si push_swap ordena correctamente)
```

Verificación con números aleatorios:
```bash
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | ./checker $ARG
```

### Validación de entrada

El programa valida la entrada y muestra "Error" en stderr si:
- Hay números duplicados
- Los argumentos no son números enteros válidos
- Los números están fuera del rango de un int
- No se proporcionan argumentos

## Ejemplos de uso

### Push_swap

```bash
# Ejemplo con 3 números
./push_swap 2 1 3
# Salida: sa

# Ejemplo con 5 números
./push_swap 5 4 3 2 1
# Salida: secuencia de operaciones para ordenar

# Ejemplo con entrada ya ordenada
./push_swap 1 2 3 4 5
# No imprime nada (ya está ordenado)
```

### Checker (Bonus)

```bash
# Verificar una secuencia de operaciones manualmente
./checker 3 2 1
sa
ra
# Ctrl+D
# Salida: KO

# Verificar que push_swap ordena correctamente
./push_swap 3 2 1 | ./checker 3 2 1
# Salida: OK

# Test con 100 números aleatorios
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
# Salida: OK

# Contar el número de operaciones
./push_swap 5 4 3 2 1 | wc -l
# Muestra el número de operaciones realizadas
```

## Decisiones técnicas

### Programa principal (push_swap)

#### Estructura de datos
- Utiliza listas enlazadas para representar las pilas
- Cada nodo contiene el valor y un índice relativo que facilita la ordenación

### Algoritmos implementados

1. **Ordenación directa (2-3 elementos)**: Se evalúan todos los casos posibles y se aplica la secuencia óptima de operaciones.

2. **Ordenación optimizada (4-5 elementos)**: Se mueven los elementos mínimos a la pila B, se ordena el resto con el algoritmo de 3 elementos, y se devuelven los elementos.

3. **Radix Sort (conjuntos grandes)**: 
   - Asigna índices a cada número según su posición relativa
   - Ordena bit por bit usando la representación binaria de los índices
   - Complejidad O(n·k) donde k es el número de bits necesarios

### Optimizaciones
- Detección temprana de pilas ya ordenadas
- Elección de rotación (ra vs rra) según la posición del elemento
- Uso de indexación relativa en lugar de valores absolutos para facilitar el radix sort

### Programa bonus (checker)

El checker implementa:
- **Lectura de entrada estándar**: Usa `get_next_line` para leer operaciones línea por línea
- **Validación de operaciones**: Verifica que cada operación sea válida (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
- **Ejecución sin impresión**: Las operaciones se ejecutan internamente sin imprimir nada
- **Verificación final**: Comprueba que la pila A esté ordenada y que la pila B esté vacía
- **Manejo de errores**: Muestra "Error" si se encuentra una operación inválida o hay problemas con los argumentos

## Recursos

### Documentación y tutoriales
- [Push_swap Subject - 42](https://cdn.intra.42.fr/pdf/pdf/960/push_swap.en.pdf): Documento oficial del proyecto
- [Radix Sort Algorithm](https://www.programiz.com/dsa/radix-sort): Explicación del algoritmo radix sort
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/): Concepto de pilas y operaciones básicas
- [Sorting Algorithms Visualization](https://www.toptal.com/developers/sorting-algorithms): Visualización de diferentes algoritmos de ordenación
- [Big-O Complexity](https://www.bigocheatsheet.com/): Referencia de complejidad algorítmica

### Artículos relevantes
- [Push_swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a): Tutorial sobre estrategias de optimización
- [Linked Lists in C](https://www.learn-c.org/en/Linked_lists): Implementación de listas enlazadas en C

### Uso de IA

Durante el desarrollo de este proyecto, se utilizó inteligencia artificial (Claude) para las siguientes tareas:

1. **Generación de este README**: La IA fue utilizada para estructurar y redactar este documento siguiendo las especificaciones requeridas por 42, asegurando que todas las secciones necesarias estuvieran presentes y bien organizadas.

2. **NO se utilizó IA para**:
   - La implementación del código fuente
   - El diseño de los algoritmos de ordenación
   - La resolución de bugs o problemas de lógica
   - La optimización del número de operaciones


Todo el código del proyecto fue escrito de forma manual, comprendiendo cada algoritmo y estructura de datos utilizada. La IA solo se empleó como herramienta de documentación, no de desarrollo.

