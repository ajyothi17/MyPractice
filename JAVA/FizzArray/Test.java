import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter a size:");
			int size = sc.nextInt();
	
			FizzArray obj = new FizzArray();

			String[] myStr = obj.fizzArray(size);
			
			System.out.println("fizz array elements:");
			for(int index = 0; index < size; index++)
				System.out.println(myStr[index]);
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
