function graphicFuzzy(x,fm,labelx,labely,titulo,color)
  s=plot(x,fm,"markersize", 10)
  xlabel(labelx)
  ylabel(labely)
  title(titulo)
  set(s,'Color',color,'LineWidth',3)
  grid
endfunction
