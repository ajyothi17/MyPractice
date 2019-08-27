import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			int[] myArr1 = new int[3];
			System.out.println("enter array1 elements:");
			for(int index = 0; index < 3; index++){
				myArr1[index] = sc.nextInt();
			}

			int[] myArr2 = new int[3];
			System.out.println("enter array2 elements:");
			for(int index = 0; index < 3; index++){
				myArr2[index] = sc.nextInt();
			}

			System.out.println("array1 elements:");
			for(int index = 0; index < 3; index++){
				System.out.println(myArr1[index]);
			}

			System.out.println("array2 elements:");
			for(int index = 0; index < 3; index++){
				System.out.println(myArr2[index]);
			}

			MiddleWay obj = new MiddleWay();
			int[] newArr = obj.middleWay(myArr1, myArr2);

			System.out.println("new array elements:");
			for(int index = 0; index < 2; index++){
				System.out.println(newArr[index]);
			}
			
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
