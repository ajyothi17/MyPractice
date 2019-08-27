import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{
			
			Scanner sc = new Scanner(System.in);

			System.out.println("enter array num");
			int num = sc.nextInt();

			if((num < 1) || (num > Integer.MAX_VALUE)){
				
				throw new Exception("invalid num ->  enter num between 0 - " + Integer.MAX_VALUE);
			}

			Diff21 obj =  new Diff21();

			System.out.println("Absolute difference " + obj.diff21(num));

		}

		catch(Exception exp){
			
			System.out.println("Caught Exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
