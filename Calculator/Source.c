#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXPR_SIZE 100
#define MAX_MYSTACK_SIZE 50


typedef enum
{
    lparen, rparen, plus, minus, times, devide, mod, eos, operand, sign_m, sign_p, my_sin, my_cos, my_tan
} precendence;
//   0    1   2     3   4    5  6   7   8      9      10     11     12     13

static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0, 0, 0, 0, 0, 0 };   // ���ÿ� ������ isp[8],isp[9]=21 �ְ��������..
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0, 21, 21, 21, 21, 21 };   // ���ÿ� ����
//# & �����ڴ� ���ÿ� ������ �����ߴٰ�.. �ٸ������� ������ ������ ������.

char expr[MAX_EXPR_SIZE];

double stack[MAX_MYSTACK_SIZE]; // ���ü���.. �����Ҵ��� �ʴ´�.
int top;  // ���� tp ����.. stack_init()���� �ʱ�ȭ.. -1



/* ���� ����..*/
void stack_init();
void push(double);
double pop();


precendence get_token(char*);
char printf_token(int);

void postfix(char*, char*);        //���� ǥ�� ����..
double eval(char*);           //���� ǥ�� ���� ������... ������..
void tri_funtion(char*, char*);      //�ﰢ �Լ��� ���� ���� ���..

double my_sin_fct(char*);
double my_cos_fct(char*);
double my_tan_fct(char*);



int main(void)
{
    int i = 0;
    char input_char;
    /* �Է� ���ڿ� */
    char expr_temp[MAX_EXPR_SIZE];

    printf("�����Է��Ͻÿ�\n");


    while ((input_char = getchar()) != '\n') //���ڿ� �Է¹���..
        expr[i++] = input_char;
    expr[i] = '\0'; // �������� �ι���.

    tri_funtion(expr, expr_temp);    // �ϴ� �ﰢ �Լ� ��� ����Ͽ� ���� ����ǥ���� �ѱ��. 

    printf("��ȯ Ȯ��:%s\n", expr_temp);
    postfix(expr_temp, expr_temp);
    printf("����ǥ��..%s\n", expr_temp);
    eval(expr_temp);
    printf("�������:%f\n", eval(expr_temp));
    //  printf("sin30=%f",sin(30*3.141592/180));

    return 0;
}




/*----------stack funtion-----------------*/

void push(double temp)
{
    stack[++top] = temp;
}

void stack_init()
{
    top = -1;
}

double pop()
{
    return stack[top--];
}
/*----------------------------------------*/


/*-------convert data---------------------*/
precendence get_token(char* input)
{
    switch (*input) {
    case '(': return lparen;
    case ')': return rparen;
    case '+': return plus;
    case '-': return minus;
    case '*': return times;
    case '/': return devide;
    case '%': return mod;
        //----------------------------------------//
    case '&': return sign_m;
    case '#': return sign_p;
        //----------------------------------------//
    case 's': return my_sin;
    case 'c': return my_cos;
    case 't': return my_tan;
        //----------------------------------------//
    case '\0': return eos;


    default: return operand;
    }
}



char printf_token(int precendence)
{
    switch (precendence) {
        //----------------------------------------//
    case sign_m: return '&'; // * -1
    case sign_p: return '#'; // * 1
    //----------------------------------------//
    case my_sin: return 's';
    case my_cos: return 'c';
    case my_tan: return 't';
        //----------------------------------------//
    case plus: return '+';
    case minus: return '-';
    case times: return '*';
    case devide: return '/';
    default: return '%';
    }
}


