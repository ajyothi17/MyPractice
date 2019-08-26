import java.util.Scanner;

public class Test
{
	public static void main(String[] args)
	{
		try
		{
			Scanner sc = new Scanner(System.in);

			System.out.println("enter a num:");
			int num = sc.nextInt();

			FindSum obj = new FindSum();

			System.out.println("Sum: " + obj.findSum(num));
		}

		catch(Exception exp)
		{
			System.out.println("Caught exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
