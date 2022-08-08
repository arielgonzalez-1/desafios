<?php
    $subcadena1 = "Php es un lenguaje de script embebido basado en el motor de Zend.";
    $subcadena2 = "Se utiliza principalmente para desarrollar contenido Html dinámico, aunque puede usarse para generar documentos Xml (entre otros) también.";
    $cadena = $subcadena1."<br/>".$subcadena2;
    #strlen() devuelve la longitud de una cadena de texto que se le pasa como parámetro.
    echo "Largo de \$subcadena1: ".strlen($subcadena1)."<br/>";
    echo "Largo de \$subcadena2: ".strlen($subcadena2)."<br/>";
    echo "Largo de \$cadena: ".strlen($cadena)."<br/>";
?>