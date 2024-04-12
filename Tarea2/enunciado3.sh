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
