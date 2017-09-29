import java.math.*;
import java.util.*;

public class hdu1047
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        while(n-->0)
        {
            BigInteger ans = new BigInteger("0");
            while(cin.hasNextBigInteger())
            {
                BigInteger a = cin.nextBigInteger();
                if (a.equals(BigInteger.valueOf(0)))
                    break;
                ans = ans.add(a);
            }
            System.out.println(ans);
            if (n!=0)
                System.out.println();
        }
        
    }
}
