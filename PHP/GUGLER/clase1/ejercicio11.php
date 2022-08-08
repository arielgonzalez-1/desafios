<?php
    $mes = 4;
    // Consulta los meses del año correspondientes a cada Estación
    if ($mes == 1 || $mes == 2) {
        echo "VERANO";
    }
    if ($mes == 4 || $mes == 5) {
        echo "OTOÑO";
    }
    if ($mes == 7 || $mes == 8) {
        echo "INVIERNO";
    }
    if ($mes == 10 || $mes == 11) {
        echo "PRIMAVERA";
    }
    if ($mes == 3) {
        echo "VERANO u OTOÑO";
    }
    if ($mes == 6) {
        echo "OTOÑO o INVIERNO";
    }
    if ($mes == 9) {
        echo "INVIERNO o PRIMAVERA";
    }
    if ($mes == 12) {
        echo "PRIMAVERA o VERANO";
    }
?>