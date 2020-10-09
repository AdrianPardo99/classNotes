function fs_1=s_norm_max(a,b)
  for i=1:length(a)
    for j=1:length(b)
      fs_1(i,j)=max(a(i),b(j))
    endfor
  endfor
endfunction
