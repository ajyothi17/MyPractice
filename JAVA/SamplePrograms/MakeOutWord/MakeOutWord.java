public class MakeOutWord
{
	public String makeOutWord(String out, String word) throws Exception{

		if((out.equals(null)) || (out.equals("")) || (word.equals(null)) || (word.equals(""))){

			throw new Exception("invalid string");
		}

		if((out.length()) == 4)
			return out.substring(0, 2) + word + out.substring(2,4);

		return null;
	}
}
