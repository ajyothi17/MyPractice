public class TheEnd
{
	public String theEnd(String str, boolean front) throws Exception{
		
		if((str.equals("")) || (str.equals(null)))	
			throw new Exception("invalid string... String cannot be empty or null");

		if(front)
			return "" + str.charAt(0);

		return "" + str.charAt(str.length() - 1);
	}
}
