import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter a number:");
			int num = sc.nextInt();
	
			SumOfDigits obj = new SumOfDigits();

			System.out.println("sum of digits: " + obj.sumOfDigits(num));
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
