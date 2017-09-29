// R^n

import java.math.BigDecimal;
import java.util.*;

public class hdu1063
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            BigDecimal a = cin.nextBigDecimal();
            int b = cin.nextInt();
            String ans = a.pow(b).stripTrailingZeros().toPlainString();
            if (ans.startsWith("0"))
                ans = ans.substring(1);
            System.out.println(ans);
        }
    }
}
