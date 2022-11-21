public class calculate{
	
	
	public static void main(String[] args) {
		Cri C1 = new Cri();
		Tri T1 = new Tri();
		stylidium sd1 =new stylidium();
		stylidium sd2 =new stylidium();
		
		C1.setR(2.0);
		T1.setA(2.0);
		T1.setH4A(2.0);
		sd1.setBottom(C1);
		sd1.setH(3.0);
		sd2.setBottom(T1);
		sd2.setH(3.0);
		
		double C1Area=C1.getArea();
		double T1Area=T1.getArea();		
		double sd1Vol=sd1.getVol();
		double sd2Vol=sd2.getVol();
		
		System.out.println("构建圆C1，半径为2");
		System.out.println("面积为：");
		System.out.println(C1Area);
		System.out.println("构建三角形T1，一底边长为2，其上高为2");		
		System.out.println("面积为：");
		System.out.println(T1Area);
		System.out.println("构建以C1为底面，高为3的圆柱");
		System.out.println("体积为：");
		System.out.println(sd1Vol);
		System.out.println("构建以T1为底面，高为3的三棱柱");
		System.out.println("体积为：");
		System.out.println(sd2Vol);		
		
		
	}

}


