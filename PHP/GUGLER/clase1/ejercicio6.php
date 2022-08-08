<?php
    $entero = 2;
    $flotante = 3.14159265359;
    $caracter  = 'una cadena';
    $logico = true;

    echo $entero." es entero: ".is_int($entero)."<br>";
    echo $flotante." es flotante: ".is_float($flotante)."<br>";
    echo $caracter." es caracter: ".is_string($caracter)."<br>";
    echo $logico." es logico: ".is_bool($logico)."<br>";
    echo $flotante." es entero: ".is_int($flotante)."<br>";
?>