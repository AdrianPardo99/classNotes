function fs=sigmoidal(x,a,c)
%
%% Funcion Difusa Sigmoide
%%  x: es un arreglo de la funcion
%%
%%  a: es un valor numerico el cual permite
%%    controlar el crecimiento de la funcion
%%
%%  c: es un valor numerico determina
%%    o aproxima la ubicación del valor
%%    central de la funcion en 0.5
%%
%
  fs=1./(1+e.^(-a*(x-c)))
endfunction
