public class StringE
{
	public boolean stringE(String str) throws Exception{

		if((str.equals(null)) || (str.equals(""))){

			throw new Exception("invalid string");
		}
		
		str = str.toLowerCase();
		int len = str.length();

		if((len == 1) && (str.charAt(0) != 'e'))
			return false;

		int count = 0;

		for(int index = 0; index < len; index++){
			
			if(str.charAt(index) == 'e')
				count++;
		}	

		if((count == 1) || (count == 3))
			return true;

		return false;
	}
}
