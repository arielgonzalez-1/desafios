<?php
    function suma($valor1, $valor2) {
        $resultado = $valor1 + $valor2;
        return $resultado;
    }
    function resta($valor1, $valor2) {
        $resultado = $valor1 - $valor2;
        return $resultado;
    }
    function multiplicacion($valor1, $valor2) {
        $resultado = $valor1 * $valor2;
        return $resultado;
    }
    function division($valor1, $valor2) {
        $resultado = $valor1 / $valor2;
        return $resultado;
    }

    $a = 2;
    $b = 4;
    echo "La suma de $a y $b es: ".suma($a, $b)."<br />";
    echo "La resta de $a y $b es: ".resta($a, $b)."<br />";
    echo "La multiplicación de $a y $b es: ".multiplicacion($a, $b)."<br />";
    echo "La división de $a y $b es: ".division($a, $b);
?>