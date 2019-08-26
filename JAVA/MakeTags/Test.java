import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			MakeTags obj = new MakeTags();	
			
			String str = "hello";
			String tag = "b";
			System.out.println("HTML tag " + obj.makeTags(tag, str));

			str = null;
		//	str = "";
			tag = "";
		//	tag = null;
			System.out.println("HTML tag " + obj.makeTags(tag, str));
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
