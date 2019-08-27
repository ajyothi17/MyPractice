import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			EndsLy obj = new EndsLy();
			
			String str = "hello";

			if(obj.endsLy(str))
				System.out.println("given string ends with \"ly\"");
			else
				System.out.println("given string does not ends with \"ly\"");
			
			str = "only";
			if(obj.endsLy(str))
				System.out.println("given string ends with \"ly\"");
			else
				System.out.println("given string does not ends with \"ly\"");
			
//			str = null;
			str = "";
			if(obj.endsLy(str))
				System.out.println("given string ends with \"ly\"");
			else
				System.out.println("given string does not ends with \"ly\"");
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
