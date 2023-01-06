# Amazing-Hopper
Programming language based on xBase/ANSI C that has the peculiarity of facilitating the creation of many types of programming languages, read "metalanguages", from formal grammars to grammars close to natural language. It's an experiment.

Para compilar Hopper, deberá tener instalado y funcionando HAROBUR 3.0.0.

Una vez tenga los pre-requisitos listos, para crear los binarios deberá ejecutar:

  ./install3.sh

con las opciones que le da el script para la generación de los programas. Estos programas se copiarán en /usr/bin.

Existen múltiples ejemplos de meta-lenguajes creados a partir de Amazing Hopper, y algunos de estos ejemplos se pueden encontrar en la página Rosetta Code:

 https://rosettacode.org/

Para una manual (casi) actualizado, puede visitar la Wiki de la misma página:

 https://rosettacode.org/wiki/Category:Amazing_Hopper

#Help

Escriba:

hopper3        

Para ayuda de analizador y ejecutor

bhopper3       

Para ayuda de ejecutor de binarios.

Puede crear un binario cuando ya está seguro de que su programa funciona bien. Use VALGRIND para asegurarse más todavía.

Un binario se crea así:

hopper3 <filename.ext> -x -o bin/nombre_de_archivo

#Compilar un programa

Para compilar un programa (y ejecutarlo) tiene dos opciones:
1) hopper3 <filename.ext> 

o si ya generó un binario:

2) bhopper /bin/<filename>

aunque también puede ejecutar en ambas modalidades como:

./<filename[.ext]>

#Otras opciones de compilación/ejecución:

Consulte la ayuda.

Dudas, consultas o ganas de colaborar con ideas o mejoras (que las necesita), contáctese con el autor en el correo:

daniel.stuardo@gmail.com

Con amor

Mr. Dalien.
