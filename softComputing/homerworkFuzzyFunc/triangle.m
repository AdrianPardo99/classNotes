function ft=triangulo(x,a,b,c)
  ft=max(min(((x-a)/(b-a)),((c-x)/(c-b))),0)
endfunction
