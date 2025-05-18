#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct customer
{
	char memName[50];
	char name[50];
	char id[10];
	char memid[10];
}cust;

float get_price(int choice, char size);
float get_addons(char addons[20]);
void get_tax(float subtotal, float *tax, float *amount);
int main()
{
	//declare
	int found=0, n=0, choice[n], amt[n],count,qty[count];
	char member, mem, cont, size, addons, addn[20], order,dogsize;
	float member_fee=0, price, tot[n], total, add_price, subtotal, tax, discount, amount;
	
	FILE *m;
	
	m = fopen("Member.txt","a");
	
	//Ask whether member or not?
	printf("Are you a member? [Y/N] : ");
	scanf("%c", &member);
	
	if(member == 'N' || member == 'n')
	{
		fflush(stdin);
		printf("Do you want to be a member? [Y/N] : ");
		scanf("%c", &mem);
		
		if(mem == 'Y' || mem == 'y')
		{
			//registration
			member_fee = 10.00;
			printf("Registration:\n-------------\n");
			fflush(stdin);
			printf("Enter Your Name \t: ");
			gets(cust.name);
			printf("Create Your 6-digit Member ID \t: ");
			gets(cust.id);
			fprintf(m,"\n%s %s", cust.name, cust.id);
			printf("Registration successful! You will enjoy a 10% discount for every purchase.\n");
			printf("Enter any key to continue : ");
			scanf("%c", &cont);
		}
	}
	
	system("cls");
	
	fclose(m);
	
	//display menu

	printf("\t\t OLIVE PET GROOMING \n");
	printf("\t\t\tMENU\n\n");
	printf("  1. Bath Only\t\t\t(S-RM20|M-RM25|L-RM30)\n");
	printf("  2. Partial Groom\t\t(S-RM25|M-RM30|L-RM35)\n");
	printf("  3. Full Groom\t\t\t(S-RM30|M-RM35|L-RM40)\n");

	
	FILE *h;
	
	h = fopen("History.txt","a");
	
	//get input
	fflush(stdin);
	printf("\nEnter Your Name \t: ");
	gets(cust.name);
	fprintf(h,"%s\t", cust.name);
	
	if(member == 'Y' || member == 'y')
	{
		printf("Enter Your Member ID \t: ");
		gets(cust.id);
		
		count=0;
		do
		{
			m = fopen("Member.txt","r");
			while(!feof(m))
			{
				fscanf(m,"%s %s", cust.memName, cust.memid);
				
				if(strcmp(cust.name,cust.memName)==0 && strcmp(cust.id,cust.memid)==0)
				{
					found = 1;
				}
			}
			if(found == 0)		
			{
				fflush(stdin);
				printf("\nInvalid Name or Member ID\n");
				printf("Enter Your Name \t: ");
				gets(cust.name);
				printf("Enter Your Member ID \t: ");
				gets(cust.id);
				count++;
				if(count==2)
				{
					exit(1);
				}
			}
			else
			{
				break;
			}
			fclose(m);
		}while(count<2);
	}

	n=0;
	do
	{
		printf("Enter Your Choice \t: ");
		scanf("%d", &choice[n]);
		
		//checking choice
		if(choice[n] > 3)
		{
			printf("Invalid choice!");
			exit(1);
		}
		
		printf("Enter Amount \t\t: ");
		scanf("%d", &amt[n]);
		for(count=0; count<amt[n]; count++)
		{
			fflush(stdin);
			printf("\nDog Size (S|M|L) \t: ");
			scanf("%c", &dogsize);	
			
			//get price
			price = get_price(choice[n], dogsize);
			
			fflush(stdin);
			printf("Do you want to include grooming add-ons? [Y/N] : ");
			scanf("%c", &addons); 
			
			
			if(addons == 'Y' || addons == 'y')
			{
				fflush(stdin);
				printf("\n\n-----------------------------------------------------------------\n");
				printf("\t\t\t[Grooming Add-Ons]\n\n");
				printf("\tOatmeal Shampoo [Oat] \t\t\t(RM10)\n");
				printf("\tTeeth Brushing [Teeth] \t\t\t(RM5)\n");
				printf("\tFlea Treatment [Flea] \t\t\t(RM15)\n");
				printf("\tDe-Shedding [Shed] \t\t\t(RM10)\n");
				printf("\tDe-Matting [Mat] \t\t\t(RM15)\n");
				printf("\tHair Colouring [HColour] \t\t(RM10)\n");
				printf("-----------------------------------------------------------------\n");
				printf("Enter your add-on for dog %d : ", count+1);
				gets(addn);
				
				//get price of Add-ons
				add_price = get_addons(addn);
				
				printf("\n");
			}
			
			tot[n] = tot[n] + price + add_price;
			add_price = 0;		
		}
		subtotal = subtotal + tot[n];
		
		printf("\nTotal \t\t\t: RM %.2f\n", tot[n]);
		fflush(stdin);
		printf("\nWould you like to add another order? [Y/N] : ");
		scanf("%c", &order);
		
		if(order == 'Y' || order == 'y')
		{
			printf("\n-----------------------------------------------------------------\n");
			printf("\t\t\t\tMENU\n\n");
	  		printf("  1. Bath Only\t\t\t(S-RM20|M-RM25|L-RM30)\n");
			printf("  2. Partial Groom\t\t(S-RM25|M-RM30|L-RM35)\n");
			printf("  3. Full Groom\t\t\t(S-RM30|M-RM35|L-RM40)\n");
			printf("-----------------------------------------------------------------\n");
		}
		
		n++;
	}while(order == 'Y' || order == 'y');
	
	char item[n][30];
	
	for(count=0; count<n; count++)
	{
		switch(choice[count])
		{
			case 1: strcpy(item[count],"Bath Only");
					break;
			case 2: strcpy(item[count],"Partial Groom");
					break;
			case 3: strcpy(item[count],"Full Groom");
					break;
		}
		
		fflush(stdin);
	}
	
	//calculate discount for member
	if(member == 'Y' || member == 'y')
	{
		discount = -(subtotal * 0.10);
		subtotal = subtotal + discount;
	}
	
	//get tax and total amount
	get_tax(subtotal, &tax, &amount);
	fprintf(h,"%7.2f\n", amount);
	
	//display receipt

	printf("\n\nName \t\t: %s\n", cust.name);
	if(member == 'Y' || member == 'y')
	{
		printf("Member ID \t: %s\n", cust.id);
	}
	printf("\n QTY \t  ITEMS \t\t\t\t\t    PRICE\n");
	printf("-------------------------------------------------------------------\n");
	for(count=0; count<n; count++)
	{
		printf("  %d \t%s \t\t\t\t\t  %7.2f\n",qty[count], item[count], tot[count]);
	}
	printf("-------------------------------------------------------------------\n");
	printf("\t\t\t\tMember Fee (RM)\t\t: %7.2f\n", member_fee);
	printf("\t\t\t\tSubtotal (RM)");
	if(member == 'Y' || member == 'y')
	{
		printf("(-10%%)\t: %7.2f\n", subtotal);
	}
	else
	{
		printf("\t\t: %7.2f\n", subtotal); 
		printf("\t\t\t\tTax 6%% \t\t\t: %7.2f\n", tax);
		printf("\t\t\t\tTotal Amount (RM)\t: %7.2f\n", amount);
		printf("\n\n\tWe'll tidy up your dogs happily. Thank you for your order'!\n");
	}
	
	fclose(h);
}
float get_price(int choice, char size)
{
	//declare
	float price;
	
	switch(choice)
	{
		case 1 :
				if(size == 'S')
				{
					price = 20;
				}
				else if(size == 'M')
				{
					price = 35;
				}
				else if(size == 'L')
				{
					price = 40;
				}
				break;
		case 2 :
				if(size == 'S')
				{
					price = 25;
				}
				else if(size == 'M')
				{
					price = 30;
				}
				else if(size == 'L')
				{
					price = 35;
				}
				break;
		case 3 :
				if(size == 'S')
				{
					price = 30;
				}
				else if (size == 'M')
				{
					price = 35;
				}
				else if(size == 'L')
				{
					price = 40;
				}
	}
	
	return price;
}
float get_addons(char addn[20])
{
	//declare
	float addns_price;
	
	if(strcmp(addn,"Oat")==0)
	{
		addns_price = 10;
	}
	else if(strcmp(addn,"Teeth")==0)
	{
		addns_price = 5;
	}
	else if(strcmp(addn,"Flea")==0)
	{
		addns_price = 15;
	}
	else if (strcmp(addn,"Shed")==0)
	{
		addns_price = 10;
	}
	else if (strcmp(addn,"Mat")==0)
	{
		addns_price = 15;
	}
	else if (strcmp(addn,"HColour")==0)
	{
		addns_price = 10;
	}
	
	return addns_price;
}
void get_tax(float subtotal, float *tax, float *amount)
{
	*tax = subtotal * 0.06;
	
	*amount = subtotal + *tax;
}
