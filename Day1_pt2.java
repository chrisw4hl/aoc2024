import java.io.File;
import java.util.*;

public class Day1_pt2{



	public static void main(String[] args)
			throws Exception
		{
			try{

				File file = new File("C:\\Users\\Christopher\\Documents\\projects\\aoc2024\\Day1.txt");

				Scanner sc = new Scanner(file);

				List<Integer> list1 = new ArrayList<>();

				HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();

				while(sc.hasNext()){


					int temp1 = sc.nextInt();
					list1.add(temp1);
					int temp2 = sc.nextInt();
					if(hash.get(temp2)!=null){
						hash.put(temp2, hash.get(temp2)+ 1);
					}else{
						hash.put(temp2, 1);
					}

				}



				int result = 0;

				for(int i = 0; i < list1.size(); i++){
					if(hash.get(list1.get(i))!=null){
						result += (list1.get(i)*hash.get(list1.get(i)));
					}


				}

				System.out.println(result);

				sc.close();
			}

			catch (Exception e){
				System.out.println("Exception thrown: " + e);
			}

		
	}
}
