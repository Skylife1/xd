# (1)
-El fork crea hace un llamado al sistema para crear un nuevo proceso identico llamado hijo el cual tiene su propio espacio en memoria haciendo que la variable x, aun asi este la cambie, no cambie al momento de volver a la ejecucion del padre, dado que son procesos alojados en diferentes locaciones de la memoria.

# (2)

-Ambos procesos pueden acceder al archivo usando open() ya que son procesos diferentes pero la entrada al archivo es "Aleatoria" mientras no se use la llamada al sistema wait()
-Puede ocurrir que si entran al mimso tiempo se sobreescriban dado que el proceso no tiene la llamada al sistema wait() pero esto es "Aleatorio"

# (3)

-En general sin usar la llamada al sistema wait se puede hacer que se ejecute primero el hijo que el padre pero es menos "eficiente" dado que se usan otras funciones como el pause(), pero para volver a activar al padre se debe enviar una senal que acabe con el pause()

# (4)

-Hay diferentes execs ya que se pueden recibir distintos tios de datos unos con mayor o menor "precision" y tambien con mayor o menor numero de argumentos, en p4.c estan las especificaciones. [p4.c](p4.c)

# (5)

-No sucedera nada dado que el hijom si el padre no tiene restriccion se ejecutara de segundo siempre dado las prioridades del sistema operativo, por lo que el wait arrojara un valor diferente de 0 que significa que no tiene un proceso por el cual esperar 

# (6)

-Dado que el sistema operativo da el control primero a el proceso padre aun cuando se quiera que el hijo espere al padre este siempe esperara dado que el padre siempre se ejecutara primero poruqe el SO le da prioridad a el

# (7)

-Cuando el hijo trata de imprimir no puede dado que antes recibe una senal de salida lo que hace que evacue el proceso antes de terminarlo.
