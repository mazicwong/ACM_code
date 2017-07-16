package acm;

import java.util.Base64;
import java.util.Scanner;
public class HDU5237 {//交的时候这里改成Main
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);  
        int cas=sc.nextInt();
        for (int k=1;k<=cas;k++)
        {
        	int cnt = sc.nextInt();  
        	String str = sc.next();  
        	byte tt[] = str.getBytes(); //转成byte型  
        	for (int i=0;i<cnt;i++)
        	{
        		tt = Base64.getEncoder().encode(tt); //加密  
        		//Base64.getDecoder().decode(tt); //解密  
        	}//coder 编码器  
        	System.out.println("Case #" + k + ": " + (new String(tt)));  
        	//输出时记得转回原来编码
        }
	}
}
