import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{
			
			Scanner sc = new Scanner(System.in);

			System.out.println("enter array size");
			int size = sc.nextInt();

			if((size < 1) || (size > Integer.MAX_VALUE)){
				
				throw new Exception("invalid size ->  enter size between 0 - " + Integer.MAX_VALUE);
			}

			int[] arr = new int[size];
			System.out.println("enter array elements:");
			for(int index = 0; index < size; index++)
				arr[index] = sc.nextInt();

			System.out.println("before shifting...");
			for(int index = 0; index < size; index++)
				System.out.println(arr[index]);

			ShiftLeft obj =  new ShiftLeft();

			arr = obj.shiftLeft(arr);

			System.out.println("after shifting...");
			for(int index = 0; index < size; index++)
				System.out.println(arr[index]);

		}

		catch(Exception exp){
			
			System.out.println("Caught Exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
