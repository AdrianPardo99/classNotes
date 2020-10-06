#!/usr/bin/env Rscript
x=c(0:100000)*0.001
mbx=1/(1+((x-50)^2/10))
print(plot(x,mbx,
           main="Function continuous",ylab="M_{b}(x)",type="l",
           col="blue"))
