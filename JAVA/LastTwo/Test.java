import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			LastTwo obj = new LastTwo();	
			
			String str = "hello";
			System.out.println("given string " + str + " new string " + obj.lastTwo(str)); 

			str = "elephant";
			System.out.println("given string " + str + " new string " + obj.lastTwo(str)); 
			
			str = "le";
			System.out.println("given string " + str + " new string " + obj.lastTwo(str)); 
			
			str = "x";
			System.out.println("given string " + str + " new string " + obj.lastTwo(str)); 

			str = "";
			//str = null;
			System.out.println("given string " + str + " new string " + obj.lastTwo(str)); 
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
