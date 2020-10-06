x=[-10:0.1:10]
a1=-7
b1=-1
c1=5

a2=-2
b2=3
c2=8

y1=max(min((x-a1)/(b1-a1),(c1-x)/(c1-b1)),0)
y2=max(min((x-a2)/(b2-a2),(c2-x)/(c2-b2)),0)
subplot(2,2,1)
plot(x,y1)
hold on
plot(x,y2)
grid
subplot(2,2,2)
plot(x,1-y1)
grid
subplot(2,2,3)
plot(x,max(y1,y2))
grid
subplot(2,2,4)
plot(x,min(y1,y2))
grid
hold off
pause(15)
