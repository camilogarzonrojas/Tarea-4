#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

float a_arr(float magnitud,float v_x_y){
	float arr=-v_x_y*magnitud;
	return arr;
}


int main()
{
	ofstream save("primera_parte");
	float a1x, a1y, a2x, a2y, a3x, a3y, a4x, a4y, b1x, b1y, b2x, b2y, b3x, b3y, b4x, b4y, x, y, vx, vy, t, angulo, v, i;
	angulo=3.1416/4;
	vx=300*cos(angulo);
	vy=300*sin(angulo);
	x=0;
	y=0;
	t=0.001;
	i=0;
	//Se hace un bucle llamado do para ejecutar el metodo runge kutta:
	do
	{
		//Se calculan los coeficientes de las velocidades
		
		v=sqrt(pow(vx,2)+pow(vy,2)); //En un principio se obtiene la magnitud de v
		b1x=a_arr(v,vx);
		b1y=-10+a_arr(v,vy);
		v=sqrt(pow((vx+b1x*t/2),2)+pow((vy+b1y*t/2),2));
		b2x=a_arr(v,(vx+b1x*t/2));
		b2y=-10+a_arr(v,(vy+b1y*t/2));
		v=sqrt(pow((vx+b2x*t/2),2)+pow((vy+b2y*t/2),2));
		b3x=a_arr(v,(vx+b2x*t/2));
		b3y=-10+a_arr(v,(vy+b2y*t/2));
		v=sqrt(pow((vx+b3x*t/2),2)+pow((vy+b3y*t/2),2));
		b4x=a_arr(v,(vx+b3x*t/2));
		b4y=-10+a_arr(v,(vy+b3y*t/2));
		
		a1x=vx;
		a1y=vy; //Se calculan los coeficientes de x y y
		a2x=vx+b1x*t/2;
		a2y=vy+b1y*t/2;
		a3x=vx+b2x*t/2;
		a3y=vy+b2y*t/2;
		a4x=vx+b3x*t/2;
		a4y=vy+b3y*t/2;
		
		x=x+(t/6)*(a1x+2*a2x+2*a3x+a4x);
		y=y+(t/6)*(a1y+2*a2y+2*a3y+a4y);
		vx=vx+(t/6)*(b1x+2*b2x+2*b3x+b4x); //Se actualizan los valores de x, y, vx y vy
		if (vx<0)
		{
			vx=0;
		}
		vy=vy+(t/6)*(b1y+2*b2y+2*b3y+b4y);
		//cout<<x<<", "<<y<<"\n";
		i+=1;
		save<<i*t<<","<<x<<","<<y<<","<<vx<<","<<vy<<"\n";
	}
	while(y>0);
	
	cout<<"la distancia alcanzada es "<<x<<"\n";

	//Segunda parte:
		//Se define una variable para almacenar el angulo con disparo mas largo:
		float angulo_disparo_mas_largo=45;
		float disparo_mas_largo=x;
		//Se define un array de nombres para los archivos:
		char* file_names[7];
		file_names[0]="dinamica_10";
		file_names[1]="dinamica_20";
		file_names[2]="dinamica_30";
		file_names[3]="dinamica_40";
		file_names[4]="dinamica_50";
		file_names[5]="dinamica_60";
		file_names[6]="dinamica_70";
		int j=0;
		//Se ejecuta la rutina del runge kutta 7 veces para los diferentes angulos:
		for (j;j<7;j=j+1){
			angulo=(10+10*j)*(3.1416/180);
			float a1x, a1y, a2x, a2y, a3x, a3y, a4x, a4y, b1x, b1y, b2x, b2y, b3x, b3y, b4x, b4y, x, y, vx, vy, t, angulo, v, i;
			angulo=(10+10*j)*(3.1416/180);
			vx=300*cos(angulo);
			vy=300*sin(angulo);
			x=0;
			y=0;
			t=0.0001;
			ofstream save(file_names[j]);
			i=0;
			//Se hace un bucle de nombre do para ejecutar el metodo de runge kutta:
			do{
				//calculamos los coeficientes de las velocidades
				//primero obtenemos la magnitud de v:
				v=sqrt(pow(vx,2)+pow(vy,2));
				b1x=a_arr(v,vx);
				b1y=-10+a_arr(v,vy);
				v=sqrt(pow(vx+b1x*t/2,2)+pow(vy+b1y*t/2,2));
				b2x=a_arr(v,vx+b1x*t/2);
				b2y=-10+a_arr(v,vy+b1y*t/2);
				v=sqrt(pow(vx+b2x*t/2,2)+pow(vy+b2y*t/2,2));
				b3x=a_arr(v,vx+b2x*t/2);
				b3y=-10+a_arr(v,vy+b2y*t/2);
				v=sqrt(pow(vx+b3x*t/2,2)+pow(vy+b3y*t/2,2));
				b4x=a_arr(v,vx+b3x*t/2);
				b4y=-10+a_arr(v,vy+b3y*t/2);
				//calculamos los coeficientes de x y y:
				a1x=vx;
				a1y=vy;
				a2x=vx+b1x*t/2;
				a2y=vy+b1y*t/2;
				a3x=vx+b2x*t/2;
				a3y=vy+b2y*t/2;
				a4x=vx+b3x*t/2;
				a4y=vy+b3y*t/2;
				//actualizamos los valores de x, y, vx y vy:
				x=x+(t/6)*(a1x+2*a2x+2*a3x+a4x);
				y=y+(t/6)*(a1y+2*a2y+2*a3y+a4y);
				vx=vx+(t/6)*(b1x+2*b2x+2*b3x+b4x);
				if (vx<0){
					vx=0;
				}
				vy=vy+(t/6)*(b1y+2*b2y+2*b3y+b4y);
				i=i+1;
				//cout<<x<<", "<<y<<"\n";
				save<<i*t<<","<<x<<","<<y<<","<<vx<<","<<vy<<"\n";
			}while(y>=0);
				if (x>disparo_mas_largo){
					disparo_mas_largo=x;
					angulo_disparo_mas_largo=10+10*j;
				}
		
		
		}
		cout<<"el angulo al que se alcanza la maxima distancia es "<<angulo_disparo_mas_largo<<"; la distancia es: "<<disparo_mas_largo;
		cout << "\n***\n" << "programa Finalizado" << "\n***\n";
	
	
	
	
	
	return 0;
}
