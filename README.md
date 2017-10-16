# Contador-de-Arduino
Contador para lcd o serial, con reinicio y reset y modos programables para hacer cualquier otra funcion.

# Modos Programables
Se especifican los modos en la variable nModes y cada numero de modo hara una funcion diferente, solo contiene dos funciones basicas 1.Pause y 2.Reset, se pueden agregar el numero de modos que se desee y que hagan cualquier funcion.

# Funciones para cada Modo
Todos los modos se inicializan en la funcion change();

# Funcion Change
La funcion change() permite mostrar un texto del nombre del modo, Ejemplo : "p" Pausa, "r" Reset, es una funcion opcional para señalar cual sera el nombre del modo deseado.

# Funcion setMode
La funcion setMode() contiene un swith() y en cada uno de los case se puede agregar la funcion que se desea realizar Ejemplo: case 0: pause(); break;, case 1 : reset(); break; y asi susecivamente con cada modo.
