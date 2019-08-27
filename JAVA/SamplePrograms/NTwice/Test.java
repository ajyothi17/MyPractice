public class Test
{
	public static void main(String[] args){
		
		try{
			NTwice obj = new NTwice();

			String str = "Hello";
			System.out.println("New String " + obj.nTwice(str, 2));

			str = "Chocolate";
			System.out.println("New String " + obj.nTwice(str, 3));
			
//			str = "Happy";
//			System.out.println("New String " + obj.nTwice(str, 7));
//			System.out.println("New String " + obj.nTwice(str, -7));
			
//			str = "";
			str = null;
			System.out.println("New String " + obj.nTwice(str, 3));
		}

		catch(Exception exp){
			System.out.println("Caught Exception... " + exp.getMessage());
			exp.printStackTrace();
		}
	}
}
