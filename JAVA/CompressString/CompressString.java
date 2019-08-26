public class CompressString
{
	public String compressString(String str){
		
		StringBuffer sb = new StringBuffer();
		char temp = str.charAt(0);		
		int count = 0;

		for(int index = 0; index < str.length(); index++){
		
			if(str.charAt(index) == temp)
				count++;

			else{
				sb.append(temp + "" + count);
				count = 1;
			}

			temp = str.charAt(index);
		}

		sb.append(temp + "" + count);
		
		return sb.toString();
	}
}
