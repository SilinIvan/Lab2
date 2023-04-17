#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;
struct housing_estate {
    int numberHouse;
    int numberApartment;
    int number_of_rooms;
    float square;
    string name;
    int number_of_residents;
    housing_estate() {};
    housing_estate(int numberHouse,int numberApartment,float square,string name){
        this->numberHouse=numberHouse;
        this->numberApartment=numberApartment;
        this->square=square;
        this->name=name;
    }
    bool operator > ( housing_estate& h2)
    {
        if (this->name==h2.name) {
                            return true;
        }
        else{


        int ans = this->name.compare(h2.name);
                    return ans > 0;
       }
    };

    bool operator >= ( housing_estate& h2)
    {
        if (this->name==h2.name) {
                            return true;
        }
        else{


        int ans = this->name.compare(h2.name);
                    return ans >= 0;
       }
    };
    bool operator < ( housing_estate& h2)
    {
        if (this->name==h2.name) {
                            return true;
        }
        else{


        int ans = this->name.compare(h2.name);
                    return ans < 0;
       }
    };
    bool operator <= ( housing_estate& h2)
    {
        if (this->name==h2.name) {
                            return true;
        }
        else{
        int ans = this->name.compare(h2.name);
                    return ans <= 0;
       }
    };

};
std::ostream& operator << (std::ostream &os, const housing_estate &h)
{
    return os << h.numberHouse << "," << h.numberApartment << "," << h.number_of_rooms << "," << h.square << "," << h.name << "," << h.number_of_residents ;
}
template <class T> std::vector<int> LinearSearch (vector<T>& a, int size, string key)
{
   std::vector<int> vec(size/2);
   for(int i=0;i<size;i++){
       if(a[i].name == key){
           vec.push_back(i);
       }
     }
   if(vec.empty()){
       vec.push_back(-1);
   }
  else return vec;
}
template<class T> int partition(vector<T>& nums, int low, int high)
{
int i = low - 1;
//choosing pivot as last element
T pivot = nums[high];
for (int j = low; j < high; j++)
{
if (nums[j] <= pivot)
{
i++;
swap(nums[i], nums[j]);
}
}
swap(nums[i + 1], nums[high]);
return i + 1;
}
template<class T> void quickSort(vector<T>& nums, int low, int high)
{
if (low < high)
{
int pivot = partition(nums, low, high);
quickSort(nums, low, pivot - 1);
quickSort(nums, pivot + 1, high);

}
}
template <class T> std::pair<int,int> BinSearch( vector<T> a,  string key,  int low, int high)
{
    //НАДО Вернуть две границы
    int f=0;
         if ( low > high )
         {
              return std::make_pair(-1,0);
         }
         int mid = ( low + high ) / 2;
         if (  a[mid].name == key && f==0 ){
             f=mid;
         }
         if(a[mid].name != key && a[mid-1].name == key){
            return std::make_pair(f,mid-1);
         }
         else if (f!=0){
             return std::make_pair(f,f);
         }
         if ( a[mid].name < key){
            BinSearch(a,key,mid+1,high);
         }
         if ( a[mid].name > key ){

            BinSearch(a,key,low,mid-1);
         }
}
void File(string file, int sort, string k){
    string path = "C:/Users/Ivan/"+file;
    ifstream f(path);
    string l;
    string fi;
    vector<housing_estate> dannie;
    while ( getline(f,l) )    // get next line in file
    {
        stringstream ss(l);
        int i = 0;
        string name1;
        int numberHouse,number_of_rooms,number_of_residents;
        float square;
        int numberApartment;
        while (getline(ss,fi,','))
        {
            if(i==0){
             name1 = fi;
            }
            if(i==1){
                square = stof(fi);
            }
            if(i==2){
                numberHouse = stoi(fi);
            }
            if(i==3){
                numberApartment = stoi(fi);
            }

            ++i;
         }
         housing_estate house(numberHouse,numberApartment,square,name1);
        dannie.push_back(house);
    }
    if (sort==2) {
    quickSort(dannie,0,dannie.size()-1);
    auto begin = std::chrono::steady_clock::now();
    BinSearch(dannie,k,0,dannie.size()-1);
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
     cout<< elapsed_ms.count()<<std::endl;
    }

    if(sort==1) {
     auto begin = std::chrono::steady_clock::now();
      LinearSearch(dannie,dannie.size(),k);  
      auto end = chrono::steady_clock::now();
      auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
      cout<< elapsed_ms.count()<<std::endl;
    }


    if (sort==3) {
    auto begin = std::chrono::steady_clock::now();
    quickSort(dannie,0,dannie.size()-1);
    BinSearch(dannie,k,0,dannie.size()-1);
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
    cout<< elapsed_ms.count()<<std::endl;
    }

    if(sort==4){
      multimap<string, housing_estate> tepl;
      for (int i = 0; i < dannie.size(); i++)
      {
          tepl.insert(make_pair(dannie[i].name, dannie[i]));
      }
      auto begin = std::chrono::steady_clock::now();
      tepl.find(k);
      auto end = chrono::steady_clock::now();
      auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
      cout << elapsed_ms.count()<<std::endl;
    }
}

