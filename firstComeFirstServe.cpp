

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"Enter total number of Process: ";
	cin>>n;
	vector<pair<float, float> >processTime(n);
	
	for(int i=0;i<n;i++){
		cout<<"Process "<<i+1<<endl;
		cout<<"---------------------";
		cout<<"\nArrival Time: ";
		cin>>processTime[i].first;
		cout<<"\nBurst Time: ";
		cin>>processTime[i].second;
		cout<<endl;
	}
	cout<<"-----------------------------------------------------\n";
	sort(processTime.begin(), processTime.end()); 
	cout<<"S.No.	         Arrival Time	      Burst Time\n";
	cout<<"-----------------------------------------------------\n";
	for(int i=0;i<n;i++){
		cout<<"Process "<<i+1<<"        "<<processTime[i].first<<"	              "<<processTime[i].second<<endl;
	}
	cout<<endl<<"-----------------------------------------------------\n";
	cout<<"Process Number   -->  Time Started : Time Ends \n";
	cout<<"-----------------------------------------------------\n";
	static float time=0;
	for(int i=0;i<n;i++){
		if(i==0){
			cout<<"Process "<<i+1<<"  	 -->         "<<processTime[0].first<<" : "<<processTime[0].first+processTime[0].second;
			time=time+processTime[0].first+processTime[0].second;
		}
		else{
			if(processTime[i].first<=time){
				cout<<endl;
				cout<<"Process "<<i+1<<"  	 -->         "<<time<<" : "<<time+processTime[i].second;
				time=time+processTime[i].second;
			}
			if(processTime[i].first>time){
				cout<<endl;
				int diff=processTime[i].first-time;
				cout<<"Process "<<i+1<<"  	 -->         "<<processTime[i].first<<" : "<<time+diff+processTime[i].second;
				time=time+diff+processTime[i].second;
			}
		}
	}
	cout<<endl<<"-----------------------------------------------------";
}
