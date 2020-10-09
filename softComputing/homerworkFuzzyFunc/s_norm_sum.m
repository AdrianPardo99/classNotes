function fs_1=s_norm_sum(a,b)
  for i=1:length(a)
    for j=1:length(b)
      fs_1(i,j)=a(i)+b(j)-a(i)*b(j)
    endfor
  endfor
endfunction
