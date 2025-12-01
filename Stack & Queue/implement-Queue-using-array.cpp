#include <bits\stdc++.h>
using namespace std;
 
class MyQueue{
    private:
    int * arr;
    int start, end;
    int currSize, maxSize;
    public:
    MyQueue(int size=1000){
         maxSize=size;
        arr=new int[maxSize];
        start=-1;
        end=-1;
        currSize=0;
    }
    int push(int x){
        if(currSize==maxSize){
            cout<<"Queue full"<<endl;
            exit(1);
        }
        if(start==-1){
            start=0;
            end=0;
        }
        else{
            end=(end+1)% maxSize;
        }
        arr[end]=x;
        currSize++;
    }
    int pop(){
        if(currSize==0){
            cout<<"Queue empty"<<endl;
            exit(1);
        }
        int ans=arr[start];
        if(currSize==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%maxSize;
        }
        currSize--;
        return ans;
    }
    int peek(){
        if(start==-1){
            cout<<"Queue empty"<<endl;
            exit(1);
        }
        return arr[start];
    }
    bool isEmpty(){
        return currSize==0;
    }
};

int main(){
  MyQueue queue;
    vector<string> commands = {"ArrayQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};
    for(size_t i =0; i<commands.size(); i++){
        if (commands[i] == "push") {
            queue.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << queue.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << queue.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayQueue") {
            cout << "null ";
        }
    }
  return 0;
}