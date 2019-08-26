public class Or35
{
	public boolean isOr35(int num){
		
		if(((num % 3) == 0) || ((num % 5) == 0)){
			return true;
		}

		return false;
	}
}
