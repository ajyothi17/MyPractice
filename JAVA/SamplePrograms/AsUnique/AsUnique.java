public class AsUnique
{
	public String isAsUnique(String str) throws Exception{

		if((str.equals("")) || (str.equals(null))){
			
			throw new Exception("invalid string... string cannot be empty or null");
		}

		if(str.length() == 1)
			return str;

		String newStr = "";

		for(int index1 = 0; index1 < str.length(); index1++){

			int count = 0;

			for(int index2 = 0; index2 < newStr.length(); index2++){

				if(Character.toLowerCase(str.charAt(index1)) == Character.toLowerCase(newStr.charAt(index2)))
					count++;
			}

			if(count == 0)
				newStr = newStr + Character.toString(str.charAt(index1));
		}

		return newStr.replace(" ", "");
	}
}
