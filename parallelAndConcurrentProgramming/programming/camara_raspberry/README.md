# Configuración de camara para Raspberry Pi
* Primero habilitaremos la interfaz de la camara:
```bash
  sudo <editor de preferencia> /boot/config.txt
  # En el archivo se habilitara la I/O SPI
  #   Por lo tanto añadir los siguientes parametros
  start_x=1
  gpu_mem=128
  # gpu_mem asigna memoria en MB al GPU por ello
  #   se establece la memoria compartida entre CPU y GPU
```
* Posteriormente se reiniciara la placa
```bash
  sudo reboot
```
* La camara se conecta en el slot especial que en las mismas placas tienen resaltado como en la imagen

![placa](./imgs/figura.jpg)

* Finalmente se puede tomar capturas con los siguientes comandos:
```bash
  # Captura normal
  raspistill -o <archivo>.jpg
  # Captura con BMP
  raspistill -n -t 500 -e bmp -w 640 -h 480 -o <archivo>.bmp
```
