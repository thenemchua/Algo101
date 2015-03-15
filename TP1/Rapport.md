# Rapport du TP1

	Les programmes de ce TP sont écrits en C++ 11

## Intersection de deux ensembles

### 3. Choix de l'algorithme

En supposant que \f$n_1 = n_2 = 10^6\f$, on a
\f$n_1 \times \log(n_2) = 6 \times 10^6\f$ alors que
\f$n_1 + n_2 = 2 \times 10^6\f$. Il semble donc judicieux de choisir le
deuxième algorithme.

En supposant que \f$n_1 = 10\f$ et \f$n_2 = 10^6\f$, on a
\f$n_1 \times \log(n_2) = 60\f$ et \f$n_1 + n_2 = 10 + 10^6\f$. Le meilleur
choix serait donc l'algorithme 1.
