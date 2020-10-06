function ffy=fuzzyYager(x,w)
%
%% Funcion Difusa Complemento Yager
%%  x: es un arreglo de la funcion
%%    la cual idealmente va de [0,1]
%%
%%  w: es un valor numerico el cual
%%    determina la curvatura de la funcion
%%    que se presenta
%
  ffy=(1-(x.^w)).^(1/w)
endfunction
