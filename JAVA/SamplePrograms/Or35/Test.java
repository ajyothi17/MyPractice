import java.util.Scanner;

public class Test
{
	public static void main(String args[]){
	
		try{	
			Scanner sc = new Scanner(System.in);
		
			System.out.println("enter a number:");
			int num = sc.nextInt();
	
			Or35 obj = new Or35();

			if(obj.isOr35(num)){
				System.out.println("Given number " + num + " is divisible by 3/5");
			}

			else{
				System.out.println("Given number " + num + " is not divisible by 3/5");
			}
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
