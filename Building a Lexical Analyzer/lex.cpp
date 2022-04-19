    #include <fstream>
    #include <string>
    #include <iostream>
    #include "lex.h"
    #include <map>

    using namespace std;

    map < string, Token > mapTok = {
      {
          /*program declared rarastring token map*/
        "PROGRAM",
        PROGRAM
      },
      {
          /*WRITELN declared rarastring token map*/
        "WRITELN",
        WRITELN
      },
      {
          /*ELSE declared rarastring token map*/
        "ELSE",
        ELSE
      },
      {
          /*EQUAL declared rarastring token map*/
        "EQUAL",
        EQUAL
      },
      {
          /*ERR declared rarastring token map*/
        "ERR",
        ERR
      },
      {
          /*FOR declared rarastring token map*/
        "FOR",
        FOR
      },
      {
          /*INTEGER declared rarastring token map*/
        "INTEGER",
        INTEGER
      },
      {
          /*THEN declared rarastring token map*/
        "THEN",
        THEN
      },
      {
          /*DO declared rarastring token map*/
        "DO",
        DO
      },
   
      {
          /*GTHAN declared rarastring token map*/
        "GTHAN",
        GTHAN
      },
      {
          /*LTHAN declared rarastring token map*/
        "LTHAN",
        LTHAN
      },
           {
          /*TO declared rarastring token map*/
        "TO",
        TO
      },
      {
          /*PLUS declared rarastring token map*/
        "PLUS",
        PLUS
      },
      {
          /*END declared rarastring token map*/
        "END",
        END
      },
      {
          /*LPAREN declared rarastring token map*/
        "LPAREN",
        LPAREN
      },
      {
          /*STRING declared rarastring token map*/
        "STRING",
        STRING
      },
      {
          /*VAR declared rarastring token map*/
        "VAR",
        VAR
      },
      {
          /*RPAREN declared rarastring token map*/
        "RPAREN",
        RPAREN
      },
      {
          /*DOWNTO declared rarastring token map*/
        "DOWNTO",
        DOWNTO
      },
      {
          /*IDENT declared rarastring token map*/
        "IDENT",
        IDENT
      },
      {
          /*ICONST declared rarastring token map*/
        "ICONST",
        ICONST
      },
      {
          /*RCONST declared rarastring token map*/
        "RCONST",
        RCONST
      },
      {
          /*DIV  declared rarastring token map*/
        "DIV",
        DIV
      },
      {
          /*COMMA declared rarastring token map*/
        "COMMA",
        COMMA
      },
      {
          /*IF declared rarastring token map*/
        "IF",
        IF
      },
      {
          /*REAL declared rarastring token map*/
        "REAL",
        REAL
      },
      {
          /*MULT declared rarastring token map*/
        "MULT",
        MULT
      },
      {
          /*SEMICOL declared rarastring token map*/
        "SEMICOL",
        SEMICOL
      },
      {
          /*DONE declared rarastring token map*/
        "DONE",
        DONE
      },
      {
          /*SCONST declared rarastring token map*/
        "SCONST",
        SCONST
      },
      {
          /*DOT declared rarastring token map*/
        "DOT",
        DOT
      },
      {
          /*MINUS declared rarastring token map*/
        "MINUS",
        MINUS
      },
      {
          /*COLON declared rarastring token map*/
        "COLON",
        COLON
      },
      {
          /*BEGIN declared rarastring token map*/
        "BEGIN",
        BEGIN
      },
      {
          /*ASSOP declared rarastring token map*/
        "ASSOP",
        ASSOP
      }

    };

    string upperCase(string lop) {
        int i/*i is declared*/;
        i =0/*i is set to zero*/;
        
        while(i < lop.length())/*while loop to go through all of it*/{
        lop[i] = toupper(lop[i])/*toupper*/;
        i = i + 1 /*adds to i and ends loop*/;
      }
      return lop /*returns lop*/;
    }

    LexItem getNextToken(istream & rara, int & lineNum) {

      enum Token_State {
        START/*start declared in toke state*/,
        INSTRING/*INSTRING declared in toke state*/,
        ININT/*ININT declared in toke state*/,
        INID/*INID declared in toke state*/,
        INREAL/*INREAL declared in toke state*/,
        INCOMMENT/*INCOMMENT declared in toke state*/
      }
        
        
      lexState = START /*START declared as state of lex*/;
      char character /*character is then set as char*/;
      string lex/*string lex is set*/;
      lex = "" /*lex is set empty*/;
        

      while ( rara.get(character)) {

        switch (lexState) {
      
        if(lexState == INSTRING){
        case INSTRING /*case for INSTRING*/:
          if (character == '\''/*character if equal to \*/) {
            return LexItem(SCONST, lex, lineNum)/*returns lex item with correct item*/;
          } else if (character == '\n') {
            lex.insert(0, 1, '\'');
            return LexItem(ERR, lex, lineNum)/*returns lex item with correct item*/;
          } 
           else {
            lex = lex + character;
          }

          break;
          }
                 if(lexState == INID){
        case INID /*case for INID*/:
          if (isalpha(character) /*is alpha character*/ || isdigit(character) /*isdigit character*/ || character == '_' /*character == _*/) {
              
            lex += character;
              
              
            if ( rara.peek() == '!' || rara.peek() == '.' || rara.peek() == '#' || rara.peek() == '?') {
              return LexItem(IDENT, upperCase(lex), lineNum);
            }
          } 
            else {
            rara.putback(character) /*Checks for erros*/ ;
            string keyword = upperCase(lex);

            if (keyword == "PROGRAM") {
              return LexItem(PROGRAM, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "WRITELN") {
              return LexItem(WRITELN, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "INTEGER") {
              return LexItem(INTEGER, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "TO") {
              return LexItem(TO, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "IF") {
              return LexItem(IF, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "REAL") {
              return LexItem(REAL, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "STRING") {
              return LexItem(STRING, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "VAR") {
              return LexItem(VAR, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "END") {
              return LexItem(END, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "FOR") {
              return LexItem(FOR, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "THEN") {
              return LexItem(THEN, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "DO") {
              return LexItem(DO, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "DOWNTO") {
              return LexItem(DOWNTO, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "BEGIN") {
              return LexItem(BEGIN, keyword, lineNum/*returns lex item with correct item*/);
            } else if (keyword == "ELSE") {
              return LexItem(ELSE, keyword, lineNum)/*returns lex item with correct item*/;
            } else {
              return LexItem(IDENT, keyword, lineNum)/*returns lex item with correct item*/;
            }
          }
          break;
        }

        if(lexState == ININT){
        case ININT:
          if (isdigit(character)) {
            lex = lex + character;
          }
            else if (isalpha(character)) {
            rara.putback(character);
            return LexItem(ICONST, lex, lineNum)/*returns lex item with correct item*/;
          }
            else if (character == '.') {
            lex = lex + character;
            lexState = INREAL;
          }
            else {
            rara.putback(character);
            return LexItem(ICONST, lex, lineNum)/*returns lex item with correct item*/;
          }

          break;
        }

        if(lexState == INREAL){        
        case INREAL:
          if (isdigit(character)) {
            lex = lex + character;
          } else if (isalpha(character)) {
            rara.putback(character);
            return LexItem(RCONST, lex, lineNum)/*returns lex item with correct item*/;
          } else if (character == '.') {
            lex = lex + character;
            return LexItem(ERR, lex, lineNum)/*returns lex item with correct item*/;
          } else {
            rara.putback(character);
            return LexItem(RCONST, lex, lineNum)/*returns lex item with correct item*/;
          }

          break;
        }
  if(lexState == START){
            
        case START/*case for start*/:
            
          if (character == ':'/*character == to :*/) {
            if ( rara.peek() == '='/*== to =*/) {
              rara.get(character);
              return LexItem(ASSOP, lex, lineNum/*returns lex item with correct item*/);
            } 
              else/*else for the if : case*/ 
              {
              return LexItem(COLON, lex, lineNum/*returns lex item with correct item*/);
              }
          }
            
            
          if ( rara.peek() == -1 || rara.eof/*rara== to -1*/()) {
            return LexItem(DONE, "DONE", lineNum/*returns lex item with correct item*/);

          }
            
            
          if (character == '+'/*character ==  to +*/) {
            lex = lex + character;
            return LexItem(PLUS, lex, lineNum/*returns lex item with correct item*/);

              
          }
            
            
          if (character == '-' /*character == -*/) {
            lex = lex + character;
            return LexItem(MINUS, lex, lineNum/*returns lex item with correct item*/);

          }
            
          if (character == ')' /*character == ) if*/) {
            lex = lex + character;
            return LexItem(RPAREN, lex, lineNum/*returns lex item with correct item*/);

          }
            
            
          if (character == '>'/*character == > if*/) {
            lex = lex + character;
            return LexItem(GTHAN, lex, lineNum/*returns lex item with correct item*/);

          }
            
          if (character == '<'/*character == < if*/) {
            lex = lex + character;
            return LexItem(LTHAN, lex, lineNum/*returns lex item with correct item*/);

          }
            
          if (character == '='/*character == = if*/) {
            lex = lex + character;
            return LexItem(EQUAL, lex, lineNum/*returns lex item with correct item*/);

          }
            
            
          if (character == '!' || character == '#' || character == '?'/*character == or and or if*/) {
            lex = lex + character;
            return LexItem(ERR, lex, lineNum/*returns lex item with correct item*/);

          }
            
            
          if (character == '\n' /*character == next line if*/) {
            lineNum = lineNum + 1;
            continue;

          }
            
            
          if (character == '.' /*character == . if*/) {
            lex += "0.";
            lexState = INREAL;

          }
            
            
          if (character == '*' /*character == * if*/) {
            lex = lex + character;
            return LexItem(MULT, lex, lineNum/*returns lex item with correct item*/);

          }
            
            
          if (character == '/' /*character == / if*/) {
            lex = lex + character;
            return LexItem(DIV, lex, lineNum/*returns lex item with correct item*/);

          }
            
            
          if (isspace(character)) {
            continue;

          }
            
            
          if (character == '(' /*character == ( if*/) {
            if ( rara.peek() == '*') {
              lexState = INCOMMENT;
            } 
              
              else {
              lex = lex + character;
              return LexItem(LPAREN, lex, lineNum/*returns lex item with correct item*/);
            }
              
              
          }

          if (character == ';' /*character == ; if*/) {
            lex = lex + character /*lex is set to lex + character*/;
            return LexItem(SEMICOL, lex, lineNum/*returns lex item with correct item*/);

          }

          if (character == ',' /*character == , if*/) {
            lex = lex + character;
            return LexItem(COMMA, lex, lineNum/*returns lex item with correct item*/);

          }
          if (character == '\n' /*character == next if*/ ) {
            lex = lex + character;
            lineNum++; /*lin*/;

          }
            
            
          if (isalpha(character) || character == '_' /*character if*/) {
            lex = lex + character /*lex is added plus character*/;
            lexState = INID /*lexstate is == ined then*/;

          }
            
          if (isdigit(character) /*another if*/ ) {
            lex = lex + character /*lex is then added to character*/;
            lexState = ININT /*lexState is then set to ININT*/;

          }
            
            
          if (character == '\'' || character == '"' /*\ if*/) {
            lexState = INSTRING;

          }

          break;
            
          }

       

        if(lexState == INCOMMENT){
        case INCOMMENT:
          if (character == '\n') {
            lineNum = lineNum + 1;
          }
          if (rara.peek() == EOF/*EOF is then equal to the.opeek*/) {
              
            lineNum -= 1;
            cout << endl;
            cout << "Missing a comment end delimiters '*)' at line " << lineNum;
            cout << endl;
            return LexItem(DONE, "DONE", lineNum);
              
          }
            
            else if (character == '*' && rara.peek() == ')') {
            rara.get(character);
            lexState = START /*lexState is set to start*/;
            break;
          }
        }

          break;

          if ( rara.peek() == -1 || rara.eof()) {
            return LexItem(DONE, "", lineNum/*returns lex item with correct item*/);
          }
        }
      }
      return LexItem();
    }

    ostream & operator << (ostream & COUT,
      const LexItem & tok) {

      map < Token, string > Token_Dictionary = {
        {
         /*TO is set into token string map*/
          TO,
          "TO"
        },
        /*DOWNTO is set into token string map*/ {
          DOWNTO,
          "DOWNTO"
        },
        /*IDENT is set into token string map*/ {
          IDENT,
          "IDENT"
        },
        /*MULT is set into token string map*/ {
          MULT,
          "MULT"
        },
        /*STRING is set into token string map*/ {
          STRING,
          "STRING"
        },
        /*IF is set into token string map*/ {
          IF,
          "IF"
        },
        /*DIV is set into token string map*/ {
          DIV,
          "DIV"
        },
        /*DO is set into token string map*/ {
          DO,
          "DO"
        },
        /*END is set into token string map*/ {
          END,
          "END"
        },
        /*WRITELN is set into token string map*/ {
          WRITELN,
          "WRITELN"
        },
        /*INTEGER is set into token string map*/ {
          INTEGER,
          "INTEGER"
        },
        /*VAR is set into token string map*/ {
          VAR,
          "VAR"
        },
        /*MINUS is set into token string map*/ {
          MINUS,
          "MINUS"
        },
        /*PLUS is set into token string map*/ {
          PLUS,
          "PLUS"
        },
        /*LTHAN is set into token string map*/ {
          LTHAN,
          "LTHAN"
        },
        /*EQUAL is set into token string map*/ {
          EQUAL,
          "EQUAL"
        },
        /*RCONST is set into token string map*/ {
          RCONST,
          "RCONST"
        },
        /*THEN is set into token string map*/ {
          THEN,
          "THEN"
        },
        /*SCONST is set into token string map*/ {
          SCONST,
          "SCONST"
        },
        /*PROGRAM is set into token string map*/ {
          PROGRAM,
          "PROGRAM"
        },
        /*BEGIN is set into token string map*/ {
          BEGIN,
          "BEGIN"
        },
        /*GTHAN is set into token string map*/ {
          GTHAN,
          "GTHAN"
        },
        /*SEMICOL is set into token string map*/ {
          SEMICOL,
          "SEMICOL"
        },
        /*COLON is set into token string map*/ {
          COLON,
          "COLON"
        },
        /*ELSE is set into token string mapTO is set into token string map*/ {
          ELSE,
          "ELSE"
        },
        /*ASSOP is set into token string map*/ {
          ASSOP,
          "ASSOP"
        },
        /*REAL is set into token string map*/ {
          REAL,
          "REAL"
        },
        /*FOR is set into token string map*/ {
          FOR,
          "FOR"
        },
        /*ICONST is set into token string map*/ {
          ICONST,
          "ICONST"
        },
        /*RPAREN is set into token string map*/ {
          RPAREN,
          "RPAREN"
        },
        /*COMMA is set into token string map*/ {
          COMMA,
          "COMMA"
        },
        /*DOT is set into token string map*/ {
          DOT,
          "DOT"
        },
        /*ERR is set into token string map*/ {
          ERR,
          "ERR"
        },
        /*DONE is set into token string map*/ {
          DONE,
          "DONE"
        },
        /*LPAREN is set into token string map*/ {
          LPAREN,
          "LPAREN"
        } /*end of map to string*/
      };

      Token last = tok.GetToken();
      COUT << Token_Dictionary[last];
      if (last == IDENT || last == ICONST || last == SCONST || last == RCONST || last == ERR) {
        COUT << "(" << tok.GetLexeme() << ")";
      }

      return COUT;
    }