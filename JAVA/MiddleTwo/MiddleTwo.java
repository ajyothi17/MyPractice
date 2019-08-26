public class MiddleTwo
{
	public String middleTwo(String str) throws Exception{
		
		if((str.equals("")) || (str.equals(null))){
			throw new Exception("invalid string... String cannot be empty");
		}

		int len = str.length();

		if((len == 1) || (len == 2))
			return str;

		len = len / 2;

		return str.substring(len - 1, len + 1);
	}
}
