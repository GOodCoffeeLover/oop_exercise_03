#include<vector>
#include<iostream>
#include"Figures.cpp"

void print_menu(){
	std::cout<<"1. Print menu."<<std::endl
	<<"2. Input figure."<<std::endl
	<<"3. Print information of all figures."<<std::endl
	<<"4. Print information of figure."<<std::endl
	<<"5. Print sum of squres of all figures."<<std::endl
	<<"6. Remove figure with index."<<std::endl
	<<"0. Exit."<<std::endl;
}

int main(){
	std::vector<Figure*> figures;
	int status = 1;
	while(status){
		switch(status){
			case 1 : print_menu(); break;
			case 2 :{
				std::cout<<"Choose figure: "<<std::endl
				<<"1. Polygn"<<std::endl
				<<"2. Square "<<std::endl
				<<"3. Rectangle"<<std::endl
				<<"4. Trapeze"<<std::endl;
				std::cout<<">>";
				int a;
				std::cin>>a;
				point p;
				switch(a){
					case 1 :{
						std::cout<<"input number of  polygon vertex."<<std::endl;
						int n;
						std::cin>>n;
						if(n<=2){
						std::cout<<"Too little vertex."<<std::endl;
						}
						std::vector<point> ppp;
						for(int i=0; i<n; ++i){
							std::cout<<"Input vertex x and y coordinates."<<std::endl;
							std::cin>>p.x;
							//std::cout<<"Input vertex y cootdinate."<<std::endl;
							std::cin>>p.y;
							ppp.push_back(p);
						}
						figures.push_back(new Figure(ppp));
						if(!(figures[figures.size()-1]->initialized())){
							std::cout<<"Inputed coordinates are not belong convex polygon."<<std::endl;
							delete figures[figures.size()-1];
							figures.pop_back();
						}
						break;
					}
					case  2:{
						std::cout<<"Input number of square vertex (3 or 4)."<<std::endl;
						int n;
						std::cin>>n;
						if(n!=3 && n!=4){
							std::cout<<"Wrong number of vertex."<<std::endl;
							break;
						}
						std::vector<point> ppp;
						point p;
						for(int i=0; i<n; ++i){
							std::cout<<"Input vertex x and y cooedinates."<<std::endl;
							std::cin>>p.x;
							//std::cout<<"Input vertex y cootdinate."<<std::endl;
							std::cin>>p.y;
							ppp.push_back(p);
						}
						figures.push_back(new Square(ppp));
						if(!figures[figures.size()-1]->initialized()){
							std::cout<<"Inputed coordinates are not belong convex square."<<std::endl;
							delete figures[figures.size()-1];
							figures.pop_back();
						}
						break;
					}
					case  3:{
						std::cout<<"Input number of rectangle vertex (3 or 4)."<<std::endl;
						int n;
						std::cin>>n;
						if(n!=3 && n!=4){
							std::cout<<"Wrong number of vertex."<<std::endl;
							break;
						}
						std::vector<point> ppp;
						std::cout<<"Input vertex x and y coordinates."<<std::endl;
						std::cin>>p.x;
						//std::cout<<"Input vertex y cootdinate."<<std::endl;
						std::cin>>p.y;
						ppp.push_back(p);
						figures.push_back(new Rectangle(ppp));
						if(!figures[figures.size()-1]->initialized()){
							std::cout<<"Inputed coordinates are not belong convex rectangle."<<std::endl;
							delete figures[figures.size()-1];
							figures.pop_back();
						}
						break;
					}
					case  4:{
						std::cout<<"Input number of trapeze vertex (3, if base parallel to axis OX,  or 4)."<<std::endl;
						int n;
						std::cin>>n;
						if(n!=3 && n!=4){
							std::cout<<"Wrong number of vertex."<<std::endl;
							break;
						}
						std::vector<point> ppp;
						point p;
						for(int i=0; i<n; ++i){
							std::cout<<"Input vertex x and y coordinates."<<std::endl;
							std::cin>>p.x;
							//std::cout<<"Input vertex y cootdinate."<<std::endl;
							std::cin>>p.y;
							ppp.push_back(p);
						}
						figures.push_back(new Trapeze(ppp));
						if(!figures[figures.size()-1]->initialized()){
							std::cout<<"Inputed coordinates are not belong convex trapeze."<<std::endl;
							delete figures[figures.size()-1];
							figures.pop_back();
						}
						break;
					}
				}
				break;
				}
			case 3:{
				std::cout<<"figures: "<<std::endl;
				for(int i=0; i<figures.size(); ++i){	std::cout<<i+1<<"."; figures[i]->print_info();}// std::cout<<*figures[i]<<std::endl;}		
				break;
			}
			case 4:{
				std::cout<<"input index of figure."<<std::endl;
				int a;
				std::cin>>a;
				if(!(a-1>=0  && a-1<figures.size())){ std::cout<<"Wrong index."<<std::endl; break;}
				figures[a]->print_info();
				//std::cout<<*figures[a];
				break;
			}
			case 5 :{
				double sum=0.0;
				if(figures.size()>0){ std::cout<<"There is no figures."<<std::endl; break;}
				for(int i=0; i<figures.size(); ++i) sum +=figures[i]->square();
				std::cout<<sum<<std::endl;
			}
			case 6 :{
				int a;
				std::cout<<"Input index of figure"<<std::endl;
				std::cin>>a;
				if(a<0 || a>=figures.size()){ std::cout<<"Wrong index"<<std::endl; break;}
				figures.erase(figures.begin() +a );	
			}
			default:
			 std::cout<<"Wrong choose."<<std::endl;
		}
		std::cout<<">>";
		std::cin>>status;
	}
	return 0;
}
