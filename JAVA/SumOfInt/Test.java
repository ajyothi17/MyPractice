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

			SumOfInt obj = new SumOfInt();

			System.out.println("Sum of two nums = " + obj.add(num1, num2));

		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
