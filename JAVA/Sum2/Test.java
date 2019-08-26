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

			Sum2 obj = new Sum2();
			System.out.println("sum of first two elements " + obj.sum2(myArr));
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
