import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{
			Scanner sc = new Scanner(System.in);

			System.out.println("enter array size:");			
			int size = sc.nextInt();

			if((size < 1) || (size > Integer.MAX_VALUE)){
				throw new Exception("invalid array size");
			}

			int[] arr = new int[size];
			System.out.println("enter array elements:");
			for(int index = 0; index < size; index++){
				
				arr[index] = sc.nextInt();
			}
			
			System.out.println("enter value:");
			int val = sc.nextInt();

			System.out.println("Before...");
			for(int index = 0; index < size; index++){
				System.out.println(arr[index]);
			}

			NotAlone obj = new NotAlone();
			
			arr = obj.notAlone(arr, val);

			System.out.println("After...");
			for(int index = 0; index < size; index++){
				System.out.println(arr[index]);
			}
			
		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
