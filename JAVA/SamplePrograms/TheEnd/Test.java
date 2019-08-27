import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);

			System.out.println("enter a string...");
			String str = sc.next();

			System.out.println("enter true for first char, false for last char");
			boolean front = sc.nextBoolean();

			TheEnd obj = new TheEnd();

			System.out.println("output " + obj.theEnd(str, front));
		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
