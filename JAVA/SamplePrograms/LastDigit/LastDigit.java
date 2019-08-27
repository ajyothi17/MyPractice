public class LastDigit
{
	public boolean lastDigit(int num1, int num2){
		
		if((num1 % 10) == (num2 % 10))
			return true;

		return false;
	}
}
