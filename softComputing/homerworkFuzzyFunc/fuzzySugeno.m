function ffs=fuzzySugeno(x,s)
%
%% Funcion Difusa Complemento Sugeno
%%  x: es un arreglo de la funcion
%%    la cual idealmente va de [0,1]
%%
%%  s: es un valor numerico el cual
%%    determina la curvatura de la funcion
%%    que se presenta
%%
%
  ffs=(1-x)./(1+(s*x))
endfunction