void postfix(char* input, char* output)  //���� ǥ������ �ٲ� string��.. strcpy(input,output);
{
    precendence token;
    int j = 0, k = 0, sign = 0, flag = 1;
    char temp_num[100];

    stack_init();     // ���� �ʱ�ȭ
    push(eos);        // stack�� ù��° ��ҿ�..eos

    while ((token = get_token(input + j)) != eos)
    {
        sign = 0;   //sign �ʱ�ȭ..
      //-------minus sign �Ǻ�..---- ���� / ��ȣ => 0 /1  --------//
        if ((token == minus))
        {
            if (j == 0 && (get_token(input + j + 1) == minus))   // ó�� - - �̸�..
                sign = -1;
            else if ((get_token(input + j - 1) != operand) && (get_token(input + j + 1) == operand))   // ���� - ���� �϶�..
                sign = 1;   //��ȣ�� ���� ������ �Ѱ���....
            else if ((get_token(input + j - 1) == rparen) && (get_token(input + j + 1) != operand))    // ) - ����..
                sign = 0;
            else if ((get_token(input + j - 1) != operand) && (get_token(input + j + 1) == lparen))    // ���� - ( �̸�..
                sign = -1;  //�� ��ȣ ���� *-1 �̴�.
            else if ((get_token(input + j - 1) == rparen) && (get_token(input + j - 1) != operand))    // ���� - ( �̸�..
                sign = -1;  //�� ��ȣ ���� *-1 �̴�
            else if ((get_token(input + j - 1) != operand) && isalpha(*(input + j + 1)))   // ���� - sin �̸�..
                sign = -1;
            else if ((get_token(input + j - 1) != operand) && (get_token(input + j + 1) == minus))   // ���� - - �̸�..
                sign = -1;  // ���� ������ -�� *-1 �̴�.
            else          // ���� - ����
                sign = 0;
        }
        //----------------------------------------------------------//

        //--------plus sign �Ǻ�..---- ���� / ��ȣ => 0 /1  --------//
        if ((token == plus))
        {
            if (j == 0 && (get_token(input + j + 1) == plus))    // ó�� + + �̸�..
                sign = -2;
            else if ((get_token(input + j - 1) != operand) && isalpha(*(input + j + 1)))   // ) - ���� �̸�..
                sign = -2;
            else if ((get_token(input + j - 1) == rparen) && (get_token(input + j + 1) != operand))    // ) - ����..
                sign = 0;
            else if ((get_token(input + j - 1) != operand) && isalpha(*(input + j + 1)))   // ���� - sin �̸�..
                sign = -2;
            else if ((get_token(input + j - 1) != operand) && (get_token(input + j + 1) == operand))   // ���� + ���� �϶�..
                sign = 1; //��ȣ..
            else if ((get_token(input + j - 1) != operand) && (get_token(input + j + 1) == lparen))    // ���� + ( �̸�..
                sign = 0;
            else if ((get_token(input + j - 1) != operand) && (get_token(input + j + 1) == plus))    // ���� + + �̸�..
                sign = -2;
            else            //���� + ����
                sign = 0;
        }
        //----------------------------------------------------------//
      //    printf("sign=%d\n",sign);
        if (sign == -3)  // ���� �÷��� ����?
        {
            printf("input error!!!!\n");
            exit(1);
        }
        else if (sign == -2)
        {
            j++;
            push(sign_p);
            continue;
        }
        else if (sign == -1)   // * -1 ó��..
        {
            j++;
            push(sign_m); // -() ó��.. ���������ϰ� ��������.. &&..
            continue;
        }

        else if (sign == 0)    // �ش��ε����� ��ȣ�� �ƴҶ�.. ������� ó��..
        {
            if (token == operand)
            {
                *(temp_num + k++) = *(input + j);
                if (!isdigit(*(input + j + 1)) && (*(input + j + 1) != '.') && !isalpha(*(input + j + 1)) && (stack[top] == 9 || stack[top] == 8))  // # & �� ���� �տ� ������� �����´�.
                { // �ڿ��� �Ҽ���, ����, ���ڰ� �ƴҰ��.. ���� ����..
                    while (stack[top] == 9 || stack[top] == 8) // �°�ȣ ���ö�����.. pop()..
                    {
                        *(temp_num + k++) = ' ';
                        *(temp_num + k++) = printf_token((int)pop());
                        *(temp_num + k++) = ' ';
                    }
                }
            }

            else if (token == rparen)   // ���ȣ..
            {
                while (stack[top] != lparen) // �°�ȣ ���ö�����.. pop()..
                {
                    *(temp_num + k++) = ' ';
                    *(temp_num + k++) = printf_token((int)pop());
                }
                pop();  // �°�ȣ ����. pop
                //----�°�ȣ ���� �ﰢ�Լ� ������ ������ ����.------//
                if (stack[top] == my_sin)
                {
                    *(temp_num + k++) = ' ';
                    *(temp_num + k++) = printf_token((int)pop());
                }
                if (stack[top] == my_cos)
                {
                    *(temp_num + k++) = ' ';
                    *(temp_num + k++) = printf_token((int)pop());
                }
                if (stack[top] == my_tan)
                {
                    *(temp_num + k++) = ' ';
                    *(temp_num + k++) = printf_token((int)pop());
                }
                //---------------------------------------------------//


            }

            else
            {
                if ((get_token(input + j - 1) == operand) && (token == lparen))  //����() ����ġȯ..
                {
                    push(times);
                }
                if ((get_token(input + j - 1) != lparen) && !isalpha(*(input + j)) && (stack[top] == 9 || stack[top] == 8)) // # & �� ���� �տ� ������� �����´�.
                { // �ڿ��� �Ҽ���, ����, ���ڰ� �ƴҰ��.. ���� ����..
                    while (stack[top] == 9 || stack[top] == 8) // �°�ȣ ���ö�����.. pop()..
                    {
                        *(temp_num + k++) = ' ';
                        *(temp_num + k++) = printf_token((int)pop());
                        *(temp_num + k++) = ' ';
                    }
                }
                while (isp[(int)stack[top]] >= icp[token])   //���� ���������Ϳ� �� �ڷ� ��.
                {
                    *(temp_num + k++) = ' ';
                    *(temp_num + k++) = printf_token((int)pop());
                }




                push(token);
                *(temp_num + k++) = ' ';  // ���� ������ ���� �־��.
            }
        }
        else      // �ش��ε����� ��ȣ �϶�.. �׳� ����Ʈ..
        {
            *(temp_num + k++) = *(input + j);
            sign = 0; // ��ó���� �ٽ� �ʱ�ȭ..
        }
        j++;
    }

    while ((token = (int)pop()) != eos)//���ÿ� �������ִ°� �� ���
    {
        *(temp_num + k++) = ' ';
        *(temp_num + k++) = printf_token(token);
    }
    *(temp_num + k++) = ' ';  // ���� ǥ�� ����� ������ �������
    temp_num[k] = '\0';
    strcpy(output, temp_num);
}




