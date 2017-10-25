int a = cin.nextInt();       相当于 scanf("%d", &a);
String s = cin.next();       相当于 scanf("%s", s);
double t = cin.nextDouble(); 相当于 scanf("%lf", &t);
String s = cin.nextLine()    相当于 gets(s);
while (cin.hasNext())        相当于 while (scanf("%d", &n) != EOF)
System.out.printf();         相当于 printf();
while(cin.hasNextBigInteger())


String:
String ans;
ans.stripTrailingZeros()  //去掉小数末尾的0
ans.toPlainString()       //转为普通计数,不要有1e5这种,纯字符串输出
if (ans.startsWith("0"))  //去掉第一个0
    ans = ans.substring(1);


BigDecimal:
BigDecimal a = cin.nextBigDecimal();
BigDecimal a[] = new BigDecimal[1005];
a[1]=a[2]=new BigDecimal(1);


BigInteger:
BigInteger ans = cin.nextInteger();      //输入大数
BigInteger ans = new BigInteger("0");    //赋初始值
if (ans.equals(BigInteger.valueOf(0)));  //判相等



import java.math.*;
import java.util.*;
import java.math.BigDecimal;

public class Main
{
    //A+B 
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


    //大浮点数相加
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


    //A+B+C+D.. (一直加直到0)
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        while(n-->0)
        {
            BigInteger ans = new BigInteger("0");
            while(cin.hasNextBigInteger())           //是否还有大数
            {
                BigInteger a = cin.nextBigInteger(); //大数输入
                if (a.equals(BigInteger.valueOf(0))) //判断大数
                    break;
                ans = ans.add(a); //大数加
            }
            System.out.println(ans);
            if (n!=0)
                System.out.println();
        }
        
    }


    // R^n
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


    //大数阶乘
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


    //fabonaqi
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
