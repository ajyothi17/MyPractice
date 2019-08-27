import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);

			System.out.println("enter a string...");
			String str = sc.next();

			CompressString obj = new CompressString();

			System.out.println("Given string " + str + " compressed string " + obj.compressString(str));
		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
