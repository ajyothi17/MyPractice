import java.util.Scanner;

public class Test
{
	public static void main(String[] args)
	{
		try
		{
			Scanner sc = new Scanner(System.in);

			System.out.println("enter array1 size:");
            int size = sc.nextInt();
			
			int[] arr1 = new int[size];
			if(size > 0)
			{
            	System.out.println("enter array1 elements:");
            	for(int index = 0; index < size; index++)
				{
                	arr1[index] = sc.nextInt();
            	}
			}

			System.out.println("enter array2 size:");
            size = sc.nextInt();

			int[] arr2 = new int[size];
			if(size > 0)
			{
	            System.out.println("enter array2 elements:");
    	        for(int index = 0; index < size; index++)
				{
            	    arr2[index] = sc.nextInt();
            	}
            }
		
			FindAverageAcrossArrays obj = new FindAverageAcrossArrays();

			System.out.println("Average across 2 arrays = " + obj.findAverageAcrossArrays(arr1, arr2));

		}

		catch(Exception exp)
		{
			System.out.println("Caught Exception..." + exp.getMessage());
            exp.printStackTrace();
		}
	}
}
