#include <stdexcept>

#include "question1.hpp"

namespace question1 {

	std::pair<int, int> maxSubArray(std::vector<int> tab) {
		//Invariant : I(d, f, s, d', s', k) => T[d:f] est le pstsm dans T[0:k], de somme s
		//                                  => T[d':k] est le suffixe de somme maximale dans T[0:k], de somme s'

		//Initialisation : d  = 0
		//                 f  = 1
		//                 s  = T[0]
		//                 d' = 0
		//                 s' = 0
		//                 k  = 1

		//Arrêt : k = n

		//Implications : I(d, f, s, d', s', k) ∧ s ≥ 0 ∧ s' + T[k] > s  => I( d' , k+1 , s'+T[k] , d' , s'+T[k] , k+1 )
		//               I(d, f, s, d', s', k) ∧ s ≥ 0 ∧ s' + T[k] ≤ s  => I( d  , f   , s       , d' , s'+T[k] , k+1 )
		//               I(d, f, s, d', s', k) ∧ s < 0 ∧      T[k] > s  => I( k  , k+1 , T[k]    , k  , T[k]    , k+1 )
		//               I(d, f, s, d', s', k) ∧ s < 0 ∧      T[k] ≤ s  => I( d  , f   , s       , k  , T[k]    , k+1 )

		int d = 0, f = 1,
		    s = tab[0],
			dp = 0,
			sp = s,
			k = 1,
			size = tab.size();
		while(k != size) {		                  //I(d, f, s, d', s', k) && (k ≠ n)
			if(sp >= 0) {	                      //I(d, f, s, d', s', k) && (k ≠ n) && (s >= 0)
				if(sp + tab[k] > s) {             //I(d, f, s, d', s', k) && (k ≠ n) && (s >= 0) && (s' + T[k] > s) => I(d', k+1, s'+T[k], d', s'+T[k], k+1)
					d = dp;
					f = k + 1;
					s = sp + tab[k];
					sp = sp + tab[k];
					k++;
				}                                 //I(d, f, s, d', s', k)
				else {                            //I(d, f, s, d', s', k) && (k != n) && (s >= 0) && & (s' + T[k] =< s) => I(d, f, s, d', s'+T[k], k+1)
					sp = sp + tab[k];
					k++;
				}                                 //I(d, f, s, d', s', k)
			}
			else {	                              //I(d, f, s, d', s', k) && (k != n) && (s < 0)-
				if (tab[k] > s) {                 //I(d, f, s, d', s', k) && (k != n) && (s < 0) && (T[k] > s) => I(k, k+1, T[k], k, T[k], k+1)
					d = k;
					f = k + 1;
					s = tab[k];
					dp = d;
					sp = s;
					k++;
				}                               //I(d,f,s,d',s',k)
				else {                           //I(d, f, s, d', s', k) && (k != n) && (s < 0) && (T[k] > s) => I(d, f, s, k, T[k], k+1)
					dp = k;
					sp = tab[k];
					k++;
				}                               //I(d, f, s, d', s', k)
			}
		}
		std::pair<int, int> dfs(d,f);
		return dfs;
	}

}
