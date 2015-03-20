# PlanificadorReuniones
tarea1

Trabajo - Planificador de reuniones 
===================================  

Introducción
------------

El objetivo de este trabajo es la implementación de un planificador de reuniones. El trabajo es en equipos de hasta 2 personas. El intercambio de información entre los equipos está permitido (y aconsejado), pero el intercambio de código NO está permitido. Trabajos que tengan porciones significativas de código iguales, o copiados de internet, serán anulados.

El trabajo colaborativo se verá reflejado en el repositorio y será considerado en la calificación.

En cada commit por favor colocar como mensaje relacionado al avance del mismo, por ejemplo:

git commit -m "función que calcula la reputación de un usuario"

Descripción
-----------

El planificador de reuniones es un programa que encuentra horarios compatibles para que diversas personas realicen una reunión. El planificador recibe como entrada los horarios de disponibilidad (semanal) de cada persona y la duración de la reunión y encuentra (si existe) los posibles horarios para realizar la reunión.

Este trabajo consiste en la implementación de un planificador de reuniones. El programa debe recibir como parámetro en la línea de comandos la duración de la reunión y una lista de archivos con las disponibilidades de las personas. La salida deberá presentar los posibles horarios para la realización de la reunión. Si no existe un horario en que sea posible realizar la reunión, el programa no debe escribir nada en la salida.

Cada línea de un "archivo de disponibilidad" consiste en un día de la semana seguido por una secuencia de intervalos. Por ejemplo:

mon 08:30-10:30 15:45-17:15

Significa que la persona tiene horarios libres para la reunión el día lunes de las 8:30 a las 10:30 y de las 15:45 a las 17:15.

Considere los archivos "a", con el siguiente contenido:

mon 08:30-10:30 14:03-16:00 17:10-18:10
tue 13:30-15:45
wed 11:27-13:00 15:00-19:00
fri 07:30-11:30 13:30-14:00 15:02-16:00 17:20-18:30

y "b", con el siguiente contenido:

mon 14:35-17:58
tue 08:40-10:30 13:31-15:13
thu 08:30-15:30
fri 14:07-15:00 16:00-17:30 19:00-22:00

Si el programa fuese consultado con los parámetros "00:45 a b", el programa deberá escribir en pantalla la siguiente respuesta:

mon 14:35-16:00 17:10-17:58
tue 13:31-15:13

Observe que el formato de salida es el mismo que los archivos de entrada.

