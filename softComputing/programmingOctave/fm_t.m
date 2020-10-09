clf
close all
a=0:0.1:1
b=0:0.1:1

for i=1:length(a)
  for j=1:length(b)
    T_min(i,j)=min(a(i),b(j))
    S_max(i,j)=max(a(i),b(j))
  endfor
endfor
subplot(2,1,1)
surf(a,b,T_min)
%grid
%grid
hold on
subplot(2,1,2)
surf(a,b,S_max)
%grid
hold off
%grid
