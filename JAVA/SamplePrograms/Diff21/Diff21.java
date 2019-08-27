public class Diff21
{
	public int diff21(int num){
		
		if(num > 21){
			return (num - 21) * 2;
		}

		return 21 - num;
	}
}
