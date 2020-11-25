#include<iostream>
using namespace std;
class Vector{
	private:
		int n;
		int *v;
	public:
		Vector(int );
		Vector(const Vector&);
		~Vector();
		void nhap();
		void xuat();
		Vector operator=(Vector);
		friend void operator+(Vector,Vector);
};
Vector::Vector(int n){
	this->n=n;
	v=new int[this->n];
	for(int i=0;i<n;i++)
		v[i]=0;
}
Vector::Vector(const Vector& x){
	n=x.n;
	v=new int[n];
	for(int i=0;i<n;i++)
		v[i]=x.v[i];
}
Vector::~Vector(){}
void Vector::nhap(){
	for(int i=0;i<n;i++){
		cout<<"Phan tu "<<i<<": ";
		cin>>*(v+i);
	}
}
void Vector::xuat(){
	cout<<"(";
	for(int i=0;i<n;i++){
		cout<<v[i];
		if(i==n-1){
		    cout<<")";
			break;
		}
		cout<<" ; ";
	}
	cout<<endl;
}
Vector Vector::operator=(Vector a){
	return a;
} 
void operator+(Vector a, Vector b){
	int n_=(a.n>=b.n)?a.n:b.n;
	Vector c(n_);
	for(int i=0;i<n_;i++){
		if(i==a.n)
			c.v[i]=b.v[i];
		else if(i==b.n)
			c.v[i]=a.v[i];
		else
			c.v[i]=a.v[i]+b.v[i];
	}
	c.xuat();
}
int main(){
	Vector a(3),b(4);
	cout<<"Vector a: "<<endl;
	a.nhap();
	cout<<"a = ";
	a.xuat();
	cout<<"Vector b: "<<endl;
	b.nhap();
	cout<<"b = ";
	b.xuat();
	cout<<"Vector a+b: "<<endl;
	cout<<"a + b = ";
	a+b;
}
