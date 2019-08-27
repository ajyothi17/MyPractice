import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter array limit:");
			int limit = sc.nextInt();
		
			int[] arr = new int[limit];
			
			System.out.println("enter array elements:");	
			for(int index = 0; index < limit; index++){
				arr[index] = sc.nextInt();
			}

			System.out.println("enter new even array count:");
			int count = sc.nextInt();

			CopyEvens obj = new CopyEvens();

			System.out.println("new even array");
			
			int[] newArr = obj.copyEvens(arr, count);
			for(int index = 0; index < newArr.length; index++)
				System.out.print(newArr[index] + " ");
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
