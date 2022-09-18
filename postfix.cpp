#include<iostream>
#include<string>
using namespace std;

//string infix, postfix, operators;

char precedence(char a, char b){
    if((a=='*'||a=='^'||a=='/'||a=='%') && (b=='*'||b=='^'||b=='/'||b=='%')){
        return(a);
    }
    if((a=='+'||a=='-') && (b=='*'||b=='^'||b=='/'||b=='%')){
        return(b);
    }
    return(a);
}

string convert(string infx){
    int count=0,top=-1;
    string postfix="";char operators[20];
    int l = infx.length();
    for(int i=0; i<l; i++){
        char sym=infx.at(i);
        if(isdigit(sym))
            postfix.append(1,sym);
        
        else if(sym=='+'|| sym=='-' || sym=='*' || sym=='^' || sym=='/' || sym=='%'){
            M:
            if(top==-1){
                operators[0]=sym;
                top++;
                continue;
            }
            if(precedence(operators[top],sym)==operators[top]){
                postfix.append(1,operators[top--]);
                goto M;                
            }
            else
                operators[++top]=sym;
        }
        else if(sym=='('){
            sym=infx.at(++i);
            char temp[30];int a=0; int marker=0;
            while(sym!=')'){
                temp[a++]=sym;
                sym=infx.at(++i);
                if(sym=='('){
                    marker++;
                }
                if(sym==')'&&marker!=0){
                    temp[a++]=sym;
                    sym=infx.at(++i);
                    marker--;
                }

            }
            temp[++a]='#';
            string g;
            for(int j=0; j<a;j++)
                g.append(1,temp[j]);
            //cout<<g<<endl;
            postfix.append(convert(g));
        }
    }
    L:
    if(top!=-1){
        postfix.append(1,operators[top--]);
        goto L;
    }
    //cout<<postfix<<endl<<infx<<endl;
    return(postfix);
}

int main(){
    string h;
    h.append(convert("1+(3*(7-5)/9)-6#"));
    cout<<h<<endl;
    cout<<"Hello?????";
    return 0;
}
