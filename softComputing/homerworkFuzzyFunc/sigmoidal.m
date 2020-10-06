function fs=sigmoidal(x,a,c)
  fs=1./(1+e.^(-a*(x-c)))
endfunction
