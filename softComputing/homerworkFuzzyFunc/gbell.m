function fb=gbell(x,a,b,c)
%
%% Funcion Difusa Campana Generalizada
%%  x: es un arreglo de la funcion
%%
%%  a: actua es la varianza de la funcion
%%
%%  b: es el valor el cual determinara el
%%    crecimiento de la funcion exponencial
%%
%%  c: es un valor numerico determina
%%    o aproxima la ubicación del valor
%%    central de la funcion
%%
%
  fb=1./(1+(abs((x-c)/a)).^(2*b))
endfunction
