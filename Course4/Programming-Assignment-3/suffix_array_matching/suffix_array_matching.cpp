#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define NUM_CHARS 5

int letterToIndex (char letter)
{
  switch (letter)
  { 
    case '$': return 0; break;
    case 'A': return 1; break;
    case 'C': return 2; break;
    case 'G': return 3; break;
    case 'T': return 4; break;
    default: assert (false); return -1;
  }
}

void sort_chars(string& S,std::vector<int>& order){
  // std::vector<int> order(S.length(),0);
  std::vector<int> count(NUM_CHARS,0);

  for(int i =0;i<S.length();i++){
    count[letterToIndex(S[i])]++;
  }

  for(int i =1;i<NUM_CHARS;i++){
    count[i] += count[i-1];
  }

  for(int i = S.length() - 1;i>=0;i--){
    
    int idx = letterToIndex(S[i]);
    count[idx]--;
    order[count[idx]] = i;
  }



}
// bool custom_cmp(string& a, string& b,int start_idx){
//   int len = b.length() - start_idx;
//   if(a.length()>len){
    
//     for(int i =0;i<len;i++){
//       while(a[i]==b[start_idx+i])
//         i++;
//       return a[i]> b[start_idx+i];
//     }
//   }
//   else{
//     for(int i =0;i<a.length();i++){
//       while(a[i]==b[start_idx+i])
//         i++;
//       return a[i]> b[start_idx+i];
//     }

//   }

// }

void compute_class(string& S, std::vector<int>& order,std::vector<int>& classes){
  // std::vector<int> classes(S.length(),0);
  classes[order[0]] = 0;

  for(int i =1;i<S.length();i++){
    if( S[order[i]] != S[order[i-1]] )
    classes[order[i]] = classes[order[i-1]] +1;
    else
      classes[order[i]] = classes[order[i-1]];
  }

  // return classes;
}

std::vector<int> sort_doubled(string& S,int L,std::vector<int>& order,std::vector<int>& classes
          ){

  std::vector<int> count(S.length(),0);
  std::vector<int> newOrder(S.length(),0);
  for(int i =0;i<S.length();i++){
    count[classes[i]]++;
  }
  for(int i =1;i<S.length();i++)
    count[i] += count[i-1];

  for(int i = S.length()-1;i>=0;i--){

    int start = (order[i]-L+ S.length()) % S.length();
    int cl = classes[start];
    count[cl]--;
    newOrder[count[cl]] = start;
  }
  return newOrder;
}

std::vector<int> update_class(std::vector<int>& newOrder,
              std::vector<int>& classes, int L){

  int n = newOrder.size();
  std::vector<int> newClass(n,0);
  newClass[newOrder[0]] = 0;
  int curr,prev,mid,midPrev;
  for(int i =1;i<n;i++){
     curr = newOrder[i];
     prev = newOrder[i-1];
     mid = (curr +L)%n;
     midPrev = (prev+L)%n;

     if(classes[curr] != classes[prev] || classes[mid] != classes[midPrev] )
      newClass[curr] = newClass[prev]+1;
     else
      newClass[curr] = newClass[prev];

  }
  return newClass;
}

vector<int> BuildSuffixArray( string& text) {
  // vector<int> result;
  // Implement this function yourself
  std::vector<int> order(text.length(),0);
  sort_chars(text,order);
  // cout<<"order done "<<endl;

  std::vector<int> classes(text.length(),0);
  compute_class(text,order,classes);
  // cout<<"compute_class done "<<endl;
  int L = 1;

  while( L < text.length()){
    // cout<<" curr L is "<<L<<endl;
    order = sort_doubled(text,L,order,classes);
    // cout<<"sort_doubled done "<<endl;
    classes = update_class(order,classes,L);
    // cout<<"update_class done "<<endl;
    L = L*2;
  }
  // cout<<"while ended "<<endl;
  // for(auto x:order)
  //  cout<<x<<" ";
  // cout<<endl;
  return order;
}

vector<int> FindOccurrences( string& pattern,  string& text, vector<int>& suffix_array) {
  vector<int> result;
  std::vector<int> order;
  order = BuildSuffixArray(text);
  // pattern +='$';
  int minIdx = 0;
  int maxIdx = text.length();
  int midIdx;
  // reverse(suffix_array.begin(),suffix_array.end());
  // for(auto x:suffix_array)
  //   cout<<x<<" ";
  // cout<<endl;
  while(minIdx<maxIdx){

    midIdx = int((minIdx+maxIdx)/2);
    // cout<<minIdx<<"-"<<midIdx<<"="<<suffix_array[midIdx]<<"-"<<maxIdx<<" "<<pattern<<" "<<text.substr(suffix_array[midIdx])<<endl;
    if( strncmp(pattern.c_str(),&(text[suffix_array[midIdx]]),pattern.size()) > 0){
    // if( custom_cmp(pattern,text,suffix_array[midIdx])){
    // if( text.substr(suffix_array[midIdx]).compare(pattern) > 0){
      // cout<<"in"<<endl;
      minIdx = midIdx +1;
    }
    else
      maxIdx = midIdx;
  }
  int start = minIdx;
  // cout<<start<<endl;

  maxIdx = text.length();


  while(minIdx<maxIdx){




    midIdx = int((minIdx+maxIdx)/2);
    
    // cout<<minIdx<<"-"<<midIdx<<"="<<suffix_array[midIdx]<<"-"<<maxIdx<<" "<<pattern<<" "<<text.substr(suffix_array[midIdx])<<endl;
    if( strncmp(pattern.c_str(),&(text[suffix_array[midIdx]]),pattern.size()) < 0){
    // if( !custom_cmp(pattern,text,suffix_array[midIdx]) ){
      maxIdx = midIdx;
      // cout<<"in"<<endl;

    }
    
    else{
      minIdx = midIdx+1;
    }

    

  }
  // cout<<"success"<<endl;
  int end = maxIdx;

  if(start>end)
    return result;
  else{

    for(int i = start;i<end;i++){
      // cout<<suffix_array[i]<<" ";
      result.push_back(suffix_array[i]);
    }
    // cout<<endl;

  }

  // write your code here

  return result;
  
}

int main() {
  char buffer[100001];
  scanf("%s", buffer);
  string text = buffer;
  text += '$';
  vector<int> suffix_array = BuildSuffixArray(text);
  int pattern_count;
  scanf("%d", &pattern_count);
  vector<bool> occurs(text.length(), false);
  for (int pattern_index = 0; pattern_index < pattern_count; ++pattern_index) {
    scanf("%s", buffer);
    string pattern = buffer;
    vector<int> occurrences = FindOccurrences(pattern, text, suffix_array);
    for (int j = 0; j < occurrences.size(); ++j) {
      occurs[occurrences[j]] = true;
    }
  }
  for (int i = 0; i < occurs.size(); ++i) {
    if (occurs[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
