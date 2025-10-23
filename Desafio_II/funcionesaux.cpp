#include "funcionesaux.h"

int verificarPremium(char &pre){
    while(pre!='0' && pre!='1'){
        cout<<"Ingrese una opcion correcta:"<<endl;
        cin>>pre;
    }
    int num=pre-'0';
    return num;
}
