//#ifndef __fff__
//#define __fff__
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
//#endif
struct point{
	double x=0.0,y=0.0;
};
class Figure{
	public:
		double square(){
			if(points.size()==0) return 0.0;
			double res=0.0;
			for(int i=2; i<points.size(); ++i){
				res+=square(points[0], points[i-1], points[i]);	
			}
		}
		point center(){
			point cntr;
			if(points.size()==0) return cntr;
			for(int i=0; i<points.size(); ++i){
				cntr.x+=points[i].x;
				cntr.y+=points[i].y;
			}
			cntr.x/=points.size();
			cntr.y/=points.size();
			return cntr;
		}
		Figure(std::vector<point> pnts){	
			if(pnts.size()>2){	
				
				//Алгоритм Джарвис ?
				//ищем самую нижнюю и левую точку(0-вую). Она точно принадлежит выпуклой оболочке.
				for(int i=1; i<pnts.size(); ++i)
					if(pnts[0].y>pnts[i].y || ( pnts[0].y==pnts[i].y && pnts[0].x>pnts[i].x)) 
						std::swap(pnts[0], pnts[i]);
				//кладем её в массив, где будет лежать наш ответ.
				points.push_back(pnts[0]);
				//ищем первую точку по принципу: угол между вектором через 0-вую и 1-вую точки и вектором (1, 0) минимален, 
				//а расстояние между точками минимально.
				point X; X.x=1.0; X.y=0.0;
				point O; O.x=0; O.y=0; 
				for(int i=2; i<pnts.size(); ++i)
					if(cos_points(pnts[0], pnts[1], O, X) < cos_points(pnts[0], pnts[i], O, X) || ( cos_points(pnts[0], pnts[1], O, X)==cos_points(pnts[0], pnts[i], O, X) && size_points(pnts[0], pnts[1]) > size_points(pnts[0], pnts[1])))
				std::swap(pnts[1], pnts[i]);
				points.push_back(pnts[1]); 
				int k=2;
				while(1){
					for(int i=k+1; i<pnts.size(); ++i)
						if(cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[k]) < cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[i]) || ( cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[k]) == cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[i]) && size_points(pnts[k-1], pnts[k]) > size_points(pnts[k-1], pnts[i]))) 
					std::swap(pnts[k], pnts[i]);	
					if(cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[k]) < cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[0]) || ( cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[k]) == cos_points(pnts[k-1], pnts[k],pnts[k-1], pnts[0]) && size_points(pnts[k-1], pnts[k]) > size_points(pnts[k-1], pnts[0]))) break;
					points.push_back(pnts[k]);
					++k;	
					if(k==pnts.size()) break;
				}
				//=====================================================================================================================================================
				//если не все точки принадлежат выпуклой оболочке, то полностью очищаем итоговый массив.
			if(points.size()<pnts.size()) while(points.size()) points.pop_back(); else{ name+=points.size()+'0'; name+="-gon";}
		}	
	}
	bool initialized(){
		if(points.size()>0) return true;
		return false;
	}
	virtual void reinitialize(std::vector<point> pnts){
		if(points.size()){
			while(points.size()) points.pop_back();
			name="";
		}
		if(pnts.size()>2){	
				
				//Алгоритм Джарвис ?
				//ищем самую нижнюю и левую точку(0-вую). Она точно принадлежит выпуклой оболочке.
				for(int i=1; i<pnts.size(); ++i)
					if(pnts[0].y>pnts[i].y || ( pnts[0].y==pnts[i].y && pnts[0].x>pnts[i].x)) 
						std::swap(pnts[0], pnts[i]);
				//кладем её в массив, где будет лежать наш ответ.
				points.push_back(pnts[0]);
				//ищем первую точку по принципу: угол между вектором через 0-вую и 1-вую точки и вектором (1, 0) минимален, 
				//а расстояние между точками минимально.
				point X; X.x=1.0; X.y=0.0;
				point O; O.x=0; O.y=0; 
				for(int i=2; i<pnts.size(); ++i)
					if(cos_points(pnts[0], pnts[1], O, X) < cos_points(pnts[0], pnts[i], O, X) || ( cos_points(pnts[0], pnts[1], O, X)==cos_points(pnts[0], pnts[i], O, X) && size_points(pnts[0], pnts[1]) > size_points(pnts[0], pnts[1])))
				std::swap(pnts[1], pnts[i]);
				points.push_back(pnts[1]);
				int k=2;
				while(1){
					for(int i=k+1; i<pnts.size(); ++i)
						if(cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[k]) < cos_points(pnts[k-1], pnts[k],pnts[k-1], pnts[i]) || ( cos_points(pnts[k-2], pnts[k-1],pnts[k-1], 	pnts[k]) == cos_points(pnts[k-1], pnts[k],pnts[k-1], pnts[i]) && size_points(pnts[k-1], pnts[k]) > size_points(pnts[k-1], pnts[i]))) 
					std::swap(pnts[k], pnts[i]);	
					if(cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[k]) < cos_points(pnts[k-1], pnts[k],pnts[k-1], pnts[0]) || ( cos_points(pnts[k-2], pnts[k-1],pnts[k-1], pnts[k]) == cos_points(pnts[k-1], pnts[k],pnts[k-1], pnts[0]) && size_points(pnts[k-1], pnts[k]) > size_points(pnts[k-1], pnts[0]))) break;
					points.push_back(pnts[k]);
					++k;	
					if(k==pnts.size()) break;
				}
				//=====================================================================================================================================================
				//если не все точки принадлежат выпуклой оболочке, то полностью очищаем итоговый массив.
			if(points.size()<pnts.size()) while(points.size()) points.pop_back(); else{ name+=points.size(); name+="-угольник";}	
		}
	}
	//std::ostream operator << (std::ostream& stream){
	void print_info(){	
		if(this->initialized()){
			std::cout<<"Name: "<<name<<std::endl;
			point cntr=this->center();
			std::cout<<"Center: ( "<<cntr.x<<" , "<<cntr.y<<" )"<<std::endl;
			std::cout<<"Square: "<<this->square()<<std::endl;
			std::cout<<"Coordinates: "<<std::endl;
			for(int i=0; i<points.size(); ++i){
				std::cout<<"( "<<points[i].x<<" , "<<points[i].y<<" )"<<std::endl;
			}
		}else{
			std::cout<<"Figure was not initialized"<<std::endl;
		}
	}
	Figure(){}
	protected:
		std::string name;
		std::vector<point> points;
		//площадь треугольника по трём точкам
		double square(point a, point b, point c){
			return 0.5*sqrt(((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y))*((c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y))-((b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y))*((b.x-a.x)*(c.x-a.x)+(c.y-a.y)*(b.y-a.y)));
		}
		//косинус угла между векторами ab и cd
		double cos_points(point a, point b, point c, point d){
			return ((b.x-a.x)*(d.x-c.x)+(b.y-a.y)*(d.y-c.y))/(sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y)) * sqrt((d.x-c.x)*(d.x-c.x) + (d.y-c.y)*(d.y-c.y)) );
		}
		double size_points(point a, point b){
			return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
		}
};
	
