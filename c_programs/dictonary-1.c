#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,l;
    printf("How many Names You want to enter : ");
    scanf("%d",&n);		// Kitne nam lene h
    char name[n][20];
    printf("Enter Names : ");
    for(i=0;i<n;i++){	//<= Taking input ye loop nam lene k liye h
        scanf("%s",name[i]);
    }
    for(i = 0;i<n-1;i++){		//ye loop pure arrey of stings m ghume ga
        int k=i,count=0,min=name[i][count],temp[20];
        if(min>='A'&&min<='Z') min=min+32;
        for(j=i+1;j<n;j++){				//ye loop pure array me jo sabse 
            if(min>name[j][count]){		//phle ane wala character hoga 
                min=name[j][count];		//us string ka index k me save krega
                k=j;
            }
        }
        for(l=k+1;l<n;l++){						//ye loop sabse phle ane wale
            char a=name[k][count],b=name[l][count];	//character string ki 1 index
            if(a>='A'&&a<='Z') a=a+32;				//age se chle ga aur dhunde ga
            if(b>='A'&&b<='Z') b=b+32;				//ki aisa aur koi string bhi h kya
            count=0;								//jiske suru ka character same ho 
            if(a==b){								//agr same hoga to if ki condition chlegi
                while(count<strlen(name[l])||count<strlen(name[k])){ //ye loop un do 
                    a=name[k][count],b=name[l][count];				//strings m comperison krega jo same avegi
                    if(a>='A'&&a<='Z') a=a+32;
                    if(b>='A'&&b<='Z') b=b+32;
                    if(b==a) count++;					//agr same avega to count m 1 jod dega aur agle character ku compare krega
                    else if(b<a){			//agr k index wali string ka agla character same wali string se bda hua to k m same string ki index dal dega
                        k=l;
                        break;
                    }
                    else if(b>a) break;//nhi to break kar dega;
                }
            }
        }
        strcpy(temp,name[i]);//ab jo string ka character sabse phle ate hoge usse i index ke sath swap kar dega
        strcpy(name[i],name[k]);
        strcpy(name[k],temp);
    }
    for(i=0;i<n;i++){//string array ku print krega
        printf("%s ",name[i]);
    }
    return 0;
}
