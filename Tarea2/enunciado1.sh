# Verificando que se haya imsertado un ID
if [ $# -ne 1 ]; then
    echo "Error: El uso correcto es $0 <ID_del_proceso>"
    exit 1
fi

# Obteniendo el ID del proceso
pid="$1"

# Verificando que el proceso brindado por el usuarios existe
if ! ps -p "$pid" > /dev/null 2>&1; then
    echo "Error: El proceso con ID $pid no existe."
    exit 1
fi

