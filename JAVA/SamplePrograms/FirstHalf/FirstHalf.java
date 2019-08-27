public class FirstHalf
{
	public String firstHalf(String str) throws Exception{
		
		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid string");
		}

		return str.substring(0, (str.length())/2);
	}
}
