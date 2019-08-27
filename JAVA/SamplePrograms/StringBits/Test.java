import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			StringBits obj = new StringBits();	
			
			String str = "hello";
			System.out.println("given string " + str + " new string " + obj.stringBits(str)); 

			str = "elephant";
			System.out.println("given string " + str + " new string " + obj.stringBits(str)); 
			
			str = "leveled";
			System.out.println("given string " + str + " new string " + obj.stringBits(str)); 
			
			str = "x";
			System.out.println("given string " + str + " new string " + obj.stringBits(str)); 

			str = "";
			//str = null;
			System.out.println("given string " + str + " new string " + obj.stringBits(str)); 
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
