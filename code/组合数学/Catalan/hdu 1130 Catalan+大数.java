import java.math.*;
import java.util.*;

/*
 * 预处理Catalan前n项
 * Catalan递推: C(n) = C(n-1)*(4n-2)/(n+1);
 */

public class hdu1130
{
    public static BigInteger ans[] = new BigInteger[105];
    public static void getCatalan(int num)
    {
        ans[0] = new BigInteger("1");
        ans[1] = new BigInteger("1");
        BigInteger one = new BigInteger("1");
        BigInteger two = new BigInteger("2");
        BigInteger four = new BigInteger("4");

        for (int i=2;i<=num;i++)
        {
            String str = String.valueOf(i);
            BigInteger n = new BigInteger(str);
            BigInteger tmp = new BigInteger("0");
            ans[i] = ans[i-1].multiply(n.multiply(four).subtract(two)).divide(n.add(one));
        }
    }

    public static void main(String[] args)
    {
        getCatalan(100);
        Scanner cin = new Scanner(System.in);
        while(cin.hasNextInt())
        {
            int n = cin.nextInt();
            System.out.println(ans[n]);
        }
    }
}
