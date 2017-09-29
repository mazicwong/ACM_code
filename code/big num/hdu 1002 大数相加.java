// A+B 
import java.math.*;
import java.util.*;

public class hdu1002
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        for (int cas=1;cas<=n;cas++)
        {
            BigInteger a = cin.nextBigInteger();
            BigInteger b = cin.nextBigInteger();
            System.out.println("Case "+cas+":");
            System.out.println(a+" + "+b+" = "+a.add(b));
            if (cas!=n)
                System.out.println("");
        }
    }
}
