import java.util.Scanner;

public class Test
{
	public static void main(String[] args){
		
		try{

			Scanner sc = new Scanner(System.in);

			System.out.println("enter string:");
			String str1 = sc.next();

			System.out.println("enter rotated string:");
			String str2 = sc.next();

			StringRotated obj = new StringRotated();

			if(obj.isStringRotated(str1, str2)){

				System.out.println("" + str2 + " is a rotated string of " + str1);
			}

			else{

				System.out.println("" + str2 + " is not a rotated string of " + str1);
			}
		}
	
		catch(Exception exp){

			System.out.println("Caught exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
