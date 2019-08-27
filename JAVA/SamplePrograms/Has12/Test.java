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

			Has12 obj = new Has12();

			if(obj.has12(arr)){
				System.out.println("has 1, 2");
			}

			else{
				System.out.println("does not have 1, 2");
			}
		}

		catch(Exception exp){
			
			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
