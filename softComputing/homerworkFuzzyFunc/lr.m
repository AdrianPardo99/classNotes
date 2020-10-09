function flr=lr(x,a,b,c)
  x1=(c-x)/a
  fl=sqrt(max(0,(1-x1.^2)))
  x1=(x-c)/b
  fr=e.^(-abs(x1.^3))
  flr=fl(x<c)
  flr=[flr fr(x>=c)]
endfunction
