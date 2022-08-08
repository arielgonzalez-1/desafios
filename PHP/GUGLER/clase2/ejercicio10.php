<?php
    $fecha = date('Y-m-d');
    $arreglo_fecha = explode("-", $fecha);
    $fecha_nueva = $arreglo_fecha[2]."/".$arreglo_fecha[1]."/".$arreglo_fecha[0];
    echo $fecha_nueva;
?>