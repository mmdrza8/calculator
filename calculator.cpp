// HEADER FILES :
#include <iostream>
#include <math.h>
#include <sstream> //for converting int-array to  string...
#include <stdlib.h> // for system function
#include <cstdlib>  // for system function
#include <conio.h>//for stoi() function

using namespace std;

//---------------------------------------------------------------------------------------------------------------------

// FUNCTIONS :
string ar_to_s(int num[],int len); //CONVERT INT-ARRAY TO STRING...

string mySum(string str1,string str2); //JAAM +
string mySub(string str1,string str2); //TAFRIGH -
string myMul(string str1,string str2); //ZARB *
string myDiv(string &str1,string &str2);//TAGHSIM /
string myMod(string &str1,string &str2);//BAGHIMANDE %
string myPow(string str1,string n);//TAVAN ^

int compare(string str1,string str2);//MOGHAYESEH

string addZero_L(string &str1,int n); //EZAFE KARDAN "0" BE SAMT CHAP HAR ADAD
string addZero_R(string &str1,int n); //EZAFE KARDAN "0" BE SAMT RAST HAR ADAD
string addDot(string &str1, int pos);//EZAFE KARDAN "."
string addNeg(string str1);//EZAFE KARDAN MANFI "-"

string remZero_L(string &str1);//HAZF "0"HAYE SAMT CHAP ADAD
string remZero_R(string &str1);//HAZF "0"HAYE SAMT RAST ADAD
string remDot(string &str1);//HAZF '.'
string remSign(string &str1);//HAZF ALAMAT

bool isNegative(string str1);//TASHKHIS ALAMAT
bool isDecimal(string str1);//TASHKHIS ASHARI
bool isInvalidInput(string str1);//TASHKHIS ETEBAR VORUDI

string corToDec(string &str1);//TABDIL ADAD SAHIH BE ASHARI
string extractCor(string &str1);//JODA SAZI GHESMAT SAHIH
string extractDec(string str1);//JODA SAZI GHESMAT ASHARI

void printStar(); // 1 KHAT * CHAP MIKONAD
void printPreface(); // MOGHADAME RA CHAP MIKONAD

//---------------------------------------------------------------------------------------------------------------------

//CONVERT INT-ARRAY TO STRING... :
string ar_to_s(int num[],int len){
    ostringstream os;
    for (int i=0;i<len;i++){
        os<<num[i];
    }
    string str(os.str());
    return str;
}

//---------------------------------------------------------------------------------------------------------------------

//JAAM :
string mySum(string str1,string str2){
    int sum=0;
    int num1[200]={0};
    int num2[200]={0};
    string str3;

    for (int i=0;i<str1.length();i++) //tabdil str1 be araye addi
        num1[i]=str1[i]-'0';
    for (int i=0;i<str2.length();i++) //tabdil str2 be araye addi
        num2[i]=str2[i]-'0';

    for (int i=1;i<=str1.length();i++){
        sum=num1[str1.length()-i]+num2[str2.length()-i];
        if (sum>=10){
            num2[str2.length()-i]=sum-10;
            num2[str2.length()-i-1]+=1;
        }
        else
            num2[str2.length()-i]=sum;
    }
    str3=ar_to_s(num2,str2.length()); //tabdil araye be string
    return str3;
}
//---------------------------------------------------------------------------------------------------------------------

//TAFRIG :
string mySub(string str1,string str2){
    int sub=0;
    int num1[200]={0};
    int num2[200]={0};
    string str3;

    for (int i=0;i<str1.length();i++) //tabdil str1 be araye addi
        num1[i]=str1[i]-'0';
    for (int i=0;i<str2.length();i++) //tabdil str2 be araye addi
        num2[i]=str2[i]-'0';

    for (int i=1;i<=str1.length();i++){
        sub=num1[str1.length()-i]-num2[str2.length()-i];
        if (sub<0){
            num2[str2.length()-i]=sub+10;
            num1[str1.length()-i-1]-=1;
        }
        else
            num2[str2.length()-i]=sub;
    }
    str3=ar_to_s(num2,str2.length()); //tabdil araye be string
    return str3;
}
//---------------------------------------------------------------------------------------------------------------------

