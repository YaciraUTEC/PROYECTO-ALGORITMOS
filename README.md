# 💻 PROYECTO ALGORITMOS 💻
# Desarrollo de una Aplicación Transaccional Segura para Retiros de Dinero basada en Tecnología Blockchain

## 1️⃣INTRODUCCIÓN 
El presente informe tiene como objetivo detallar el desarrollo de una aplicación transaccional enfocada en el dominio de los retiros de dinero. Esta aplicación ha sido diseñada para proporcionar a los usuarios una solución eficiente y segura para realizar transacciones de retiro de fondos de sus cuentas.En el contexto actual, donde las transacciones financieras desempeñan un papel crucial en nuestra vida diaria, es fundamental contar con una aplicación confiable que garantice la integridad, seguridad y transparencia en los retiros de dinero. Por lo tanto, esta aplicación busca cubrir estas necesidades y ofrecer una experiencia fluida y segura para los usuarios.

El dominio de los retiros de dinero implica una serie de consideraciones importantes, como la identificación del cliente, el lugar donde se realiza el retiro, el monto retirado y la fecha de la transacción. Estos elementos constituyen la base de la aplicación transaccional que estamos desarrollando.
Además, para asegurar la integridad de las transacciones y proteger los datos sensibles de los usuarios, se ha optado por utilizar tecnología de cadena de bloques **(Blockchain)**. Esta tecnología proporciona una capa adicional de seguridad y transparencia a las transacciones, al tiempo que permite un seguimiento preciso y una mayor confianza en el proceso de retiro de dinero.

A lo largo de este informe, se describirán en detalle los aspectos clave de la aplicación, incluyendo la arquitectura, los requisitos funcionales y no funcionales, así como las estructuras de datos y algoritmos utilizados para garantizar la eficiencia y confiabilidad de las transacciones de retiro de dinero.
Además, se presentarán los resultados de pruebas y análisis de rendimiento realizados para evaluar la calidad y el rendimiento de la aplicación. Estos resultados son fundamentales para garantizar que la aplicación cumpla con los estándares de calidad y brinde una experiencia óptima a los usuarios.

## 2️⃣DESCRIPCIÓN DEL CASO DE ESTUDIO
El caso de estudio planteado consiste en desarrollar una aplicación con un dominio transaccional **💸RETIROS DE DINERO💸**. Esta aplicación está conformado por los siguientes campos: Cliente, Lugar, Monto, Fecha.

🧍**Cliente:** Este campo representa al cliente que realiza el retiro de dinero. Puede ser el nombre del cliente o algún identificador único que lo identifique en el sistema.

🏧**Lugar:** Este campo indica el lugar o la ubicación donde se realiza el retiro de dinero. Puede ser un cajero automático, una sucursal bancaria, una tienda, etc.

💸**Monto:** El campo de Monto especifica la cantidad de dinero que se retira de la cuenta del cliente. Es un valor numérico que representa la cantidad en la moneda correspondiente.

📅**Fecha:** Este campo registra la fecha en la que se realiza el retiro de dinero. Puede ser en formato de fecha y hora, como una cadena de texto o un objeto de fecha y hora.

## 3️⃣BLOCKCHAIN EN EL DOMINIO TRANSACCIONAL
### IMPORTANCIA

El Blockchain juega un papel fundamental en el dominio transaccional de retiros de dinero, brindando importantes beneficios y mejoras. Aquí se destacan algunas de las razones clave por las cuales el Blockchain es importante en este dominio:
RAZONES  | DESCRIPCIÓN
------------- | -------------
SEGURIDAD  | Cada retiro de dinero puede ser registrado en forma de bloque en la cadena, y cada bloque contiene una referencia al bloque anterior, formando una secuencia inmutable. Esto hace que sea extremadamente difícil para los atacantes manipular o alterar los registros de retiros.
TRANSPARENCIA Y TRAZABILIDAD  | Cada retiro de dinero registrado en la cadena puede ser verificado y rastreado por cualquier participante de la red. Esto brinda transparencia y permite una mayor confianza en el proceso de retiros de dinero, ya que las transacciones son visibles y auditable por todos los participantes autorizados.
ELIMINACIÓN DE INTERMEDIARIOS | A menudo se requieren intermediarios, como bancos u otras instituciones financieras, para facilitar y verificar las transacciones. Con el blockchain, es posible eliminar o reducir la dependencia de estos intermediarios, lo que puede resultar en costos más bajos, mayor eficiencia y tiempos de procesamiento más rápidos.

## 4️⃣ESTRUCTURA DE DATOS PARA LA INDEXACIÓN

La estructura de datos del Blockchain se compone de una lista de bloques de registros ordenados cronológicamente. Cada bloque contiene información y un código hash generado mediante un algoritmo criptográfico a partir de los datos del bloque. Se utilizarán varias estructuras de datos para implementar los diferentes criterios de búsqueda requeridos. Las estructuras de datos utilizadas serán Hash, AVL, Heap, BTree, B+Tree y Trie. Cada una de estas estructuras se adaptará según los criterios de búsqueda, como igualdad, rangos, prefijos y patrones de búsqueda.

