#include <stdio.h>
#include <string.h>

int main(){
    char str[100], rep[100], pat[100], ans[100];
    
    printf("Enter String : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str,"\n")] = '\0';
    
    printf("Enter Pattern : ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat,"\n")] = '\0';
    
    printf("Enter Replace : ");
    fgets(rep, sizeof(rep), stdin);
    rep[strcspn(rep,"\n")] = '\0';
    
    int c=0, i=0, j=0, m=0, flag=0,k=0;
    
    while(str[c]!= '\0'){
        i=c;
        j=0;
        while(str[i]!='\0' && pat[j]!='\0' && pat[j] == str[i]){
            i++;
            j++;
        }
        if(pat[j]=='\0'){
            flag =1;  
            for(k=0; rep[k]!='\0';k++,m++){
                ans[m]=rep[k];
                c=i;
            }
        }
        else{
            ans[m++]=str[c];
            c++;
        }
    }
    
    ans[m]='\0';
    
    if(flag==0){
        printf("No pattern matched");
    }
    else{
        printf("New String : %s",ans);
    }
    return 0;
}

