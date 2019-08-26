import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{
			
			Scanner sc = new Scanner(System.in);

			System.out.println("enter array size");
			int size = sc.nextInt();

			if((size < 1) || (size > Integer.MAX_VALUE)){
				
				throw new Exception("invalid array size");
			}

			int[] arr = new int[size];
			System.out.println("enter array elements:");
			for(int index = 0; index < size; index++){
				
				arr[index] = sc.nextInt();
			}

			Unlucky1 obj =  new Unlucky1();

			if(obj.unlucky1(arr))
				System.out.println("Given array contains 1 followed by 3");
	
			else			
				System.out.println("Given array does not contain 1 followed by 3");
		}

		catch(Exception exp){
			
			System.out.println("Caught Exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
