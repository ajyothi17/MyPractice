import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter a number:");
			int num = sc.nextInt();
	
			DivisibleBy7 obj = new DivisibleBy7();

			if(obj.isDivisibleBy7(num)){
				System.out.println("Given number " + num + " is divisible by 7");
			}

			else{
				System.out.println("Given number " + num + " is not divisible by 7");
			}
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