class Square : public Figure {
	public:
	Square(std::vector<point> pnts){
			int i=0;
		if(pnts.size()==3) for(i =0; i<3; ++i) if( cos_points(pnts[i], pnts[(i+1)%3], pnts[(i+1)%3], pnts[(i+2)%3])==0.0 && size_points(pnts[i], pnts[(i+1)%3]) == size_points(pnts[(i+1)%3], pnts[(i+2)%3])){
			point fth;
			//достраивает квадрат по трём точкам, если стороны квадрата не паралельны.
			if((pnts[(i+2)%3].x-pnts[(i+1)%3].x)!=0 && (pnts[i].x-pnts[(i+1)%3].x)!=0 ){
				fth.y=(pnts[i].x -pnts[(i+2)%3].x + pnts[i].y*(pnts[(i+2)%3].y-pnts[(i+1)%3].y)/(pnts[(i+2)%3].x-pnts[(i+1)%3].x) -pnts[(i+2)%3].y*(pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(1+i)%3].x))/((pnts[(i+2)%3].y-pnts[(i+1)%3].y)/(pnts[(i+2)%3].x-pnts[(i+1)%3].x) - (pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(i+1)%3].x));
				fth.x= pnts[i].x - (pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(i+1)%3].x)*(fth.y-pnts[(i+2)%3].y);
			}else{
				if(pnts[i].x==pnts[(i+1)%3].x){
					fth.x=pnts[(i+2)%3].x;
					fth.y=pnts[i].y;
				}else{
					fth.y=pnts[(i+2)%3].y;
					fth.x=pnts[i].x;
				}
			}
			for(int j=0; j<i; ++j){
				point t;
				t.x=pnts[0].x;
				t.y=pnts[0].y;
				pnts.erase(pnts.begin());
				pnts.push_back(t);
			}
			pnts.push_back(fth);
			break;
		}
		if(pnts.size()==4 && cos_points(pnts[0], pnts[1], pnts[1], pnts[2])==0.0 && size_points(pnts[0], pnts[1]) == size_points(pnts[1], pnts[2]) && size_points(pnts[0], pnts[1]) == size_points(pnts[0], pnts[3]) && size_points(pnts[1], pnts[2]) == size_points(pnts[2], pnts[3])){
			for(int i=0; i<pnts.size(); ++i) points.push_back(pnts[i]);
			name="Square";
		}	
	}
	
	void reinitialize(std::vector<point> pnts) override {
		int i=0;
		if(pnts.size()==3) for(i =0; i<3; ++i) if( cos_points(pnts[i], pnts[(i+1)%3], pnts[(i+1)%3], pnts[(i+2)%3])==0.0 && size_points(pnts[i], pnts[(i+1)%3]) == size_points(pnts[(i+1)%3], pnts[(i+2)%3])){
			point fth;
			//достраивает квадрат по трём точкам, если стороны квадрата не паралельны.
			if((pnts[(i+2)%3].x-pnts[(i+1)%3].x)!=0 && (pnts[i].x-pnts[(i+1)%3].x)!=0 ){
				fth.y=(pnts[i].x -pnts[(i+2)%3].x + pnts[i].y*(pnts[(i+2)%3].y-pnts[(i+1)%3].y)/(pnts[(i+2)%3].x-pnts[(i+1)%3].x) -pnts[(i+2)%3].y*(pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(1+i)%3].x))/((pnts[(i+2)%3].y-pnts[(i+1)%3].y)/(pnts[(i+2)%3].x-pnts[(i+1)%3].x) - (pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(i+1)%3].x));
				fth.x= pnts[i].x - (pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(i+1)%3].x)*(fth.y-pnts[(i+2)%3].y);
			}else{
				if(pnts[i].x==pnts[(i+1)%3].x){
					fth.x=pnts[(i+2)%3].x;
					fth.y=pnts[i].y;
				}else{
					fth.y=pnts[(i+2)%3].y;
					fth.x=pnts[i].x;
				}
			}
			for(int j=0; j<i; ++j){
				point t;
				t.x=pnts[0].x;
				t.y=pnts[0].y;
				pnts.erase(pnts.begin());
				pnts.push_back(t);
			}
			pnts.push_back(fth);
			break;
		}
		if(pnts.size()==4 && cos_points(pnts[0], pnts[1], pnts[1], pnts[2])==0.0 && size_points(pnts[0], pnts[1]) == size_points(pnts[1], pnts[2]) && size_points(pnts[0], pnts[1]) == size_points(pnts[0], pnts[3]) && size_points(pnts[1], pnts[2]) == size_points(pnts[2], pnts[3])){
			for(int i=0; i<pnts.size(); ++i) points.push_back(pnts[i]);
			name="Square";
		}		
	}
};

