function ft=triangulo(x,a,b,c)
  %
  %% Funcion Difusa Triangulo
  %%  x: es un arreglo de la funcion
  %%
  %%  a y c: son un valor numerico el cual ayuda a trazar una recta
  %%
  %%  b: es un valor numerico el cual debe ser distinto de a o de c
  %%
  %
  ft=max(min((x-a)/(b-a),(c-x)/(c-b)),0)
endfunction
