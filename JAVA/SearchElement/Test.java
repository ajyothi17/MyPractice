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

			System.out.println("enter the element to be searched:");
			int numToSearch = sc.nextInt();
 
			SearchElement obj = new SearchElement();

			if(obj.searchElement(myArr, numToSearch))
				System.out.println("element found");
	
			else	
				System.out.println("element not found");
		}

		catch(Exception exp){
			System.out.println("Caught Exception..." + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
