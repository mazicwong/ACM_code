package acm;

import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class hdu1042 {
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		while(input.hasNext())
		{
			int n = input.nextInt();
			BigInteger ans = BigInteger.ONE;
			for (int i =1;i<=n;i++)
				ans = ans.multiply(BigInteger.valueOf(i));
			System.out.println(ans);
		}
	}
}
