import java.math.*;
import java.util.*;

public class f
{

    static BigInteger[] fib = new BigInteger[80];
    static BigInteger ans;
    static public void solve(BigInteger n, int up)
    {
        if (n.equals(BigInteger.valueOf(1)))
        {
            return;
        }
        for(int i=up;i>=0;i--)
        {
            if(fib[i].compareTo(n)<0)
            {
                ans = ans.add(BigInteger.valueOf(1<<(i-2)));
                solve(n.subtract(fib[i]),i-1);
                return;
            }
        }

    }
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        fib[1]=fib[2] = BigInteger.valueOf(1);
        for(int i=3;i<=77;i++)
        {
            fib[i] = fib[i-1].add(fib[i-2]);
        }

        for(int kk=1;kk<=t;kk++)
        {
            BigInteger n = cin.nextBigInteger();
            ans = BigInteger.valueOf(0);
            solve(n.add(BigInteger.valueOf(1)),77);
            System.out.println(ans);
        }
        
    }
}
