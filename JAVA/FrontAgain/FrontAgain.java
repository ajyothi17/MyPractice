public class FrontAgain
{
	public boolean frontAgain(String str) throws Exception{

		if((str.equals(null)) || (str.equals("")))
			throw new Exception("invalid string... string cannot be empty");
	
		if(str.length() <= 2)
			return true;
		
		String subStr = str.substring(0, 2);
	
		if(str.endsWith(subStr))
			return true;

		return false;
	}
}
