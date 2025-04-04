#include<bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> &start,vector<int> &end,int n)
{
    vector<pair<int,int>>activities(n);
    for(int i=0; i<n; i++)
    {
        activities.push_back({end[i],start[i]});
    }
    sort(activities.begin(),activities.end());//sort(start to end)
    int ans=1;
    int finish=-1;
    for(int i=0; i<n-1; i++)
    { pair<int,int> activity= activities[i];
        if(activity.second>finish){
            finish=activity.first;
             ans++;
        }

    }
    return ans;

}
int main()
{

    int n;
    cout<<"Number of schedules: ";
    cin>>n;
    vector<int> start(n);
    vector<int> end(n);
    for(int i=0; i<n; i++)
    {
        cin>> start[i];
        cin>>end[i];
    }


    int result=activitySelection(start,end,n);

    cout<<"total: "<<result<<endl;

}
