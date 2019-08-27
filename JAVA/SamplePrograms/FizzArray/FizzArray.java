public class FizzArray
{
	public String[] fizzArray(int size) throws Exception{
		
		if(size <= 0){
			throw new Exception("invalid size");
		}

		String[] strArr = new String[size];

		for(int index = 0; index < size; index++){
			
			strArr[index] = String.valueOf(index);
		}

		return strArr;
	} 
}
