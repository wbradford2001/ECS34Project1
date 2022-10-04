#include "StringUtils.h"
#include <iostream>
#include <cctype>
#include <vector>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    int N = str.length();


    //if blank string
    if (N == 0){
        return "";
    }


    //End is more than last index
    if (end >=N){
        return "";
    }

    //negative end
    if (end<0){
        end=N+end;
    }  

    //make sure end is within bounts (cannot be N, max is N-1) 
    if (end>=N || end < 0){
        return "";
    }    
    //if end ==0
    if (end==0){
        end = N;
    }
    

    //negative start
    if (start<0){
        start=N+start;
    }

    //make sure start is within bounds(cannot be N, max is N-1)
    if (start>=N || start < 0){
        return "";
    }
  
  

    //populate return string 
    std::string out = "";
    for (int i=start; i< end; i++){
        out = out + str[i];
    }
    return out;
}

std::string Capitalize(const std::string &str) noexcept{
    int N = str.length();
    if (N==0){
        return "";
    }

    std::string Return = str;
    Return[0] = toupper(str[0]);

    return Return;
}

std::string Upper(const std::string &str) noexcept{
    int N = str.length();
    if (N==0){
        return "";
    }

    std::string ret = "";
    for (int i=0; i < N; i++){
        ret = ret + char(toupper(str[i]));
    }

    

    return ret;
}

std::string Lower(const std::string &str) noexcept{
    int N = str.length();
    if (N==0){
        return "";
    }

    std::string ret = "";
    for (int i=0; i < N; i++){
        ret = ret + char(tolower(str[i]));
    }

    

    return ret;
}

std::string LStrip(const std::string &str) noexcept{
    int N = str.length();
    if (N==0){
        return "";
    }

    int i = 0;
    while (i<N && isspace(str[i])){
        i += 1;
    }

    return StringUtils::Slice(str, i);
}

std::string RStrip(const std::string &str) noexcept{
    int N = str.length();

    if (N==0){
        return "";
    }

    int i = N-1;
    while (i>-1 && isspace(str[i])){
        i -= 1;
    }
    if (i==-1){
        return "";
    }
    i += 1;
    
    if (i==N){
        i=0;
    }
    return StringUtils::Slice(str, 0, i);
}

std::string Strip(const std::string &str) noexcept{
    return StringUtils::RStrip(StringUtils::LStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    int N = str.length();
    if (N==0){
        return "";
    }

    int subPointer = 0;
    int streak = 0;
    std::string ret = str;
    for (int i = 0; i < N; i++){
        if (str[i]==old[subPointer]){
            streak += 1;

            if (streak == old.length()){
                ret.replace(i-old.length()+1, old.length(), rep);
                
                
                streak  = 0;
                subPointer = 0;
            }
            subPointer+= 1;
        } else {
            subPointer = 0;
            streak = 0;
        }
    }
    return ret;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    int N = str.length();
    if (N==0){
        return {};
    }
    std::string dlim = splt;
    if (splt==""){
        dlim = " ";
    } 
    
    std::vector<std::string> vec;
    int l = 0;
    int r = 0;

    while (r < N){
        std::string s(1, str[r]);
        if (s == dlim){
            vec.push_back(StringUtils::Slice(str, l, r));
            l = r+1;
        }
        r += 1;
    }
    vec.push_back(StringUtils::Slice(str, l, 0));
    return vec;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string ret = "";
    int N =vect.size();
    for (int i=0; i< N; i++){
        ret = ret + vect[i];
        if (i != N-1){
            ret = ret + str;
        }
    }
    return ret;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};