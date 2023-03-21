# Homemade ChatGPT CLI

## Instalacion

1. Clonar el repositorio

    ``` bash
    git clone https://github.com/c05m4r/desafios.git
    ```

2. Dirigirse a la carpeta del proyecto
    
    ``` bash
    cd ./Python/msc/chatgpt
    ```

3. Crear un entorno virtual

    ``` bash
    python -m venv env
    ```

4. Activar el entorno virtual

    ``` bash
    source env/bin/activate
    ```

5. Instalar paquetes requeridos con pip

    ``` bash
    pip install -r requerements.txt 
    ```

6. Crear una API Key [aquí](https://platform.openai.com/account/api-keys)

7. Agregar la API key de la forma

    <details>
    <summary>Desplegar</summary>
    
    ### Windows

    1. Haz clic derecho en "Este equipo" y selecciona "Propiedades" en el menú contextual.
    2. En la ventana de Propiedades del sistema, haz clic en "Configuración avanzada del sistema".
    3. En la ventana Propiedades del sistema, selecciona la pestaña "Opciones avanzadas" y haz clic en "Variables de entorno".
    4. En la sección "Variables del sistema" o "Variables de usuario", haz clic en "Nuevo".
    5. Ingresa el nombre y el valor de la variable de entorno que deseas agregar y haz clic en "Aceptar".
        
    O por el comando

    ``` bash
    setx API_KEY <clave>
    ```

    ### POSIX
        
    ``` bash
    echo "API_KEY=<clave>" >> .env
    ```

    </details>


5. Ejecutar el script

    ``` bash
    python3 chatgpt.py
    ```

## FAQ

Para más información, ver [aquí](https://platform.openai.com/docs/api-reference)