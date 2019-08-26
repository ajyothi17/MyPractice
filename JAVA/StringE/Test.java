import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			StringE obj = new StringE();	
			
			String str = "hello";
			if(obj.stringE(str))
				System.out.println("given string " + str + " contains 1/3 e's");

			str = "elephant";
			if(!(obj.stringE(str)))
				System.out.println("given string " + str + " does not contain 1/3 e's");
			
			str = "leveled";
			if(obj.stringE(str))
				System.out.println("given string " + str + " contains 1/3 e's");
			
			str = "x";
			if(!(obj.stringE(str)))
				System.out.println("given string " + str + " does not contain 1/3 e's");

			str = "e";
			if(obj.stringE(str))
				System.out.println("given string " + str + " contains 1/3 e's");

			str = "";
			//str = null;
			if(obj.stringE(str))
				System.out.println("given string " + str + " contains 1/3 e's");
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