//ZARB :
string myMul(string str1,string str2){
    int z;
    int num1[200]={0};
    int num2[200]={0};
    int zarb[400]={0};
    string str3;

    for (int i=0;i<str1.length();i++) //tabdil str1 be araye adadi
        num1[i]=str1[i]-'0';
    for (int i=0;i<str2.length();i++) //tabdil str2 be araye adadi
        num2[i]=str2[i]-'0';

    for (int i=0;i<str2.length();i++){
        for (int j=1;j<=str1.length();j++){
            z=num2[str2.length()-i-1]*num1[str1.length()-j];
            zarb[str1.length()+str2.length()-j-i]+=z%10;
            zarb[str1.length()+str2.length()-j-i-1]+=z/10;
            if (zarb[str1.length()+str2.length()-j-i]>=10){
                zarb[str1.length()+str2.length()-j-i-1]+=zarb[str1.length()+str2.length()-j-i]/10;
                zarb[str1.length()+str2.length()-j-i]=zarb[str1.length()+str2.length()-j-i]%10;
            }
        }
    }
    str3=ar_to_s(zarb,str1.length()+str2.length()); //tabdil araye be string
    return str3;
}
//---------------------------------------------------------------------------------------------------------------------

//TAVAN :
string myPow(string str1,string n){
    string p="1";

    p=addZero_L(p,str1.length()-1); //yeksan kardan size paye va p

    for (int i=0;i<stoi(n);i++){
        p=myMul(str1,p);
    }
    return p;
}
//---------------------------------------------------------------------------------------------------------------------

//TAGHSIM :
string myDiv(string &str1,string &str2){
    string count1="000000000000000000000000000000000000000000";
    string s1="000000000000000000000000000000000000000001";
    string org2,rstr1;
    int d,n;

    str1=addZero_R(str1,10); //30 sefr be manzoor 30 raqam ashar

    org2=str2; // negah dashtan noskhe asli maqsoom elaih

    d=str1.length()-str2.length();
    str2=addZero_R(str2,d); //yeksan kardan size do adad

    s1=addZero_R(s1,d);
    count1=addZero_L(count1,s1.length()-count1.length()); //yeksan kardan size 1 , 0


    while (compare(org2,str2)!=1){
        while (compare(str1,str2)!=2){
            str1=mySub(str1,str2);
            count1=mySum(count1,s1);
        }
        str2.erase(str2.length()-1,1);
        s1.erase(s1.length()-1,1);
        if (count1[0]=='0')
            count1.erase(0,1);
    }
    return count1;
}
//---------------------------------------------------------------------------------------------------------------------

