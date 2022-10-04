#include <gtest/gtest.h>
#include "StringUtils.h"
#include <cstring>
#include <vector>
using namespace std;

TEST(StringUtilsTest, SliceTest){
    string str = "hellothere";
    ASSERT_EQ("hello",StringUtils::Slice(str, 0, 5));
    ASSERT_EQ("t",StringUtils::Slice(str, 5, 6));
    ASSERT_EQ("hellothere",StringUtils::Slice(str, 0, 0));
    ASSERT_EQ("there",StringUtils::Slice(str, 5, 0));

    string str2 = "myNameIsCalvin";
    ASSERT_EQ("myNameIsCalvin",StringUtils::Slice(str2, 0, 0));
    ASSERT_EQ("my",StringUtils::Slice(str2, 0, 2));
    ASSERT_EQ("IsCalvin",StringUtils::Slice(str2, 6));
    ASSERT_EQ("sCalvin",StringUtils::Slice(str2, 7));    
    ASSERT_EQ("",StringUtils::Slice(str2, 7, 7));
    
    ASSERT_EQ("myNameIsCalv",StringUtils::Slice(str2, 0, -2));
    ASSERT_EQ("ameIsCalvi",StringUtils::Slice(str2, 3, -1));
    ASSERT_EQ("sC",StringUtils::Slice(str2, 7, -5));    
    ASSERT_EQ("alvin",StringUtils::Slice(str2, -5));  

    string str3 = ""; 
    ASSERT_EQ("",StringUtils::Slice(str3, 1, 2));

    string str4 = "short";     
    ASSERT_EQ("hort",StringUtils::Slice(str4, 1, 100));
    ASSERT_EQ("",StringUtils::Slice(str4, 100, 1));
    ASSERT_EQ("",StringUtils::Slice(str4, 1, -100));
    ASSERT_EQ("",StringUtils::Slice(str4, -100, -1));

    string str5 = "hey";     
    ASSERT_EQ("ey",StringUtils::Slice(str5, 1, 3));
    ASSERT_EQ("hey",StringUtils::Slice(str5, 0, 4));
    ASSERT_EQ("hey",StringUtils::Slice(str5, 0, 10));    
    ASSERT_EQ("",StringUtils::Slice(str5, 5, 8));
   
   
}

TEST(StringUtilsTest, Capitalize){
    string str = "hello";
    ASSERT_EQ("Hello",StringUtils::Capitalize(str));

    string str2 = "Goodbye";
    ASSERT_EQ("Goodbye",StringUtils::Capitalize(str2));    

    string str3 = "dfgdfklgn";
    ASSERT_EQ("Dfgdfklgn",StringUtils::Capitalize(str3));  

    string str4 = "";
    ASSERT_EQ("",StringUtils::Capitalize(str4));      

    string str5 = " ";
    ASSERT_EQ(" ",StringUtils::Capitalize(str5));   

    string str6 = " .";
    ASSERT_EQ(" .",StringUtils::Capitalize(str6));            

}

TEST(StringUtilsTest, Upper){

    string str = "ubuntu";
    ASSERT_EQ("UBUNTU",StringUtils::Upper(str));      

    string str2 = "Protein";
    ASSERT_EQ("PROTEIN",StringUtils::Upper(str2));     

    string str3 = "CANDy";
    ASSERT_EQ("CANDY",StringUtils::Upper(str3));   

    string str4 = "";
    ASSERT_EQ("",StringUtils::Upper(str4));   

    string str5 = " ";
    ASSERT_EQ(" ",StringUtils::Upper(str5));     

    
    
}

TEST(StringUtilsTest, Lower){
    string str = "THIS WILL BE LOWER";
    ASSERT_EQ("this will be lower",StringUtils::Lower(str));      

    string str2 = "sfgFR";
    ASSERT_EQ("sfgfr",StringUtils::Lower(str2));    

    string str3 = "";
    ASSERT_EQ("",StringUtils::Lower(str3));        
}

TEST(StringUtilsTest, LStrip){
    string str = "  Hello  ";
    ASSERT_EQ("Hello  ",StringUtils::LStrip(str));       

    string str2 = "Hello  ";
    ASSERT_EQ("Hello  ",StringUtils::LStrip(str2));    

    string str3 = "         Hello  ";
    ASSERT_EQ("Hello  ",StringUtils::LStrip(str3));      

    string str4 = "  ";
    ASSERT_EQ("",StringUtils::LStrip(str4));         

    string str5 = "";
    ASSERT_EQ("",StringUtils::LStrip(str5));      
}

