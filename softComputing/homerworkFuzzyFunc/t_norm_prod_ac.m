function ft_1=t_norm_prod_ac(a,b)
  for i=1:length(a)
    for j=1:length(b)
      ft_1(i,j)=max(0,(a(i)+b(j)-1))
    endfor
  endfor
endfunction
