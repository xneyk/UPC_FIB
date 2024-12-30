rm(list = ls())


#OPCIÓ 1 - Carregueu el fitxer cardiac.Rda
#Fixeu el directori de treball on hi ha el fitxer
#Empreu la comanda següent o aneu a Session - Set Working Directory

setwd("")
load(file='cardiac.Rda')


#OPCIÓ 2 - Llegiu el fitxer cardiac.txt
cor <- read.table("clipboard",header=T)

#OPCIÓ 3 - Empreu Import Dataset de l'Enviroment de dalt a la dreta de RStudio
#En aquest cas, Import Dataset - From Text (base) i empreu el fitxer .txt
#En les opcions fixeu-vos que indiqueu que:
#- El nom és cor (enlloc de cardiac que és el nom del fitxer)
#- El fitxer té Capçalera (Heading),
#- Row names: Use first columns
#- El separador és per Comma 
#- Els decimals són amb "."

# PREGUNTA 1

# attach(cor);
# detach(cor);

MODEL1 <- lm(cor$problemes.cor ~ cor$bicicleta);
plot(MODEL1);
variacio <- summary(MODEL1)$r.squared;
summary(MODEL1);

qt(0.975, 496);

cor(cor$problemes.cor,cor$fumador);

MODEL2 <- lm(cor$problemes.cor ~ cor$fumador);
variacio_2 <- summary(MODEL2)$r.squared;
summary(MODEL2);
names(cor)
summary(cor)
attach(cor)