TEST(StringUtilsTest, RStrip){
    string str = "  Hello  ";
    ASSERT_EQ("  Hello",StringUtils::RStrip(str));       

    string str2 = "Hello";
    ASSERT_EQ("Hello",StringUtils::RStrip(str2));    

    string str3 = "Hello  ";
    ASSERT_EQ("Hello",StringUtils::RStrip(str3));      

    string str4 = "  ";
    ASSERT_EQ("",StringUtils::RStrip(str4));         

    string str5 = "";
    ASSERT_EQ("",StringUtils::RStrip(str5));     
    
}

TEST(StringUtilsTest, Strip){
    string str = "  Hello  ";
    ASSERT_EQ("Hello",StringUtils::Strip(str));       

    string str2 = "Hello";
    ASSERT_EQ("Hello",StringUtils::Strip(str2));    

    string str3 = "Hello  ";
    ASSERT_EQ("Hello",StringUtils::Strip(str3));      

    string str4 = "    How is it going?  ";
    ASSERT_EQ("How is it going?",StringUtils::Strip(str4));       

    string str5 = "  ";
    ASSERT_EQ("",StringUtils::Strip(str5));         

    string str6 = "";
    ASSERT_EQ("",StringUtils::Strip(str6));       
    
}

TEST(StringUtilsTest, Center){
    string str = "Hello";
    
    ASSERT_EQ("__Hello___",StringUtils::Center(str, 10, '_')); 
    ASSERT_EQ("**Hello***",StringUtils::Center(str, 10, '*')); 
    ASSERT_EQ("***Hello****",StringUtils::Center(str, 12, '*'));         

    str = "Hello";
    ASSERT_EQ("   Hello    ",StringUtils::Center(str, 12, ' '));    

    str = "Hello";
    ASSERT_EQ("    Hello     ",StringUtils::Center(str, 14));   
    str = "Hello";
    ASSERT_EQ("Hello ",StringUtils::Center(str, 6));             

    str = "L";
    ASSERT_EQ(" L ",StringUtils::Center(str, 3));   

    str = "RightJustifyMe";
    ASSERT_EQ("RightJustifyMe",StringUtils::Center(str, 3));   

    str = "Rig";
    ASSERT_EQ("Rig",StringUtils::Center(str, 3));  

    str = "";
    ASSERT_EQ("",StringUtils::Center(str, 3));
}

TEST(StringUtilsTest, LJust){
    
    string str = "Hello";
    
    ASSERT_EQ("_____Hello",StringUtils::LJust(str, 10, '_')); 
    ASSERT_EQ("*****Hello",StringUtils::LJust(str, 10, '*'));     

    str = "Hello";
    ASSERT_EQ("       Hello",StringUtils::LJust(str, 12, ' '));    

    str = "Hello";
    ASSERT_EQ("         Hello",StringUtils::LJust(str, 14));       

    str = "L";
    ASSERT_EQ("  L",StringUtils::LJust(str, 3));   

    str = "LeftJustifyMe";
    ASSERT_EQ("LeftJustifyMe",StringUtils::LJust(str, 3));   

    str = "Lef";
    ASSERT_EQ("Lef",StringUtils::LJust(str, 3));  

    str = "";
    ASSERT_EQ("",StringUtils::LJust(str, 3));                     
}

TEST(StringUtilsTest, RJust){

    string str = "Hello";
    
    ASSERT_EQ("Hello_____",StringUtils::RJust(str, 10, '_')); 
    ASSERT_EQ("Hello*****",StringUtils::RJust(str, 10, '*')); 
    ASSERT_EQ("Hello*******",StringUtils::RJust(str, 12, '*'));         

    str = "Hello";
    ASSERT_EQ("Hello       ",StringUtils::RJust(str, 12, ' '));    

    str = "Hello";
    ASSERT_EQ("Hello         ",StringUtils::RJust(str, 14));       

    str = "L";
    ASSERT_EQ("L  ",StringUtils::RJust(str, 3));   

    str = "RightJustifyMe";
    ASSERT_EQ("RightJustifyMe",StringUtils::RJust(str, 3));   

    str = "Rig";
    ASSERT_EQ("Rig",StringUtils::RJust(str, 3));  

    str = "";
    ASSERT_EQ("",StringUtils::RJust(str, 3));      
    
}

