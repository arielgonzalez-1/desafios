<?php
    $a = 0;
    $b = 1;
    $suma = $a + $a;
    $resta = $b - $a;
    $multiplicacion = $a * $b;
    $division = $b / 7;
    $resto = 10 % 3;
    
    #que diferencia existe entre $GLOBALS y get_defined_vars()
    #que diferencia existe entre var_dump() y print_r()

    #This function displays structured information about one or more expressions that includes its type and value. Arrays and objects are explored recursively with values indented to show structure.
    // var_dump($GLOBALS);

    #This function returns a multidimensional array containing a list of all defined variables, be them environment, server or user-defined variables, within the scope that get_defined_vars() is called.
    // var_dump(get_defined_vars());

    #print_r() displays information about a variable in a way that's readable by humans.print_r(), var_dump() and var_export() will also show protected and private properties of objects. Static class members will not be shown.
    // print_r($GLOBALS);
    // print_r(get_defined_vars());
?>