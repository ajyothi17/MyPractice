import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			CountConsonents obj = new CountConsonents();	
			
			String str = "hello";
			System.out.println("no of vowels in given string " + str + " " + obj.countConsonents(str));

			str = "rhythm";
			System.out.println("no of vowels in given string " + str + " " + obj.countConsonents(str));
			
			str = null;
			System.out.println("no of vowels in given string " + str + " " + obj.countConsonents(str));
			
			str = "";
			System.out.println("no of vowels in given string " + str + " " + obj.countConsonents(str));
		
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
