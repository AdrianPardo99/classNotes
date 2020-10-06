function fb=gbell(x,a,b,c)
  fb=1./(1+(abs((x-c)/a)).^(2*b))
endfunction
