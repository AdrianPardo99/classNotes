x=[0:0.001:100]
mbx=1./(1+((x-50).^2/10))
plot(x,mbx)
xlabel("x=Edad")
ylabel('\mu_{B}(x) \in Pertenencia')
title(strcat('\mu_{B}(x)=1/(1 + ( (x-50)/(10) )^{2} ) B=Alrededor de los 50 años'))
name=sprintf("FunCon.jpg")
print(name)
pause(20)
