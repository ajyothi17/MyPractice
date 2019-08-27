import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);

			System.out.println("enter a string...");
			String str = sc.next();

			MiddleThree obj = new MiddleThree();

			System.out.println("output " + obj.middleThree(str));
		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
