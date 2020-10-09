function ft_1=t_norm_prod_a(a,b)
  for i=1:length(a)
    for j=1:length(b)
      ft_1(i,j)=a(i)*b(j)
    endfor
  endfor
endfunction
