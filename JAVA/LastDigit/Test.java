import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
	
		try{

			Scanner sc = new Scanner(System.in);
	
			System.out.println("enter num1");
			int num1 = sc.nextInt();

			System.out.println("enter num1");
			int num2 = sc.nextInt();

			LastDigit obj = new LastDigit();

			if(obj.lastDigit(num1, num2)){
				System.out.println("num1 " + num1 + " and num2 " + num2 + " has same last digit");
			}

			else{
				System.out.println("num1 " + num1 + " and num2 " + num2 + " doesnot have same last digit");
			}
		}

		catch(Exception exp){
	
			System.out.println("Caught Exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
