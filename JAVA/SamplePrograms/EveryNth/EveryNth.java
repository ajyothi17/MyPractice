public class EveryNth
{
	public String everyNth(String str, int val) throws Exception{
	
		if((str.equals(null)) || (str.equals("")))
			throw new Exception("invalid string... string cannot be empty or null");

		if(val < 0)
			throw new Exception("invalid value");

		if(val == 0)
			return Character.toString(str.charAt(0));
		
		if(val == 1)
			return str;

		String newStr = "";

		for(int index = 0; index < str.length(); index++){

			if((index % val) == 0)
				newStr += str.charAt(index);
		}

		return newStr;
	}
}
