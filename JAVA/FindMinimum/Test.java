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

			FindMinimum obj = new FindMinimum();

			System.out.println("min " + obj.findMinimum(arr));

		}

		catch(Exception exp){

			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
