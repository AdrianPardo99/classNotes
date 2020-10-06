function fg=gaussian(x,c,ro)
%
%% Funcion Difusa Gaussiana
%%  x: es un arreglo de la funcion
%%
%%  c: es un valor numerico determina
%%    o aproxima la ubicación del valor
%%    central de la funcion
%%
%%  ro: es la varianza de la funcion
%%
%
  fg=e.^(-0.5*((x-c)/ro).^2)
endfunction
