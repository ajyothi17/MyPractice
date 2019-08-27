import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter array limit:");
			int limit = sc.nextInt();
	
			FibSeries obj = new FibSeries();

			System.out.println("fibonacci series");
			
			int[] fib = obj.generateFibSeries(limit);
			for(int index = 0; index < limit; index++)
				System.out.print(fib[index] + " ");
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
