#!/usr/bin/env bash
# @author Adrian González Pardo
if [ $# -ne  1 ];then
  echo -e "Usage:\n\tbash toma_bmp.sh <output>.bmp\n\t./toma_bmp <output>.bmp"
  exit 1
fi
output=$1
echo "Tomando una captura de 480*640"
raspistill -e bmp -h 480 -w 640 -o ${output}.bmp
