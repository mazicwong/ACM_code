import java.math.*;
import java.util.*;

/*
 * 出栈次数,Catalan
 * C(n) = C(n-1)*(4n-2)/(n+1);
 */

public class hdu1023
{
    public static BigInteger ans[] = new BigInteger[105];
    public static void getCatalan()
    {
        BigInteger one = new BigInteger("1");
        BigInteger two = new BigInteger("2");
        BigInteger four = new BigInteger("4");
        ans[1]=ans[0]=new BigInteger("1");
        for (int i=2;i<=100;i++)
        {
            String str = String.valueOf(i);
            BigInteger n = new BigInteger(str);
            ans[i]=ans[i-1].multiply(n.multiply(four).subtract(two)).divide(n.add(one));
        }
    }

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        getCatalan();
        while(cin.hasNextInt())
        {
            int n = cin.nextInt();
            System.out.println(ans[n]);
        }
    }
}
