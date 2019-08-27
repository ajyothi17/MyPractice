public class NTwice
{
	public String nTwice(String str, int n) throws Exception{
		
		if((str.equals("")) || (str.equals(null))){
			
			throw new Exception("invalid string");
		}

		int len = str.length();

		if((n <= 0) || (n > len)){
			throw new Exception("invalid n value");
		}

		return str.substring(0, n) + str.substring((len - n), len);
	}
}
