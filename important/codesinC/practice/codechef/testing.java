import java.util.Scanner
class Solution
{
	public void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int diff=a-b;
		int l=diff%10;
		String str=diff;
		str=str.substring(0,str.length()-1)+"8";
		System.out.println(str);
	}
}