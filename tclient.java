import java.io.*;
import java.net.*;
class tclient
{
public static void main(String args[])throws Exception
{
Socket soc=new Socket("192.168.189.129",7778);
BufferedReader in=new BufferedReader(new 
InputStreamReader(soc.getInputStream() ));
System.out.println(in.readLine());
}
}
