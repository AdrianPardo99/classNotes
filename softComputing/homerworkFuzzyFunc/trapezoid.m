function ftr=trapezoid(x,a,b,c,d)
  ftr=max(min(min(((x-a)/(b-a)),1),min(((d-x)/(d-c)),1)),0)
endfunction
