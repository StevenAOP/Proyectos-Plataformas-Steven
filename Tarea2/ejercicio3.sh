# Comprobar que se ha pasado un parámetro
if [ $# -ne 1 ]; then
    echo "Uso: $0 <ejecutable>"
    echo "Ejemplo $0 /ruta/a/archivo"
    exit 1
fi

# Verificar si la ruta ingresada es un directorio válido
if [ ! -e "$1" ]; then
    echo "La ruta especificada no es válida."
    exit 1
fi


# Creando el archivo de log
LOGFILE="proceso.log"

# Agregando titulos a los datos por almacenar
echo "Fecha-Hora CPU Memoria" > $LOGFILE

# Ejecutando el binario (El ejecutable) en segundo plano
"$1" &
PID=$!


# Función para obtener y registrar el uso de CPU y memoria
function monitoreo {
    while kill -0 $PID 2>/dev/null; do
        # Capturando el %CPU y %memoria sin encabezados
        USAGE=$(ps -p $PID -o %cpu,%mem --no-headers)
        # Agregando una marca de tiempo
        DATE=$(date +"%Y-%m-%d %H:%M:%S")
        # Escribiendo la información en el archivo .log
        echo "$DATE $USAGE" >> $LOGFILE
        # Reguistrando los valores cada 0.1 segundo
        sleep 0.5
    done
}

# Llamando a la función en segundo plano para el monitoreo y
# agregar los datos
monitoreo &

# Esperarando a que el proceso termine
wait $PID


# Graficar los resultados con gnuplot
gnuplot -persist <<-EOFMarker
    set title "Consumo de CPU y Memoria"
    set xlabel "Segundos que duró proceso"
    set ylabel "Porcentaje"
    set timefmt "%Y-%m-%d %H:%M:%S"
    set format x "%S"
    set xdata time
    plot "$LOGFILE" using 1:3 title 'CPU' with lines, \
         "$LOGFILE" using 1:4 title 'Memoria' with lines
EOFMarker

echo "Monitoreo completado. Los resultados han sido graficados."