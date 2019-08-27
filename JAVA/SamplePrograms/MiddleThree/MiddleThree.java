public class MiddleThree
{
	public String middleThree(String str) throws Exception{
		
		if((str.equals(null)) || (str.equals(""))){
			
			throw new Exception("invalid string... string cannot be empty or null");
		}

		if(str.length() <= 3)
			return str;

		return str.substring(((str.length() / 2) - 1), ((str.length() / 2) + 2));
	}
}
