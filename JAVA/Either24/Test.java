import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter array size:");
			int size = sc.nextInt();
			if(size <= 0){
				throw new Exception("invalid array size");
			}
	
			int[] myArr = new int[size];
			System.out.println("enter array elements:");
			for(int index = 0; index < size; index++){
				myArr[index] = sc.nextInt();
			}

			Either24 obj = new Either24();
			if(obj.either24(myArr))
				System.out.println("the given array contain either 2, 2/ 4, 4");
			
			else	
				System.out.println("the given array does not contain either 2, 2/ 4, 4 or contains both");
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
