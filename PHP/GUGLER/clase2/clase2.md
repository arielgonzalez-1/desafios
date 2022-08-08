Preparar y verificar nuestro entorno de desarrollo PHP.

> Antes de comenzar con la práctica, asegúrese de tener instalado su entorno de desarrollo.

1) Realice un script PHP que permita mostrar las características de interprete PHP utilizando la función phpinfo().

Utilizar los conceptos básicos del lenguaje (Arreglos)

2) Realice un script que defina un arreglo de nombre $dias_semana y al cual debemos asignar cada uno de los días de la misma comenzando por el Domingo.Recuerde utilizar etiquetas estándares.

3) Edite el script anterior y agregue una nueva sentencia que muestre el contenido del arreglo con la construcción foreach.

4) Edite el script del punto 3 y agregue la función print_r() para ver el contenido y la estructura del arreglo $dias_semana.

5) Edite el script del punto 4 y ordene el arreglo de forma ascendente y muestre en pantalla el contenido del mismo.

6) Edite el script del punto 4 y ordene el arreglo de forma descendiente y muestre en pantalla el contenido del mismo.

7) Realice un nuevo script que defina un arreglo asociativo de nombre $persona y al cual debemos asignar los siguiente valores y mostrarlos en pantalla:
```
Clave: tipo_documento, Valor: DNI
Clave: numero_documento, Valor: 30.122.122
Clave: apellidos, Valor: Garcia
Clave: nombres, Valor: Juan
Clave: domicilio, Valor: San Martín 123
Clave: telefono, Valor: 4222324
Clave: edad, Valor: 25
```

Utilizar funciones en PHP

8) Escriba un script PHP que defina cuatro funciones que realicen las operaciones matemáticas de suma, resta, multiplicación y división. Las funciones deberán esperar dos parámetros pasados por valor y devolver el resultado de la operación. Dentro del mismo script deberán utilizar cada una de las funciones y mostrar el resultado por pantalla.

9) Editar el script PHP del punto anterior y agregue una función que permita incrementar el valor de una variable pasada como parámetro por referencia. Dentro del mismo script deberá utilizar la función y mostrar el resultado por pantalla.

Utilizar y manejar cadenas en PHP

10) Escriba un script PHP que utilice la función date('Y-m-d') para obtener la fecha actual y utilizando la función explode() cambie el formato de la fecha a dd/mm/yyyy, muestre la fecha con formato por pantalla.

Utilizar y manejar cadenas en PHP

1) Escriba un script PHP que almacene en la variable $subcadena1 el siguiente texto:
```
Php es un lenguaje de script embebido basado en el motor de Zend.
```
en una segunda variable de nombre $subcadena2 el siguiente texto:
```
Se utiliza principalmente para desarrollar contenido Html dinámico, aunque puede usarse para generar documentos Xml (entre otros) también.
```
Luego concatene las dos subcadenas en una variable de nombre $cadena y muestre por pantalla la misma.

2) Edite el script del ejercicio anterior para buscar y reemplazar la cadena “Php” por la nueva cadena “PHP”.

3) Edite el script del ejercicio anterior para buscar y reemplazar la cadena “Html” por la nueva cadena “HTML”.

4) Edite el script del ejercicio anterior para buscar y reemplazar la cadena “Xml” por la
nueva cadena “XML”.

5) Edite el script del ejercicio anterior para mostrar el largo de las subcadenas iniciales ($subcadenas1 y $subcadenas2) y de la cadena que resultante de concatenar las anteriores ($cadena).

6) Escriba un script que muestre la siguiente salida:
```
La última versión estable de PHP es la 5.3.2.
la última versión estable de php es la 5.3.2.
LA ÚLTIMA VERSIÓN ESTABLE DE PHP ES LA 5.3.2.
```

7) Escriba un nuevo script que obtenga la fecha y la hora del servidor (date('Y-m-d H:i:s')) para luego mostrar en pantalla la siguiente salida:
```
Información de fecha y hora actual
Fecha actual
Año: 2010
Mes: 04
Día: 09
Hora actual
Hora: 15
Minutos: 00
Segundos: 00
```

8) Escriba un nuevo script que permita quitar los espacios en blanco y caracteres especiales de una cadena definida. La cadena debe contener el siguiente texto:
```
\n\t Cadena a tratar con la función trim(). \0\n\r
```
Antes de quitar los espacios y caracteres especiales obtenga y muestre el largo de la cadena, luego de quitar los espacios vuelva a obtener y mostrar el largo de la cadena.