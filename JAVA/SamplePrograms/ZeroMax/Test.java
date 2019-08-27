import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{
			Scanner sc = new Scanner(System.in);

			System.out.println("enter array size");			
			int size = sc.nextInt();

			if((size < 1) || (size > Integer.MAX_VALUE))
				throw new Exception("invalid array size");

			int[] arr = new int[size];
			for(int index = 0; index < size; index++){
				arr[index] = sc.nextInt();				
			}
			
			System.out.println("before replacing zero by next max");
			for(int index = 0; index < size; index++){
				System.out.println(arr[index]);
			}

			ZeroMax obj = new ZeroMax();
			
			arr = obj.zeroMax(arr);

			System.out.println("after replacing zero by next max");
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
