import java.math.*;
import java.util.*;

public class hdu1715
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        BigDecimal a[] = new BigDecimal[1005];
        a[1]=a[2]=new BigDecimal(1);
        for (int i=3;i<=1000;i++)
            a[i] = a[i-1].add(a[i-2]);
        while(n-->0)
        {
            int x = cin.nextInt();
            System.out.println(a[x]);
        }
    }
}
