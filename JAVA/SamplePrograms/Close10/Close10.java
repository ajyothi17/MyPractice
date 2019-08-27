public class Close10
{
	public int close10(int num1, int num2){

		if((Math.abs(10 - num1)) == (Math.abs(10 - num2)))
			return 0;

		if((Math.abs(10 - num1)) < (Math.abs(10 - num2)))
			return num1;
		
		return num2;
	}
}