//BAGHIMANDE :
string myMod(string &str1,string &str2){
    string org2;

    org2=str2;
    str2=addZero_R(str2,str1.length()-str2.length());

    while (compare(org2,str2)!=1){
        while (compare(str1,str2)!=2){
            str1=mySub(str1,str2);
        }
        str2.erase(str2.length()-1,1);
    }
    return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//MOGHAYESEH DO ADAD :
int compare(string str1,string str2){
    if (str1.length()>str2.length())
        return 1;
    else if (str1.length()<str2.length())
        return 2;
    else {
        if (str1>str2)
            return 1;
        else if (str1<str2)
            return 2;
        else
            return 0;
    }
}
//---------------------------------------------------------------------------------------------------------------------

//EZAFE KARDAN "0" BE SAMT CHAP HAR ADAD :
string addZero_L(string &str1,int n){
    string s1="0";
    for (int i=1;i<=n;i++){
        str1.insert(0,s1);
    }
    return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//EZAFE KARDAN "0" BE SAMT RAST HAR ADAD :
string addZero_R(string &str1,int n){
    string s1="0";
    int len1;
    len1=str1.length();
    for (int i=1;i<=n;i++){
        str1.insert(len1,s1);
    }
    return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//TASHKHIS ALAMAT :
bool isNegative(string str1){
    if (str1[0]=='-')
        return 1;
    else
        return 0;
}
//---------------------------------------------------------------------------------------------------------------------

//TASHKHIS ASHARI :
bool isDecimal(string str1){
    int j=0;
    for (int i=0;i<str1.length();i++){
        if (str1[i]=='.')
            j=1;
    }
    if (j==0)
        return 0;
    else
        return 1;
}
//---------------------------------------------------------------------------------------------------------------------

//HAZF ALAMAT :
string remSign(string &str1){
    if (str1[0]=='-' || str1[0]=='+'){
        str1.erase(0,1);
        return str1;
    }
    else
        return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//HAZF NOGHTEH '.' :
string remDot(string &str1){
    int pos;
    if (isDecimal(str1)==1){
        pos=str1.find(".");
        str1.erase(pos,1);
    }
    return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//ESTEKHRAJ GHESMAT SAHIH :
string extractCor(string &str1){
    string str2;
    int num2[300];
    int i=0;
    if (isDecimal(str1)==1){
        while (str1[i]!='.'){
            num2[i]=str1[i]-'0';
            i++;
        }
        str2=ar_to_s(num2,i);
        return str2;
    }
    else
        return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//ESTEKHRAJ GHESMAT ASHARI :
string extractDec(string str1){
    string str2;
    int num2[300];
    int pos,i=0;
    pos=str1.find(".");
    if (isDecimal(str1)==1){
        while (i<str1.length()-pos-1){
            num2[i]=str1[pos+i+1]-'0';
            i++;
        }
        str2=ar_to_s(num2,i);
        return str2;
    }
    else
        return "0";
}
//---------------------------------------------------------------------------------------------------------------------

//GOZASHTAN NOGHTEH PAS AZ MOHASEBAT :
string addDot(string &str1, int pos){
    str1.insert(str1.length()-pos,".");

    return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//GOZASHTAN MANFI DAR AVAL ADAD :
string addNeg(string str1){
    string str2="-";

    str2.insert(1,str1);
    return str2;
}
//---------------------------------------------------------------------------------------------------------------------

//PAK KARDAN SEFR HAYE CHAP ADAD :
string remZero_L(string &str1){
    for (int i=0;i<str1.length();i++){
        if (str1[0]=='0')
            str1.erase(0,1);
        else
            break;
    }
    return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//PAK KARDAN SEFR HAYE RAST ADAD :
string remZero_R(string &str1){
    for (int i=0;i<str1.length();i++){
        if (str1[str1.length()-1]=='0')
            str1.erase(str1.length()-1,1);
        else
            break;
    }
    return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//TABDIL BE ASHARI :
string corToDec(string &str1){

    if (isDecimal(str1)==0){
        str1=addDot(str1,0);
        str1=addZero_R(str1,2);
    }
    return str1;
}
//---------------------------------------------------------------------------------------------------------------------

//KHATA GEREFTAN AZ VORUDI :
bool isInvalidInput(string str1){
    int j=0;

    for (int i=0;i<str1.length();i++){
        if ( str1[i]<'0' || str1[i]>'9'){
            j=1;
            break;}
    }
    if (j==1)
        return 1;
    else
        return 0;
}
//---------------------------------------------------------------------------------------------------------------------

//CHAP 1 KHAT * :
void printStar(){

    cout << "********************************************************************************\n";
}
//---------------------------------------------------------------------------------------------------------------------

//CHAP DASTURE KAR AVAL BARNAME :
void printPreface(){

    cout << "                                  ...WELCOME...                                 \n";
    printStar();
    cout << "   INPUT ALGORITHM :\t\t number1 ... number2=\n\n";
    cout << "   \tJAAM :  +\n\tTAFRIGH :  -\n\tZARB :  *\n\tTAGHSIM :  /\n\tBAGHIMANDE :  % --> (...har 2 adad bayad sahih bashand...)\n\tTAVAN :  ^ --> (...tavan bayad sahih bashad...)\n";
    printStar();
}
//---------------------------------------------------------------------------------------------------------------------

int main(){

    system("color F0");       //taghir rang consul

    char ch='0';
    string str1,str2,str3,op,org1,org2,cor1,cor2,dec1,dec2,sum,sub,mul,pow,div,mod,result;
    bool sign1,sign2,iv1,iv2;
    int max_ash,i=0;


    printPreface();          //chaap moghadame

    while (ch!=27){

        cout <<"\tSTART...\n\n\t";

        getline(cin,str1,' ');     //gereftan argham az karbar
        getline(cin,op,' ');       //gereftan operator az karbar
        getline(cin,str2,'=');     //gereftan argham az karbar

        org1=str1;
        org2=str2;

        if (op!="^" && op!="%" && op!="/" && op!="*"){ //agar operator tavan, baghimande va taghsim nabashad:
            str1=corToDec(str1);            //tabdil add sahih be ashari str1
            str2=corToDec(str2);}           //tabdil add sahih be ashari str2

        sign1=isNegative(str1);             //taeen alamat str1
        sign2=isNegative(str2);             //taeen alamat str2
        str1=remSign(str1);                 //hazf alamat str1
        str2=remSign(str2);                 //hazf alamat str2

        cor1=extractCor(str1);              //jadasazi ghesmat sahih str1
        cor2=extractCor(str2);              //jodasazi ghesmat sahih str2
        dec1=extractDec(str1);              //jodasazi ghesmat ashari str1
        dec2=extractDec(str2);              //jodasazi ghesmat ashari str2

        if (op!="/" && op!="%"){            //agar operator taghsim va baghimande nabashad:

            max_ash=dec1.length();          //moshakhas kardan tedad ashar
            if (cor1.length()>cor2.length())
                str2=addZero_L(str2,cor1.length()-cor2.length());    //ezafe kardan sefr az chap
            if (cor1.length()<cor2.length())
                str1=addZero_L(str1,cor2.length()-cor1.length());    //ezafe kardan sefr az chap
            if (dec1.length()>dec2.length()){
                str2=addZero_R(str2,dec1.length()-dec2.length());    //ezafe kardan sefr az rast
                max_ash=dec1.length();}
            if (dec1.length()<dec2.length()){
                str1=addZero_R(str1,dec2.length()-dec1.length());    //ezafe kardan sefr az rast
                max_ash=dec2.length();}
        }

        str1=remDot(str1);                  //hazf noghte sr1
        str2=remDot(str2);                  //hazf noghte str2

        iv1=isInvalidInput(str1);           //tashkhis error input str1
        iv2=isInvalidInput(str2);           //tashhis error input str2

        if (i!=0)
            str2.erase(0,3);

        if (i!=0)
                str1.erase(0,1);

        if ((iv2==1 || iv1==1)&&i==0){
            cout << "\t<...INVALID INPUT...>\n" << "\a";
            printStar();
            continue;
        }

        if (op=="+"){
            if (sign1==0 && sign2==0){          //vared kardan do ad mosabt :
                sum=mySum(str1,str2);           //jam karden
                sum=addDot(sum,max_ash);        //ezafe kardan noghte
                sum=remZero_R(sum);             //hazf sefrhaye bi manii az rast
                result=remZero_L(sum);}         //hazf sefrhaye bi manii az chap
            else if (sign1==1 && sign2==1){     //vared kardan do add manfi :
                sum=mySum(str1,str2);           //jam kardan
                sum=addDot(sum,max_ash);        //ezafe kardan noghte
                sum=remZero_R(sum);             //hazf sefrhaye bi manii az rast
                sum=remZero_L(sum);             //hazf sefrhaye bi manii az chap
                result=addNeg(sum);}            //ezafe kardan manfi be add
            else if (sign1==0 && sign2==1){     //vared kardan do add mosbat va manfi
                if (cor1.length()>=cor2.length()){      //check kardan tool ghesmat sahih adaad :
                    sub=mySub(str1,str2);       //tafrigh kardan
                    sub=addDot(sub,max_ash);    //ezafe krdan noghte
                    sub=remZero_R(sub);         //hazf sefrhaye bi manii az rast
                    result=remZero_L(sub);}     //hazf sefrhaye bi manii az chap
                else{
                    sub=mySub(str2,str1);       //tafrigh kardan
                    sub=addDot(sub,max_ash);    //ezafe kardan noghte
                    sub=remZero_R(sub);         //hazf sefrhaye bi manii az rast
                    sub=remZero_L(sub);         //hazf sefrhaye bi manii az chap
                    result=addNeg(sub);}}       //ezafe kardan manfi
            else if (sign1==1 && sign2==0){     //vared kardan do add manfi va mosbat
                if (cor2.length()>=cor1.length()){     //check kardan tool ghesmat sahih adaad :
                    sub=mySub(str2,str1);       //tafrigh kardan
                    sub=addDot(sub,max_ash);    //ezafe kardan noghte
                    sub=remZero_R(sub);         //hazf sefrhaye bi manii az rast
                    result=remZero_L(sub);}     //hazf zefrhaye bi manii az chap
                else{
                    sub=mySub(str1,str2);       //tafrigh kardan
                    sub=addDot(sub,max_ash);    //ezafe kardan noghte
                    sub=remZero_R(sub);         //hazf sefrhaye bi manii az rast
                    sub=remZero_L(sub);         //hazf sefrhaye bi manii az chap
                    result=addNeg(sub);}}       //ezafe kardan manfi be adad
        }
        else if (op=="-"){                      //agar operator menha bood:
            if (sign1==0 && sign2==1){          //vared kardan do add mosbat va manfi
                sum=mySum(str1,str2);           //jam kardan
                sum=addDot(sum,max_ash);        //ezafe kardan noghte
                sum=remZero_R(sum);             //hazf sefrhaye bi manii az rast
                result=remZero_L(sum);}         //hazf sefrhaye bi manii az chap
            else if (sign1==1 && sign2==0){     //vaed kardan do add manfi va mosbat
                sum=mySum(str1,str2);           //jam kardan
                sum=addDot(sum,max_ash);        //ezafe kardan noghte
                sum=remZero_R(sum);             //hazf sefrhaye bi manii az rast
                sum=remZero_L(sum);             //hazf sefrhaye bi manii az chap
                result=addNeg(sum);}            //ezafe kardan manfi be add
            else if (sign1==0 && sign2==0){     //vared kardan do add mosbat:
                if (compare(cor1,cor2)!=2){     //moghayse ghesmat sahih do add
                    sub=mySub(str1,str2);       //tafrigh kardan
                    sub=addDot(sub,max_ash);    //ezafe kardan noghte
                    sub=remZero_R(sub);         //hazf sfrhaye bi manii az rast
                    result=remZero_L(sub);}     //hazf sefrhaye bi manii az chap
                else{
                    sub=mySub(str2,str1);       //tafrigh kardan
                    sub=addDot(sub,max_ash);    //ezafe kardan noghte
                    sub=remZero_R(sub);         //hazf sfrhaye bi manii az rast
                    sub=remZero_L(sub);         //hazf sefrhaye bi manii az chap
                    result=addNeg(sub);}}       //ezafe kardan manfi be add
            else if (sign1==1 && sign2==1){     //vared kardan do add manfi:
                if (compare(cor1,cor2)!=1){     //moghayse ghesmat sahih do add
                    sub=mySub(str2,str1);       //tafrigh kardan
                    sub=addDot(sub,max_ash);    //ezafe kardan noghte
                    sub=remZero_R(sub);         //hazf sfrhaye bi manii az rast
                    result=remZero_L(sub);}     //hazf sefrhaye bi manii az chap
                else{
                    sub=mySub(str1,str2);       //tafrigh kardan
                    sub=addDot(sub,max_ash);    //ezafe kardan noghte
                    sub=remZero_R(sub);         //hazf sefrhaye bi manii az rast
                    sub=remZero_L(sub);         //hazf sefrhaye bi manii az chap
                    result=addNeg(sub);}}       //ezafe kardan manfi be add
        }
        else if (op=="*"){                                          //agar operator zarb bood:
            max_ash=dec1.length()+dec2.length();                    //moshakhas kardan tedad ashar
            if ((sign1==1 && sign2==1)||(sign1==0 && sign2==0)){    //vared kardan do add ham alamat:
                mul=myMul(str1,str2);                               //zarb kardan
                mul=addDot(mul,max_ash);                            //ezafe kardan noghte
                mul=remZero_R(mul);                                 //hazf sfrhaye bi manii az rast
                result=remZero_L(mul);                              //hazf sefrhaye bi manii az chap
            }
            else{
                mul=myMul(str1,str2);           //zarb kardan
                mul=addDot(mul,max_ash);        //ezafe kardan noghte
                mul=remZero_R(mul);             //hazf sefrhaye bi manii az rast
                mul=remZero_L(mul);             //hazf sefrhaye bi manii az chap
                result=addNeg(mul);}            //ezafe kardan manfi be add
        }
        else if (op=="^"){                      //agar operator tavan bood:
            if (isDecimal(org1)==1){            //check kardan bakhsh ashari adad
                max_ash=0;                      //ezafe kardan noghte
                for (int i=0;i<stoi(str2);i++)
                    max_ash+=dec1.length();     //ezafe kardan noghte
            }else
                max_ash=0;                      //ezafe kardan noghte
            if (sign1==1 && stoi(str2)%2==1){   //vared kardan add manfi ba tavan fard:
                pow=myPow(str1,str2);           //be tavan resandan
                pow=addDot(pow,max_ash);        //ezafe kardan noghte
                pow=remZero_R(pow);             //hazf sfrhaye bi manii az rast
                pow=remZero_L(pow);             //hazf sefrhaye bi manii az chap
                pow=remZero_L(pow);             //hazf sefrhaye bi manii az chap
                pow=remZero_L(pow);             //hazf sefrhaye bi manii az chap
                result=addNeg(pow);}            //ezafe kardan manfi be add
            else{
                pow=myPow(str1,str2);           //be tavan resandan
                pow=addDot(pow,max_ash);        //ezafe kardan noghte
                pow=remZero_R(pow);             //hazf sfrhaye bi manii az rast
                pow=remZero_L(pow);             //hazf sefrhaye bi manii az chap
                pow=remZero_L(pow);             //hazf sefrhaye bi manii az chap
                result=remZero_L(pow);}         //hazf sefrhaye bi manii az chap
        }
        else if (op=="/"){                                   //agar operator taghsim bood:
            if (isDecimal(org1)==1 && isDecimal(org2)==1)    //tashkhis ashari boodan adad
                max_ash=10+dec1.length()-dec2.length();      //ezafe kardan noghte
            else
                max_ash=10;                                  //ezafe kardan noghte

            if ((sign1==1 && sign2==1)||(sign1==0 && sign2==0)){    //vared kardan do add ham alamat:
                div=myDiv(str1,str2);                               //taghsim kardan
                div=addDot(div,max_ash);                            //ezafe kardan noghte
                div=remZero_L(div);                                 //hazf sefrhaye bi manii az chap
                div=remZero_L(div);                                 //hazf sefrhaye bi manii az chap
                div=remZero_L(div);                                 //hazf sefrhaye bi manii az chap
                div=remZero_R(div);                                 //hazf sfrhaye bi manii az rast
                result=remZero_L(div);                              //hazf sefrhaye bi manii az chap
            }else{
                div=myDiv(str1,str2);           //taghsim kardan
                div=addDot(div,max_ash);        //ezafe kardan noghte
                div=remZero_L(div);             //hazf sefrhaye bi manii az chap
                div=remZero_L(div);             //hazf sefrhaye bi manii az chap
                div=remZero_L(div);             //hazf sefrhaye bi manii az chap
                div=remZero_R(div);             //hazf sfrhaye bi manii az rast
                div=remZero_L(div);             //hazf sefrhaye bi manii az chap
                result=addNeg(div);             //ezafe kardan manfi be add
            }
        }
        else if (op=="%"){
            mod=myMod(str1,str2);               //baghimande gereftan
            mod=remZero_L(mod);                 //hazf sefrhaye bi manii az chap
            mod=remZero_L(mod);                 //hazf sefrhaye bi manii az chap
            result=remZero_R(mod);              //hazf sfrhaye bi manii az rast
        }

        cout << "\tTHE RESULT :" << result;     //namayesh natije
        cout << "\n\n\n\tEND...\n";
        cout << "\a";                           //sound effect
        printStar();                            //chap setare

        ch=getch();
        i++;
    }

    cout << "\t\t\t     MOHAMMADREZA GHOLINIA\n";

    return 0;
}
