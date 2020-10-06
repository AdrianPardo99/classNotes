function ffy=fuzzyYager(x,w)
  ffy=(1-(x.^w)).^(1/w)
endfunction
