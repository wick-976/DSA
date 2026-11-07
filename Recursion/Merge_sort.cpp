
void merge(vector<int> &arr,int low,int middle,int high)
{
    int left=low;
    int right=middle+1;
    vector<int>temp;

    while(left<=middle && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=middle)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void ms(vector<int> &arr,int low,int high)
{
    if(low>=high) return;

    int middle=(low+high)/2;

    ms(arr,low,middle);
    ms(arr,middle+1,high);
    merge(arr,low,middle,high);
}
void mergeSort(vector < int > & arr, int n) {
    ms(arr,0,n-1);
}