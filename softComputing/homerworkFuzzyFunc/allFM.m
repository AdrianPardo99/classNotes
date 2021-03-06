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
  subplot(3,3,1)
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
  subplot(3,3,2)
  graphicFuzzy(x,ffs,'x','Sugeno complement N_{s}(x)','Fuzzy function Sugeno complement',colors)
endfor
legend(sprintf('w=%.1f',s(1)),sprintf('w=%.1f',s(2)),sprintf('w=%.1f',s(3)),...
sprintf('w=%.1f',s(4)),sprintf('w=%.1f',s(5)))
hold off
%
%x=[-10:0.5:10]
%a=-7;
%b=-1;
%c=5;
%ffs=triangle(x,a,b,c)
%[xx,yy]=functionThreeD(x,ffs)
%z=ones(length(xx),length(yy))
%hold on
%subplot(1,2,1)
%graphicFuzzy(x,ffs,'x','triangleFM','Fuzzy Triangle Function','red')
%subplot(1,2,2)
%graphicFuzzy3D(xx,yy,z)
%hold off




% Triangulos
x=[-10:0.5:10]
a1=-7;
b1=-1;
c1=5;
a2=-2;
b2=3;
c2=8;
ft1=triangle(x,a1,b1,c1)
ft2=triangle(x,a2,b2,c2)
subplot(3,3,3)
hold on
graphicFuzzy(x,ft1,'x','triangleFM','Fuzzy Triangle Function','red')
subplot(3,3,3)
graphicFuzzy(x,ft2,'x','triangleFM','Fuzzy Triangle Function','blue')
legend('Triangle 1','Triangle 2')
grid



% Sigmoide
x=[0:0.1:90]
fs=sigmoidal(x,1,30)
subplot(3,3,4)
graphicFuzzy(x,fs,'x','sigmoidalFM','Fuzzy Sigmoidal Function','red')


% Gaussian
c=45
ro=9
fg=gaussian(x,c,ro)
subplot(3,3,5)
graphicFuzzy(x,fg,'x','gaussianFM','Fuzzy Gaussian Function','green')



% Trapezoide
a=10
b=20
c=60
d=80
ftr=trapezoid(x,a,b,c,d)
subplot(3,3,6)
graphicFuzzy(x,ftr,'x','trapezoidFM','Fuzzy Trapezoid Function','magenta')


% Bell
subplot(3,3,7)
fgb=gbell(x,a,b,c)
graphicFuzzy(x,fgb,'x','gBellFM','Fuzzy General Bell Function','blue')


% Bell Complement
subplot(3,3,8)
fgbc=complementFuzzy(fgb)
graphicFuzzy(x,fgbc,'x','gBellFM complement','Fuzzy Complement Function','yellow')

% Bell Complement
subplot(3,3,9)
x=[-10:0.5:10]
f_or=orFuzzy(ft1,ft2)
graphicFuzzy(x,f_or,'x','max(triangle1,triangle2)','Fuzzy Set Operation','magenta')
hold off
hold on
fand=andFuzzy(ft1,ft2)
graphicFuzzy(x,fand,'x','min(triangle1,triangle2)','Fuzzy Set Operation','blue')
subplot(3,3,9)
legend('AND','OR')
grid
hold off
print(sprintf("primeras_funciones.png"))
pause(10)
clf
x=0:0.1:100
flr1=lr(x,60,10,65)
flr2=lr(x,10,40,25)
subplot(1,2,1)
graphicFuzzy(x,flr1,'x','LR Function','Example LR FM 1','blue')
hold on
subplot(1,2,2)
graphicFuzzy(x,flr2,'x','LR Function','Example LR FM 2','red')
hold off
print(sprintf("lr_funciones.png"))
pause(10)


clf
x=[0:0.1:90]
fs=sigmoidal(x,1,30)
fs1=sigmoidal(x,-1,80)
subplot(1,3,1)
graphicFuzzy(x,fs,'x','Sigmoidal FM','FM Sigmoidal 1','yellow')
hold on
graphicFuzzy(x,fs1,'x','Sigmoidal FM','FM Sigmoidal 2','blue')
legend('S1','S2')
grid
subplot(1,3,2)
graphicFuzzy(x,abs(fs-fs1),'x','Sigmoidal |S1-S2|','FM','magenta')
subplot(1,3,3)
graphicFuzzy(x,fs.*fs1,'x','Sigmoidal S1*S2','FM','green')
hold off
print(sprintf("sigmoidal_op.png"))
pause(10)


clf
a=0:0.1:1
t1=t_norm_min(a,a)
subplot(2,2,1)
graphicFuzzy3D(a,a,t1)
t2=t_norm_prod_a(a,a)
subplot(2,2,2)
graphicFuzzy3D(a,a,t2)
t1=t_norm_prod_ac(a,a)
subplot(2,2,3)
graphicFuzzy3D(a,a,t1)
t2=t_norm_d(a,a)
subplot(2,2,4)
graphicFuzzy3D(a,a,t2)
print(sprintf("t_norma_graphics.png"))
pause(10)


clf
s1=s_norm_max(a,a)
subplot(2,2,1)
graphicFuzzy3D(a,a,s1)
s1=s_norm_sum(a,a)
subplot(2,2,2)
graphicFuzzy3D(a,a,s1)
s1=s_norm_s_ac(a,a)
subplot(2,2,3)
graphicFuzzy3D(a,a,s1)
subplot(2,2,1)
s1=s_norm_s_d(a,a)
subplot(2,2,4)
graphicFuzzy3D(a,a,s1)
print(sprintf("s_norma_graphics.png"))
pause(10)
