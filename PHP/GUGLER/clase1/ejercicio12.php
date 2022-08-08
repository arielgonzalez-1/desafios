<?php
    $mes = 4;
    // Consulta los meses del año correspondientes a cada Estación
    if ($mes == 1 || $mes == 2) {
        echo "VERANO";
    }
    elseif ($mes == 4 || $mes == 5) {
        echo "OTOÑO";
    }
    elseif ($mes == 7 || $mes == 8) {
        echo "INVIERNO";
    }
    elseif ($mes == 10 || $mes == 11) {
        echo "PRIMAVERA";
    }
    elseif ($mes == 3) {
        echo "VERANO u OTOÑO";
    }
    elseif ($mes == 6) {
        echo "OTOÑO o INVIERNO";
    }
    elseif ($mes == 9) {
        echo "INVIERNO o PRIMAVERA";
    }
    elseif ($mes == 12) {
        echo "PRIMAVERA o VERANO";
    }
?>