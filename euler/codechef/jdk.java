import java.io.*;
import java.math.*;
import java.util.*;

class Main
{
     static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args)throws IOException
    {
        FastReader sc=new FastReader();
        int n,m,lo,disp=0,l,r;
        n=sc.nextInt();
        m=sc.nextInt();
        lo=n;
        while(m>0)
        {
        	l=sc.nextInt();
        	r=sc.nextInt();
        	lo=Math.min(lo,Math.abs(r-l+1));
        	m--;
        }
        System.out.println(lo);
        for(int i=0;i<n;i++)
        {
        	System.out.print(disp+" ");
        	disp=(disp+1)%lo;
        }
    }
} 