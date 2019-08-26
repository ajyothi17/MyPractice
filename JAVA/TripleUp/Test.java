import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter array limit:");
			int limit = sc.nextInt();

			int[] myArr = new int[limit];

			System.out.println("enter array elements:");
			for(int index = 0; index < limit; index++)
				myArr[index] = sc.nextInt();

			TripleUp obj = new TripleUp();

			if(obj.tripleUp(myArr))
				System.out.println("given array contains increasing adjacent numbers");

			else	
				System.out.println("given array does not contain increasing adjacent numbers");
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
