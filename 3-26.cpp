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
    auto cmp = [](item left, item right) {return ((left.weight) <= (right.weight));};
    priority_queue<item, vector<item>, decltype(cmp)> q(cmp);

    for(item i : items) {
        q.push(i);
    }

    int currWeight = 0, currBenefit = 0;    
    while(!q.empty()) {
        if(currWeight + q.top().weight <= maxWeight) {
            currWeight += q.top().weight;
            currBenefit += q.top().benefit;
        }
        q.pop();
    }

    return currBenefit;
}

int greedyMaxRatio(vector<item> items, int maxWeight) {
    auto cmp = [](item left, item right) {return ((left.benefit/left.weight) <= (right.benefit/right.weight));};
    priority_queue<item, vector<item>, decltype(cmp)> q(cmp);

    for(item i : items) {
        q.push(i);
    }

    int currWeight = 0, currBenefit = 0;
    while(!q.empty()) {
        if(currWeight + q.top().weight <= maxWeight) {
            currWeight += q.top().weight;
            currBenefit += q.top().benefit;
        }
        q.pop();
    }

    return currBenefit;

}

float greedyMaxWeightFractionalKnapsack(vector<item> items, float maxWeight) {
    auto cmp = [](item left, item right) {return ((left.weight) <= (right.weight));};
    priority_queue<item, vector<item>, decltype(cmp)> q(cmp);

    for(item i : items) {
        q.push(i);
    }

    float currWeight = 0, currBenefit = 0;
    while(!q.empty()) {
        float selectedWeightRatio = min((maxWeight - currWeight)/q.top().weight, 1.0f);
        currBenefit += q.top().benefit * selectedWeightRatio; 
        currWeight += q.top().weight * selectedWeightRatio;
        q.pop();
    }

    return currBenefit;
}

float greedyMaxRatioFractionalKnapsack(vector<item> items, float maxWeight) {
    auto cmp = [](item left, item right) {return ((left.benefit/left.weight) <= (right.benefit/right.weight));};
    priority_queue<item, vector<item>, decltype(cmp)> q(cmp);

    for(item i : items) {
        q.push(i);
    }

    float currWeight = 0, currBenefit = 0;
    while(!q.empty()) {
        float selectedWeightRatio = min((maxWeight - currWeight)/q.top().weight, 1.0f);
        currBenefit += q.top().benefit * selectedWeightRatio; 
        currWeight += q.top().weight * selectedWeightRatio;
        q.pop();
    }

    return currBenefit;
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

    cout<<"maximum benefit (dynamic) is " << dynamicKnapsack(list, W)<<endl;
    cout<<"maximum benefit (greedy maxWeight) is "<< greedyMaxWeight(list, W)<<endl;
    cout<<"maximum benefit (greedy maxRatio) is "<< greedyMaxRatio(list, W)<<endl;
    cout<<"maximum benefit (greedy maxWeight Fractional) is "<< greedyMaxWeightFractionalKnapsack(list, W)<<endl;
    cout<<"maximum benefit (greedy maxRatio Fractional) is "<< greedyMaxRatioFractionalKnapsack(list, W)<<endl;

    return 0;
}
