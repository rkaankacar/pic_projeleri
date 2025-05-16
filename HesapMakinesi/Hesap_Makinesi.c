
#include <main.h>
#define use_portb_lcd TRUE
#include <lcd.c>

#define MAX_LEN 50

char infix[MAX_LEN];
char postfix[MAX_LEN];
char stack[MAX_LEN];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return (top == -1) ? 0 : stack[top--];
}

char peek() {
    return (top == -1) ? 0 : stack[top];
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infix_to_postfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    char ch;
    while (infix[i] != '\0') {
        ch = infix[i];
        if (ch >= '0' && ch <= '9') {
            postfix[j++] = ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            postfix[j++] = ' ';
            while (precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(ch);
        }
        i++;
    }

    postfix[j++] = ' ';
    while (top != -1) {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

int evaluate_postfix(char *postfix) {
    int valStack[MAX_LEN];
    int valTop = -1;
    int i = 0, num;

    while (postfix[i] != '\0') {
        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        if (postfix[i] >= '0' && postfix[i] <= '9') {
            num = 0;
            while (postfix[i] >= '0' && postfix[i] <= '9') {
                num = num * 10 + (postfix[i++] - '0');
            }
            valStack[++valTop] = num;
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            int b = valStack[valTop--];
            int a = valStack[valTop--];
            switch (postfix[i]) {
                case '+': valStack[++valTop] = a + b; break;
                case '-': valStack[++valTop] = a - b; break;
                case '*': valStack[++valTop] = a * b; break;
                case '/': valStack[++valTop] = a / b; break;
            }
            i++;
        }
    }
    return valStack[0];
}

void main() {
    set_tris_d(0xFF);
    set_tris_b(0x00);
    output_b(0);
    lcd_init();

    int pos = 0;

    while (TRUE) {
        int a = input_d();
        delay_ms(20);

        if (!(a & 0b00001000)) continue;
        while (input(PIN_D3));  

        switch (a) {
            
            case 0b01111000: infix[pos++] = '0'; printf(lcd_putc, "0"); break;
            case 0b00101000: infix[pos++] = '1'; printf(lcd_putc, "1"); break;
            case 0b01101000: infix[pos++] = '2'; printf(lcd_putc, "2"); break;
            case 0b10101000: infix[pos++] = '3'; printf(lcd_putc, "3"); break;
            case 0b00011000: infix[pos++] = '4'; printf(lcd_putc, "4"); break;
            case 0b01011000: infix[pos++] = '5'; printf(lcd_putc, "5"); break;
            case 0b10011000: infix[pos++] = '6'; printf(lcd_putc, "6"); break;
            case 0b00001000: infix[pos++] = '7'; printf(lcd_putc, "7"); break;
            case 0b01001000: infix[pos++] = '8'; printf(lcd_putc, "8"); break;
            case 0b10001000: infix[pos++] = '9'; printf(lcd_putc, "9"); break;

            
            case 0b11001000: infix[pos++] = '/'; printf(lcd_putc, "/"); break;
            case 0b11011000: infix[pos++] = '*'; printf(lcd_putc, "*"); break;
            case 0b11101000: infix[pos++] = '-'; printf(lcd_putc, "-"); break;
            case 0b11111000: infix[pos++] = '+'; printf(lcd_putc, "+"); break;

            // '=' butonu
            case 0b10111000:
                infix[pos] = '\0';
                infix_to_postfix(infix, postfix);
                int result = evaluate_postfix(postfix);
                lcd_init();
                printf(lcd_putc, "= %d", result);
                pos = 0;
                top = -1;
                delay_ms(1500);
                lcd_init();
                break;

            //  (Clear) tuşu
            case 0b00111000:
                lcd_init();
                pos = 0;
                top = -1;
                break;
        }
    }
} 