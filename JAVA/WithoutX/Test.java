import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			WithoutX obj = new WithoutX();	
			
			String str = "xhexllox";
			System.out.println("given string " + str + " new string " + obj.withoutX(str)); 

			str = "elephant";
			System.out.println("given string " + str + " new string " + obj.withoutX(str)); 
			
			str = "xlevel";
			System.out.println("given string " + str + " new string " + obj.withoutX(str)); 
			
			str = "x";
			System.out.println("given string " + str + " new string " + obj.withoutX(str)); 

			str = "abx";
			System.out.println("given string " + str + " new string " + obj.withoutX(str)); 
			
			str = "";
			//str = null;
			System.out.println("given string " + str + " new string " + obj.withoutX(str)); 
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
