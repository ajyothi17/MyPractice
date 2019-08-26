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

			System.out.println("before swaping");	
			for(int index = 0; index < myArr.length; index++)
				System.out.println(myArr[index]);

			SwapEnds obj = new SwapEnds();
			myArr = obj.swapEnds(myArr);
		
			System.out.println("after swaping");	
			for(int index = 0; index < myArr.length; index++)
				System.out.println(myArr[index]);
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
