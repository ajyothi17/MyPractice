import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
	
			int num1;
			int num2;

			System.out.println("enter num1");
			num1 = sc.nextInt();

			System.out.println("enter num2");
			num2 = sc.nextInt();

			Close10 obj = new Close10();

			num1 = obj.close10(num1, num2);

			if(num1 == 0)
				System.out.println("both " + num2 + " and " + num2 + " are close to 10");

			else
				System.out.println(num1 + " is close to 10");

		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
