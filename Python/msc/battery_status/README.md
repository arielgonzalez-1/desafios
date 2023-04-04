# Battery Status

## Instalacion

1. Clonar el repositorio

    ``` bash
    git clone https://github.com/c05m4r/desafios.git
    ```

2. Dirigirse a la carpeta del proyecto
    
    ``` bash
    cd ./Python/msc/battery_status
    ```

3. Instalar paquetes requeridos con pip

    ``` bash
    pip install -r requerements.txt 
    ```

4. Otorgar permisos de ejecución al script
 
    ``` bash
    sudo chmod +x battery_status.py 
    ```

5. Copiar el archivo
 
    ``` bash
    sudo cp $(realpath battery_status.py) /usr/local/bin/
    ```

6. Configurar ejecucion del script al iniciar el sistema

    1. Usando Crontab
        
        1. Ejecutar el siguiente comando

            ``` bash
            crontab -e
            ```

        2. Agregar la siguiente línea
        
            ``` bash
            @reboot /usr/local/bin/battery_status.py
            ```

    2. Usando systemd
    
        1. Crear el servicio para systemd
    
            ``` bash
            sudo touch /etc/systemd/system/battery_status.service
            ```
    
        2. Editarlo de la forma
    
            ``` 
            [Unit]
            Description=Show low battery notification
            
            [Service]
            Type=simple
            ExecStart=/usr/local/bin/battery_status.py
            Restart=on-failure
            RestartSec=10
            KillMode=process
            
            [Install]
            WantedBy=multi-user.target
            ```
    
        3. Comprobar el estado del servicio
    
            ``` bash
            systemctl status battery_status
            ```
    
        4. Iniciar el servicio
    
            ``` bash
            sudo systemctl start battery_status
            sudo systemctl enable battery_status
            ```