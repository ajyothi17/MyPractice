import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			NonStart obj = new NonStart();	
			
			String str1 = "hello";
			String str2 = "world";

			System.out.println("given strings str1: " + str1 + " str2: " + str2);
			System.out.println("new string: " + obj.nonStart(str1, str2));

			str1 = "chotl";
			str2 = "java";
			
			System.out.println("given strings str1: " + str1 + " str2: " + str2);
			System.out.println("new string: " + obj.nonStart(str1, str2));
			
	//		str1 = null;
			str1 = "";
	//		str2 = null;
			str2 = "";
			
			System.out.println("given strings str1: " + str1 + " str2: " + str2);
			System.out.println("new string: " + obj.nonStart(str1, str2));
		
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
