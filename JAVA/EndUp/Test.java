import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			EndUp obj = new EndUp();	
			
			String str = "hello";
			System.out.println("given string " + str + " new string " + obj.endUp(str)); 

			str = "elephant";
			System.out.println("given string " + str + " new string " + obj.endUp(str)); 
			
			str = "leveled";
			System.out.println("given string " + str + " new string " + obj.endUp(str)); 
			
			str = "x";
			System.out.println("given string " + str + " new string " + obj.endUp(str)); 

			str = "";
			//str = null;
			System.out.println("given string " + str + " new string " + obj.endUp(str)); 
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
