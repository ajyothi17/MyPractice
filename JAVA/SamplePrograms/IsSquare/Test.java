import java.util.Scanner;

class Test
{
	public static void main(String[] args)
	{
		try
		{
            Scanner sc = new Scanner(System.in);

            System.out.println("enter a number:");
            int num = sc.nextInt();

			IsSquare obj = new IsSquare();

			if(obj.isSquare(num))
			{
				System.out.println(num + " is a square");
			}
			
			else
			{
				System.out.println(num + " is not a square");
			}

		}
		
		catch(Exception exp)
		{
			System.out.println("Caught Exception..." + exp.getMessage());
            exp.printStackTrace();
		}
	}
}
