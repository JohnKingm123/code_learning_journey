public class Cri extends shape{
	private double r;
	
	void setR(double r) {
		this.r=r;
	}
	
	double getArea() {
		double Area=0;
		Area=3.14*r*r;
		return Area;
	}
	

}