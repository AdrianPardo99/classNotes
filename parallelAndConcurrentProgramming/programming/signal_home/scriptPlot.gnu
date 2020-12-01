#!/bin/gnuplot
# @author Adrian Gonzalez Pardo


set terminal png size 1000,500
set output "graficas.png"

if (!exists("MP_LEFT"))   MP_LEFT = .1
if (!exists("MP_RIGHT"))  MP_RIGHT = .95
if (!exists("MP_BOTTOM")) MP_BOTTOM = .14
if (!exists("MP_TOP"))    MP_TOP = .9
if (!exists("MP_xGAP"))   MP_xGAP = 0.05
if (!exists("MP_yGAP"))   MP_yGAP = 0.02

set multiplot layout 2,2 columnsfirst title "{/:Bold=15 Signals analysis}" \
              margins screen MP_LEFT, MP_RIGHT, MP_BOTTOM, MP_TOP spacing screen MP_xGAP, MP_yGAP

set format y "%.1f"
set key box opaque
set ylabel 'ylabel'


plot "PulseSensor.dat" with lines lt 1
set xlabel 'xlabel'
plot "HannWindow.dat" with lines lt 2

unset ylabel
unset ytics

unset xlabel
files="Producto_threads Producto_process"
plot for [file in  files] file.".dat"  title file with lines lt 3
set xlabel 'xlabel'
plot "Autocorrelacion.dat" with lines lt 4
unset multiplot
pause mouse
