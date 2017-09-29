
while(n-->0)
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
BigInteger ans = cin.nextInteger();
BigInteger ans = new BigInteger("0");
if (ans.equals(BigInteger.valueOf(0)));


