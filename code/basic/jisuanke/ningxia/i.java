import java.math.*;
import java.util.*;

public class i
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNextBigInteger())
        {
            BigInteger a = cin.nextBigInteger();
            //System.out.println(a);
            BigInteger tmp = a;
            BigInteger b = BigInteger.valueOf(0);

            while(!tmp.equals(BigInteger.valueOf(0)))
            {
                b = b.multiply(BigInteger.valueOf(10));
                b = b.add(tmp.remainder(BigInteger.valueOf(10)));
                tmp = tmp.divide(BigInteger.valueOf(10));
            }
            a = a.subtract(b);
            if(a.compareTo(BigInteger.valueOf(0)) == -1)
                a = a.multiply(BigInteger.valueOf(-1));
            a = a.divide(BigInteger.valueOf(9));
            

            boolean flag=true;
            BigInteger test = a.remainder(BigInteger.valueOf(10));
            a = a.divide(BigInteger.valueOf(10));
            while(!a.equals(BigInteger.valueOf(0)))
            {
                BigInteger tt = a.remainder(BigInteger.valueOf(10));
                a = a.divide(BigInteger.valueOf(10));
                if(!tt.equals(test))
                {
                    flag = false;
                    break;
                }
            }
            if(flag==false)
            {
                System.out.println("NO");
            }
            else System.out.println("YES");
        }
    }
}
