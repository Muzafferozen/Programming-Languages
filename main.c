#include <stdio.h>
#include <ctype.h>

int charClass;
char lexeme [100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp,
*fopen();
void addChar();
void getChar();
void getNonBlank();
void error();
int isKeyword();
int lex();

void factor();
void stmts();
void stmt();
void assign();
void asgnInt();
void asgnFloat();
void asgnChar();
void asgnBool();
void ifcon();
void elsecon();
void logicExpr();
void whilecon();
void addition();
void substraction();
void multiplication();
void division();
void print();
void asgnArray();
void error();
void program();


#define LETTER 0
#define DIGIT 1
#define DOUBLE 2
#define UNKNOWN 99
#define INT_LIT 10
#define IDENT 11
#define FLOAT 12
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
#define RIGHT_BRA 27
#define LEFT_BRA 28
#define SEMI_COLON 29
#define COMMA 30
#define DOT 31
#define DOUBLE_DOT 32
#define QUESTION 34
#define EQUIVALENT 35
#define NAIL 36
#define LEFT_STRAIGH 37
#define RIGHT_STRAIGH 38

#define OPERATOR 33
#define ASSIGN_OP 90
#define ADD_FUNC 91
#define INTEGER_OP 92
#define CHAR_OP 93
#define FLOAT_OP 94
#define BOOL_OP 95
#define IF 96
#define ELSE 104
#define WHILE 97
#define SUB_FUNC 98
#define DIV_FUNC 99
#define MULT_FUNC 100
#define PRINT_FUNC 101
#define TRUE 102
#define FALSE 103
#define ARRAY 104
#define START 105

main() {
  if ((in_fp = fopen("program4.txt", "r")) == NULL)
    printf("ERROR - cannot open program2.txt\n");
  else {
        getChar();
     do { lex();
          parse();

        } while (nextToken != EOF);
       }
}
int lookup(char ch) {
    switch (ch)
{   case '(':
    addChar();
    nextToken = LEFT_PAREN;
    break;
    case ')':
    addChar();
    nextToken = RIGHT_PAREN;
    break;
    case '[':
    addChar();
    nextToken = LEFT_STRAIGH;
    break;
    case ']':
    addChar();
    nextToken = RIGHT_STRAIGH;
    break;
    case '}':
    addChar();
    nextToken = RIGHT_BRA;
    break;
    case '{':
    addChar();
    nextToken = LEFT_BRA;
    break;
    case ';':
    addChar();
    nextToken = SEMI_COLON;
    break;
    case ',':
    addChar();
    nextToken = COMMA;
    break;
    case '.':
    addChar();
    nextToken = DOT;
    break;
    case ':':
    addChar();
    nextToken = DOUBLE_DOT;
    break;
    case '+':
    addChar();
    nextToken = OPERATOR;
    break;
    case '/':
    addChar();
    nextToken = OPERATOR;
    break;
    case '*':
    addChar();
    nextToken = OPERATOR;
    break;
    case '-':
    addChar();
    nextToken = OPERATOR;
    break;
    case '=':
    addChar();
    nextToken = EQUIVALENT;
    break;
    case '?':
    addChar();
    nextToken = QUESTION;
    break;
    case '^':
    addChar();
    nextToken = NAIL;
    break;

    default:
    addChar();
    nextToken = EOF;
    break;
     }
     return nextToken; }
void addChar() {
if (lexLen <= 98) {
   lexeme[lexLen++] = nextChar;
   lexeme[lexLen] = 0;
                  }
else
    printf("Error - lexeme is too long \n");
               }
void getChar() {
if ((nextChar = getc(in_fp)) != EOF)
{
    if (isalpha(nextChar))
        charClass = LETTER;
          else if (isdigit(nextChar))
                     charClass = DIGIT;
                 else if( nextChar == '.')
                        charClass = DOUBLE;

               else charClass = UNKNOWN;
}
else
    charClass = EOF;

               }
void getNonBlank() {
while (isspace(nextChar))
       getChar();
                    }
int lex() {
lexLen = 0;
getNonBlank();
switch (charClass) {
    case LETTER:
    addChar();
    getChar();
    while (charClass == LETTER || charClass == DIGIT) {
           addChar();
           getChar();
                                                }
           nextToken = IDENT;
     break;
     case DIGIT:
            nextToken = INT_LIT;
            while (charClass == DIGIT) {
                addChar();
                getChar();
                if(charClass == DOUBLE){
                    nextToken = FLOAT;
                    addChar();
                    getChar();
                    while (charClass == DIGIT){
                        addChar();
                        getChar();
                    }
                }
            }
     break;


     case UNKNOWN:
     lookup(nextChar);
     getChar();
     break;
     case EOF:
     nextToken = EOF;
     lexeme[0] = 'E';
     lexeme[1] = 'O';
     lexeme[2] = 'F';
     lexeme[3] = 0;
     break;
                }

switch(nextToken){
       case 10:
            printf("Next token is:INTEGER, Next lexeme is %s\n", lexeme);
            break;
       case 11:
                if(strcmp(lexeme, "ata") == 0){
                nextToken = ASSIGN_OP;
                printf("Next token is:ASSIGN_OP, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "basla") == 0){
                nextToken = START;
                printf("Next token is:START Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "tamsayi") == 0){
                nextToken = INTEGER_OP;
                printf("Next token is:INTEGER_OP Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "harf") == 0){
                nextToken = CHAR_OP;
                printf("Next token is:CHAR_OP, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "ondalik") == 0){
                nextToken =FLOAT_OP;
                printf("Next token is:FLOAT_OP, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "belirtec") == 0){
                nextToken = BOOL_OP;
                printf("Next token is:BOOL_OP, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "eger") == 0){
                nextToken = IF;
                printf("Next token is:IF, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "dongu") == 0){
                nextToken = WHILE;
                printf("Next token is:WHILE, Next lexeme is %s\n", lexeme);
                } else if(strcmp(lexeme, "tamsayi") == 0){
                nextToken = INTEGER_OP;
                printf("Next token is:INTEGER_OP Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "topla") == 0){
                nextToken = ADD_FUNC;
                printf("Next token is:ADD_FUNC, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "cikar") == 0){
                nextToken = SUB_FUNC;
                printf("Next token is:SUB_FUNC, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "carp") == 0){
                nextToken = MULT_FUNC;
                printf("Next token is:MULT_FUNC, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "bol") == 0){
                nextToken = DIV_FUNC;
                printf("Next token is:DIV_FUNC, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "yaz") == 0){
                nextToken = PRINT_FUNC;
                printf("Next token is:PRINT_FUNC, Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "dogru") == 0){
                nextToken = TRUE;
                printf("Next token is:TRUE Next lexeme is %s\n", lexeme);
                }
                else if(strcmp(lexeme, "yanlis") == 0){
                nextToken = FALSE;
                printf("Next token is:FALSE Next lexeme is %s\n", lexeme);
                } else if(strcmp(lexeme, "degilse") == 0){
                nextToken = ELSE;
                printf("Next token is:ELSE Next lexeme is %s\n", lexeme);
                                }
                else if(strcmp(lexeme, "dizi") == 0){
                nextToken = ARRAY;
                printf("Next token is:ARRAY Next lexeme is %s\n", lexeme);
                }
                else{
                printf("Next token is:IDENTIFIER, Next lexeme is %s\n", lexeme);
                }
                  break;


       case 12 :
             printf("Next token is:FLOAT, Next lexeme is %s\n", lexeme);
             break;
       case 29:
            printf("Next token is:SEMI_COLON, Next lexeme is %s\n", lexeme);
            break;
       case 25 :
            printf("Next token is:LEFT_PAREN,   Next lexeme is %s\n", lexeme);
            break;
       case 26:
            printf("Next token is:RIGHT_PAREN,   Next lexeme is %s\n", lexeme);

            break;
       case 27 :
            printf("Next token is:RIGHT_CURLY,   Next lexeme is %s\n", lexeme);
            break;
       case 28 :
            printf("Next token is:LEFT_CURLY,   Next lexeme is %s\n", lexeme);
            break;
       case 30 :
            printf("Next token is:COMMA,   Next lexeme is %s\n", lexeme);
            break;
       case 31 :
            printf("Next token is:DOT,   Next lexeme is %s\n", lexeme);
            break;
        case 32 :
            printf("Next token is:DOUBLE_DOT,   Next lexeme is %s\n", lexeme);
            break;
        case 33 :
            printf("Next token is:OPERATOR,   Next lexeme is %s\n", lexeme);
            break;
        case 34 :
            printf("Next token is:QUESTION_MARK,   Next lexeme is %s\n", lexeme);
            break;
        case 35 :
            printf("Next token is:EQUIVALENT,   Next lexeme is %s\n", lexeme);
            break;
        case 36 :
            printf("Next token is:NAIL_OP,   Next lexeme is %s\n", lexeme);
            break;
        case 37 :
            printf("Next token is:LEFT_STRAIGH,   Next lexeme is %s\n", lexeme);
            break;
         case 38 :
            printf("Next token is:RIGHT_STRAIGH,   Next lexeme is %s\n", lexeme);
            break;
       default :
            printf("Next token is:IDENTIFIER,   Next lexeme is %s\n", lexeme);
            break;
        }

    return nextToken;

}


void parse(){

program();

}

void factor() {

        printf("Enter <factor>\n");
        if ( (nextToken == IDENT) || (nextToken == INT_LIT) || (nextToken == FLOAT)){
            lex();
        }
            else {
                error();
            }
        printf("Exit <factor>\n");
    }

void stmts(){

        printf("Enter <stmts>\n");

        while(nextToken == INTEGER_OP || nextToken == FLOAT_OP || nextToken == CHAR_OP || nextToken == BOOL_OP ||
         nextToken == IF || nextToken == IF || nextToken == WHILE || nextToken == ADD_FUNC ||
         nextToken == SUB_FUNC || nextToken == MULT_FUNC || nextToken == DIV_FUNC ||
         nextToken == PRINT_FUNC || nextToken == IDENT)
         {
          stmt();
          lex();
         }
         printf("Exit <stmts>\n");

    }


void stmt(){
        printf("Enter <stmt>\n");

        if(nextToken == INTEGER_OP || nextToken == ARRAY || nextToken == FLOAT_OP || nextToken == CHAR_OP || nextToken == BOOL_OP || nextToken == IDENT)
            assign();
        else if (nextToken == IF)
            ifcon();
        else if (nextToken == WHILE)
            whilecon();
        else if (nextToken == ADD_FUNC)
            addition();
        else if( nextToken == SUB_FUNC)
           substraction();
       else if ( nextToken == MULT_FUNC)
            multiplication();
       else if(nextToken == DIV_FUNC)
            division();
       else if(nextToken == PRINT_FUNC)
            print();
        else
            printf("ERROR",nextToken);

        printf("Exit <stmt>\n");
    }

void assign(){
        printf("Enter <assign>\n");

            if(nextToken == INTEGER_OP)
                asignInt();
            else if(nextToken == FLOAT_OP)
                asignFloat();
            else if(nextToken == CHAR_OP)
                asignChar();
            else if(nextToken == BOOL_OP)
                asignBool();
            else if(nextToken == ARRAY)
                asignArray();
            else{
                if(nextToken == IDENT){
                    lex();
                    if(nextToken != ASSIGN_OP)
                        error();
                    else{
                        lex();
                            if(nextToken == IDENT){
                                lex();
                                if(nextToken != SEMI_COLON)
                                    error();
                            }

                            else{
                                lex();
                                logic();
                            }

                    }

                }
            }

        printf("Exit <assign>\n");
    }



void asignInt(){
        printf("Enter <int>\n");

        if(nextToken != INTEGER_OP){
            error();
        }
        else{
            lex();
            if(nextToken != LEFT_PAREN){
                error();
            }else{
                lex();
                if(nextToken != IDENT){
                    error();
                }
                else{
                    lex();
                    if(nextToken != COMMA){
                        error();
                    }
                    else{
                        lex();
                        factor();
                        if(nextToken != RIGHT_PAREN){
                            error();
                        }
                        else {
                            lex();
                            if(nextToken != SEMI_COLON){
                                error();
                            }
                        }
                    }
                }

            }
        }
        printf("Exit <int>\n");
    }


void asignFloat(){
        printf("Enter <float>\n");
        if(nextToken != FLOAT_OP){
            error();
        }
        else{
            lex();
            if(nextToken != LEFT_PAREN){
                error();
            }else{
                lex();
                if(nextToken != IDENT){
                    error();
                }
                else{
                    lex();
                    if(nextToken != COMMA){
                        error();
                    }
                    else{
                        lex();
                        factor();
                        if(nextToken != RIGHT_PAREN){
                            error();
                        }
                        else {
                            lex();
                            if(nextToken != SEMI_COLON){
                               error();
                            }
                        }
                    }
                }

            }
        }
        printf("Exit <float>\n");
    }




void asignChar(){

        printf("Enter <char>\n");

        if(nextToken != CHAR_OP){
            error();
        }
        else{
            lex();
            if(nextToken != LEFT_PAREN){
                error();
            }else{
                lex();
                if(nextToken != IDENT){
                    error();
                }
                else{
                    lex();
                    if(nextToken != COMMA){
                        error();
                    }
                    else{
                        lex();
                        if(nextToken != IDENT){
                           error();
                        }
                        else{
                            lex();
                            if(nextToken != RIGHT_PAREN){
                                error();
                            }
                            else {
                                lex();
                                if(nextToken != SEMI_COLON){
                                error();
                                }
                            }
                        }
                    }
                }

            }
        }
        printf("Exit <char>\n");

    }


void asignBool(){
        printf("Enter <bool>\n");

        if(nextToken != BOOL_OP){
            error();
        }
        else{
            lex();
            if(nextToken != LEFT_PAREN){
                error();
            }else{
                lex();
                if(nextToken != IDENT){
                    error();
                }
                else{
                    lex();
                    if(nextToken != COMMA){
                        error();
                    }
                    else{
                        lex();
                        logic();
                        if(nextToken != RIGHT_PAREN){
                            error();
                        }
                        else {
                            lex();
                            if(nextToken != SEMI_COLON){
                                error();
                            }
                        }
                    }
                }

            }
        }
        printf("Exit <bool>\n");
    }



void ifcon(){
                printf("Enter <if>\n");
        if (nextToken != IF)
            error();
        else{
            lex();
            if(nextToken != LEFT_PAREN)
                error();
            else{
                lex();
                logic();
                if(nextToken != RIGHT_PAREN)
                    error();
                else{
                    lex();
                    if(nextToken != LEFT_BRA)
                        error();
                    else{
                        lex();
                        stmts();
                        if(nextToken != RIGHT_BRA)
                            error();
                        else{
                            lex();
                            if(nextToken == ELSE){
                                elsecon();
                            }
                        }
                    }
                }
            }
        }

            printf("Exit <if>\n");
    }


void elsecon(){
        printf("Enter <else>\n");

        if (nextToken != ELSE)
            error();
        else{
            lex();
            if(nextToken != LEFT_BRA)
                error();
            else{
                lex();
                stmts();
                if(nextToken != RIGHT_BRA)
                   error();
            }
        }
        printf("Exit <else>\n");
    }



void logic(){
        printf("Enter <logic>\n");


        if(nextToken == TRUE){
                    lex();
        }
        else if(nextToken == FALSE){
                    lex();
        }
	else{
	error();
	}

    printf("Exit <logic>\n");

    }


void whilecon(){

        printf("Enter <while>\n");
            if(nextToken != WHILE){
                error();
            }
            else{
                lex();
                if(nextToken != LEFT_PAREN){
                    error();
                }
                else{
                    lex();
                    logic();

                    if(nextToken != RIGHT_PAREN){
                        error();
                    }
                    else{
                        lex();
                        if(nextToken != LEFT_BRA){
                            error();
                        }
                        else{
                                lex();
                                stmts();
                                if(nextToken != RIGHT_BRA)
                                    error();
                                else
                                    lex();
                        }
                    }
                }
            }

        printf("Exit <while>\n");
    }


void addition(){
        printf("Enter <addition>\n");

        if(nextToken != ADD_FUNC)
            error();

        lex();

        if(nextToken != LEFT_PAREN){
            error();
        }
        else{
            lex();
            if(nextToken != IDENT){
                error();
            }
            else{
                lex();
                if(nextToken != COMMA){
                    error();
                }
                else{
                    lex();
                    factor();


                            if(nextToken != COMMA){
                            error();
                            }
                            else{
                            lex();
                            factor();


                            if(nextToken != RIGHT_PAREN){
                            error();
                            }
                            else{
                            lex();
                                if(nextToken != SEMI_COLON){
                                error();
                            }
                        }

                    }

                }
            }
        }
        printf("Exit <addition>\n");
    }



void substraction(){
        printf("Enter <substraction>\n");

        if(nextToken != SUB_FUNC)
            error();

        lex();

        if(nextToken != LEFT_PAREN){
            error();
        }
        else{
            lex();
            if(nextToken != IDENT){
                error();
            }
            else{
                lex();
                if(nextToken != COMMA){
                    error();
                }
                else{
                    lex();
                    factor();


                            if(nextToken != COMMA){
                            error();
                            }
                            else{
                            lex();
                            factor();


                            if(nextToken != RIGHT_PAREN){
                            error();
                            }
                            else{
                            lex();
                                if(nextToken != SEMI_COLON){
                                error();
                            }
                        }

                    }

                }
            }
        }
        printf("Exit <substraction>\n");
    }


void multiplication(){
        printf("Enter <multiplication>\n");

        if(nextToken != MULT_FUNC)
            error();

        lex();

        if(nextToken != LEFT_PAREN){
            error();
        }
        else{
            lex();
            if(nextToken != IDENT){
                error();
            }
            else{
                lex();
                if(nextToken != COMMA){
                    error();
                }
                else{
                    lex();
                    factor();


                            if(nextToken != COMMA){
                            error();
                            }
                            else{
                            lex();
                            factor();


                            if(nextToken != RIGHT_PAREN){
                            error();
                            }
                            else{
                            lex();
                                if(nextToken != SEMI_COLON){
                                error();
                            }
                        }

                    }

                }
            }
        }
        printf("Exit <multiplication>\n");
    }


void division(){
        printf("Enter <division>\n");

        if(nextToken != DIV_FUNC)
            error();

        lex();

        if(nextToken != LEFT_PAREN){
            error();
        }
        else{
            lex();
            if(nextToken != IDENT){
                error();
            }
            else{
                lex();
                if(nextToken != COMMA){
                    error();
                }
                else{
                    lex();
                    factor();


                            if(nextToken != COMMA){
                            error();
                            }
                            else{
                            lex();
                            factor();


                            if(nextToken != RIGHT_PAREN){
                            error();
                            }
                            else{
                            lex();
                                if(nextToken != SEMI_COLON){
                                error();
                            }
                        }

                    }

                }
            }
        }
        printf("Exit <division>\n");
    }

void print(){
	printf("Enter <print>\n");
  if(nextToken != PRINT_FUNC)
            error();

        lex();

        if(nextToken != LEFT_PAREN){
            error();
        }
        else{
            lex();
            if(nextToken != NAIL){
                error();
            }
            else{
                lex();
                if(nextToken != IDENT){
                    error();
                }
                    else{
                        lex();
                        if(nextToken != NAIL){
                            error();
                        }
                        else{
                            lex();
                            if(nextToken != RIGHT_PAREN){
                                error();
	           }else{
                		lex();
                		if(nextToken != SEMI_COLON){
                   		 error();
                                }
                           }
                    }
                }
            }
        }

}


void asignArray(){
        printf("Enter <array>\n");

        if(nextToken != ARRAY){
            error();
        }
        else{
            lex();
            if(nextToken != LEFT_STRAIGH){
                error();
            }
                else{
                    lex();
                    if(nextToken !=INT_LIT){
                        error();
                    }
                    else{
                        lex();
                        if(nextToken != RIGHT_STRAIGH){
                            error();
                        }
                        else {
                            lex();
                            if(nextToken != LEFT_BRA){
                                error();
                            }
	           else {
                lex();
                factor();
                if(nextToken = COMMA){
                    lex();
                    while (nextToken == IDENT || nextToken == INT_LIT || nextToken == FLOAT){
                        lex();
                        factor();
                    }
                }
                if(nextToken !=RIGHT_BRA){
                error();
                    }else{
			         lex();
				if(nextToken !=SEMI_COLON){
				error();
				}
			}
		}
                          }
                     }
                 }

        }
        printf("Exit <array>\n");
    }
void error() {
printf("This syntax is wrong.");
exit(0);
}

void program(){

        if(nextToken != START)
            error();
        else{
            printf("Enter <program>\n");
            lex();
            stmts();
                printf("Exit <program>\n");
                exit(0);
        }


}


