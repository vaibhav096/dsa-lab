# include <iostream>
# include <string.h>

using namespace std;

class HashFunction{
    typedef struct hash{
        int key;
        int value;
    }hash;
    hash h[10];
    public:
    HashFunction(){
        int i;
        for(i=0;i<10;i++){
            h[i].key=-1;
            h[i].value=-1;

        }

    }

    void insert(){
        char ans;
        int k,v,hi,cnt=0,flag=0,i;
        do{
            if (cnt>=10){
                cout<<"Hash table is full"<<endl;
                break;
            }
            cout<<"Enter a key value"<<endl;
            cin>>k;
            cout<<"Enter a value"<<endl;
            cin>>v;

            hi= k%10;
            if(h[hi].key==-1){
                h[hi].key=k;
                h[hi].value=v;

            }
            else{
                for(i=hi+1;i<10;i++){
                    if(h[i].key==-1){
                        h[i].key=k;
                        h[i].value=v;
                        flag=1;
                        break;

                    }


                }
                for(i=0;i<hi && flag==0;i++){
                    if(h[i].key==-1){

                        h[i].key=k;
                        h[i].value=v;
                        break;
                    }

                }

            }
            flag =0;
            cnt++;
            cout<<"Do you want to insert another keys:"<<endl;
            cin>>ans;

        }while(ans=='y'||ans=='Y');
    }

    void display(){
        int i;
        cout<<"\n\t\tKey\tValue";
        for(i=0;i<10;i++){
            cout<<"\n\th["<<i<<"]\t"<<h[i].key<<"\t"<<h[i].value;

        }

    }
    void Delete(int k){

        int index = find(k);
        if (index==-1){
            cout<<"The key is not present in the table"<<endl;
        }
        else{
            h[index].key =-1;
            h[index].value=-1;
            cout<<"Key is deleted from table"<<endl;
        }
    }

    int find(int k){
        int i;
        for(i=0;i<10;i++){
            if(h[i].key==k){
                cout<<"\n\t"<<h[i].key<<" is Found at "<<i<<" Location With Value "<<h[i].value;
                return i;

            }

        }
        if (i==10){
            return -1;
        }
        

    }
};

int main(){

    int ch,k,index;
    char ans;
    HashFunction obj;
    do{
        cout<<"\n\t Dictionary (ADT) ";
        cout<<"\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
        cout<<"Enter your choice :"<<endl;
        cin>>ch;

        switch (ch){
            case 1: obj.insert();
				break;
			case 2:	obj.display();
                break;
            case 3: cout<<"\n\tEnter a Key Which You Want to Search: "<<endl;
                    cin>>k;
                    index=obj.find(k);
                    if(index==-1){
                        cout<<"key is not found "<<endl;
                    }
                    break;
            case 4: cout<<"\n\tEnter a Key Which You Want to Delete: "<<endl;
                    cin>>k;
                    obj.Delete(k);
                    break;

            case 5: 
            break;


        }
        cout<<"\n\t..... Do You Want to Continue in Main Menu: ";
        cin>>ans;



    } while(ans=='y'||ans=='Y');

    return 0;
}