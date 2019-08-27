import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);
			
			System.out.println("enter array size:");
			int size = sc.nextInt();
			
			int[] arr = new int[size];
			System.out.println("enter array elements:");
			for(int index = 0; index < arr.length; index++){
				
				arr[index] = sc.nextInt();
			}

			CenteredAverage obj = new CenteredAverage();

			System.out.println("centered average of given elements: " + obj.centeredAverage(arr));
		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
