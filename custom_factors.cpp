#include "custom_factors.h"

using namespace std;

//per il prefix trie è buono bassp
int offset = 3;

void set_offset(int x){
    offset = x;
}

vector<int> get_custom_factor(vector<int>& icfl,int word_size){
    int j,z,custom_offset;
    vector<int> temp,res;

    //Il primo indice sarà sempre 0, possiamo iniziare da i=1.
    res.push_back(0);
    //per ogni fattore icfl
    for(int i=1;i<icfl.size();i++){
        //vedo se posso creare un suffisso artificiale
        for(j=1;i>0 && icfl[i]-(custom_offset*j) > icfl[i-1];j++)
            temp.push_back(icfl[i]-(custom_offset*j));
        
        //reverse
        for(z=temp.size()-1;z>=0;z--)
            res.push_back(temp[z]);
        //aggiungo quello canonico
        res.push_back(icfl[i]);
        temp.clear();
    }

    for(j=1;word_size-(offset*j) > icfl[icfl.size()-1];j++)
        temp.push_back(word_size-(offset*j));
    
    for(z=temp.size()-1;z>=0;z--)
        res.push_back(temp[z]);
    temp.clear();

    //printVec(res);
    //for(int i=0;i<word_size;i++){
    //    cout<<i<<" "<<check_if_custom_index(icfl,word_size,i)<<"\n";
    //}


    return res;
}

vector<int> get_custom_factor_random(vector<int>& icfl,int word_size){
    int j,z,custom_offset,current_size;
    vector<int> temp,res;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,offset); // distribution in range [1, offset]

    //Il primo indice sarà sempre 0, possiamo iniziare da i=1.
    res.push_back(0);
    //per ogni fattore icfl
    for(int i=1;i<icfl.size();i++){
        //vedo se posso creare un suffisso artificiale
        
        current_size=0;
    
        while(true){
            custom_offset=dist6(rng);
            current_size+=custom_offset;
            if(icfl[i]-current_size > icfl[i-1]) temp.push_back(icfl[i]-current_size);
            else break;
        }
        
        //reverse
        for(z=temp.size()-1;z>=0;z--)
            res.push_back(temp[z]);
        //aggiungo quello canonico
        res.push_back(icfl[i]);
        temp.clear();
    }

    for(j=1;word_size-(offset*j) > icfl[icfl.size()-1];j++)
        temp.push_back(word_size-(offset*j));
    
    for(z=temp.size()-1;z>=0;z--)
        res.push_back(temp[z]);
    temp.clear();

    //printVec(res);
    //for(int i=0;i<word_size;i++){
    //    cout<<i<<" "<<check_if_custom_index(icfl,word_size,i)<<"\n";
    //}


    return res;
}

bool check_if_custom_index(vector<int>& icfl,int word_size,int index){

    for(int i=1;i<icfl.size();i++){
        //cout<<"("<<icfl[i-1]<<","<<icfl[i]<<","<<index<<")";
        if(index>=icfl[i-1] && index<icfl[i]){
            if((icfl[i] - index) <= offset) return false;
        }
    }

    //cout<<"word_size: "<<word_size<<" index: "<<index<<" offset: "<<offset<<"\n";
    if((word_size - index) <= offset) return false;

    return true;


}

//si cerca un testimone per dire che l'inidice è canonico, ritorna true se non lo trova
bool check_if_custom_index_random(std::vector<int>& icfl,std::vector<int>& custom_icfl,int word_size,int index){


    for(int i=1;i<icfl.size();i++){
        //cout<<"("<<icfl[i-1]<<","<<icfl[i]<<","<<index<<")";
        if(index>=icfl[i-1] && index<icfl[i]){
            //a questo punto potrebbe essere canonico
            if((icfl[i] - index) <= offset){
                for(int temp_index=icfl[i]-1;temp_index>=index;temp_index--){
                    if(std::find(custom_icfl.begin(), custom_icfl.end(), temp_index) != custom_icfl.end())
                        return true;
                }
                return false;
            }
        }
    }

    //cout<<"word_size: "<<word_size<<" index: "<<index<<" offset: "<<offset<<"\n";
    if((word_size - index) <= offset) return false;

    return true;


}

bool check_if_normal_index(vector<int>& icfl,int word_size,int index){
    return !check_if_custom_index(icfl,word_size,index);
}

bool check_if_normal_index_random(std::vector<int>& icfl,std::vector<int>& custom_icfl,int word_size,int index){
    return !check_if_custom_index_random(icfl,custom_icfl,word_size,index);
}