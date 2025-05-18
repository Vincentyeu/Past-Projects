import 'dart:io';
void main()
{bool check1,check2;
 check1= 2*5 == 10;
 check2= 10>11;

  print(check1);
  print(check2);

  double num1=4,num2=8,ans;
  ans=num1+num2;
  print("4+8= /r"+ans.toString());

  print("Please enter your name:");
  String name = stdin.readLineSync()!; 
  print("HI!$name");
  

  print("Please choose your beverage tea(1),coffee(2),juice(3) or mineral(4)");
  int choice= int.parse(stdin.readLineSync()!);
  print("Your choice is $choice");

}