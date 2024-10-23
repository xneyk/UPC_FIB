
fich = url('http://www-eio.upc.es/teaching/pe/tipus_dades.txt')
DAT = read.table(fich, header=FALSE, col.names=c('op','mysql','post'))

DAT
View(DAT)
head(DAT)
str(DAT)

mean(DAT$mysql)
median(DAT$mysql)
summary(DAT$mysql)
var(DAT$mysql)
sd(DAT$mysql)

#OPCIÓ 2
attach(DAT)
mean(mysql)

#detach(DAT)

par(mfrow=c(1,2))
hist(DAT$mysql)
boxplot(DAT$mysql)

table(DAT$op)
prop.table(table(DAT$op))
barplot(table(DAT$op))

install.packages("descr") # Installacio del paquet (si no esta installat)
library(descr) # Es carrega el paquet
freq(DAT$op, plot=F)

write.table(DAT, file="DadesDAT.txt", quote=F, row.names=F)
save.image("DadesDAT.RData")


