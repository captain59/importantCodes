import java.io.*;
import java.util.*;
class Main
{
    public static void main(String[] args)throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tok = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(tok.nextToken());
        int m=Integer.parseInt(tok.nextToken());
        int k=Integer.parseInt(tok.nextToken());
        StringTokenizer elements =new StringTokenizer(br.readLine());
        int arr[]=new int[n+1];
        Arrays.fill(arr,0);
        for(int i=1;i<=n;i++)
        	arr[i]=Integer.parseInt(elements.nextToken());
        int i=m-1,j=m+1;
        int price=0;
        while(i>0||j<=n)
        {
        	if(i>0)
        	{
        		if(k>=arr[i]&&arr[i]!=0)
        		{
        			price=(m-i)*10;
        			break;
        		}
        		i--;
        	}
        	if(j<=n)
        	{
        		if(k>=arr[j]&&arr[j]!=0)
        		{
        			price=(j-m)*10;
        			break;
        		}
        		j++;
        	}
        }
        //System.out.println(i+" "+j);
        System.out.print(price);
    }
}