<?php
    $a = 2;
    $b = 1;
    // Se realiza una comparación de conjunción AND
    if ($a> $b && $a == 2) {
            echo "\$a es mayor que \$b y es igual a 2"."<br/>";
        }
    // Se realiza una comparación de conjunción OR
    if ($a > $b || $a == 2) {
        echo "\$a es mayor que \$b o es igual a 2 o ambas"."<br/>";
    }
    // Se realiza una comparación de conjunción XOR
    if ($a > $b xor $a == 2) {
        echo "\$a es mayor que \$b o es igual a 2 pero no ambas"."<br/>";
    }
    // Se realiza una comparación de conjunción NAND
    if (!($b > $a && $b == 2)) {
        echo "\$b es no mayor que \$a y es no igual a 2"."<br/>";
    }
?>