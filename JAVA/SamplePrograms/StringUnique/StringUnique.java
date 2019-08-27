import java.util.*;

public class StringUnique
{
	public boolean isStringUnique(String str) throws Exception{
		
		if((str.equals(null)) || (str.equals(""))){
			throw new Exception("invalid string... string cannot be null or empty");
		}

		char[] chArr = str.toCharArray();
			
		Arrays.sort(chArr);

		for(int index = 0; index < chArr.length - 1; index++){
			if(chArr[index] == chArr[index + 1])
				return false;
		}

		return true;
	}
}
