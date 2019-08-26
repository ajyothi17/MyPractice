import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			AltPairs obj = new AltPairs();
			
			String str = "hello";

			System.out.println("given string = " + str + " new string = " + obj.altPairs(str));
			
			str = "chocolate";
			System.out.println("given string = " + str + " new string = " + obj.altPairs(str));
			
			str = null;
			str = "";
			System.out.println("given string = " + str + " new string = " + obj.altPairs(str));
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
