function graphicFuzzy(x,fm,labelx,labely,titulo,color)
%
%% Modulo que grafica funciones 2D
%%  x y fm:  son arreglos de funciones
%%    del mismo tamaño el cual permite
%%    realizar la grafica
%%
%%  labelx y labely: son los nombres que
%%    se le asigna a los ejes (x,y) respectivamente
%%
%%  titulo: es el como se determinara el nombre
%%    de la grafica
%%
%% color: es un parametro el cual asigna el color del trazo
%%
%
  s=plot(x,fm,"markersize", 10)
  xlabel(labelx)
  ylabel(labely)
  title(titulo)
  set(s,'Color',color,'LineWidth',3)
  grid
endfunction
