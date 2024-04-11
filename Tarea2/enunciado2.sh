# Verificando que se hayan pasado los parámetros
if [ "$#" -ne 2 ]; then
    echo "Uso: $0 nombre_del_proceso comando_para_ejecutar"
    exit 1
fi

# Almacenado las 
nombre_del_proceso=$1
comando_para_ejecutar=$2

echo "Monitoreando el proceso: $nombre_del_proceso"

while true; do
    # Utiliza pgrep para buscar el proceso por su nombre
    pgrep -f "$nombre_del_proceso" > /dev/null
    status=$?
    
    # Si pgrep retorna 1, el proceso no se encuentra en ejecución
    if [ $status -ne 0 ]; then
        echo "Proceso $nombre_del_proceso no encontrado. Iniciando..."
        # Ejecuta el comando para iniciar el proceso
        $comando_para_ejecutar &
    fi
    # Espera un tiempo antes de verificar nuevamente
    sleep 2
done