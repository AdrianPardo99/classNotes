x=[0:0.1:90]
sigmoid=1./(1+e.^(x-30))
sigmoid1=1-1./(1+e.^(x-60))
bell=1./(1+((x-45)/15).^6)

hold on
s=plot(x,sigmoid,"markersize", 10)
s1=plot(x,sigmoid1,"markersize", 10)
b=plot(x,bell,"markersize", 10)
set(s,'Color','blue','LineWidth',1)
set(s1,'Color','yellow','LineWidth',2)
set(b,'Color','magenta','LineWidth',3)
xlabel('x = Edad')
ylabel('Pertenencia')
title('Fuzzy Partitions Functions')
legend('Young','Old','Middle Aged')
hold off
name=sprintf("FuzzyPart.jpg")
print(name)
pause(20)
