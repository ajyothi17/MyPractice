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

			Lucky13 obj =  new Lucky13();

			if(obj.lucky13(arr))
				System.out.println("Given array does not contain 1's and 3's");

			else
				System.out.println("Given array contains either 1 or 3 or both");

		}

		catch(Exception exp){
			
			System.out.println("Caught Exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
