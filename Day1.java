import java.io.File;
import java.util.*;

public class Day1{



	public static void main(String[] args)
			throws Exception
		{
			try{

				File file = new File("C:\\Users\\Christopher\\Documents\\projects\\aoc2024\\Day1.txt");

				Scanner sc = new Scanner(file);

				List<Integer> list1 = new ArrayList<>();

				List<Integer> list2 = new ArrayList<>();

				while(sc.hasNext()){


					int temp1 = sc.nextInt();
					list1.add(temp1);
					int temp2 = sc.nextInt();
					list2.add(temp2);

				}


				Collections.sort(list1);
				Collections.sort(list2);

				int result = 0;

				for(int i = 0; i < list1.size(); i++){
					result += Math.abs((list1.get(i)-list2.get(i)));


				}

				System.out.println(result);

				sc.close();
			}

			catch (Exception e){
				System.out.println("Exception thrown: " + e);
			}

		
	}
}
