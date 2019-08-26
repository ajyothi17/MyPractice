import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
	
			int num1;
			int num2;
			int num3;

			System.out.println("enter num1");
			num1 = sc.nextInt();

			System.out.println("enter num2");
			num2 = sc.nextInt();

			System.out.println("enter num3");
			num3 = sc.nextInt();

			TwoAsOne obj = new TwoAsOne();

			if(obj.twoAsOne(num1, num2, num3))
				System.out.println("two ints are sum of third");

			else
				System.out.println("two ints are not sum of third");
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