double eval(char* postfix)
{
    int i = 0, j = 0;
    char temp_num[10];  // atof �������� �ӽ� �迭..
    int flag = 0;
    double op1, op2;

    stack_init(); //stack�� ���� ���� �ٽ� �ʱ�ȭ.

    while (*(postfix + i) != '\0')
    {
        //printf("���� ���ð� : %f \n",stack[top]);
        //----- �Ϲ� ���ڿ����. --------------------------------------------------------------//
        if (*(postfix + i) == ' ')
        {
            i++;    // �ϴ� ���� ����..
            continue; // �ε����� �ٷ� �ű��.
        }
        else if (isdigit(*(postfix + i + 1)))  // �ڿ��� ���ڸ�.. ��ȣ�̹Ƿ�... atof ��ȯ�Ͽ� ��������.
        {
            while ((*(postfix + i) != ' '))
            {
                temp_num[j++] = *(postfix + i++);
            }

            temp_num[j] = '\0';   // temp_num�� ������
            push(atof(temp_num)); // push �Ͽ� ���ÿ� ����..
            j = 0;          // temp_num�� �ٽ� �ʱ�ȭ �ؼ� ����.
        }
        else if (isdigit(*(postfix + i)))  // �ش� �ε����� ���ڸ� �����ϰ��..
        {
            while (*(postfix + i) != ' ')
                temp_num[j++] = *(postfix + i++);
            temp_num[j] = '\0';   // temp_num�� ������
            push(atof(temp_num)); // push �Ͽ� ���ÿ� ����..
            j = 0;          // temp_num�� �ٽ� �ʱ�ȭ �ؼ� ����.
        }
        else if (*(postfix + i) == '&')  // -( ) ó��..
            stack[top] = stack[top] * -1;
        else if (*(postfix + i) == '#')  // +( ) ó��..
            stack[top] = stack[top] * 1;
        else if (*(postfix + i) == 's')
            stack[top] = sin(stack[top] * 3.141592 / 180);
        else if (*(postfix + i) == 'c')
            stack[top] = cos(stack[top] * 3.141592 / 180);
        else if (*(postfix + i) == 't')
            stack[top] = tan(stack[top] * 3.141592 / 180);
        else
        {
            op2 = pop();
            op1 = pop();
            switch (get_token(postfix + i))
            {
            case plus:
            {
                push(op1 + op2);
                break;
            }
            case minus:
            {
                push(op1 - op2);
                break;
            }
            case times:
            {
                push(op1 * op2);
                break;
            }
            case devide:
            {
                push(op1 / op2);
                break;
            }
            case mod:
            {
                push((int)op1 % (int)op2);
                break;
            }
            }
        }
        //------------------------------------------------------------------------------//
        i++;  // ������ �ѹ����� �ε��� ����. �� ������ �ٷ�.. continue
    }

    //  printf("�������:%f",stack[top]); // stack�� ���������ִ°��� ��.
    return stack[top];
}

