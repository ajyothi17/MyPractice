import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			FirstHalf obj = new FirstHalf();	
		
			String str = "Hello World! 123";
			System.out.println("first half of given string " + str + " is " + obj.firstHalf(str));	
		
			str = "abcdef";
			System.out.println("first half of given string " + str + " is " + obj.firstHalf(str));	

			str = "!@#$%^&";
			System.out.println("first half of given string " + str + " is " + obj.firstHalf(str));	
	
			str = "";
			//str = null;
			System.out.println("first half of given string " + str + " is " + obj.firstHalf(str));	
			
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
