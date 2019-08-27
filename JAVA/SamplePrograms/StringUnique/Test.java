import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);

			System.out.println("enter a string...");
			String str = sc.next();

			StringUnique obj = new StringUnique();

			if(obj.isStringUnique(str)){
				System.out.println("Given string " + str + " has unique characters");
			}
			
			else{
				System.out.println("Given string " + str + " does not have unique characters");
			}
		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
