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

# Obteniendo información del ID con el comando ps
nombre_proceso=$(ps -p "$pid" -o comm=)
id_proceso="$1"
parent_id=$(ps -p "$pid" -o ppid=)
usuario_propietario=$(ps -p "$pid" -o user=)
cpu_porcentaje=$(ps -p "$pid" -o %cpu=)
mem_porcentaje=$(ps -p "$pid" -o %mem=)
estado=$(ps -p "$pid" -o state=)
# Se utiliza sudo para que pueda acceder al usuario root (superusuario)
path_ejecutable=$(sudo readlink /proc/"$pid"/exe)

# Mostrando la información al usuario
echo "Información del proceso con ID $id_proceso:"
echo "a) Nombre del proceso: $nombre_proceso"
echo "b) ID del proceso: $id_proceso"
echo "c) Parent process ID: $parent_id"
echo "d) Usuario propietario: $usuario_propietario"
echo "e) Porcentaje de uso de CPU: $cpu_porcentaje%"
echo "f) Consumo de memoria: $mem_porcentaje%"
echo "g) Estado: $estado"
echo "h) Path del ejecutable: $path_ejecutable"
