function ft_1=t_norm_d(a,b)
  for i=1:length(a)
    for j=1:length(b)
      if b(j)==1
        ft_1(i,j)=a(i)
      elseif a(i)==1
        ft_1(i,j)=b(j)
      else
        ft_1(i,j)=0
      endif
    endfor
  endfor
endfunction
