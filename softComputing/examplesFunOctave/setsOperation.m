x=[0:0.01:90]
bell1=1./(1+((x-45)/15).^6)
bell2=1./(1+((x-70)/20).^6)
hold on
s=plot(x,bell1,"markersize", 10)
s1=plot(x,bell2,"markersize", 10)
set(s,'Color','red','LineWidth',1)
set(s,'Color','green','LineWidth',1)
xlabel('x')
ylabel('Pertenencia')
title('Two sets A,B')
hold off
name=sprintf("twoSetsAB.jpg")
print(name)
pause(10)
clf
notA=1-bell1
hold on
s=plot(x,notA,"markersize", 10)
set(s,'Color','red','LineWidth',1)
xlabel('x')
ylabel('Pertenencia')
title('Not A')
hold off
name=sprintf("NotAB.jpg")
print(name)
pause(10)
clf
orC=max(bell1,bell2)
hold on
s=plot(x,orC,"markersize", 10)
set(s,'Color','red','LineWidth',1)
xlabel('x')
ylabel('Pertenencia')
title('A or B')
hold off
name=sprintf("AorB.jpg")
print(name)
pause(10)
clf
andC=min(bell1,bell2)
hold on
s=plot(x,andC,"markersize",10)
set(s,'Color','red','LineWidth',1)
xlabel('x')
ylabel('Pertenencia')
title('A and B')
hold off
name=sprintf("AandB.jpg")
print(name)
pause(10)




