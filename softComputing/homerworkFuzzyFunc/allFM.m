clc
x=[0:.01:1]
s=[3,1.5,1,0.7,0.4]
colors='green'
for i=1:length(s)
  switch i
  case 1
    colors='green'
  case 2
    colors='red'
  case 3
    colors='yellow'
  case 4
    colors='blue'
  otherwise
    colors='magenta'
  endswitch
  hold on
  ffs=fuzzyYager(x,s(i))
  subplot(1,2,1)
  graphicFuzzy(x,ffs,'x','Yager complement N_{w}(x)','Fuzzy function Yager complement',colors)
endfor
legend(sprintf('w=%.1f',s(1)),sprintf('w=%.1f',s(2)),sprintf('w=%.1f',s(3)),...
sprintf('w=%.1f',s(4)),sprintf('w=%.1f',s(5)))
hold off

s=[-0.95,-0.7,0,2,20]
for i=1:length(s)
  switch i
  case 1
    colors='magenta'
  case 2
    colors='red'
  case 3
    colors='green'
  case 4
    colors='blue'
  otherwise
    colors='yellow'
  endswitch
  hold on
  ffs=fuzzySugeno(x,s(i))
  subplot(1,2,2)
  graphicFuzzy(x,ffs,'x','Sugeno complement N_{s}(x)','Fuzzy function Sugeno complement',colors)
endfor
legend(sprintf('w=%.1f',s(1)),sprintf('w=%.1f',s(2)),sprintf('w=%.1f',s(3)),...
sprintf('w=%.1f',s(4)),sprintf('w=%.1f',s(5)))
hold off
pause(15)
