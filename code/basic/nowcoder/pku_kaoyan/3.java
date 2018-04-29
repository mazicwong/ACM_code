import java.math.*;
import java.util.*;


public class qq
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            Stack<BigInteger> S = new Stack<BigInteger>();
            BigInteger num = cin.nextBigInteger();
            if(num.equals(BigInteger.valueOf(0)))
            {
                System.out.println("0");
                continue;
            }
            int cnt = 0;
            while(!num.equals(BigInteger.valueOf(0)))
            {
                //System.out.print(num.remainder(BigInteger.valueOf(2)));
                S.push(num.remainder(BigInteger.valueOf(2)));
                num = num.divide(BigInteger.valueOf(2));
            }
            while(!S.empty())
                System.out.print(S.pop());
            System.out.println();
        }
    }
}
