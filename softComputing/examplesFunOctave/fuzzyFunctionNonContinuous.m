x=[0:6]
B=[.1,.3,.7,1,.6,.2,.1]
stem(x,B)
xlabel("x= Número de hijos")
ylabel('\mu_{A}(x) Grados de deseo')
title("A=Número deseado de niños")
name=sprintf("FunNonCon.jpg")
print(name)
pause(20)

