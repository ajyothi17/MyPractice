import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter a number:");
			int num = sc.nextInt();
	
			EvenOdd obj = new EvenOdd();

			if(obj.checkEvenOdd(num)){
				System.out.println("Given number " + num + " is even");
			}

			else{
				System.out.println("Given number " + num + " is odd");
			}
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
