public class FibSeries
{
	public int[] generateFibSeries(int limit){
		
		int[] fib = new int[limit];

		fib[0] = 0;
		fib[1] = 1;

		for(int index = 2; index < limit; index++){
			
			fib[index] = fib[index - 1] + fib[index - 2];
		}

		return fib;
	}
}	
