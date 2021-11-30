## ¿Qué GIT?
[GIT](https://git-scm.com/) es un [Sistema de Control de Versiones](https://es.wikipedia.org/wiki/Control_de_versiones) (CVS), su utilidad se encuentra en cómo el mismo gestiona proyectos logrando que puedas volver en el tiempo a determinados estados y coordinar tu proyecto entre varias personas. 

## ¿Cómo usar GIT?
GIT consta de 3 estados:
1. Working Directory.
2. Staging Area.
3. Repository.

### Instrucciones:
1. Configurar GIT:
    ``` bash
    git config --global user.name "Nombre Apellido"
    git config --global user.email tucorreo@dominio.com
    ```
2. Clonar repositorio:
    ``` bash
    git clone https://github.com/c05m4r/tp1POO.git
    ```
3. Pasar del Working Directory a Staging Area:
    ``` bash
    git add .
    ```
4. Pasar del Staging Area al repositorio local:
    ``` bash
    git commit -m "descripción"
    ```
5. Subir archivos al repositorio remoto:
    ``` bash
    git push origin master
    ```

### Recomendaciones
1. Realizar el "clone" por única vez
2. Para ver el estado de nuestros archivos:
    ``` bash
    git status
    ```
3. Para ver el registro de "commits" realizados:
    ``` bash
    git log
    ```
4. Si queremos arreglar el commit antes de hacer "push":
    ``` bash
    git commit --amend -m "Este es el mensaje correcto"
    ```
4. Si queremos arreglar el commit despues de hacer "push":
    ``` bash
    git reset --hard HEAD~1
    ```
5. Si deseamos actualizar el fork con los nuevos contenidos del repo original [LEER](https://medium.com/@sahoosunilkumar/how-to-update-a-fork-in-git-95a7daadc14e).
#### Trabajo Práctico 1
1. Realice una función que retorne una matriz de números enteros (aleatorios) de n filas y m columnas, siendo n y m parámetros.
2. Realice una función que sume todos los elementos de 2 matrices de n filas y m columnas, siendo n y m parámetros
3. Realice una función que llene una matriz de n filas y m columnas con un número pasado por parámetro.
4. Realice una función que rote una matriz de n filas y m columnas siendo n y m parámetros.
5. Realice una función que llene una matriz de n por m (siendo n y m parámetros) con 2 números, de forma aleatoria. Los dos números puede definirlos usted
6. Realice una función que dada una matriz de n por m (siendo n y m parámetros) llena de 2 números, valide que la matriz no tenga áreas cerradas. Se considera que una matriz de dos números tiene un área cerrada cuando a partir de un número (ubicación ij), no puedo acceder al espacio de números que le corresponde, avanzando hacia cualquiera de los 4 costados. Es decir, a través de un casillero nij, que está completo por un número i, debo poder moverme a otro casillero que también tenga ese mismo número i.
7. Realice una función que genere una matriz de n por m (siendo n y m parámetros) llena de 2 números y la matriz no debe tener áreas cerradas.
#### Andrian, Alexis - Miller, Marcos - Suquilvide, Jerónimo
