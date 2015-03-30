public class exo3
{
    public static void main(String[] args)
    {
        int [] T = {-2, 3, -1, 5, -2, 4, -3, -6, 8, 1};
        int [] result = pstsm(T);
        printArray(result);
         
    }
     
    public static int[] pstsm(int [] T){
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

        int d = 0, f = 1, s = T[0], dp = 0, sp = s, k = 1;
        while (k != T.length) {                 //I(d, f, s, d', s', k) && (k ≠ n)
            if (sp >= 0) {                      //I(d, f, s, d', s', k) && (k ≠ n) && (s >= 0)
                if(sp + T[k] > s) {             //I(d, f, s, d', s', k) && (k ≠ n) && (s >= 0) && (s' + T[k] > s) => I(d', k+1, s'+T[k], d', s'+T[k], k+1)
                    d = dp;
                    f = k + 1;
                    s = sp + T[k];
                    sp = sp + T[k];
                    k++;
                }                               //I(d, f, s, d', s', k)
                else{                           //I(d, f, s, d', s', k) && (k != n) && (s >= 0) && & (s' + T[k] =< s) => I(d, f, s, d', s'+T[k], k+1)
                    sp = sp + T[k];            
                    k++;
                }                               //I(d, f, s, d', s', k)
            }
            else{                               //I(d, f, s, d', s', k) && (k != n) && (s < 0)-
                if (T[k] > s) {                 //I(d, f, s, d', s', k) && (k != n) && (s < 0) && (T[k] > s) => I(k, k+1, T[k], k, T[k], k+1)
                    d = k;
                    f = k + 1;
                    s = T[k];
                    dp = d;
                    sp = s;
                    k++;
                }                               //I(d,f,s,d',s',k)
                else{                           //I(d, f, s, d', s', k) && (k != n) && (s < 0) && (T[k] > s) => I(d, f, s, k, T[k], k+1)
                    dp = k;
                    sp = T[k];
                    k++;
                }                               //I(d, f, s, d', s', k)
            }
        }
        int[] dfs = {d,f,s};
        return dfs;
    }

    public static void printArray(int[] T) {
        System.out.print("{");
        for(int i = 0; i < T.length; i++){
            System.out.print(T[i]);
            if(i != T.length-1) System.out.print(", ");
        }
        System.out.println("}");    
    }

}   