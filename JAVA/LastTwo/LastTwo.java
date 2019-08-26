public class LastTwo
{
	public String lastTwo(String str) throws Exception{
		
		if((str.equals(null)) && (str.equals(""))){
			throw new Exception("invalid string");
		}

		if(str.length() == 1)
			return str;

		return str.substring(0, (str.length() - 2)) + str.charAt(str.length() - 1) + str.charAt(str.length() - 2);
	}
}
