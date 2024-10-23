DF <- read.table(file="DadesDF", header=TRUE, sep='\t', stringsAsFactors = TRUE)

write.table(DF, file="DadesDF", quote=F, row.names=F)
DF2 = read.table("DadesDF", header=TRUE)


# Comprovació de la lectura de dades
dim(DF)		  # Nombre d'observacions i de variables 
names(DF)		# Noms de les variables 
head(DF) 		# Primeres files de les dades
summary(DF)	# Descriptiva de les variables a la base

f <- function(x){
  
  ##-- Càlcul funcions
  t <- table(x)
  k <- as.numeric(names(t))      # Valors que pren la VAD
  p <- as.numeric(prop.table(t)) # Funci?n de probabilidad
  F <- cumsum(p)                 # Funci?n de distribuci?n
  df <- data.frame(k,p,F)        # Taula amb dues funcions
  print(k);print(p);print(F)
  
  ##-- Gràfic funcions
  par(mfrow=c(1,2),las=1)
  plot(k,p,type="h",main="Probabilitat")
  plot(k,F,type="S",main="Distribuci?")
  
  return(df)
}

# DF <- read.table("clipboard", header=TRUE, sep='\t')
Df.nger <- f(x = DF$nger)
Df.nger

##-- Esperança (E) i variància (V)
E <- with(Df.nger, sum(k*p))
V <- with(Df.nger, sum((k-E)^2*p))
E;V


##-- Esperan?a (E) i vari?ncia (V)
tab.conj <- with(DF,table(nger,gerpa))
round(prop.table(tab.conj),3)

sum(diag(prop.table(tab.conj)))

install.packages("scatterplot3d")
library("scatterplot3d")

par(mfrow=c(1,1),las=1)
conj <- prop.table(tab.conj)
X <- rep(rownames(conj),10)
Y <- rep(colnames(conj),each=5)
scatterplot3d(X,Y,conj, type='h', lwd=3, lab=c(5,5,1), box=FALSE, color=X, xlab='Germans fill', ylab='Germans pare', zlab='p')

##-- Funcions de probabilitat
px <- apply(conj,1,sum)
py <- apply(conj,2,sum)
px;py

##-- Esperances
kx <- as.numeric(names(px))
Ex <- sum(kx*px)
ky <- as.numeric(names(py))
Ey <- sum(ky*py)
Ex;Ey

##-- Desviacions tipus
Vx <- sum((kx-Ex)^2*px)
Vy <- sum((ky-Ey)^2*py)
Sx <- sqrt(Vx)
Sy <- sqrt(Vy)

##-- Càlcul de la correlació
Cov <- sum(((kx-Ex) %*% t((ky-Ey)))*conj)
Corr <- Cov/(Sx*Sy)
Corr

round(conj/apply(conj,1,sum),3)  # Condicionat als germans del fill
round(conj/apply(conj,2,sum),3)  # Condicional als germans del pare

