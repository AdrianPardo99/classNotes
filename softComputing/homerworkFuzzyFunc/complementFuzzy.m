function fmc=complementFuzzy(fm)
%
%% Funcion NOT/Complemento de una funcion difusa
%%  fm: es el arreglo de la funcion de tamanio N
%%    y devuelve una funcion difusa
%%    del mismo tamaño el cual permite
%%    realizar la operacion difusa
%
  fmc=1-fm
endfunction
