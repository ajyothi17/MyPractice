import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);
			
			System.out.println("enter array1 size:");
			int size = sc.nextInt();
			
			if((size < 1) || (size > Integer.MAX_VALUE))
				throw new Exception("invalid array size");

			int[] arr1 = new int[size];
			System.out.println("enter array elements:");
			for(int index = 0; index < arr1.length; index++){
				
				arr1[index] = sc.nextInt();
			}

			System.out.println("enter array2 size:");
			size = sc.nextInt();
			
			if((size < 1) || (size > Integer.MAX_VALUE))
				throw new Exception("invalid array size");

			int[] arr2 = new int[size];
			System.out.println("enter array elements:");
			for(int index = 0; index < arr2.length; index++){
				
				arr2[index] = sc.nextInt();
			}

			Average obj = new Average();

			System.out.println("average of given 2 arrays: " + obj.averageAcrossArrays(arr1, arr2));
		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
