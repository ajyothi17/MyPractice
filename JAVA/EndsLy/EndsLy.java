public class EndsLy
{
	public boolean endsLy(String str) throws Exception{

		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid string");
		}

		if(str.endsWith("ly"))
			return true;

		return false;
	}
}
