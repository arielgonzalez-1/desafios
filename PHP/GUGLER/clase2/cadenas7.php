<?php
    #que diferencia existe entre explode() y str_split()
    #explode() permite separar (dividir) una cadena de texto indicándole el carácter separador como parámetro
    $aux = date('Y-m-d H:i:s');
    // var_dump($aux);

    $aux = explode(" ", $aux);
    $fecha = $aux[0];
    $tiempo = $aux[1];

    list($anio, $mes, $dia) = explode("-", $fecha);
    list($hora, $minutos, $segundos) = explode(":", $tiempo);
    echo "Información de fecha y hora actual"."<br/>";
    echo "Fecha actual"."<br/>";
    echo "Año: ".$anio."<br/>";
    echo "Mes: ".$mes."<br/>";
    echo "Día: ".$dia."<br/>";
    echo "Hora actual"."<br/>";
    echo "Hora: ".$hora."<br/>";
    echo "Minutos: ".$minutos."<br/>";
    echo "Segundos: ".$segundos;
?>