function fs_1=s_norm_s_ac(a,b)
  for i=1:length(a)
    for j=1:length(b)
      fs_1(i,j)=min(1,(a(i)+b(j)))
    endfor
  endfor
endfunction
