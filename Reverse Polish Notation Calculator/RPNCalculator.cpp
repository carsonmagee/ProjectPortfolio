#include<iostream>
#include<string>
#include<math.h>
#define MAX 100
using namespace std;

class stack
{
private:
       float arr[MAX];
       int top;
public:
    stack();
    ~stack();
    void push(float item);
    void pop();
    float Top();
    void display();
    void clear();
};

//Function Prototypes
float calculate_Postfix(string  post_exp);

int main()
{
    while (1==1)
    {
        //Save the postfix expression to calculate in postfix_expression string
        cout << "\033[2J\033[1;1H"; //clear screen
        cout << "\n\n\n\n\n\n\n\n\n            Please enter a postfix expression (or type 'quit'): \n             Ex. 123.45 67.4 + 18.34 *\n            ";
        string postfix_expression;
        // Ex. 123.45 67.4 + 18.34 *
        getline( cin, postfix_expression);
        calculate_Postfix(postfix_expression);
        cout << "\n\n\n\n\n\n\n\n\n            Press enter to Continue . . .";
        cin.get();
    }
}

//The function calculate_Postfix returns the final answer of the expression after calculation
float calculate_Postfix(string post_exp)
{
    stack stack;
    float len = post_exp.length();
    string expChars = "";
    string expNums = "";

    // loop to iterate through the expression
    // if the character is an operand we push it in the stack
    for (float i = 0; i < len; i++)
    {
        if (post_exp[i] != ' ')
        {
            if (post_exp[i] == '0' || post_exp[i] == '1' || post_exp[i] == '2' || post_exp[i] == '3' || post_exp[i] == '4' || post_exp[i] == '5' || post_exp[i] == '6' || post_exp[i] == '7' || post_exp[i] == '8' || post_exp[i] == '9' || post_exp[i] == '.')
            {
                expNums += post_exp[i];
            }
            else
            {
                expChars += post_exp[i];
            }
        }
        if((post_exp[i] == ' ' || i == len-1) && expChars.length() == 0)
        {
            stack.push(stof(expNums));
            expNums="";
        }
        if ((post_exp[i] == ' ' || i == len-1) && expChars.length() > 0) //if character is a space (end of operator or operand)
        {
            if (expChars == "ps")
            {
                stack.display(); //Think smarter, not harder.
            }
            else if (expChars == "sq") //square
            {
                float a = stack.Top();
                stack.pop();
                stack.push(a*a);
            }
            else if (expChars == "sqrt")
            {
                float a = stack.Top();
                stack.pop();
                stack.push(sqrt(a));
            }
            else if (expChars == "dup")
            {
                stack.push(stack.Top());
            }
            else if (expChars == "clear") // clear stack (destruct)
            {
                stack.clear();
            }
            else if (expChars == "quit")
            {
                cout << "\n            Program has exited.\n";
                exit(0);
            }
            else
            {
                // we pop the top two elements from the stack and save them in two floats
                float a = stack.Top();
                stack.pop();
                float b = stack.Top();
                stack.pop();
            
                //performing the operation on the operands
                if (expChars == "+") // addition
                {
                    stack.push(b + a);
                }
                else if (expChars == "-") // subtraction
                {
                    stack.push(b - a);
                }   
                else if (expChars == "*") // multiplication
                {
                    stack.push(b * a);
                }
                else if (expChars == "/") // division
                {
                    stack.push(b / a);
                }
                else if (expChars == "^") // exponent
                {
                    stack.push(pow(b,a));
                }
                else if (expChars == "swap")
                {
                    stack.push(a);
                    stack.push(b);
                }
                else
                    cout << "            invalid input: " << expChars << endl;
            }
            expChars="";
        }
    }
    //returning the calculated result
    cout <<"\n            The answer after calculating the postfix expression is : "
    << stack.Top() << endl;
    return stack.Top();
}

// Constructor for the stack class, initializes the top index to -1
stack::stack()
{
    top = -1;
}

// Destructor for the stack class, empties the stack and prints a message
stack::~stack()
{
    for(int i=0; i<top; i++)
    {
        top--;
    }
    cout << "            Stack is destructed\n";
}

// Method to push a value onto the stack
void stack::push(float val) 
{
    // If the stack is full, print an error message
    if(top>=MAX-1)
        cout<<"            Stack Overflow"<<endl;
    else 
    {
    // Otherwise, increment the top index and add the value to the stack
        top++;
        arr[top]=val;
    }
}
void stack::pop() 
{
    if(top<=-1)
        cout<<"            Stack Underflow"<<endl;
    else 
    {
        top--;
    }
}

float stack::Top()
{
        return arr[top];
}

void stack::display() 
{
   if(top>=0) {
      cout<<"            Stack elements are: \n";
      for(int i=top; i>=0; i--)
      cout<< "            " << arr[i] <<" \n";
   } else
   cout<<"            Stack is empty\n";
}

void stack::clear()
{
    for (int i=top; i>=0; i--)
        arr[i] = (float)NULL;
    cout << "            Stack is cleared\n";
}