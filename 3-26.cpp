// Dynamic Solution to 0-1 Knapsack problem
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct item {
    int benefit, weight;
    item(int b, int w): benefit(b), weight(w) {}
};

int greedyMaxWeight(vector<item> items, int maxWeight) {

}

int dynamicKnapsack(vector<item> items, int maxWeight) {
    if (items.empty() || maxWeight <= 0) {
        return 0;
    }
    item lastItem = items.back();
    items.pop_back();
    return max( lastItem.benefit + dynamicKnapsack(items, maxWeight - lastItem.weight), dynamicKnapsack(items, maxWeight));
}

int main(void) {
    int W, n;
    vector<item> list;
    cout<<"Enter maximum weight"<<endl;
    cin>>W;
    cout<<"How many elements? ";
    cin>>n;
    cout<<"Enter "<<n<<" benefits and weights"<<endl;

    for(int i = 0; i < n; i++) {
        int b, w;
        cin>>b>>w;
        list.push_back(item(b, w));
    }

    cout<<"maximum benefit is " << dynamicKnapsack(list, W);

    return 0;
}
