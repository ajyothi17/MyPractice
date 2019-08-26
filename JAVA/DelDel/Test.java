import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);

			System.out.println("enter a string...");
			String str = sc.next();

			DelDel obj = new DelDel();

			System.out.println("output " + obj.delDel(str));
		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