## 5️⃣ESTRATEGIA PARA ASEGURA LA INTEGRIDAD

El código hash también sirve para verificar la integridad del bloque. Para asegurar la integridad de los bloques, se utiliza una estrategia de ```proof of work ```, donde se realiza un cálculo computacionalmente costoso para añadir un nuevo bloque a la cadena. Esto dificulta la manipulación de los bloques existentes y garantiza la seguridad del Blockchain.

## 6️⃣IMPLEMENTACIÓN DE  PROOF OF WORK

El algoritmo de Prueba de Trabajo (Proof of Work, PoW) es utilizado en sistemas basados en Blockchain para asegurar la integridad y seguridad de la red.

### *Define los parámetros del algoritmo:*

- Dificultad (target): Determina la cantidad de ceros consecutivos requeridos en el hash del bloque para que se considere válido. Cuanto mayor sea la dificultad, más tiempo llevará encontrar un hash válido.
- Bloque de datos: Los datos que se van a incluir en el bloque, como transacciones u otra información relevante.
- Nonce: Un número arbitrario que se incrementará durante el proceso de minería para obtener diferentes hashes.

### *Crea una función de hash:*
Elige una función de hash criptográfica, como ```SHA-256```, que tomará como entrada los **datos del bloque** y el **nonce**, y generará un **hash**.

### *Minería del bloque:*

- Inicializa el nonce en 0.
- Crea un bucle infinito:
  - Concatena los datos del bloque y el nonce.
  - Calcula el hash aplicando la función de hash al bloque y al nonce.
  - Verifica si el hash cumple con la dificultad establecida (por ejemplo, si los primeros "n" caracteres son ceros).
  - Si el hash cumple con la dificultad, se ha encontrado una solución válida. Sal del bucle.
  - Si el hash no cumple con la dificultad, incrementa el nonce en 1 y repite el bucle.

Una vez que se encuentra un nonce que produce un hash válido, se considera que se ha completado la Prueba de Trabajo y se agrega el bloque a la cadena.

## 7️⃣ESTRUCTURA DE DATOS DE LA APLICACIÓN
<image
  src="/DIAGRAMA.png"
  alt="Descripción de la imagen"
  caption="Diagrama de la Aplicación Transaccional">



## 8️⃣ANÁLISIS DE COMPLEJIDAD
Se realizará un análisis de la complejidad en notación Big O de los métodos del Blockchain, principalmente los métodos de inserción y búsqueda. Esto permitirá evaluar el rendimiento y la eficiencia de la aplicación. Además, se realizará una tabla comparativa que mostrará el rendimiento del Blockchain con índices y sin índices, demostrando las ventajas de utilizar estructuras de datos para optimizar las búsquedas.

BÚSQUEDA     | COMPLEJIDAD
------------ | -------------
Bloques      | O(1)             
Registros    | O(1)


INSERCIÓN    | COMPLEJIDAD
------------ | -------------
Rango        |  O(n(log n))         
Hash         | O(1)


## Tabla comparativa de Blockain sin índices vs con índices

## 9️⃣CONCLUSIONES
El desarrollo de una aplicación transaccional de ***retiros de dinero*** basada en Blockchain, con una estructura de datos adecuada y considerando la complejidad de los métodos, permite garantizar la seguridad, integridad y eficiencia en las transacciones de retiros de dinero. El uso de Blockchain en este dominio tiene un impacto significativo en la confianza, la transparencia y la eliminación de intermediarios, lo que mejora la experiencia del usuario y optimiza el proceso de retiro de dinero. El análisis de complejidad y la comparativa entre Blockchain con y sin índices demuestran la eficiencia de utilizar estructuras de datos para mejorar el rendimiento de las búsquedas.

## 🔟REFERENCIAS BIBLIOGRÁFICAS
- Video: "Introduction to Blockchain and Proof of Work" - https://www.youtube.com/watch?v=C5NZnD12yjg
- Brownworth, A. "Blockchain Demo" - https://andersbrownworth.com/blockchain/
- Video: "Instalación de wxWidgets" - https://www.youtube.com/watch?v=v_v9HtaoPRs


## ✅ACTIVIDADES CONCLUIDAS POR CADA INTEGRANTE
- Campoverde San Martín, Yacira Nicol
- [x] Informe
- [x] Implementación Blockachain
- [x] Implementación Chainhash
- Jaramillo Alfaro, Michel Marcelo 
- [x] Implementación Main
- [x] Implementación Reader
- Pajuelo Reyes, César Eduardo:
- [x] Implementación Block
- [x] Implementación Record  
- Pinedo Espinoza, Jose Eddison:
- [x] Implementación Avl
- Rodriguez Gutierrez, Gonzalo Alonso: 
- [x] Implementación Forward
- [x] Implementación Node
- [x] Modificación en el Blockchain 