void tri_funtion(char* input, char* output)
{
    char tri_result[MAX_EXPR_SIZE];
    char temp_arr[10];  // s c t �ӽ� �˻��..
    int i = 0, j = 0, z = 0;

    while (*(input + i) != '\0')
    {
        //    tri_result[z++] = *(*(input+i));

        if (isalpha(*(input + i)) != 0) // ����,����=0 // �빮��=1 // �ҹ���=2 //�����ϰ��.. ����..
        {
            char char_sin[] = { "sin" };
            char char_cos[] = { "cos" };
            char char_tan[] = { "tan" };

            //--------- s c t �˻��� ���ڿ� ��ȯ.. ------------------//
            for (j = 0; j < 3; j++)    // �ﰢ�Լ� ���ڿ� ����..() ������..
                temp_arr[j] = *(input + i + j);
            temp_arr[j] = '\0';

            if (!strncmp(temp_arr, char_sin, 3))
            {
                tri_result[z++] = 's';
                i += 3; // ���� sin ������.. �ε��� 3 �ű�� ���� ����.
                continue;
            }
            else if (!strncmp(temp_arr, char_cos, 3))
            {
                tri_result[z++] = 'c';
                i += 3; // ���� cos ������.. �ε��� 3 �ű�� ���� ����.
                continue;
            }
            else if (!strncmp(temp_arr, char_tan, 3))
            {
                tri_result[z++] = 't';
                i += 3; // ���� tan ������.. �ε��� 3 �ű�� ���� ����.
                continue;
            }
            else
            {
                printf("input data is error"); // �߸��� �����͸� ���α׷� ��������.
                exit(1);
            }
        }
        //--------- s c t �˻��� ���ڿ� ��ȯ.. ------------------//
        else
            tri_result[z++] = *(input + i);
        i++;
    }
    tri_result[z] = '\0';

    //  printf("test:%s\n",tri_result);
    strcpy(output, tri_result);

}


/*
double my_sin_fct(char* input)
{
  char temp_tri_sin[50];
  double result;

  postfix(input,temp_tri_sin);  // ���� ��Ʈ���� ���� ǥ������ �����..
  eval(temp_tri_sin);       // �� ���ڸ� �����Ͽ�..

  result = sin(eval(temp_tri_sin)*3.141592/180);  // ���� ���ΰ�����..

  return result;
}

double my_cos_fct(char* input)
{
  char temp_tri_cos[50];
  double result;

  postfix(input,temp_tri_cos);  // ���� ��Ʈ���� ���� ǥ������ �����..
  eval(temp_tri_cos);       // �� ���ڸ� �����Ͽ�..

  result = cos(eval(temp_tri_cos)*3.141592/180);  // ���� ���ΰ�����..

  return result;
}

double my_tan_fct(char* input)
{
  char temp_tri_tan[50];
  double result;

  postfix(input,temp_tri_tan);  // ���� ��Ʈ���� ���� ǥ������ �����..
  eval(temp_tri_tan);       // �� ���ڸ� �����Ͽ�..

  result = tan(eval(temp_tri_tan)*3.141592/180);  // ���� ���ΰ�����..

  return result;
}
*/