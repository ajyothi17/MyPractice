import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			CountXX obj = new CountXX();	
			
			String str = "helloxxxxx";
			System.out.println("no of XX/xx/Xx/xX in given string " + str + " " + obj.countXX(str));

			str = "rhythm";
			System.out.println("no of XX/xx/Xx/xX in given string " + str + " " + obj.countXX(str));
			
			str = null;
		//	str = "";
			System.out.println("no of XX/xx/Xx/xX in given string " + str + " " + obj.countXX(str));
			
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
