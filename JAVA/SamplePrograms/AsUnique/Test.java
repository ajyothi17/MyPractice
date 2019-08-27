import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);
			sc.useDelimiter("\n");

			System.out.println("enter a string:");
			String str = sc.next();

			AsUnique obj = new AsUnique();

			System.out.println("Given string " + str + " Output " + obj.isAsUnique(str));
		}
	
		catch(Exception exp){

			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