TEST(StringUtilsTest, Replace){
    string str = "hello there buddy";
    string old = "there";
    string replace = "sdfh";        
    ASSERT_EQ("hello sdfh buddy",StringUtils::Replace(str, old, replace)); 

    string str2 = "there buddy";
    string old2 = "there";
    string replace2 = "sdfh";        
    ASSERT_EQ("sdfh buddy",StringUtils::Replace(str2, old2, replace2)); 

    string str3 = "there buddy";
    string old3 = "buddy";
    string replace3 = "sdfh";        
    ASSERT_EQ("there sdfh",StringUtils::Replace(str3, old3, replace3));   

    string str4 = "hello there buddy";
    string old4 = "hhhhh";
    string replace4 = "sdfh";        
    ASSERT_EQ("hello there buddy",StringUtils::Replace(str4, old4, replace4)); 

    string str5 = "hello there buddy";
    string old5 = "h";
    string replace5 = "x";        
    ASSERT_EQ("xello txere buddy",StringUtils::Replace(str5, old5, replace5));    

    string str6 = "";
    string old6 = "h";
    string replace6 = "x";        
    ASSERT_EQ("",StringUtils::Replace(str6, old6, replace6));       


}

TEST(StringUtilsTest, Split){
    string str = "hello,there,pal";   
    vector<string> vec = {"hello", "there", "pal"};
    ASSERT_EQ(vec,StringUtils::Split(str, ","));    

    string str2 = "hello there pal";   
    vector<string> vec2 = {"hello", "there", "pal"};
    ASSERT_EQ(vec2,StringUtils::Split(str2, "")); 

    string str3 = "hello there pal";   
    vector<string> vec3 = {"hello", "there", "pal"};
    ASSERT_EQ(vec3,StringUtils::Split(str3, " "));  

    string str4 = "how;are;you;doing;today";   
    vector<string> vec4 = {"how", "are", "you", "doing", "today"};
    ASSERT_EQ(vec4,StringUtils::Split(str4, ";"));      

    string str5 = "how;are;you;doing;today";   
    vector<string> vec5 = {"how;are;you;doing;today"};
    ASSERT_EQ(vec5,StringUtils::Split(str5, "l"));   

    string str6 = "";   
    vector<string> vec6 = {};
    ASSERT_EQ(vec6,StringUtils::Split(str6, ""));            
}

TEST(StringUtilsTest, Join){
    string str = "hello,there,pal";   
    vector<string> vec = {"hello", "there", "pal"};
    ASSERT_EQ(str,StringUtils::Join(",",vec));    

    string str2 = "hellotherepal";   
    vector<string> vec2 = {"hello", "there", "pal"};
    ASSERT_EQ(str2,StringUtils::Join("", vec2)); 

    string str3 = "hello there pal";   
    vector<string> vec3 = {"hello", "there", "pal"};
    ASSERT_EQ(str3,StringUtils::Join(" ",vec3));  

    string str4 = "how;are;you;doing;today";   
    vector<string> vec4 = {"how", "are", "you", "doing", "today"};
    ASSERT_EQ(str4,StringUtils::Join(";",vec4));      
 

    string str6 = "";   
    vector<string> vec6 = {};
    ASSERT_EQ(str6,StringUtils::Join("", vec6));      
}

TEST(StringUtilsTest, ExpandTabs){
    string str = "hello there   pal";   
    ASSERT_EQ("hello    there    pal",StringUtils::ExpandTabs(str));    

    str = "hey there   pal";   
    ASSERT_EQ("hello   there   pal",StringUtils::ExpandTabs(str, 3)); 

    str = "my    name    is  Calvin";   
    ASSERT_EQ("my   name   is   Calvin",StringUtils::ExpandTabs(str, 3));  

    str = "my    name    is  Calvin";   
    ASSERT_EQ("my    name    is    Calvin",StringUtils::ExpandTabs(str));

    str = "I Went    To  The Store";   
    ASSERT_EQ("I  Went  To  The  Store",StringUtils::ExpandTabs(str,2));   

    str = "";   
    ASSERT_EQ("",StringUtils::ExpandTabs(str,2));                         
}

TEST(StringUtilsTest, EditDistance){
    
}
