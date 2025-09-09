#include <iostream>
using namespace std;

class Vehicle {
private:
    int id;
    char manufacturer[20];
    char model[20];
    int year;

public:
    static int totalVehicles;

    Vehicle(int vid=0, const char* manu="", const char* mod="", int y=0) {
        id = vid;

        int i=0;
        for(; manu[i]!='\0' && i<19; i++) manufacturer[i] = manu[i];
        manufacturer[i] = '\0';

        i=0;
        for(; mod[i]!='\0' && i<19; i++) model[i] = mod[i];
        model[i] = '\0';

        year = y;
        totalVehicles++;
    }

    ~Vehicle() { totalVehicles--; }

    int getId() { return id; }
    int getYear() { return year; }

    void setId(int v) { id=v; }
    void setYear(int y) { year=y; }

    void printInfo() {
        cout << "[Vehicle] ID:" << id
             << " " << manufacturer << " " << model
             << " Year:" << year << "\n";
    }
};
int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
private:
    char fuel[10];
public:
    Car(int id=0,const char* manu="",const char* mod="",int y=0,const char* f="Petrol")
        : Vehicle(id,manu,mod,y) {
        int i=0; for(; f[i]!='\0' && i<9; i++) fuel[i]=f[i]; fuel[i]='\0';
    }
    void printInfo() {
        cout << "[Car] ID:" << getId() << " Fuel:" << fuel << "\n";
    }
};
class ElectricCar : public Car {
    int battery;
public:
    ElectricCar(int id=0,const char* manu="",const char* mod="",int y=0,const char* f="Electric",int b=0)
        : Car(id,manu,mod,y,f) {
        battery=b;
    }
    void printInfo() {
        cout << "[ElectricCar] ID:" << getId() << " Battery:" << battery << "kWh\n";
    }
};

class Aircraft {
    int range;
public:
    Aircraft(int r=0){ range=r; }
    int getRange(){ return range; }
    void printInfo(){ cout<<"[Aircraft] Range:"<<range<<" km\n"; }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id=0,const char* manu="",const char* mod="",int y=0,const char* f="Hybrid",int r=0)
        : Car(id,manu,mod,y,f), Aircraft(r) {}
    void printInfo(){
        cout<<"[FlyingCar] ID:"<<getId()<<" Range:"<<getRange()<<" km\n";
    }
};
class SportsCar : public ElectricCar {
    int topSpeed;
public:
    SportsCar(int id=0,const char* manu="",const char* mod="",int y=0,int b=0,int s=0)
        : ElectricCar(id,manu,mod,y,"Electric",b) {
        topSpeed=s;
    }
    void printInfo(){
        cout<<"[SportsCar] ID:"<<getId()<<" TopSpeed:"<<topSpeed<<" km/h\n";
    }
};

class Sedan : public Car {
public:
    Sedan(int id=0,const char* manu="",const char* mod="",int y=0,const char* f="Petrol")
        : Car(id,manu,mod,y,f) {}
    void printInfo(){ cout<<"[Sedan] ID:"<<getId()<<" (Family Car)\n"; }
};

class SUV : public Car {
public:
    SUV(int id=0,const char* manu="",const char* mod="",int y=0,const char* f="Diesel")
        : Car(id,manu,mod,y,f) {}
    void printInfo(){ cout<<"[SUV] ID:"<<getId()<<" (Offroad)\n"; }
};
class VehicleRegistry {
    Vehicle* list[50];
    int count;
public:
    VehicleRegistry(){ count=0; }
    ~VehicleRegistry(){ for(int i=0;i<count;i++) delete list[i]; }

    void add(Vehicle* v){ if(count<50) list[count++]=v; }
    void showAll(){
        for(int i=0;i<count;i++) list[i]->printInfo();
    }
    void searchById(int id){
        for(int i=0;i<count;i++){
            if(list[i]->getId()==id){ list[i]->printInfo(); return; }
        }
        cout<<"Not found\n";
    }
};
int main(){
    VehicleRegistry reg;
    int ch;
    do {
        cout<<"\n1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV 7.ShowAll 8.Search 9.Total 10.Exit\n";
        cin>>ch;
        if(ch==1) reg.add(new Car(1,"Toyota","Corolla",2020,"Petrol"));
        else if(ch==2) reg.add(new ElectricCar(2,"Tesla","ModelS",2022,"Electric",100));
        else if(ch==3) reg.add(new FlyingCar(3,"Aero","X",2023,"Hybrid",400));
        else if(ch==4) reg.add(new SportsCar(4,"Porsche","Taycan",2021,90,320));
        else if(ch==5) reg.add(new Sedan(5,"Honda","Civic",2019,"Petrol"));
        else if(ch==6) reg.add(new SUV(6,"Jeep","Wrangler",2021,"Diesel"));
        else if(ch==7) reg.showAll();
        else if(ch==8){ int id; cout<<"Enter id:"; cin>>id; reg.searchById(id);}
        else if(ch==9) cout<<"Total vehicles:"<<Vehicle::totalVehicles<<"\n";
    } while(ch!=10);
}


/*
     Output :-

1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV 7.ShowAll 8.Search 9.Total 10.Exit
1
1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV 7.ShowAll 8.Search 9.Total 10.Exit
2
1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV 7.ShowAll 8.Search 9.Total 10.Exit
5
1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV 7.ShowAll 8.Search 9.Total 10.Exit
7
[Car] ID:1 Fuel:Petrol
[ElectricCar] ID:2 Battery:100kWh
[Sedan] ID:5 (Family Car)

1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV 7.ShowAll 8.Search 9.Total 10.Exit
8
Enter id: 2
[ElectricCar] ID:2 Battery:100kWh

1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV 7.ShowAll 8.Search 9.Total 10.Exit
9
Total vehicles:3

1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV 7.ShowAll 8.Search 9.Total 10.Exit
10

*/

     
     
     