//new class
class Rectangle : public Figure {
	public:
	Rectangle(std::vector<point> pnts){
		int i=0;
		if(pnts.size()==3) for(i =0; i<3; ++i)  if( cos_points(pnts[i], pnts[(i+1)%3], pnts[(i+1)%3], pnts[(i+2)%3])==0.0 ){
			point fth;
			//достраивает прямоугольник по трём точкам, если стороны его не паралельны.
			if((pnts[(i+2)%3].x-pnts[(i+1)%3].x)!=0 && (pnts[i].x-pnts[(i+1)%3].x)!=0 ){ //проверка непаралельности
				fth.y=(pnts[i].x -pnts[(i+2)%3].x + pnts[i].y*(pnts[(i+2)%3].y-pnts[(i+1)%3].y)/(pnts[(i+2)%3].x-pnts[(i+1)%3].x) -pnts[(i+2)%3].y*(pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(1+i)%3].x))/((pnts[(i+2)%3].y-pnts[(i+1)%3].y)/(pnts[(i+2)%3].x-pnts[(i+1)%3].x) - (pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(i+1)%3].x));
				fth.x= pnts[i].x - (pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(i+1)%3].x)*(fth.y-pnts[(i+2)%3].y);//страшная и противная формулы координат такого прямоугольника
			}else{
				if(pnts[i].x==pnts[(i+1)%3].x){
					fth.x=pnts[(i+2)%3].x;
					fth.y=pnts[i].y;
				}else{
					fth.y=pnts[(i+2)%3].y;
					fth.x=pnts[i].x;
				}
			}
			for(int j=0; j<i; ++j){
				point t;
				t.x=pnts[0].x;
				t.y=pnts[0].y;
				pnts.erase(pnts.begin());
				pnts.push_back(t);
			}
			pnts.push_back(fth);
			break;
		}		
		if(pnts.size()==4 && cos_points(pnts[0], pnts[1], pnts[1], pnts[2])==0.0  && cos_points(pnts[1], pnts[2], pnts[2], pnts[3])==0.0 ){
			for(int i=0; i<pnts.size(); ++i) points.push_back(pnts[i]);
			name="Rectangle";
		}		
	}
	
	void reinitialize(std::vector<point> pnts) override {
	int i=0;
		if(pnts.size()==3) for(i =0; i<3; ++i)  if( cos_points(pnts[i], pnts[(i+1)%3], pnts[(i+1)%3], pnts[(i+2)%3])==0.0 ){
			point fth;
			//достраивает прямоугольник по трём точкам, если стороны его не паралельны.
			if((pnts[(i+2)%3].x-pnts[(i+1)%3].x)!=0 && (pnts[i].x-pnts[(i+1)%3].x)!=0 ){ //проверка непаралельности
				fth.y=(pnts[i].x -pnts[(i+2)%3].x + pnts[i].y*(pnts[(i+2)%3].y-pnts[(i+1)%3].y)/(pnts[(i+2)%3].x-pnts[(i+1)%3].x) -pnts[(i+2)%3].y*(pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(1+i)%3].x))/((pnts[(i+2)%3].y-pnts[(i+1)%3].y)/(pnts[(i+2)%3].x-pnts[(i+1)%3].x) - (pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(i+1)%3].x));
				fth.x= pnts[i].x - (pnts[i].y-pnts[(i+1)%3].y)/(pnts[i].x-pnts[(i+1)%3].x)*(fth.y-pnts[(i+2)%3].y);//страшная и противная формулы координат такого прямоугольника
			}else{
				if(pnts[i].x==pnts[(i+1)%3].x){
					fth.x=pnts[(i+2)%3].x;
					fth.y=pnts[i].y;
				}else{
					fth.y=pnts[(i+2)%3].y;
					fth.x=pnts[i].x;
				}
			}
			for(int j=0; j<i; ++j){
				point t;
				t.x=pnts[0].x;
				t.y=pnts[0].y;
				pnts.erase(pnts.begin());
				pnts.push_back(t);
			}
			pnts.push_back(fth);
			break;
		}		
		if(pnts.size()==4 && cos_points(pnts[0], pnts[1], pnts[1], pnts[2])==0.0  && cos_points(pnts[1], pnts[2], pnts[2], pnts[3])==0.0 ){
			for(int i=0; i<pnts.size(); ++i) points.push_back(pnts[i]);
			name="Rectangle";
		
		}		
	}
};
//new class
class Trapeze : public Figure {
	public:
	Trapeze(std::vector<point> pnts){//трапеция по трём точкам может быть только с основаниями паралельными оси ОХ.
		if(pnts.size()==3){
			if(pnts[0].y != pnts[1].y && pnts[1].y == pnts[2].y){
				point fth;
				fth.y=pnts[0].y;
				fth.x=pnts[2].x + pnts[1].x - pnts[0].x;
				pnts.push_back(fth);
			}else if(pnts[0].y == pnts[1].y && pnts[1].y != pnts[2].y){
				point fth;
				fth.y=pnts[2].y;
				fth.x=pnts[0].x + pnts[1].x - pnts[2].x;
				pnts.push_back(fth);
			}if(pnts[0].y == pnts[2].y && pnts[1].y != pnts[2].y){
				point fth;
				fth.y=pnts[1].y;
				fth.x=pnts[0].x + pnts[2].x - pnts[1].x;
				pnts.push_back(fth);
			}
		}
		if(pnts.size()==4) for(int j=0; j<pnts.size(); ++j) 
		if((
		cos_points( pnts[(j+1)%4], pnts[(j+2)%4], pnts[(j+0)%4], pnts[(j+3)%4])>0.999 
		|| cos_points( pnts[(j+1)%4], pnts[(j+2)%4], pnts[(j+0)%4], pnts[(j+3)%4])<-0.999) 
		&& cos_points( pnts[(j+1)%4], pnts[(j+2)%4], pnts[(j+1)%4], pnts[(j)%4])!=-1.0
		&& cos_points( pnts[(j+1)%4], pnts[(j+2)%4], pnts[(j+1)%4], pnts[(j)%4])!=1.0 
		&& size_points(pnts[(j)%4], pnts[(j+1)%4]) == size_points(pnts[(j+3)%4], pnts[(j+2)%4]) ){
				for(int i=j; i<j+pnts.size(); ++i) points.push_back(pnts[i%4]);
				name="Trapeze";break;
		}
	}
	void reinitialize(std::vector<point> pnts) override {//трапеция по трём точкам может быть только с основаниями паралельными оси ОХ.
		if(pnts.size()==3){
			if(pnts[0].y != pnts[1].y && pnts[1].y == pnts[2].y){
				point fth;
				fth.y=pnts[0].y;
				fth.x=pnts[2].x + pnts[1].x - pnts[0].x;
				pnts.push_back(fth);
			}else if(pnts[0].y == pnts[1].y && pnts[1].y != pnts[2].y){
				point fth;
				fth.y=pnts[2].y;
				fth.x=pnts[0].x + pnts[1].x - pnts[2].x;
				pnts.push_back(fth);
			}if(pnts[0].y == pnts[2].y && pnts[1].y != pnts[2].y){
				point fth;
				fth.y=pnts[1].y;
				fth.x=pnts[0].x + pnts[2].x - pnts[1].x;
				pnts.push_back(fth);
			}
		}
		if(pnts.size()==4) for(int j=0; j<pnts.size(); ++j){ if((cos_points( pnts[(j+1)%4], pnts[(j+2)%4], pnts[(j+0)%4], pnts[(j+3)%4])>0.999 ||
		cos_points( pnts[(j+1)%4], pnts[(j+2)%4], pnts[(j+0)%4], pnts[(j+3)%4])<-0.999) 
		&& cos_points( pnts[(j+1)%4], pnts[(j+2)%4], pnts[(j+1)%4], pnts[(j)%4])!=-1.0
		&& cos_points( pnts[(j+1)%4], pnts[(j+2)%4], pnts[(j+1)%4], pnts[(j)%4])!=1.0 
		&& size_points(pnts[(j)%4], pnts[(j+1)%4]) == size_points(pnts[(j+3)%4], pnts[(j+2)%4]) ){
				for(int i=j; i<j+pnts.size(); ++i) points.push_back(pnts[i%4]);
				name="Trapeze";break;
		}
	}}
};


