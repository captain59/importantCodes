import java.io.*;
class solution
{
	public static void main(String args[])throws IOException
	{
		InputStreamReader inp=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(inp);
		int t=Integer.parseInt(br.readLine());
		while(t-->0)
		{
			String str=br.readLine();String temp="";
			str=str+" ";String sum="";
			int n=str.length();
			for(int i=0;i<n;i++)
			{
				if(str.charAt(i)!=' ')
					temp+=str.charAt(i);
				else
				{
					int l=temp.length();
					sum+=l;
					temp="";
				}
			}
			System.out.println(sum);
		}
	}
}