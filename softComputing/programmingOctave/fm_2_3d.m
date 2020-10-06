x=[-10:0.5:10];
y=[-10:0.5:10];

a1=-7;
b1=-1;
c1=5;
a2=-2;
b2=3;
c2=8;

for r=1:length(x)
    for p=1:length(y)
        z1(r,p)=max(max(min(((x(r)-a1)/(b1-a1)),((c1-x(r))/(c1-b1))),0),...
            max(min(((y(p)-a2)/(b2-a2)), ((c2-y(p))/(c2-b2))),0));
        z2(r,p)=min(max(min(((x(r)-a1)/(b1-a1)),((c1-x(r))/(c1-b1))),0),...
            max(min(((y(p)-a2)/(b2-a2)), ((c2-y(p))/(c2-b2))),0));
    end
end

subplot(2,1,1)
surf(x,y,z1)
grid
subplot(2,1,2)
surf(x,y,z2)
grid

pause(15)
