import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);

			System.out.println("enter a string:");
			String str = sc.next();

			ConvertCase obj = new ConvertCase();

			System.out.println("Given string " + str + " Output " + obj.convertCase(str));
		}
	
		catch(Exception exp){

			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
