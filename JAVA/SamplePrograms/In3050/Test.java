import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter num1:");
			int num1 = sc.nextInt();
	
			System.out.println("enter num2:");
			int num2 = sc.nextInt();

			In3050 obj = new In3050();

			if(obj.in3050(num1, num2))
				System.out.println("given numbers are in 30-40/ 40-50 range");
		
			else
				System.out.println("given numbers are not in 30-40/ 40-50 range");
				
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
