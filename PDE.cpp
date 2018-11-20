#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
float T_next(float T[],int i,float c, int accion){
	switch (accion)
	{
		float T_next;
		case 0://nodo interno
			T_next=T[i]+c*(-4*T[i]+T[i+1]+T[i-1]+T[i+6]+T[i-6]);
			return T_next;
			break;
		case 1://nodo ubicado sobre borde derecho
			T_next=T[i]+c*(-4*T[i]+2*T[i-1]+T[i+6]+T[i-6]);
			return T_next;
			break;
		case 2://nodo ubicado sobre borde superipr
			T_next=T[i]+c*(-4*T[i]+2*T[i-6]+T[i+1]+T[i-1]);
			return T_next;
			break;
		case 3://nodo derecho:
			T_next=T[i]+c*(-4*T[i]+2*T[i+1]+T[i+6]+T[i-6]);
			return T_next;
			break;
		case 4://nodo inferior:
			T_next=T[i]+c*(-4*T[i]+2*T[i+6]+T[i+1]+T[i-1]);
			return T_next;
			break;
		default:
			cout<<"error fatal"<<"\n";			
			
		
	}
	
}
int main (){
	//propiedades fisicas de la roca:
	float k=1.62;
	float cp=820;
	float p=2710;
	//valores de deltax y deltat:
	float dx=0.05;
	float dt=3;
	//cremoas arreglos para guardar las coordenadas y las temperaturas:
	float x[36];
	float y[36];
	float T[36];
	float Ti[36];
	float c=dt*(k/(p*cp))*(1/(dx*dx));
	//rellenamos las coordenadas:
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			x[j+6*i]=j*dx;
			y[j+6*i]=i*dx;
		}
	}
	for(int i=30;i<35;i++){
		x[i]=dx*(i-30);
		y[i]=5*dx;
	}
	//nodo pared añadido para asemejar un circulo:
	x[35]=0.215;
	y[35]=0.215;
	//crear archivo para puntos:
	ofstream puntos("puntos.txt");
	//escribir el rchivo:
	for(int i=0;i<36;i++){
		puntos<<x[i]<<","<<y[i]<<"\n";
	}
	//Primer apartado: temperatura_bordes=10:
	//asignamos las condiciones de fronter:
	for (int i=0;i<35;i++){
		T[i]=0;
	}
	//las temparaturas de las paredes a 10°
	for(int i=0;i<6;i++){
		T[i]=10;
		T[6*i]=10;
	}
	//Las paredes del cilindro en T=100°
	T[29]=100;T[34]=100;T[35]=100;
	//crear archivo para guardar temperaturas:
	ofstream guardar("bordes_10C.txt");
	//resolver para los diferentes tiempos:
	for(int s=0;s<10000;s++){
		//recorrer los nodos internos:
		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				Ti[7+j+6*i]=T_next(T,7+j+6*i,c,0);
			}
		}
		//recorrer los nodos de las simetrias:
		for (int i=0;i<3;i++){
			Ti[11+6*i]=T_next(T,11+6*i,c,1);
			Ti[31+i]=T_next(T,31+i,c,2);
		}
		//Actualizar Temperaturas:
		for(int i=0;i<34;i++){
			T[i]=Ti[i];
		}//reestablecer temperaturas en las paredes:
		for(int i=0;i<6;i++){
			T[i]=10;
			T[6*i]=10;
		}
		T[29]=100;
		//guardar las temperaturas:
		for(int i=0;i<36;i++){
			guardar<<T[i]<<",";
		}
		guardar<<"\n";	
				
	}
	//paredes abiertas:
	//las temparaturas de las paredes a 10°
	for (int i=0;i<35;i++){
		T[i]=0;
	}
	//Las paredes del cilindro en T=100°
	T[29]=100;T[34]=100;T[35]=100;
	ofstream guardar1("bordes_abiertos.txt");
	//resolver para los diferentes tiempos:
	for(int s=0;s<100000;s++){
		//recorrer los nodos internos:
		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				Ti[7+j+6*i]=T_next(T,7+j+6*i,c,0);
			}
		}
		//recorrer los nodos de las simetrias:
		for (int i=0;i<3;i++){
			Ti[11+6*i]=T_next(T,11+6*i,c,1);
			Ti[31+i]=T_next(T,31+i,c,2);
		}
		//garantizar que no haya gradiente de T en las paredes:
		for(int i=1;i<6;i++){
			Ti[i]=Ti[i+6];
			Ti[6*i]=Ti[i+1];
		}
		Ti[0]=Ti[1];
		//Actualizar Temperaturas:
		for(int i=0;i<34;i++){
			T[i]=Ti[i];
		}
		T[29]=100;
		//guardar las temperaturas:
		for(int i=0;i<36;i++){
			guardar1<<T[i]<<",";
		}
		guardar1<<"\n";	
				
	}
	//finalmente fronteras periodicas:
	//las temparaturas de las paredes a 10°
	for (int i=0;i<35;i++){
		T[i]=0;
	}
	//Las paredes del cilindro en T=100°
	T[29]=100;T[34]=100;T[35]=100;
	ofstream guardar2("bordes_periodicos.txt");
	dt=10;
	c=dt*(k/(p*cp))*(1/(dx*dx));
	for(int s=0;s<100000;s++){
		//recorrer los nodos internos:
		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				Ti[7+j+6*i]=T_next(T,7+j+6*i,c,0);
			}
		}
		//recorrer los nodos de las simetrias:
		for (int i=0;i<3;i++){
			Ti[11+6*i]=T_next(T,11+6*i,c,1);
			Ti[31+i]=T_next(T,31+i,c,2);
		}
		//recorrer los nodos periodicos:
		for(int i=1;i<5;i++){
			Ti[i]=T_next(T,i,c,4);
			Ti[6*i]=T_next(T,i,c,3);
		}
		//los nodos 0, 5 y 30:
		Ti[0]=T[0]+c*(2*T[1]+2*T[6]-4*T[0]);
		Ti[5]=T[5]+c*(2*T[4]+2*T[11]-4*T[5]);
		Ti[30]=T[30]+c*(2*T[31]+2*T[24]-4*T[30]);
		//Actualizar Temperaturas:
		for(int i=0;i<34;i++){
			T[i]=Ti[i];
		}
		T[29]=100;
		//guardar las temperaturas:
		for(int i=0;i<36;i++){
			guardar2<<T[i]<<",";
		}
		guardar2<<"\n";	
				
	}
	
	
	
	
	
	return 0;
}