int main(){
     cout<<"linear"<<std::endl;
    File("200.txt",1,"dpftfx hmvpzdg hciqjb");
    File("1000.txt",1,"gtxqdy nunwti uifeyrezmy");
    File("2000.txt",1,"vtpqqp pfqsterl rtvnwwz");
    File("10000.txt",1,"lqlsbldux ncxbilebcfx eilaku");
    File("20000.txt",1,"lieoreosb lrmqwwmzqf ttfvqwrledr");
    File("100000.txt",1,"pcounimo eudeljnxs zsvxmdr");
    File("150000.txt",1,"jnelslczzzi vtborlnqyse bhwaowv");

    cout<<"binary"<<std::endl;
    File("200.txt",2,"jnqkddcwj sbvtjpikpkm ztpdfoaj");
    File("1000.txt",2,"gtxqdy nunwti uifeyrezmy");
    File("2000.txt",2,"vtpqqp pfqsterl rtvnwwz");
    File("10000.txt",2,"lqlsbldux ncxbilebcfx eilaku");
    File("20000.txt",2,"lieoreosb lrmqwwmzqf ttfvqwrledr");
    File("100000.txt",2,"pcounimo eudeljnxs zsvxmdr");
    File("150000.txt",2,"zqcjll bluvdfocka iywmigt");

    cout<<"sort+binary"<<std::endl;
    File("200.txt",3,"xykzftlsfy hvfakglmxj jblpcexrb");
    File("1000.txt",3,"gtxqdy nunwti uifeyrezmy");
    File("2000.txt",3,"vtpqqp pfqsterl rtvnwwz");
    File("10000.txt",3,"lqlsbldux ncxbilebcfx eilaku");
    File("20000.txt",3,"lieoreosb lrmqwwmzqf ttfvqwrledr");
    File("100000.txt",3,"pcounimo eudeljnxs zsvxmdr");
    File("150000.txt",3,"jnelslczzzi vtborlnqyse bhwaowv");

    cout<<"multimap"<<std::endl;
    File("200.txt",4,"xykzftlsfy hvfakglmxj jblpcexrb");
    File("1000.txt",4,"gtxqdy nunwti uifeyrezmy");
    File("2000.txt",4,"vtpqqp pfqsterl rtvnwwz");
    File("10000.txt",4,"lqlsbldux ncxbilebcfx eilaku");
    File("20000.txt",4,"lieoreosb lrmqwwmzqf ttfvqwrledr");
    File("100000.txt",4,"pcounimo eudeljnxs zsvxmdr");
    File("150000.txt",4,"jnelslczzzi vtborlnqyse bhwaowv");
    cout<<"  "<<endl;

};
