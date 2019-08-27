import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			StartWord obj = new StartWord();	
			
			String str = "hello";
			String word = "he";
			System.out.println("given string " + str + " given word " + word + " result string " + obj.startWord(str, word));

			str = "elephant";
			word = "lep";
			System.out.println("given string " + str + " given word " + word + " result string " + obj.startWord(str, word));

			str = "good evening";
			word = "hood";
			System.out.println("given string " + str + " given word " + word + " result string " + obj.startWord(str, word));

			str = "rhythm";
			word = "music";
			System.out.println("given string " + str + " given word " + word + " result string " + obj.startWord(str, word));
		
			str = "123";
			word = "12345";
			System.out.println("given string " + str + " given word " + word + " result string " + obj.startWord(str, word));
	
			str = "";
//			str = null;	
			word = "";
//			word = null;
			System.out.println("given string " + str + " given word " + word + " result string " + obj.startWord(str, word));
		
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
