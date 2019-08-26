import java.util.Scanner;

public class Test
{
	public static void main(String[] args){

		try{
	
			WithoutEnd2 obj = new WithoutEnd2();

			String str = "hello";
			System.out.println("given string " + str + " new string " + obj.withoutEnd2(str));
		
			str = "ab";
			System.out.println("given string " + str + " new string " + obj.withoutEnd2(str));
	
			str = "";
	//		str = null;
			System.out.println("given string " + str + " new string " + obj.withoutEnd2(str));
		
		}

		catch(Exception exp){
			System.out.println("Caught Exeption... " + exp.getMessage());
			exp.printStackTrace();	
		}

	}
}
