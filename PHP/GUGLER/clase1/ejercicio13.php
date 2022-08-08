<?php
    // Consulta el dia dado un numero
    $dia = 7;
    switch($dia){
        case '0':
            echo "DOMINGO";
        break;
        case '1':
            echo "LUNES";
        break;
        case '2':
            echo "MARTES";
        break;
        case '3':
            echo "MIERCOLES";
        break;
        case '4':
            echo "JUEVES";
        break;
        case '5':
            echo "VIERNES";
        break;
        case '6':
            echo "SABADO";
        break;
        default:
            echo "Ingrese un número de día correspondiente";
        break;
    }
?>