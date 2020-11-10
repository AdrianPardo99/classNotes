#!/bin/gnuplot
# @author Adrian Gonzalez Pardo
clear
files="PulseSensor Producto\_process"
plot for [file in  files] file.".dat"  title file with lines
pause mouse
clear
files="Producto\_threads PulseSensor"
plot for [file in  files] file.".dat"  title file with lines
pause mouse
clear
files="HannWindow"
plot for [file in  files] file.".dat"  title file with lines
pause mouse
