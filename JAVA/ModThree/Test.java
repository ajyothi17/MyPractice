import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter array size:");
			int size = sc.nextInt();
	
			int[] myArr = new int[size];
			System.out.println("enter array elements:");
			for(int index = 0; index < size; index++){
				myArr[index] = sc.nextInt();
			}

			ModThree obj = new ModThree();
			
			if(obj.modThree(myArr)){
				System.out.println("given array contains three odd or even");
			}

			else{	
				System.out.println("given array doesnot contain three odd or even");
			}
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
