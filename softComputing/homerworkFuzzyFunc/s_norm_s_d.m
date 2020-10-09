function fs_1=s_norm_s_d(a,b)
  for i=1:length(a)
    for j=1:length(b)
      if b(j)==0
        fs_1(i,j)=a(i)
      elseif a(i)==0
        fs_1(i,j)=b(j)
      else
        fs_1(i,j)=1
      endif
    endfor
  endfor
endfunction
