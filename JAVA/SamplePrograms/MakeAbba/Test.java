import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			MakeAbba obj = new MakeAbba();
			
			String str1 = "hello";
			String str2 = "world";

			System.out.println("result = " + obj.makeAbba(str1, str2));

			str1 = "";
			System.out.println("result = " + obj.makeAbba(str1, str2));
			
			str1 = null;
			System.out.println("result = " + obj.makeAbba(str1, str2));
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
