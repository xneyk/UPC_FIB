n <- 10
p <- 0.5
par(mfrow=c(1,2))
plot(0:n,dbinom(0:n,n,p),type="h",main="Funció de probabilitat")
plot(0:n,pbinom(0:n,n,p),type="s",main="Funció de distribució")


lambda <- 4
xmax <- qpois(0.99,lambda) # Valor fins on arriba el gr?fic
par(mfrow=c(1,2))
plot(0:xmax,dpois(0:xmax,lambda),type="h",main="Funció de probabilitat")
plot(0:xmax,ppois(0:xmax,lambda),type="s",main="Funció de distribució")

n <- 100
p <- 0.05
lambda <- n*p
xmax <- qpois(0.99,lambda)
par(mfrow=c(1,1))
plot(0:xmax-0.1,dbinom(0:xmax,n,p),type="h",main="Funci?deprobabilitat")
points(0:xmax+0.1,dpois(0:xmax,lambda),type="h",col="red")

lambda <- 10
xmax <- qexp(0.99,lambda)
par(mfrow=c(1,2))
curve(dexp(x,lambda),0,xmax,main="Funci? de densitat")
curve(pexp(x,lambda),0,xmax,main="Funci? de distribuci?")

X1 = rexp(5000, 2)
X2 = rexp(5000, 2)
X3 = rexp(5000, 2)
T = cbind(X1, X2, X3)
S = apply(T, 1, min)
P = apply(T, 1, max)
par(mfrow=c(1,2))
hist(S,freq=FALSE)
curve(dexp(x,1/mean(S)),add=TRUE,col=2,lwd=2)
hist(P,freq=FALSE)
curve(dexp(x,1/mean(P)),add=TRUE,col=2,lwd=2)

mu <- 0
sigma <- 1
xlim <- qnorm(c(0.01,0.99),mu,sigma)
par(mfrow=c(1,2))
curve(dnorm(x,mu,sigma),xlim[1],xlim[2],main="Funci? de probabilitat")
curve(pnorm(x,mu,sigma),xlim[1],xlim[2],main="Funci? de distribuci?")



