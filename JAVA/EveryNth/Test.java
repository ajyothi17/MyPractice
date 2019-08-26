import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);
			sc.useDelimiter("\n");

			System.out.println("enter a string:");
			String str = sc.next();

			System.out.println("enter value:");
			int val = sc.nextInt();

			EveryNth obj = new EveryNth();

			System.out.println("Given string " + str + " Output " + obj.everyNth(str, val));
		}
	
		catch(Exception exp){

			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
