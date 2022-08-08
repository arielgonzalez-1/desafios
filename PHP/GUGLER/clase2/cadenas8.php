<?php
    #trim() elimina los espacios en blanco al inicio y al final de una cadena que se recibe como parámetro.
    #ltrim() elimina los espacios en blanco que se encuentran al comienzo de una cadena de texto que se pasa como parámetro.
    #rtrim() permite eliminar los espacios en blanco que se encuentran al final de una cadena de texto que se pasa como parámetro.
    $cadena = "\n\t Cadena a tratar con la función trim(). \0\n\r";
    echo "Largo de cadena: ".strlen($cadena)."<br/>";
    $trimmed = trim($cadena);
    echo "Largo de cadena: ".strlen($trimmed);
?>