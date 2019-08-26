public class AtFirst
{
	public String atFirst(String str) throws Exception{

		if((str.equals("")) || (str.equals(null))){
			throw new Exception("invalid string... string cannot be empty or null");
		}

		if(str.length() < 2){
			
			return str + "@";
		}

		return str.substring(0, 2);
	}
}
