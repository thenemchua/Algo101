svg("fibonacci.svg", width=10, height=10)
plot(read.csv("fibonacci.csv"), type="b",
	 xlab="Indice de la valeur à calculer",
	 ylab="Temps écoulé (en millisecondes)")
dev.off()
