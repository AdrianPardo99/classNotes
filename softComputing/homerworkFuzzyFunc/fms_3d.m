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
print(sprintf("t_norma_graphics_2.png"))
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
print(sprintf("s_norma_graphics_2.png"))
pause(10)
clf
a=-10:10
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
print(sprintf("t_norma_graphics_3.png"))
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
print(sprintf("s_norma_graphics_3.png"))
pause(10)
