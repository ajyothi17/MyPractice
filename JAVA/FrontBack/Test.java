import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			FrontBack obj = new FrontBack();	
			
			String str = "hello";
			System.out.println("given string " + str + " after swaping first and last element " + obj.frontBack(str));
		
			str = "ab";
			System.out.println("given string " + str + " after swaping first and last element " + obj.frontBack(str));

		
			str = "x";
			System.out.println("given string " + str + " after swaping first and last element " + obj.frontBack(str));
		

			str = "";
			System.out.println("given string " + str + " after swaping first and last element " + obj.frontBack(str));

		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
