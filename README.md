# Contador-de-Arduino
Contador para lcd o serial, con reinicio y reset y modos programables para hacer cualquier otra función.

# Modos Programables
Se especifican los modos en la variable nModes y cada numero de modo hara una función diferente, solo contiene dos funciones basicas 1.Pause y 2.Reset, se pueden agregar el numero de modos que se desee y que hagan cualquier función.

# Funciones para cada Modo
Todos los modos se inicializan en la función change();

# Función Change
La función change() permite mostrar un texto del nombre del modo, Ejemplo : "p" Pausa, "r" Reset, es una función opcional para señalar cuál sera el nombre del modo deseado.

# Función setMode
La función setMode() contiene un switch() y en cada uno de los case se puede agregar la funcion que se desea realizar Ejemplo: case 0: pause(); break;, case 1 : reset(); break; y asi susecivamente con cada modo.
