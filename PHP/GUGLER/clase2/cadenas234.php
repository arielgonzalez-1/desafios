<?php
    $subcadena1 = "Php es un lenguaje de script embebido basado en el motor de Zend.";
    $subcadena2 = "Se utiliza principalmente para desarrollar contenido Html dinámico, aunque puede usarse para generar documentos Xml (entre otros) también.";
    $cadena = $subcadena1."<br />".$subcadena2;
    $mal = array("php", "xml", "html");
    $bien = array("PHP", "XML", "HTML");
    $cadena = str_ireplace($mal, $bien, $cadena);
    print($cadena)
?>