function ftr=trapezoid(x,a,b,c,d)
%
%% Funcion Difusa Trapezoide
%%  x: es un arreglo de la funcion
%%
%%  a y c: son un valor numerico el cual ayuda a trazar una recta
%%
%%  b y d: son un valor numerico el cual debe ser distinto de a y de c
%%    respectivamente
%%
%
  ftr=max(min(min(((x-a)/(b-a)),1),min(((d-x)/(d-c)),1)),0)
endfunction
