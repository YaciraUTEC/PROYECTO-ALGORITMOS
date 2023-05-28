# 💻 PROYECTO ALGORITMOS 💻
# Desarrollo de una aplicación transaccional ***RETIROS DE DINERO*** basada en Blockchain

## Introducción
El presente informe detalla el desarrollo de una aplicación transaccional de interacción de datos utilizando una estructura de datos de cadena de bloques (Blockchain) en un solo host. Se busca garantizar la seguridad y la integridad de los registros mediante el uso de algoritmos criptográficos, así como implementar diversas estructuras de datos para permitir búsquedas eficientes y cálculos transaccionales. Además, se realizará un análisis de la complejidad de los métodos utilizados y se presentará una comparativa entre el uso de Blockchain con índices y sin índices.

## Descripción del caso de estudio
El caso de estudio planteado consiste en desarrollar una aplicación con un dominio transaccional **💸RETIROS DE DINERO💸**. Esta aplicación está conformado por los siguientes campos: Cliente, Lugar, Monto, Fecha.

🧍**Cliente:** Este campo representa al cliente que realiza el retiro de dinero. Puede ser el nombre del cliente o algún identificador único que lo identifique en el sistema.
🏧**Lugar:** Este campo indica el lugar o la ubicación donde se realiza el retiro de dinero. Puede ser un cajero automático, una sucursal bancaria, una tienda, etc.
💸**Monto:** El campo de Monto especifica la cantidad de dinero que se retira de la cuenta del cliente. Es un valor numérico que representa la cantidad en la moneda correspondiente.
📅**Fecha:** Este campo registra la fecha en la que se realiza el retiro de dinero. Puede ser en formato de fecha y hora, como una cadena de texto o un objeto de fecha y hora.

## Importancia del Blockchain en el dominio de datos elegido
El blockchain es una tecnología que desempeña un papel importante en el dominio transaccional de retiros de dinero, especialmente en términos de seguridad, transparencia y confianza. 

## Estructura de datos del Blockchain y estrategia de integridad
- ***Explicación***:

La estructura de datos del Blockchain se compone de una lista de bloques de registros ordenados cronológicamente. Cada bloque contiene información y un código hash generado mediante un algoritmo criptográfico a partir de los datos del bloque.

- ***Estrategia para asegurar la integridad***:

El código hash también sirve para verificar la integridad del bloque. Para asegurar la integridad de los bloques, se utiliza una estrategia de "proof of work", donde se realiza un cálculo computacionalmente costoso para añadir un nuevo bloque a la cadena. Esto dificulta la manipulación de los bloques existentes y garantiza la seguridad del Blockchain.

- ***Implementación del proof of work***:

1. Define los parámetros del algoritmo

- Dificultad (target): Determina la cantidad de ceros consecutivos requeridos en el hash del bloque para que se considere válido. Cuanto mayor sea la dificultad, más tiempo llevará encontrar un hash válido.
- Bloque de datos: Los datos que se van a incluir en el bloque, como transacciones u otra información relevante.
- Nonce: Un número arbitrario que se incrementará durante el proceso de minería para obtener diferentes hashes.

2. Crea una función de hash:
Elige una función de hash criptográfica, como SHA-256, que tomará como entrada los datos del bloque y el nonce, y generará un hash.

3. Minería del bloque:
Inicializa el nonce en 0.
Crea un bucle infinito:
- Concatena los datos del bloque y el nonce.
- Calcula el hash aplicando la función de hash al bloque y al nonce.
- Verifica si el hash cumple con la dificultad establecida (por ejemplo, si los primeros "n" caracteres son ceros).
- Si el hash cumple con la dificultad, se ha encontrado una solución válida. Sal del bucle.
- Si el hash no cumple con la dificultad, incrementa el nonce en 1 y repite el bucle.

4. Una vez que se encuentra un nonce que produce un hash válido, se considera que se ha completado la Prueba de Trabajo y se agrega el bloque a la cadena.
## Estructuras de datos utilizadas para la indexación
Se utilizarán varias estructuras de datos para implementar los diferentes criterios de búsqueda requeridos. Las estructuras de datos utilizadas serán Hash, AVL, Heap, BTree, B+Tree y Trie. Cada una de estas estructuras se adaptará según los criterios de búsqueda, como igualdad, rangos, prefijos y patrones de búsqueda.

## Análisis de complejidad y tabla comparativa
Se realizará un análisis de la complejidad en notación Big O de los métodos del Blockchain, principalmente los métodos de inserción y búsqueda. Esto permitirá evaluar el rendimiento y la eficiencia de la aplicación. Además, se realizará una tabla comparativa que mostrará el rendimiento del Blockchain con índices y sin índices, demostrando las ventajas de utilizar estructuras de datos para optimizar las búsquedas.

- ***Insertar***:

Validación del bloque: Antes de agregar un bloque, se deben realizar diversas validaciones para asegurar la integridad y la consistencia de la cadena. Esto puede incluir la verificación de firmas digitales, comprobación de transacciones duplicadas, verificación de pruebas de trabajo (proof-of-work) u otros mecanismos de consenso. La complejidad de estas validaciones puede variar dependiendo de los algoritmos y mecanismos de consenso utilizados, pero generalmente tienen una complejidad de O(1).

Insertar bloques: O(1)
Insertar registros: O(1)

- ***Buscar***:
Búsqueda por rango: n(lg(n)
Búsqueda hash: O(1)

- ***Tabla comparativa de Blockain sin índices vs con índices***
## Conclusiones
La implementación de una aplicación transaccional basada en Blockchain proporciona seguridad y confiabilidad en el dominio de datos seleccionado. El uso de una estructura de cadena de bloques y algoritmos criptográficos garantiza la integridad y la inmutabilidad de los registros. La aplicación cumple con los requerimientos establecidos y ofrece una interfaz gráfica intuitiva para los usuarios. El análisis de complejidad y la comparativa entre Blockchain con y sin índices demuestran la eficiencia de utilizar estructuras de datos para mejorar el rendimiento de las búsquedas.

## Referencias bibliográficas
- Video: "Introduction to Blockchain and Proof of Work" - https://www.youtube.com/watch?v=C5NZnD12yjg
- Brownworth, A. "Blockchain Demo" - https://andersbrownworth.com/blockchain/
- Video: "Instalación de wxWidgets" - https://www.youtube.com/watch?v=v_v9HtaoPRs

## Actividades concluidas por cada integrante del grupo
- Campoverde San Martín, Yacira Nicol
- Jaramillo Alfaro, Michel Marcelo
- Pajuelo Reyes, César Eduardo:
- Pinedo Espinoza, Jose Eddison: 
- Rodriguez Gutierrez, Gonzalo Alonso: 

