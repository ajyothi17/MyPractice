public class TwoChar
{
	public String twoChar(String str, int index) throws Exception{
		
		if((str.equals("")) || (str.equals(null))){
			throw new Exception("invalid string... string cannot be null or empty");
		}

		if((index < 0) || ((index + 2) > str.length())){
			return str.substring(0, 2);
		}

		return str.substring(index, index + 2);
	} 
}
