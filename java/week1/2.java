
public class Sum{

	int sum(int ...a){
	int s = 0;
	for ( int i : a ){
	s = s + i;
	}
	return s;

	}
}
class in{


public static void main(String[] args) {
		Sum obj = new Sum();
		int a[] = {1,2,3,4,5};
		System.out.println(obj.sum(a));
	}
}