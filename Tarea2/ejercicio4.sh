# Este archivo debe estar en el directorio /tmb/ para que el archivo
# monitoreo_de_directorio.service lo pueda reconocer y ejecutar

# Directorio que se quiere monitorear
# Nota: Por favor colocar el path al directorio que quiere monitorear
DIRECTORIO="/home/steven/Documentos"

# Esperando por cambios en el directorio para almacenar los datos en 
inotifywait -m -r -e create,modify,delete --timefmt '+%Y-%m-%d %H:%M:%S' --format '%T %w %f %e' "$DIRECTORIO" >> /var/log/cambios_monitoreo.log
