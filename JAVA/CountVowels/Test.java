import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			CountVowels obj = new CountVowels();	
			
			String str = "hello";
			System.out.println("no of vowels in given string " + str + " " + obj.countVowel(str));

			str = "rhythm";
			System.out.println("no of vowels in given string " + str + " " + obj.countVowel(str));
			
			str = null;
			System.out.println("no of vowels in given string " + str + " " + obj.countVowel(str));
			
			str = "";
			System.out.println("no of vowels in given string " + str + " " + obj.countVowel(str));
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
