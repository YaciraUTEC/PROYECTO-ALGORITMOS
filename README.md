# 💻 PROYECTO ALGORITMOS 💻
# Informe - Desarrollo de una aplicación transaccional basada en Blockchain

## Introducción
El presente informe detalla el desarrollo de una aplicación transaccional de interacción de datos utilizando una estructura de datos de cadena de bloques (Blockchain) en un solo host. Se busca garantizar la seguridad y la integridad de los registros mediante el uso de algoritmos criptográficos, así como implementar diversas estructuras de datos para permitir búsquedas eficientes y cálculos transaccionales. Además, se realizará un análisis de la complejidad de los métodos utilizados y se presentará una comparativa entre el uso de Blockchain con índices y sin índices.

## Descripción del caso de estudio
El caso de estudio planteado consiste en desarrollar una aplicación transaccional que permita registrar diferentes tipos de transacciones, como retiros de dinero, transferencias bancarias, registro de ventas y registro de votos. Se requiere cargar los datos transaccionales desde archivos de texto y proporcionar una interfaz gráfica interactiva para ingresar nuevas transacciones, realizar búsquedas y realizar cálculos transaccionales.

## Importancia del Blockchain en el dominio de datos elegido
El uso de Blockchain en este dominio de datos brinda importantes beneficios en términos de seguridad y confiabilidad. Al utilizar una estructura de cadena de bloques, se garantiza la integridad de los registros, ya que cualquier modificación en un bloque afectará a todos los bloques posteriores, asegurando la inmutabilidad de los datos. Además, al emplear algoritmos criptográficos para generar y verificar los códigos hash de los bloques, se proporciona una capa adicional de seguridad. Esto resulta especialmente relevante en transacciones financieras y registro de votos, donde la integridad y la confidencialidad son fundamentales.

## Estructura de datos del Blockchain y estrategia de integridad
- Explicación:

La estructura de datos del Blockchain se compone de una lista de bloques de registros ordenados cronológicamente. Cada bloque contiene información y un código hash generado mediante un algoritmo criptográfico a partir de los datos del bloque.

- Estrategia para asegurar la integridad:

El código hash también sirve para verificar la integridad del bloque. Para asegurar la integridad de los bloques, se utiliza una estrategia de "proof of work", donde se realiza un cálculo computacionalmente costoso para añadir un nuevo bloque a la cadena. Esto dificulta la manipulación de los bloques existentes y garantiza la seguridad del Blockchain.

- Implementación del proof of work:

## Estructuras de datos utilizadas para la indexación
Se utilizarán varias estructuras de datos para implementar los diferentes criterios de búsqueda requeridos. Las estructuras de datos utilizadas serán Hash, AVL, Heap, BTree, B+Tree y Trie. Cada una de estas estructuras se adaptará según los criterios de búsqueda, como igualdad, rangos, prefijos y patrones de búsqueda.

## Análisis de complejidad y tabla comparativa
Se realizará un análisis de la complejidad en notación Big O de los métodos del Blockchain, principalmente los métodos de inserción y búsqueda. Esto permitirá evaluar el rendimiento y la eficiencia de la aplicación. Además, se realizará una tabla comparativa que mostrará el rendimiento del Blockchain con índices y sin índices, demostrando las ventajas de utilizar estructuras de datos para optimizar las búsquedas.

- Insertar:
Validación del bloque: Antes de agregar un bloque, se deben realizar diversas validaciones para asegurar la integridad y la consistencia de la cadena. Esto puede incluir la verificación de firmas digitales, comprobación de transacciones duplicadas, verificación de pruebas de trabajo (proof-of-work) u otros mecanismos de consenso. La complejidad de estas validaciones puede variar dependiendo de los algoritmos y mecanismos de consenso utilizados, pero generalmente tienen una complejidad de O(1) o O(log n), donde "n" representa el tamaño de la cadena existente.

Agregar el bloque: Una vez que el bloque ha pasado todas las validaciones, se agrega a la cadena. En un Blockchain típico basado en una estructura de lista enlazada, la inserción de un nuevo bloque implica simplemente agregarlo al final de la cadena existente. Esto tiene una complejidad de O(1), ya que solo implica actualizar los punteros del bloque anterior y establecer un nuevo puntero para el bloque recién agregado.

- Buscar:
 La complejidad de búsqueda sería O(n), donde "n" es el número total de bloques en el Blockchain.

- Tabla comparativa de Blockain sin índices vs con índices
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

