#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

int flag=0;

float bulk_5_discount(int n1,int n2,int n3){
    float discount=0;
    if(n1>10){
        discount+=(20*n1)*0.05;
    }
    if(n2>10){
        discount+=(40*n2)*0.05;
    }
    if(n3>10){
        discount+=(50*n3)*0.05;
    }
    
    return discount;
}


float bulk_10_discount(float tp){
    return (tp*0.1);
}

float tiered_50_discount(int n1,int n2,int n3){
    float discount=0;
    float price;
    if(n1>15){
        flag=1;
        price=((n1-15)*20);//price of items more thn 15 in number;
        discount+=price*0.5;
    }
    if(n2>15){
        flag=1;
        price=((n2-15)*40);//price of items more thn 15 in number;
        discount+=price*0.5;
    }
    if(n3>15){
        flag=1;
        price=((n3-15)*50);//price of items more thn 15 in number;
        discount+=price*0.5;
    }
    return discount;
}


int giftWrapFeeCalc(bool ques,int total){
    if(ques){
        return total;
    }
    else{
        return 0;
    }
}


float shippingFee(float total){
    return ceil(total/10)*5;
    
}


int main() {
    cout<<"Prices of the products"<<endl;
    cout<<"A->$20"<<endl;
    cout<<"B->$40"<<endl;
    cout<<"C->$50"<<endl;
	float n1,n2,n3;//number of products A,B,C 
	cout<<"Enter the quantity of A,B,C"<<endl;
	cin>>n1>>n2>>n3;
	
	float total=n1+n2+n3;
	
	//giftwrap
	bool giftWrap;
	cout<<"do you want to gift wrap:::if yes 1::else 0"<<endl;
	cin>>giftWrap;
	int giftWrapFee=giftWrapFeeCalc(giftWrap,total);
	
	
	
	//shipping Fee
	float shipfee=shippingFee(total);
	
	
	map<string,float> discounts;//to store all discounts
	
	float totalPrice=n1*20+n2*40+n3*50;
	
    
	
	if(totalPrice>200){
	    //flat 10 discount case
	    flag=1;
	    discounts["Flat 10 discount"]=10;
	}
	
	if(n1>10 || n2>10 || n3>10){
	    flag=1;
	    discounts["Bulk 5 discount"]=bulk_5_discount(n1,n2,n3);
	}
	
	if(n1+n2+n3>20){
	    flag=1;
	    discounts["Bulk 10 discount"]=bulk_10_discount(totalPrice);
	}
	
	if(n1+n2+n3>30){
	    discounts["tiered 50 discount"]=tiered_50_discount(n1,n2,n3);
	}
	
	
	//finds the max of map
	float maxDiscountAmount = 0;
    string maxDiscount;

    for(auto it = discounts.cbegin(); it != discounts.cend(); ++it )
    {
        if (it ->second > maxDiscountAmount)
        {
            maxDiscount = it->first;
            maxDiscountAmount=it ->second ;
        }
    }
    
    
    if(flag==0){
        maxDiscountAmount=0;
        maxDiscount="None";
    }
    
    //final Amount
    float finalAmount=totalPrice-maxDiscountAmount+giftWrapFee+shipfee;
    
    //display
    
    cout<<"Product:A"<<"  "<<n1<<endl;
    cout<<"Product:B"<<"  "<<n2<<endl;
    cout<<"Product:C"<<"  "<<n3<<endl;
	
	cout<<"Subtotal"<<"  $"<<totalPrice<<endl;
	
	cout<<"Discount Name"<< "  "<<maxDiscount<<endl;
	cout<<"Discount Amount"<< "  $"<<maxDiscountAmount<<endl;
	
	cout<<"Gift Wrap Fee "<< "  $"<<giftWrapFee<<endl;
	cout<<"Shipping Fee"<<"  $"<<shipfee<<endl;
	
	cout<<"Total"<< "  $"<<finalAmount<<endl;
	
	return 0;
}
