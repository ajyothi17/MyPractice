public class TwoAsOne
{
	public boolean twoAsOne(int num1, int num2, int num3){
		
		if((num1 == num2 + num3) || (num2 == num1 + num3) || (num3 == num1 + num2))
			return true;

		return false;
	}
}
