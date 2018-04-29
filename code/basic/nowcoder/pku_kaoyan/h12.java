import java.math.*;
import java.util.*;

public class h12
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            BigInteger n = cin.nextBigInteger();
            boolean flag=false;
            for(int i=2;i<=9;i++)
            {
                BigInteger tmp = BigInteger.valueOf(i);
                if(n.remainder(tmp).equals(BigInteger.valueOf(0)) == true)
                {
                    if(!flag) ;//System.out.print(i);
                    else System.out.print(' ');
                    System.out.print(i);
                    flag=true;
                }
            }
            if(!flag) System.out.println("none");
            else System.out.println();
        }
    }
}
