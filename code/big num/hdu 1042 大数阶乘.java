import java.math.*;
import java.util.*;

public class hdu1024
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            int n = cin.nextInt();
            //BigDecimal ans = new BigDecimal(1);
            BigInteger ans = BigInteger.ONE;
            for (int i=1;i<=n;i++)
            {
                //BiDecimal a = new BigDecimal(i);
                ans = ans.multiply(BigInteger.valueOf(i));
            }
            System.out.println(ans);
        }
    }
}
