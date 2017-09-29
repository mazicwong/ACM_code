import java.math.BigDecimal;
import java.util.*;

public class hdu1753
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        BigDecimal a,b;
        while(cin.hasNext())
        {
            a = cin.nextBigDecimal();
            b = cin.nextBigDecimal();
            System.out.println(a.add(b).stripTrailingZeros().toPlainString());
        }
    }
}
