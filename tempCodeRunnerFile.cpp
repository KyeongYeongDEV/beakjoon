
void print(int i){
    if(res[i] != 0){
        print(res[i]);
    }
    cout << arr[i] <<  ' ';
}