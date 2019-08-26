import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			MakeOutWord obj = new MakeOutWord();	
			
			String out = "<<>>";
			String word = "hello";
			String resWord;

			if((resWord = obj.makeOutWord(out, word)) != null){
				System.out.println("Given out " + out + " given word " + word);
				System.out.println("Result: " + resWord);
			}

			out = "(())";
			word = "hi";

			if((resWord = obj.makeOutWord(out, word)) != null){
				System.out.println("Given out " + out + " given word " + word);
				System.out.println("Result: " + resWord);
			}

			out = "<<>>";
			word = "yoyo";

			if((resWord = obj.makeOutWord(out, word)) != null){
				System.out.println("Given out " + out + " given word " + word);
				System.out.println("Result: " + resWord);
			}

			out = "[[]]";
			word = "yipeee";

			if((resWord = obj.makeOutWord(out, word)) != null){
				System.out.println("Given out " + out + " given word " + word);
				System.out.println("Result: " + resWord);
			}

			out = ""; 
			//one = null;
			word = "";
			//word = null;

			if((resWord = obj.makeOutWord(out, word)) != null){
				System.out.println("Given out " + out + " given word " + word);
				System.out.println("Result: " + resWord);
			}

		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
